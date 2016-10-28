// ヘッダのインクルード
#include "MainWindow.h"	// メインウィンドウクラス
#include "MainMenu.h"	// メインメニュークラス

// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
void CMainWindow::Destroy(){

	// 子ウィンドウの破棄.
	m_pWindowListView->Destroy();	// m_pWindowListView->Destroyで破棄.

	// ウィンドウリストビューの破棄.
	if (m_pWindowListView != NULL) {	// NULLでなければ.

		// m_pWindowListViewの破棄.
		delete m_pWindowListView;	// deleteでm_pWindowListViewを解放.
		m_pWindowListView = NULL;	// m_pWindowListViewをNULLにセット.

	}

}

// ウィンドウ作成時のハンドラOnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// メインメニューの作成.
	m_pMainMenu = new CMainMenu(hwnd);	// CMainMenuオブジェクトを作成し, ポインタをm_pMainMenuに格納.

	// メインメニューのロード.
	m_pMainMenu->LoadMenu(IDR_MAINMENU);	// m_pMainMenu->LoadMenuでIDR_MAINMENUをロード.

	// メインメニューのセット
	m_pMainMenu->SetMenu();	// m_pMainMenu->SetMenuでメニューをセット.

	// 子ウィンドウとなるウィンドウリストビューオブジェクトの作成.
	m_pWindowListView = new CWindowListView();	// CWindowListViewオブジェクトm_pWindowListViewの作成.
	
	// 子ウィンドウの作成.
	m_pWindowListView->Create(100, 100, 200, 200, hwnd, (HMENU)IDC_WINDOW_LISTVIEW, lpCreateStruct->hInstance);	// m_pWindowListView->Createでウィンドウリストビューを作成.

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

// ウィンドウを閉じる時のハンドラOnClose.
int CMainWindow::OnClose(){

		// 子ウィンドウの破棄.
		Destroy();	// Destroyで子ウィンドウの破棄.
		return 0;	// 0を返すと閉じる.

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