// ヘッダのインクルード
// 独自のヘッダ
#include "MainMenuBar.h"	// メインメニューバークラス
#include "MainWindow.h"		// メインウィンドウクラス
#include "BinaryFile.h"		// バイナリファイルクラス

// コンストラクタCMainMenuBar()
CMainMenuBar::CMainMenuBar() : CMenuBar(){

}

// コンストラクタCMainMenuBar(HWND hWnd)
CMainMenuBar::CMainMenuBar(HWND hWnd) : CMenuBar(hWnd){

}

// "開く"選択時の独自ハンドラOnFileOpen.
void CMainMenuBar::OnFileOpen() {

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.

		// 挿入.
		HINSTANCE hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWL_HINSTANCE);	// GetWindowLongでhInstanceを取得.
		pMainWindow->m_pWindowListControl->Insert(_T("0"), 0, 50, hInstance);	// pMainWindow->m_pWindowListControl->Insertで0番目にウィンドウを挿入.

	}

}

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMainMenuBar::OnFileSaveAs(){

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.

	}

}