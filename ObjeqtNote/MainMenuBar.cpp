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

// "新規"選択時の独自ハンドラOnFileNew.
void CMainMenuBar::OnFileNew() {

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.

		// 1番目のアイテムを取得.
		CWindowListItem * pItem = pMainWindow->m_pWindowListControl->Get(1);	// pMainWindow->m_pWindowListControl->Getで1番目を取得.
		if (pItem != NULL) {
			// エディットボックスをアイテムの子ウィンドウにする.
			HINSTANCE hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWL_HINSTANCE);	// GetWindowLongでhInstanceを取得.
			CEditBox *pEditBox = new CEditBox();	// エディットボックス作成.
			pEditBox->Create(_T(""), WS_BORDER, 30, 10, 100, 30, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, hInstance);	// Createで生成.
			pItem->m_mapChildMap.insert(std::make_pair(_T("EditBox"), pEditBox));	// pItem->m_mapChildMap.insertでマップ登録.
		}

	}

}

// "開く"選択時の独自ハンドラOnFileOpen.
void CMainMenuBar::OnFileOpen() {

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.

		// 挿入.
		HINSTANCE hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWL_HINSTANCE);	// GetWindowLongでhInstanceを取得.
		pMainWindow->m_pWindowListControl->Insert(_T("0"), 0, 50, hInstance);	// pMainWindow->m_pWindowListControl->Insertで0番目にウィンドウを挿入.

	}

}

// "名前を付けて保存"選択時の独自ハンドラOnFileSaveAs.
void CMainMenuBar::OnFileSaveAs() {

	// メインウィンドウオブジェクトの取得
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]でpMainWindowを取得.(途中dynamic_castしている.)
	if (pMainWindow != NULL) {	// キャスト成功.

		// 削除.
		pMainWindow->m_pWindowListControl->Remove(0);	// pMainWindow->m_pWindowListControl->Removeで0番目を削除.

	}

}