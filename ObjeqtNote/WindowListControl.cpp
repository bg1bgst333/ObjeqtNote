// ヘッダのインクルード
// 独自のヘッダ
#include "WindowListControl.h"	// ウィンドウリストコントロールクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CWindowListControl::RegisterClass(HINSTANCE hInstance) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("WindowListControl"));	// CUserControl::RegisterClassでウィンドウクラス"WindowListControl"を登録.

}

// コンストラクタCWindowListControl()
CWindowListControl::CWindowListControl() : CUserControl() {

}

// デストラクタ~CWindowListControl()
CWindowListControl::~CWindowListControl() {

}

// ウィンドウ作成関数Create
BOOL CWindowListControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	return CUserControl::Create(_T("WindowListControl"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createでウィンドウクラス"WindowListControl"なウィンドウを作成.

}

// ウィンドウ破棄関数Destroy
void CWindowListControl::Destroy() {

	// ペンとブラシの破棄.
	DeleteObject(m_hBrush);	// ブラシの破棄.
	DeleteObject(m_hPen);	// ペンの破棄.

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindowListControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ペンとブラシの作成.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0x7f, 0));		// 緑(濃)のペンを作成.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0xff, 0));		// 緑(淡)のブラシを作成.

	// 成功なので0を返す.
	return 0;

}

// ウィンドウの描画を要求された時のハンドラOnPaint.
void CWindowListControl::OnPaint() {

	// 変数の宣言
	HDC hDC;			// デバイスコンテキストハンドルHDC型hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT構造体変数ps.

	// 描画開始.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaintで描画開始.
	// ペンとブラシの選択.
	HPEN hOldPen = (HPEN)SelectObject(hDC, m_hPen);		// 緑のペンを選択.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, m_hBrush);	// 緑のブラシを選択.
	// 矩形を描画.
	Rectangle(hDC, 0, 0, m_iWidth, m_iHeight);
	// ペンとブラシの復元
	SelectObject(hDC, hOldBrush);		// 古いブラシを選択.
	SelectObject(hDC, hOldPen);		// 古いペンを選択.
	// 描画終了.
	EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

}