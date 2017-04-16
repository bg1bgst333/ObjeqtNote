// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "PictureBox.h"	// ピクチャーボックスクラス

// コンストラクタCPictureBox()
CPictureBox::CPictureBox() {

	// 初期化
	m_hBitmap = NULL;	// m_hBitmapにNULLをセット.

}

// デストラクタ~CPictureBox()
CPictureBox::~CPictureBox() {

	// 終了処理
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

	// インスタンスハンドルの取得.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWLP_HINSTANCE);	// GetWindowLongでインスタンスハンドルを取得.

	// 画像のロード.(ひとまずビットマップのみ.)
	m_hBitmap = (HBITMAP)LoadImage(hInstance, lpctszFileName, IMAGE_BITMAP, iWidth, iHeight, LR_LOADFROMFILE);	// LoadImageでビットマップをロード.
	if (m_hBitmap == NULL) {	// NULLなら.

		// 失敗.
		return FALSE;	// 失敗なのでFALSEを返す.

	}

	// 成功.
	return TRUE;	// 成功なのでTRUEを返す.

}

// 画像をセット(表示)する関数SetImage.
void CPictureBox::SetImage() {

	// 画像をセットする.
	SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_hBitmap);	// SendMessageでSTM_SETIMAGEを送信することでm_hBitmapをセットする.

}