// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "MenuWindow.h"	// メニューウィンドウクラス

// ウィンドウクラス登録関数RegisterClass(メニュー指定)
BOOL CMenuWindow::RegisterClass(HINSTANCE hInstance, UINT nID){

	// ウィンドウクラスの登録
	return CWindow::RegisterClass(hInstance, _T("MenuWindow"), nID);	// CWindow::RegisterClass(メニュー指定)でウィンドウクラス"MenuWindow"を登録.

}

// コンストラクタCMenuWindow()
CMenuWindow::CMenuWindow() : CBasicWindow(){

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CMenuWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ここに来る場合はウィンドウクラス"MenuWindow"のウィンドウとして作成.
	return CWindow::Create(_T("MenuWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラスを"MenuWindow"にしてCreateのフルバージョンを呼ぶ.

}