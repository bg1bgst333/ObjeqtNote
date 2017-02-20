// ヘッダのインクルード
// 独自のヘッダ
#include "MainMenuBar.h"	// メインメニューバークラス
#include "MainWindow.h"		// メインウィンドウクラス
#include "TextFile.h"		// テキストファイルクラス

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
		if (pMainWindow->m_pEditBox != NULL) {	// エディットボックスが生成済みの場合.

			// オブジェクトの宣言
			CTextFile *pTextFile;	// テキストファイルポインタCTextFile *型pTextFile.

			// CTextFileオブジェクトでテキストを保存.
			pTextFile = new CTextFile();	// CTextFileオブジェクトを作成し, ポインタをpTextFileに格納.

			// 開くファイルを選択.
			// フィルタ文字列の作成.
			TCHAR tszFilter[1024] = { 0 };	// 拡張子でフィルタリングするフィルタtszFilter.
			_tcscat_s(tszFilter, 1024, FILTER_TEXT_BIN_FILE);	// "バイナリファイル"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// 区切り文字
			_tcscat_s(tszFilter, 1024, FILTER_RULE_BIN_FILE);	// "*.bin"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// 区切り文字
			_tcscat_s(tszFilter, 1024, FILTER_TEXT_ALL_FILE);	// "すべてのファイル"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// 区切り文字
			_tcscat_s(tszFilter, 1024, FILTER_RULE_ALL_FILE);	// "*.*"
			_tcscat_s(tszFilter, 1024, FILTER_END);				// 終了文字
			// ファイル選択ダイアログの表示.
			if (pTextFile->GetOpenFileName(pTextFile->m_tszFileName, 1024, tszFilter, m_hWnd)) {	// 選択されたら.

				// pTextFile->m_tszFileNameを開く.
				if (pTextFile->Open(pTextFile->m_tszFileName, GENERIC_READ, OPEN_EXISTING)) {	// pTextFile->Openでファイルを開けたら.

					// pTextFile->m_tszFileNameから読み込んだテキストをUNICODEに変換.
					pMainWindow->m_pEditBox->m_iLen = pTextFile->Read(&pMainWindow->m_pEditBox->m_ptszText, CTextFile::SHIFT_JIS);	// pTextFile->Readで読み込んでpMainWindow->m_pEditBox->m_ptszTextにテキストを格納, 長さをpMainWindow->m_pEditBox->m_iLenに格納.

					// 閉じる.
					pTextFile->Close();	// pTextFile->Closeで閉じる.

				}

			}

			// オブジェクトの解放.
			delete pTextFile;	// deleteでpTextFileを解放.

			// エディットボックスのテキストを設定.
			pMainWindow->m_pEditBox->SetWindowText();	// pMainWindow->m_pEditBox->SetWindowTextでエディットボックスのテキストを設定.

		}
	}

}

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMainMenuBar::OnFileSaveAs(){

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.
		if (pMainWindow->m_pEditBox != NULL) {	// エディットボックスが生成済みの場合.
			
			// オブジェクトの宣言
			CTextFile *pTextFile;	// テキストファイルポインタCTextFile *型pTextFile.

			// エディットボックスのテキストを取得.
			pMainWindow->m_pEditBox->GetWindowText();	// pMainWindow->m_pEditBox->GetWindowTextでエディットボックスのテキストを取得.

			// CTextFileオブジェクトでテキストを保存.
			pTextFile = new CTextFile();	// CTextFileオブジェクトを作成し, ポインタをpTextFileに格納.

			// 保存先のファイルを選択.
			// フィルタ文字列の作成.
			TCHAR tszFilter[1024] = { 0 };	// 拡張子でフィルタリングするフィルタtszFilter.
			_tcscat_s(tszFilter, 1024, FILTER_TEXT_BIN_FILE);	// "バイナリファイル"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// 区切り文字
			_tcscat_s(tszFilter, 1024, FILTER_RULE_BIN_FILE);	// "*.bin"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// 区切り文字
			_tcscat_s(tszFilter, 1024, FILTER_TEXT_ALL_FILE);	// "すべてのファイル"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// 区切り文字
			_tcscat_s(tszFilter, 1024, FILTER_RULE_ALL_FILE);	// "*.*"
			_tcscat_s(tszFilter, 1024, FILTER_END);				// 終了文字
			// ファイル選択ダイアログの表示.
			if (pTextFile->GetSaveFileName(pTextFile->m_tszFileName, 1024, tszFilter, m_hWnd)) {	// 選択されたら.

				// pTextFile->m_tszFileNameを開く.
				if (pTextFile->Open(pTextFile->m_tszFileName, GENERIC_WRITE, OPEN_ALWAYS)) {	// pTextFile->Openでファイルを開けたら.

					// pTextFile->m_tszFileNameにエディットボックスのテキストをSHIFT_JISに変換したものを書き込む.
					pTextFile->Write(pMainWindow->m_pEditBox->m_ptszText, CTextFile::EncodeType::SHIFT_JIS);	// pTextFile->WriteでpMainWindow->m_pEditBox->m_ptszTextをSHIFT_JISで書き込み.

					// 閉じる.
					pTextFile->Close();	// pTextFile->Closeで閉じる.

				}

			}

			// オブジェクトの解放.
			delete pTextFile;	// deleteでpTextFileを解放.

		}

	}

}