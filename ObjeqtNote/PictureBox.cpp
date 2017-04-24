// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "PictureBox.h"	// ピクチャーボックスクラス

// コンストラクタCPictureBox()
CPictureBox::CPictureBox() {

	// 初期化
	m_hBitmap = NULL;		// m_hBitmapにNULLをセット.
	m_hMemDC = NULL;		// m_hMemDCにNULLをセット.
	m_iPictureWidth = 0;	// m_iPictureWidthに0をセット.
	m_iPictureHeight = 0;	// m_iPictureHeightに0をセット.

}

// デストラクタ~CPictureBox()
CPictureBox::~CPictureBox() {

	// 終了処理
	m_iPictureHeight = 0;	// m_iPictureHeightに0をセット.
	m_iPictureWidth = 0;	// m_iPictureWidthに0をセット.
	if (m_hMemDC != NULL) {
		DeleteDC(m_hMemDC);			// DelteDCでm_hMemDCを削除.
		m_hMemDC = NULL;			// m_hMemDCにNULLをセット.
	}
	if (m_hBitmap != NULL) {
		DeleteObject(m_hBitmap);	// DeleteObjectでm_hBitmapを削除.
		m_hBitmap = NULL;			// m_hBitmapにNULLをセット.
	}

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CPictureBox::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Createでウィンドウを作成し, その戻り値をreturnで返す.

}

// 画像をロードする関数Load.
BOOL CPictureBox::Load(LPCTSTR lpctszFileName, int iWidth, int iHeight) {

	// 変数の宣言.
	HINSTANCE hInstance;	// アプリケーションインスタンスハンドルhInstance.

	// 幅と高さをメンバにセット.
	m_iPictureWidth = iWidth;	// m_iPictureWidthにiWidthをセット.
	m_iPictureHeight = iHeight;	// m_iPictureHeightにiHeightをセット.

	// インスタンスハンドルの取得.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWLP_HINSTANCE);	// GetWindowLongでインスタンスハンドルを取得.

	// 画像のロード.(ひとまずビットマップのみ.)
	m_hBitmap = (HBITMAP)LoadImage(hInstance, lpctszFileName, IMAGE_BITMAP, m_iPictureWidth, m_iPictureHeight, LR_LOADFROMFILE);	// LoadImageでビットマップをロード.
	if (m_hBitmap == NULL) {	// NULLなら.

		// 失敗.
		return FALSE;	// 失敗なのでFALSEを返す.

	}

	// 成功.
	return TRUE;	// 成功なのでTRUEを返す.

}

// 画像をセット(表示)する関数SetImage.
void CPictureBox::SetImage() {

	// 変数の宣言
	HDC hDC;	// デバイスコンテキストハンドルHDC型hDC.

	// デバイスコンテキストの取得.
	hDC = GetDC(m_hWnd);	// GetDCでデバイスコンテキストを取得.

	// メモリデバイスコンテキストの作成.
	m_hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでメモリデバイスコンテキスト作成.

	// 画像をセットする.
	SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_hBitmap);	// SendMessageでSTM_SETIMAGEを送信することでm_hBitmapをセットする.

	// デバイスコンテキストの解放.
	ReleaseDC(m_hWnd, hDC);	// ReleaseDCでデバイスコンテキスト解放.

}

// ウィンドウの描画を要求された時のハンドラOnPaint.
void CPictureBox::OnPaint() {

	// 変数の宣言
	HDC hDC;			// デバイスコンテキストハンドルHDC型hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT構造体変数ps.
	HBITMAP hOld;		// 以前のビットマップハンドルhOld.
	int iDrawWidth;		// 実際の描画幅.
	int iDrawHeight;	// 実際の描画高さ.

	// 描画開始.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaintで描画開始.

	// ビットマップの選択.
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObjectでm_hBitmapを選択.

	// ビット転送による描画.
	iDrawWidth = m_iWidth - SCROLLBAR_THICKNESS;	// 実際にはコントロール幅 - スクロールバーの厚さ.
	iDrawHeight = m_iHeight - SCROLLBAR_THICKNESS;	// 実際にはコントロール高さ - スクロールバーの厚さ.
	BitBlt(hDC, 0, 0, iDrawWidth, iDrawHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBltでm_hMemDCからhDCにビット転送することで描画される.

	// 古いビットマップを再選択して戻す.
	SelectObject(m_hMemDC, hOld);	// SelectObjectでhOldを選択.

	// 描画終了.
	EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

}