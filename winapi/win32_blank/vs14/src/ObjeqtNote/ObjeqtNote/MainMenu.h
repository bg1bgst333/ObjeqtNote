// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Menu.h"	// メニュークラス
#include "resource.h"		// リソースID

// メインメニュークラスCMainMenu
class CMainMenu : public CMenu {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMainMenu(HWND hWnd);	// コンストラクタCMainMenu
		virtual BOOL OnCommandMenuItem(WPARAM wParam, LPARAM lParam);	// メニュー選択時の独自ハンドラOnCommandMenuItem.

		// メンバ関数
		void OnFileNew();		// "新規"選択時の独自ハンドラOnFileNew.
		void OnFileOpen();		// "開く"選択時の独自ハンドラOnFileOpen.
		void OnFileSave();		// "上書き保存"選択時の独自ハンドラOnFileSave.
		void OnFileSaveAs();	// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
		void OnAppExit();		// "アプリケーションの終了"選択時の独自ハンドラOnAppExit.

};