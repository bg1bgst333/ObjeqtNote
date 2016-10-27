// ヘッダのインクルード
#include "Menu.h"	// メニュークラス

// コンストラクタCMenu
CMenu::CMenu(HWND hWnd){
	// メンバの初期化
	m_hWnd = hWnd;	// m_hWndにhWndをセット.
}

// デストラクタ~CMenu
CMenu::~CMenu() {

}

// メニューロード関数LoadMenu
BOOL CMenu::LoadMenu(UINT nIDResource){

	// 変数の宣言
	HINSTANCE hInstance;	// インスタンスハンドルhInstance

	// アプリケーションインスタンスハンドルを取得.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWL_HINSTANCE);	// GetWindowLongでhInstance取得.

	// メニューアイテムnIDResourceをロード.
	m_hMenu = ::LoadMenu(hInstance, MAKEINTRESOURCE(nIDResource));	// LoadMenuでnIDResourceをロードし, メニューハンドルをm_hMenuに格納.
	if (m_hMenu == NULL) {	// NULLならロード失敗.

		// FALSEを返す.
		return FALSE;

	}

	// 成功ならTRUEを返す.
	return TRUE;

}

// メニューセット関数SetMenu
BOOL CMenu::SetMenu() {

	// メニューのセット.
	return ::SetMenu(m_hWnd, m_hMenu);	// SetMenuでm_hWndにm_hMenuをセットし, 戻り値をそのまま返す.

}