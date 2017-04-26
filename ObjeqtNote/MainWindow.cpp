// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "MainWindow.h"		// メニューウィンドウクラス	
#include "MainMenuBar.h"	// メインメニューバークラス

// ウィンドウクラス登録関数RegisterClass(メニュー指定)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// ウィンドウクラスの登録
	return CWindow::RegisterClass(hInstance, _T("MainWindow"), nID);	// CWindow::RegisterClass(メニュー指定)でウィンドウクラス"MainWindow"を登録.

}

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() : CStandardWindow() {

	// メンバの初期化
	m_pUserControl = NULL;			// m_pUserControlをNULLで初期化.
	m_pEditBox = NULL;				// m_pEditBoxをNULLで初期化.
	m_pPictureBox = NULL;			// m_pPictureBoxをNULLで初期化.
	m_pWindowListControl = NULL;	// m_pWindowListControlをNULLで初期化.

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

	// メンバの終了処理.
	Destroy();	// Destroyで破棄.
	if (m_pPictureBox != NULL) {
		delete m_pPictureBox;		// deleteでm_pPictureBoxを解放.
		m_pPictureBox = NULL;		// m_pPictureBoxをNULLで埋める.
	}
	if (m_pEditBox != NULL) {
		delete m_pEditBox;			// deleteでm_pEditBoxを解放.
		m_pEditBox = NULL;			// m_pEditBoxをNULLで埋める.
	}
	if (m_pUserControl != NULL) {
		delete m_pUserControl;		// deleteでm_pUserControlを解放.
		m_pUserControl = NULL;		// m_pUserControlをNULLで埋める.
	}

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ここに来る場合はウィンドウクラス"MainWindow"のウィンドウとして作成.
	return CWindow::Create(_T("MainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラスを"MainWindow"にしてCreateのフルバージョンを呼ぶ.

}

// ウィンドウ破棄関数Destroy
void CMainWindow::Destroy() {

	// 子ウィンドウの破棄.
	if (m_pWindowListControl != NULL) {
		m_pWindowListControl->Destroy();	// m_pWindowListControlのウィンドウを破棄.
		delete m_pWindowListControl;		// m_pWindowListControlを解放.
		m_pWindowListControl = NULL;		// m_pWindowListControlをNULLで埋める.
	}

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// ウィンドウ作成時のハンドラOnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// メインメニューバーの作成.(ウィンドウクラス登録時にIDを指定した場合.)
	m_pMenuBar = new CMainMenuBar(hwnd);	// CMainMenuBarのコンストラクタにhwndを渡してオブジェクトを作成し, ポインタをm_pMenuBarに格納.

	// ウィンドウリストコントロールの作成.
	m_pWindowListControl = new CWindowListControl();	// // CWindowListControlオブジェクトを作成し, ポインタをm_pWindowListControlに格納.
	m_pWindowListControl->Create(_T(""), WS_HSCROLL | WS_VSCROLL, 50, 50, 400, 300, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Createでウィンドウリストコントロールを作成.(この時点では, まだWS_BORDERを付けている.)

	// ウィンドウリストアイテムの挿入.
	m_pWindowListControl->Insert(_T("0"), 0, 50, lpCreateStruct->hInstance);	// 0番目に高さ50のアイテムを挿入.
	m_pWindowListControl->Insert(_T("1"), 1, 50, lpCreateStruct->hInstance);	// 1番目に高さ50のアイテムを挿入.
	m_pWindowListControl->Insert(_T("2"), 0, 50, lpCreateStruct->hInstance);	// 0番目に高さ50のアイテムを挿入.
	m_pWindowListControl->Insert(_T("3"), 1, 50, lpCreateStruct->hInstance);	// 1番目に高さ50のアイテムを挿入.
	m_pWindowListControl->Insert(_T("4"), 0, 50, lpCreateStruct->hInstance);	// 0番目に高さ50のアイテムを挿入.

	// ウィンドウリストアイテムの削除.
	m_pWindowListControl->Remove(0);	// 0番目を削除.
	m_pWindowListControl->Remove(3);	// 3番目を削除.
	m_pWindowListControl->Remove(1);	// 1番目を削除.

	// 成功.
	return 0;	// 成功なので0を返す.

}

// ウィンドウサイズが変更された時のハンドラOnSize.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

}