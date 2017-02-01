// ヘッダのインクルード
// 独自のヘッダ
#include "MainMenuBar.h"	// メインメニューバークラス

// コンストラクタCMainMenuBar()
CMainMenuBar::CMainMenuBar() : CMenuBar() {

}

// コンストラクタCMainMenuBar(HWND hWnd)
CMainMenuBar::CMainMenuBar(HWND hWnd) : CMenuBar(hWnd) {

}

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMainMenuBar::OnFileSaveAs() {

	// 変数の宣言
	HWND hEdit;			// エディットボックスのウィンドウハンドルHWND型hEdit.
	int iLen;			// エディットボックスのテキストの長さint型iLen.
	TCHAR *ptszText;	// テキストのポインタTCHAR *型ptszText.

	// エディットボックスのテキストを取得して, メッセージボックスで表示.
	hEdit = GetDlgItem(m_hWnd, IDC_EDITBOX1);	// GetDlgItemでIDC_EDITBOX1の指すエディットボックスのウィンドウハンドルhEditを取得.
	iLen = GetWindowTextLength(hEdit);	// GetWindowTextLengthでhEditのテキストの長さiLenを取得.
	ptszText = new TCHAR[iLen + 1];	// TCHAR型動的配列をnewで作成し, ポインタをptszTextに格納.(長さiLen + 1)
	GetWindowText(hEdit, ptszText, iLen + 1);	// GetWindowTextでテキストを取得し, ptszTextに格納.
	MessageBox(NULL, ptszText, _T("ObjeqtNote"), MB_OK);	// MessageBoxでptszTextを表示.
	delete[] ptszText;	// deleteでptszTextを解放.

}