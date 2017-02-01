// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "MenuBar.h"	// メニューバークラス

// コンストラクタCMenuBar()
CMenuBar::CMenuBar(){

	// メンバの初期化.
	m_hMenu = NULL;	// m_hMenuをNULLで初期化.

}

// コンストラクタCMenuBar(HWND hWnd)
CMenuBar::CMenuBar(HWND hWnd) {

	// メンバの初期化.
	m_hMenu = NULL;	// m_hMenuをNULLで初期化.
	m_hWnd = hWnd;	// m_hWndをhWndで初期化.

}

// デストラクタ~CMenuBar()
CMenuBar::~CMenuBar(){

	// メンバの終了処理.
	// とりあえずなしでいい.

}

// メニューロード関数LoadMenu.
BOOL CMenuBar::LoadMenu(HINSTANCE hInstance, UINT nID){

	// メニューnIDをロード.
	m_hMenu = ::LoadMenu(hInstance, MAKEINTRESOURCE(nID));	// LoadMenuでnIDをロード.
	if (m_hMenu == NULL) {	// m_hMenuがNULLなら.

		// 失敗なのでFALSEを返す.
		return FALSE;	// FALSEを返す.

	}

	// 成功なのでTRUEを返す.
	return 0;	// TRUEを返す.

}

// メニューセット関数SetMenu.
BOOL CMenuBar::SetMenu(HWND hwnd){

	// メンバに引数をセット.
	m_hWnd = hwnd;	// m_hWndにhwndをセット.

	// メニューのセット.
	return ::SetMenu(m_hWnd, m_hMenu);	// SetMenuでm_hMenuをセットし, 戻り値をそのまま返す.

}

// メニュー選択時のハンドラOnCommandMenuItem.
BOOL CMenuBar::OnCommandMenuItem(WPARAM wParam, LPARAM lParam){

	// メニュー処理
	switch (LOWORD(wParam)) {	// LOWORD(wParam)でどのメニューアイテムが選択されたか, IDが返ってくる.

		// ID_FILE_NEWの時.
		case ID_FILE_NEW:

			// ID_FILE_NEWブロック
			{

				// OnFileNewに任せる.
				OnFileNew();

			}

			// 既定の処理
			break;	// breakで抜ける.

		// ID_FILE_OPENの時.
		case ID_FILE_OPEN:

			// ID_FILE_OPENブロック
			{

				// OnFileOpenに任せる.
				OnFileOpen();

			}

			// 既定の処理
			break;	// breakで抜ける.

		// ID_FILE_SAVEの時.
		case ID_FILE_SAVE:

			// ID_FILE_SAVEブロック
			{

				// OnFileSaveに任せる.
				OnFileSave();

			}

			// 既定の処理
			break;	// breakで抜ける.

		// ID_FILE_SAVEASの時.
		case ID_FILE_SAVEAS:

			// ID_FILE_SAVEASブロック
			{

				// OnFileSaveAsに任せる.
				OnFileSaveAs();

			}

			// 既定の処理
			break;	// breakで抜ける.

		// ID_APP_EXITの時.
		case ID_APP_EXIT:

			// ID_APP_EXITブロック
			{

				// OnAppExitに任せる.
				OnAppExit();

			}

			// 既定の処理
			break;	// breakで抜ける.

		// それ以外の時.
		default:

			// FALSEを返す.
			return FALSE;

	}

	// どれかのハンドラが処理された後はTRUEを返す.
	return TRUE;

}

// "新規"選択時の独自ハンドラOnFileNew.
void CMenuBar::OnFileNew(){

	// "新規"と表示.
	MessageBox(NULL, _T("新規"), _T("ObjeqtNote"), MB_OK);	// MessageBoxで"新規"と表示.

}

// "開く"選択時の独自ハンドラOnFileOpen.
void CMenuBar::OnFileOpen(){

	// "開く"と表示.
	MessageBox(NULL, _T("開く"), _T("ObjeqtNote"), MB_OK);	// MessageBoxで"開く"と表示.

}

// "上書き保存"選択時の独自ハンドラOnFileSave.
void CMenuBar::OnFileSave(){

	// "上書き保存"と表示.
	MessageBox(NULL, _T("上書き保存"), _T("ObjeqtNote"), MB_OK);	// MessageBoxで"上書き保存"と表示.

}

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMenuBar::OnFileSaveAs(){

	// "名前を付けて保存"と表示.
	MessageBox(NULL, _T("名前を付けて保存"), _T("ObjeqtNote"), MB_OK);	// MessageBoxで"名前を付けて保存"と表示.

}

// "アプリケーションの終了"選択時の独自ハンドラOnAppExit.
void CMenuBar::OnAppExit(){

	// "アプリケーションの終了"と表示.
	MessageBox(NULL, _T("アプリケーションの終了"), _T("ObjeqtNote"), MB_OK);	// MessageBoxで"アプリケーションの終了"と表示.

}
