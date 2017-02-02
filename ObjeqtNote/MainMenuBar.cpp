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

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMainMenuBar::OnFileSaveAs(){

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.
		if (pMainWindow->m_pEditBox != NULL) {	// エディットボックスが生成済みの場合.
			
			// オブジェクトの宣言
			CBinaryFile *pBinaryFile;	// バイナリファイルポインタCBinaryFile *型pBinaryFile.
			int iMultiByteLen;	// マルチバイトに変換したときの長さiMultiByteLen.
			char *pBuf;	// char *型pBuf.

			// エディットボックスのテキストを取得.
			pMainWindow->m_pEditBox->GetWindowText();	// pMainWindow->m_pEditBox->GetWindowTextでエディットボックスのテキストを取得.
			
			// 文字コード変換(ワイド文字からマルチバイト文字へ変換したときに必要なバッファサイズを求める.)
			iMultiByteLen = WideCharToMultiByte(CP_ACP, 0, pMainWindow->m_pEditBox->m_ptszText, -1, NULL, 0, NULL, NULL);	// WideCharToMultiByteで変換後のバッファサイズを求める.

			// バッファを確保.
			pBuf = new char[iMultiByteLen];	// char型配列を生成し, ポインタをpBufに格納.

			// 文字コード変換(ワイド文字からマルチバイト文字へ.)
			WideCharToMultiByte(CP_ACP, 0, pMainWindow->m_pEditBox->m_ptszText, -1, pBuf, iMultiByteLen, NULL, NULL);	// WideCharToMultiByteで変換する.

			// テキストを"test1.txt"に保存.
			pBinaryFile = new CBinaryFile();	// CBinaryFileオブジェクトを作成し, ポインタをpBinaryFileに格納.
			
			// "test1.txt"を開く.
			if (pBinaryFile->Open(_T("test1.txt"), GENERIC_WRITE, OPEN_ALWAYS)) {	// pBinaryFile->Openでファイルを開けたら.

				// "test1.txt"にpBuf(pMainWindow->m_pEditBox->m_ptszTextの内容を変換したもの.)を書き込む.
				pBinaryFile->Write((BYTE *)pBuf, iMultiByteLen - 1);	// pBinaryFile->Writeで書き込み.

				// 閉じる.
				pBinaryFile->Close();	// pBinaryFile->Closeで閉じる.

			}
			
			// バッファを解放.
			delete[] pBuf;	//deleteでpBufを解放.

			// バイナリファイルオブジェクトも解放.
			delete[] pBinaryFile;	// deleteでpBinaryFileを解放.

		}

	}

}