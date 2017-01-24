// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "StandardWindow.h"	// スタンダードウィンドウクラス

// ウィンドウクラス登録関数RegisterClass(メニュー指定)
BOOL CStandardWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// ウィンドウクラスの登録
	return CWindow::RegisterClass(hInstance, _T("StandardWindow"), nID);	// CWindow::RegisterClass(メニュー指定)でウィンドウクラス"StandardWindow"を登録.

}

// コンストラクタCStandardWindow()
CStandardWindow::CStandardWindow() : CMenuWindow() {

	// メンバの初期化
	m_pMenuBar = NULL;	// m_pMenuBarをNULLで初期化.
	m_pUserControl = NULL;	// m_pUserControlをNULLで初期化.

}

// デストラクタ~CStandardWindow()
CStandardWindow::~CStandardWindow(){

	// メンバの終了処理.
	if (m_pUserControl != NULL) {
		delete m_pUserControl;	// deleteでm_pUserControlを解放.
		m_pUserControl = NULL;	// m_pUserControlをNULLで埋める.
	}
	if (m_pMenuBar != NULL) {	// m_pMenuBarがNULLでなければ.
		delete m_pMenuBar;	// deleteでm_pMenuBarを解放.
		m_pMenuBar = NULL;	// m_pMenuBarをNULLで埋める.
	}


}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CStandardWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ここに来る場合はウィンドウクラス"StandardWindow"のウィンドウとして作成.
	return CWindow::Create(_T("StandardWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラスを"StandardWindow"にしてCreateのフルバージョンを呼ぶ.

}

// ウィンドウ作成時のハンドラOnCreate.
int CStandardWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// メニューバーの作成.(ウィンドウクラス登録時にIDを指定した場合.)
	m_pMenuBar = new CMenuBar();	// CMenuBarオブジェクトを作成し, ポインタをm_pMenuBarに格納.

	// ユーザコントロールの作成.
	m_pUserControl = new CUserControl();	// CUserControlオブジェクトを作成し, ポインタをm_pUserControlに格納.
	m_pUserControl->Create(_T("UserControl"), _T(""), WS_BORDER, 100, 100, 200, 200, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// m_pUserControl->Createでウィンドウクラス名"UserControl"なウィンドウを作成.

	// ウィンドウ作成成功
	return 0;	// 成功なので0を返す.

}