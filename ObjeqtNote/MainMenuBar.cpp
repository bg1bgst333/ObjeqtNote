// ヘッダのインクルード
// 独自のヘッダ
#include "MainMenuBar.h"	// メインメニューバークラス
#include "MainWindow.h"		// メインウィンドウクラス
#include "BinaryFile.h"		// バイナリファイルクラス

// コンストラクタCMainMenuBar()
CMainMenuBar::CMainMenuBar() : CMenuBar(){

}

// コンストラクタCMainMenuBar(HWND hWnd)
CMainMenuBar::CMainMenuBar(HWND hWnd) : CMenuBar(hWnd){

}

// "開く"選択時の独自ハンドラOnFileOpen.
void CMainMenuBar::OnFileOpen(){

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.

		// ファイル選択ダイアログの表示.
		// フィルタ文字列の作成.
		TCHAR tszFilter[1024] = { 0 };	// 拡張子でフィルタリングするフィルタtszFilter.
		_tcscat_s(tszFilter, 1024, FILTER_TEXT_ALL_FILE);	// "すべてのファイル"
		_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// 区切り文字
		_tcscat_s(tszFilter, 1024, FILTER_RULE_ALL_FILE);	// "*.*"
		_tcscat_s(tszFilter, 1024, FILTER_END);				// 終了文字
		TCHAR tszFileName[1024] = { 0 };	// tszFileNameを0で埋める.
		TCHAR tszExtension[16] = { 0 };		// tszExtensionを0で埋める.
		CBinaryFile::GetOpenFileName(tszFileName, 1024, tszFilter, m_hWnd, tszExtension);	// スタティックなCBinaryFile::GetOpenFileNameで選択したファイル名を取得.
		if (!_tcsicmp(tszExtension, _T(".txt"))) {	// ".txt"なら.
			MessageBox(NULL, _T("テキストファイル"), _T("ObjeqtNote"), MB_OK);	// "テキストファイル"と表示.
		}
		else if (!_tcsicmp(tszExtension, _T(".bmp"))) {	// ".bmp"なら.
			MessageBox(NULL, _T("ビットマップファイル"), _T("ObjeqtNote"), MB_OK);	// "ビットマップファイル"と表示.
		}

	}

}

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMainMenuBar::OnFileSaveAs(){

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.

	}

}