// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "MenuWindow.h"	// メニューウィンドウクラス

// ウィンドウクラス登録関数RegisterClass(メニュー指定)
BOOL CMenuWindow::RegisterClass(HINSTANCE hInstance, UINT nID){

	// ウィンドウクラスの登録
	//return CWindow::RegisterClass(hInstance, _T("MenuWindow"), nID);	// CWindow::RegisterClass(メニュー指定)でウィンドウクラス"MenuWindow"を登録.
	return CWindow::RegisterClass(hInstance, _T("MenuWindow"));	// CWindow::RegisterClassでウィンドウクラス"MenuWindow"を登録.

}

// コンストラクタCMenuWindow()
CMenuWindow::CMenuWindow() : CBasicWindow(){

	// メンバの初期化.
	m_pMenuBar = NULL;	// m_pMenuBarをNULLで初期化.

}

// デストラクタ~CMenuWindow()
CMenuWindow::~CMenuWindow(){

	// メンバの終了処理.
	if (m_pMenuBar != NULL) {	// m_pMenuBarがNULLでなければ.
		delete m_pMenuBar;	// deleteでm_pMenuBarを解放.
		m_pMenuBar = NULL;	// m_pMenuBarをNULLで埋める.
	}

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CMenuWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ここに来る場合はウィンドウクラス"MenuWindow"のウィンドウとして作成.
	return CWindow::Create(_T("MenuWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラスを"MenuWindow"にしてCreateのフルバージョンを呼ぶ.

}

// ウィンドウ作成時のハンドラOnCreate.
int CMenuWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// メニューバーの作成.(動的に作成する場合.)
	m_pMenuBar = new CMenuBar();	// CMenuBarオブジェクトを作成し, ポインタをm_pMenuBarに格納.

	// メニューのロード.
	m_pMenuBar->LoadMenu(lpCreateStruct->hInstance, IDR_MAINMENU);	// LoadMenuでID_MAINMENUをロード.

	// メニューのセット.
	m_pMenuBar->SetMenu(hwnd);	// SetMenuでhwndにメニューをセット.

	// ウィンドウ作成成功
	return 0;	// 成功なので0を返す.

}

// コマンド処理時のハンドラOnCommand.
BOOL CMenuWindow::OnCommand(WPARAM wParam, LPARAM lParam){

	// メニューコマンドだった場合.
	if (HIWORD(wParam) == 0) {	// HIWORD(wParam)が0ならメニューが選択されたということ.

		// メニューオブジェクトがあるかチェック.
		if (m_pMenuBar != NULL) {	// m_pMenuBarがNULLでない場合.

			// OnCommandMenuItemにコマンド処理を任せる.
			return m_pMenuBar->OnCommandMenuItem(wParam, lParam);	// OnCommandMenuItemにwParam, lParamを渡してあとは任せ, 戻り値をそのまま返す.

		}

	}

	// FALSEを返す.
	return TRUE;

}
