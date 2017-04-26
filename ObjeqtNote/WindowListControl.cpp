// ヘッダのインクルード
// 独自のヘッダ
#include "WindowListControl.h"	// ウィンドウリストコントロールクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CWindowListControl::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウリストアイテムズパネルを登録.
	CWindowListItemsPanel::RegisterClass(hInstance);	// 子ウィンドウを登録.

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("WindowListControl"));	// CUserControl::RegisterClassでウィンドウクラス"WindowListControl"を登録.

}

// コンストラクタCWindowListControl()
CWindowListControl::CWindowListControl() : CUserControl() {

	// メンバの初期化
	m_pWindowListItemsPanel = NULL;	// m_pWindowListItemsPanelをNULLで初期化.

}

// デストラクタ~CWindowListControl()
CWindowListControl::~CWindowListControl() {

	// メンバの終了処理.
	Destroy();	// Destroyで破棄.

}

// ウィンドウ作成関数Create
BOOL CWindowListControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	return CUserControl::Create(_T("WindowListControl"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createでウィンドウクラス"WindowListControl"なウィンドウを作成.

}

// ウィンドウ破棄関数Destroy
void CWindowListControl::Destroy() {

	// 子ウィンドウの破棄.
	if (m_pWindowListItemsPanel != NULL) {
		m_pWindowListItemsPanel->Destroy();	// m_pWindowListItemsPanelのウィンドウを破棄.
		delete m_pWindowListItemsPanel;		// m_pWindowListItemsPanelを解放.
		m_pWindowListItemsPanel = NULL;		// m_pWindowListItemsPanelをNULLで埋める.
	}

	// ペンとブラシの破棄.
	DeleteObject(m_hBrush);	// ブラシの破棄.
	DeleteObject(m_hPen);	// ペンの破棄.

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// アイテム挿入関数Insert
BOOL CWindowListControl::Insert(int iIndex) {

	// アイテムズパネルのサイズを大きくする.
	m_pWindowListItemsPanel->MoveWindow(TRUE, 0, 50);	// m_pWindowListItemsPanel->MoveWindowで相対的に50増やす.

	// 成功なのでTRUEを返す.
	return TRUE;

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindowListControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ペンとブラシの作成.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0x7f, 0));		// 緑(濃)のペンを作成.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0xff, 0));		// 緑(淡)のブラシを作成.

	// ウィンドウリストアイテムズパネルクラスの作成.
	m_pWindowListItemsPanel = new CWindowListItemsPanel();	// CWindowListItemsPanelオブジェクトを作成し, ポインタをm_pWindowListItemsPanelに格納.
	m_pWindowListItemsPanel->Create(_T(""), 0, 30, 0, 300, 50, hwnd, (HMENU)IDC_WINDOWLISTITEMSPANEL1, lpCreateStruct->hInstance);	// m_pWindowListItemsPanel->Createでウィンドウリストアイテムズパネルを作成.(親ウィンドウより小さめ.)

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