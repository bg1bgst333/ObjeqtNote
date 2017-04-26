// ヘッダのインクルード
// 独自のヘッダ
#include "WindowListItemsPanel.h"	// ウィンドウリストアイテムズパネルクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CWindowListItemsPanel::RegisterClass(HINSTANCE hInstance) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("WindowListItemsPanel"));	// CUserControl::RegisterClassでウィンドウクラス"WindowListItemsPanel"を登録.

}

// コンストラクタCWindowListItemsPanel()
CWindowListItemsPanel::CWindowListItemsPanel() : CUserControl() {

}

// デストラクタ~CWindowListItemsPanel()
CWindowListItemsPanel::~CWindowListItemsPanel() {

}

// ウィンドウ作成関数Create
BOOL CWindowListItemsPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	return CUserControl::Create(_T("WindowListItemsPanel"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createでウィンドウクラス"WindowListItemsPanel"なウィンドウを作成.

}

// ウィンドウ破棄関数Destroy
void CWindowListItemsPanel::Destroy() {

	// ペンとブラシの破棄.
	DeleteObject(m_hBrush);	// ブラシの破棄.
	DeleteObject(m_hPen);	// ペンの破棄.

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindowListItemsPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ペンとブラシの作成.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 0xff));		// 青(濃)のペンを作成.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0x9d, 0xcc, 0xe0));		// 青(淡)のブラシを作成.

	// 成功なので0を返す.
	return 0;

}

// ウィンドウの描画を要求された時のハンドラOnPaint.
void CWindowListItemsPanel::OnPaint() {

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
	// ペンとブラシの復元
	SelectObject(hDC, hOldBrush);		// 古いブラシを選択.
	SelectObject(hDC, hOldPen);		// 古いペンを選択.
	// 描画終了.
	EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

}