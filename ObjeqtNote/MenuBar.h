// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
// 独自のヘッダ
#include "resource.h"	// リソース

// メニューバークラスCMenuBar
class CMenuBar {

	// publicメンバ
	public:

		// publicメンバ変数
		HMENU m_hMenu;	// メニューハンドルm_hMenu
		HWND m_hWnd;	// ウィンドウハンドルm_hWnd

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMenuBar();	// コンストラクタCMenuBar()
		CMenuBar(HWND hWnd);	// コンストラクタCMenuBar(HWND hWnd)
		virtual ~CMenuBar();	// デストラクタ~CMenuBar()

		// メンバ関数
		virtual BOOL LoadMenu(HINSTANCE hInstance, UINT nID);	// メニューロード関数LoadMenu.
		virtual BOOL SetMenu(HWND hwnd);	// メニューセット関数SetMenu.
		virtual BOOL OnCommandMenuItem(WPARAM wParam, LPARAM lParam);	// メニュー選択時のハンドラOnCommandMenuItem.
		virtual void OnFileNew();		// "新規"選択時の独自ハンドラOnFileNew.
		virtual void OnFileOpen();		// "開く"選択時の独自ハンドラOnFileOpen.
		virtual void OnFileSave();		// "上書き保存"選択時の独自ハンドラOnFileSave.
		virtual void OnFileSaveAs();	// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
		virtual void OnAppExit();		// "アプリケーションの終了"選択時の独自ハンドラOnAppExit.

};