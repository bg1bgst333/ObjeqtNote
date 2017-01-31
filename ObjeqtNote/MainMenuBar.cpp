// ヘッダのインクルード
// 独自のヘッダ
#include "MainMenuBar.h"	// メインメニューバークラス

// コンストラクタCMainMenuBar()
CMainMenuBar::CMainMenuBar() : CMenuBar() {

}

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMainMenuBar::OnFileSaveAs() {

	// とりあえずメッセージボックスで"CMainMenuBar::OnFileSaveAs()"表示.
	MessageBox(NULL, _T("CMainMenuBar::OnFileSaveAs()"), _T("ObjeqtNote"), MB_OK);	// MessageBoxで"CMainMenuBar::OnFileSaveAs()"と表示.

}