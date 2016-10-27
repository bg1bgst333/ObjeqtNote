// ヘッダのインクルード
#include "MainWindow.h"	// メインウィンドウクラス
#include "MainMenu.h"	// メインメニュークラス

// ウィンドウ作成時のハンドラOnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// メインメニューの作成.
	m_pMainMenu = new CMainMenu(hwnd);	// CMainMenuオブジェクトを作成し, ポインタをm_pMainMenuに格納.

	// メインメニューのロード.
	m_pMainMenu->LoadMenu(IDR_MAINMENU);	// m_pMainMenu->LoadMenuでIDR_MAINMENUをロード.

	// メインメニューのセット
	m_pMainMenu->SetMenu();	// m_pMainMenu->SetMenuでメニューをセット.

	// ウィンドウ作成成功
	return 0;	// 成功なら0を返す.

}

// ウィンドウ破棄時のハンドラOnDestroy
void CMainWindow::OnDestroy() {

	// メインメニューの破棄.
	if (m_pMainMenu != NULL) {	// NULLでなければ.

		// m_pMainMenuの解放.
		delete m_pMainMenu;	// deleteでm_pMainMenuを解放.
		m_pMainMenu = NULL;	// m_pMainMenuをNULLにセット.

	}

	// メッセージループ終了.
	PostQuitMessage(0);	// PostQuitMessageでメッセージループを抜けさせる.

}

// コマンド処理時のハンドラOnCommand.
BOOL CMainWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	// メニューが選択された場合.
	if (HIWORD(wParam) == 0) {	// HIWORD(wParam)が0ならメニューが選択されたということ.

		// メニューオブジェクトがあるかチェック.
		if (m_pMainMenu != NULL) {	// ある.

			// m_pMainMenuのOnCommandMenuItemに任せる.
			return m_pMainMenu->OnCommandMenuItem(wParam, lParam);

		}
		else {	// それ以外.

		}

	}
	else {	// それ以外.

	}

	// FALSEを返す.
	return FALSE;

}