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
	m_pUserControl = NULL;		// m_pUserControlをNULLで初期化.
	m_pEditBox = NULL;			// m_pEditBoxをNULLで初期化.
	m_pPictureBox = NULL;		// m_pPictureBoxをNULLで初期化.

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

	// メンバの終了処理.
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

// ウィンドウ作成時のハンドラOnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// メインメニューバーの作成.(ウィンドウクラス登録時にIDを指定した場合.)
	m_pMenuBar = new CMainMenuBar(hwnd);	// CMainMenuBarのコンストラクタにhwndを渡してオブジェクトを作成し, ポインタをm_pMenuBarに格納.

	// ピクチャーボックスの作成.
	m_pPictureBox = new CPictureBox();	// CPictureBoxオブジェクトを作成し, ポインタをm_pPictureBoxに格納.
	m_pPictureBox->Create(_T(""), SS_BITMAP | WS_HSCROLL | WS_VSCROLL, 50, 50, 320, 240, hwnd, (HMENU)IDC_PICTUREBOX1, lpCreateStruct->hInstance);	// m_pPictureBox->Createでピクチャーボックスを作成.

	// 成功.
	return 0;	// 成功なので0を返す.

}

// ウィンドウサイズが変更された時のハンドラOnSize.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

}