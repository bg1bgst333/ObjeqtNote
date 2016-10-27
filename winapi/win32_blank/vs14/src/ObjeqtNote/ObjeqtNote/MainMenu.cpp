// ヘッダのインクルード
#include "MainMenu.h"	// メインメニュークラス

// コンストラクタCMainMenu
CMainMenu::CMainMenu(HWND hWnd) : CMenu(hWnd) {	// 実際は先にCMenuを呼び, hWndを渡す.

}

// メニュー選択時の独自ハンドラOnCommandMenuItem.
BOOL CMainMenu::OnCommandMenuItem(WPARAM wParam, LPARAM lParam) {

	// メニュー処理
	switch (LOWORD(wParam)) {	// LOWORD(wParam)でどのメニューアイテムが選択されたか, IDが返ってくる.

		// "新規"(IDM_FILE_NEW)
		case IDM_FILE_NEW:

			// IDM_FILE_NEWブロック
			{

				// OnFileNewに任せる.
				OnFileNew();

			}

			// 既定の処理
			break;	// breakで抜ける.

		// "開く"(IDM_FILE_OPEN)
		case IDM_FILE_OPEN:

			// IDM_FILE_OPENブロック
			{

				// OnFileOpenに任せる.
				OnFileOpen();

			}

			// 既定の処理
			break;	// breakで抜ける.

		// "保存"(IDM_FILE_SAVE)
		case IDM_FILE_SAVE:

			// IDM_FILE_SAVEブロック
			{

				// OnFileSaveに任せる.
				OnFileSave();

			}

			// 既定の処理
			break;	// breakで抜ける.

		// "名前を付けて保存"(IDM_FILE_SAVEAS)
		case IDM_FILE_SAVEAS:

			// IDM_FILE_SAVEASブロック
			{

				// OnFileSaveAsに任せる.
				OnFileSaveAs();

			}

			// 既定の処理
			break;	// breakで抜ける.

		// "アプリケーションの終了"(IDM_APP_EXIT)
		case IDM_APP_EXIT:

			// IDM_APP_EXITブロック
			{

				// OnAppExitに任せる.
				OnAppExit();

			}

			// 既定の処理
			break;	// breakで抜ける.

		// それ以外
		default:

			// fALSEを返す.
			return FALSE;

	}

	// どれかのハンドラが処理された後はTRUEを返す.
	return TRUE;

}

// "新規"選択時の独自ハンドラOnFileNew.
void CMainMenu::OnFileNew() {

	// "OnFileNew"と表示.
	MessageBox(NULL, _T("OnFileNew"), _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"OnFileNew"と表示.

}

// "開く"選択時の独自ハンドラOnFileOpen.
void CMainMenu::OnFileOpen() {

	// "OnFileOpen"と表示.
	MessageBox(NULL, _T("OnFileOpen"), _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"OnFileOpen"と表示.

}

// "保存"選択時の独自ハンドラOnFileSave.
void CMainMenu::OnFileSave() {

	// "OnFileSave"と表示.
	MessageBox(NULL, _T("OnFileSave"), _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"OnFileSave"と表示.

}

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMainMenu::OnFileSaveAs() {

	// "OnFileSaveAs"と表示.
	MessageBox(NULL, _T("OnFileSaveAs"), _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"OnFileSaveAs"と表示.

}

// "アプリケーションの終了"選択時の独自ハンドラOnAppExit.
void CMainMenu::OnAppExit() {

	// "OnAppExit"と表示.
	MessageBox(NULL, _T("OnAppExit"), _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);	// MessageBoxで"OnAppExit"と表示.

}