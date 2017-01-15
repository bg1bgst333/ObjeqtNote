// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "BasicWindow.h"	// ベーシックウィンドウクラス

// メニューウィンドウクラスCMenuWindow
class CMenuWindow : public CBasicWindow {

	// publicメンバ
	public:

		// publicメンバ関数	
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// ウィンドウクラス登録関数RegisterClass(メニュー指定)

		// コンストラクタ・デストラクタ
		CMenuWindow();	// コンストラクタCMenuWindow()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)

};