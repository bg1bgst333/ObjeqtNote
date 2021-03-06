// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "MenuBar.h"	// メニューバークラス

// メインメニューバークラスCMainMenuBar
class CMainMenuBar : public CMenuBar {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMainMenuBar();	// コンストラクタCMainMenuBar()
		CMainMenuBar(HWND hWnd);	// コンストラクタCMainMenuBar(HWND hWnd)

		// メンバ関数
		virtual void OnFileNew();		// "新規"選択時の独自ハンドラOnFileNew.
		virtual void OnFileOpen();		// "開く"選択時の独自ハンドラOnFileOpen.
		virtual void OnFileSaveAs();	// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.

};