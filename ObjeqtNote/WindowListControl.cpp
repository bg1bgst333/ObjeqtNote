// ヘッダのインクルード
// 独自のヘッダ
#include "WindowListControl.h"	// ウィンドウリストコントロールクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CWindowListControl::RegisterClass(HINSTANCE hInstance) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("WindowListControl"));	// CUserControl::RegisterClassでウィンドウクラス"WindowListControl"を登録.

}

// コンストラクタCWindowListControl()
CWindowListControl::CWindowListControl() : CUserControl() {

}

// デストラクタ~CWindowListControl()
CWindowListControl::~CWindowListControl() {

}

// ウィンドウ作成関数Create
BOOL CWindowListControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	return CUserControl::Create(_T("WindowListControl"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createでウィンドウクラス"WindowListControl"なウィンドウを作成.

}