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

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMainMenuBar::OnFileSaveAs() {

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.
		if (pMainWindow->m_pEditBox != NULL) {	// エディットボックスが生成済みの場合.

			// オブジェクトの宣言
			CTextFile *pTextFile;	// テキストファイルポインタCTextFile *型pTextFile.

			// エディットボックスのテキストを取得.
			pMainWindow->m_pEditBox->GetWindowText();	// pMainWindow->m_pEditBox->GetWindowTextでエディットボックスのテキストを取得.

			// テキストを"test1.txt"に保存.
			pTextFile = new CTextFile();	// CTextFileオブジェクトを作成し, ポインタをpTextFileに格納.

			// "test1.txt"を開く.
			if (pTextFile->Open(_T("test1.txt"), GENERIC_WRITE, OPEN_ALWAYS)) {	// pTextFile->Openでファイルを開けたら.

				// "test1.txt"にエディットボックスのテキストをSHIFT_JISに変換したものを書き込む.
				pTextFile->Write(pMainWindow->m_pEditBox->m_ptszText, CTextFile::EncodeType::SHIFT_JIS);	// pTextFile->WriteでpMainWindow->m_pEditBox->m_ptszTextをSHIFT_JISで書き込み.

				// 閉じる.
				pTextFile->Close();	// pTextFile->Closeで閉じる.

			}

			// オブジェクトの解放.
			delete pTextFile;	// deleteでpTextFileを解放.

		}

	}

}