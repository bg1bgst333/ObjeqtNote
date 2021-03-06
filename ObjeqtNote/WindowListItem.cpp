// ヘッダのインクルード
// 独自のヘッダ
#include "WindowListItem.h"	// ウィンドウリストアイテムクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CWindowListItem::RegisterClass(HINSTANCE hInstance) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("WindowListItem"));	// CUserControl::RegisterClassでウィンドウクラス"WindowListItem"を登録.

}

// コンストラクタCWindowListItem()
CWindowListItem::CWindowListItem() : CUserControl() {

}

// デストラクタ~CWindowListItem()
CWindowListItem::~CWindowListItem() {

}

// ウィンドウ作成関数Create
BOOL CWindowListItem::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	return CUserControl::Create(_T("WindowListItem"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createでウィンドウクラス"WindowListItem"なウィンドウを作成.

}

// ウィンドウ破棄関数Destroy
void CWindowListItem::Destroy() {

	// アイテムの一斉削除
	std::map<tstring, CWindow *>::iterator itor = m_mapChildMap.begin();	// イテレータ.
	while (itor != m_mapChildMap.end()) {
		if (itor->second != NULL) {
			itor->second->Destroy();
			delete itor->second;
			itor->second = NULL;
		}
		itor++;
	}
	m_mapChildMap.clear();

	// ペンとブラシの破棄.
	DeleteObject(m_hBrush);	// ブラシの破棄.
	DeleteObject(m_hPen);	// ペンの破棄.

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindowListItem::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ペンとブラシの作成.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0xff, 0, 0));		// 赤(濃)のペンを作成.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0xff, 0xc0, 0xcb));		// 赤(淡)のブラシを作成.

	// 成功なので0を返す.
	return 0;

}

// ウィンドウの描画を要求された時のハンドラOnPaint.
void CWindowListItem::OnPaint() {

	// 変数の宣言
	HDC hDC;			// デバイスコンテキストハンドルHDC型hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT構造体変数ps.

	// 描画開始.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaintで描画開始.
	// ペンとブラシの選択.
	HPEN hOldPen = (HPEN)SelectObject(hDC, m_hPen);		// 青のペンを選択.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, m_hBrush);	// 青のブラシを選択.
	// 矩形を描画.(クライアント領域はスクロールバーを含まない.)
	RECT rc;
	GetClientRect(m_hWnd, &rc);	// GetClientRectでクライアント領域の矩形を取得.
	Rectangle(hDC, 0, 0, rc.right - rc.left, rc.bottom - rc.top);	// Rectangleで矩形を描画.
	SetTextColor(hDC, RGB(0, 0, 0));
	TCHAR tszText[1024] = { 0 };
	::GetWindowText(m_hWnd, tszText, 1024);
	TextOut(hDC, 10, 10, tszText, lstrlen(tszText));
	// ペンとブラシの復元
	SelectObject(hDC, hOldBrush);		// 古いブラシを選択.
	SelectObject(hDC, hOldPen);		// 古いペンを選択.
	// 描画終了.
	EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

}