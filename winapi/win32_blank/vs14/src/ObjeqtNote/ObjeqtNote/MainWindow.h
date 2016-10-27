// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス
#include "Menu.h"	// メニュークラス

// メインウィンドウクラス
class CMainWindow : public CWindow {	// CWindowの派生クラス

	// publicメンバ
	public:

		// publicメンバ変数
		CMenu *m_pMainMenu;	// CMainMenuオブジェクトポインタm_pMainMenu.

		// publicメンバ関数
		// メンバ関数
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// コマンド処理時のハンドラOnCommand.
	
};