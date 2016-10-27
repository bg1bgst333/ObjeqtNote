// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// メニュークラスCMenu
class CMenu {

	// publicメンバ
	public:

		// publicメンバ変数
		HMENU m_hMenu;	// メニューハンドルm_hMenu
		HWND m_hWnd;	// ウィンドウハンドルm_hWnd
						
		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMenu(HWND hWnd);	// コンストラクタCMenu
		virtual ~CMenu();	// デストラクタ~CMenu

		// メンバ関数
		virtual BOOL LoadMenu(UINT nIDResource);	// メニューロード関数LoadMenu
		virtual BOOL SetMenu();			// メニューセット関数SetMenu
		virtual BOOL OnCommandMenuItem(WPARAM wParam, LPARAM lParam) = 0;	// メニュー選択時の独自ハンドラOnCommandMenuItem.(純粋仮想関数)

};
