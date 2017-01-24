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

	// メンバの初期化.
	m_pMenuBar = NULL;	// m_pMenuBarをNULLで初期化.

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

	// ウィンドウ作成成功
	return 0;	// 成功なので0を返す.

}