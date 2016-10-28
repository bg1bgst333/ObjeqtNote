// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス
#include "Menu.h"	// メニュークラス
#include "WindowListView.h"	// ウィンドウリストビュークラス

// メインウィンドウクラス
class CMainWindow : public CWindow {	// CWindowの派生クラス

	// publicメンバ
	public:

		// publicメンバ変数
		CMenu *m_pMainMenu;	// CMainMenuオブジェクトポインタm_pMainMenu.
		CWindowListView *m_pWindowListView;	// CWindowListViewオブジェクトポインタm_pWindowListView.

		// publicメンバ関数
		// メンバ関数
		virtual void Destroy();	// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual int OnClose();	// ウィンドウを閉じる時のハンドラOnClose.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// コマンド処理時のハンドラOnCommand.
	
};