// ヘッダのインクルード
// 独自のヘッダ
#include "MainMenuBar.h"	// メインメニューバークラス
#include "MainWindow.h"	// メインウィンドウクラス

// コンストラクタCMainMenuBar()
CMainMenuBar::CMainMenuBar() : CMenuBar() {

}

// コンストラクタCMainMenuBar(HWND hWnd)
CMainMenuBar::CMainMenuBar(HWND hWnd) : CMenuBar(hWnd) {

}

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMainMenuBar::OnFileSaveAs() {

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.
		if (pMainWindow->m_pEditBox != NULL) {	// エディットボックスが生成済みの場合.
			pMainWindow->m_pEditBox->GetWindowText();	// pMainWindow->m_pEditBox->GetWindowTextでエディットボックスのテキストを取得.
			MessageBox(NULL, pMainWindow->m_pEditBox->m_ptszText, _T("ObjeqtNote"), MB_OK);	// MessageBoxでpMainWindow->m_pEditBox->m_ptszTextを表示.
		}
	}

}