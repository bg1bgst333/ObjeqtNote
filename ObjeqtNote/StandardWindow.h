// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "MenuWindow.h"	// メニューウィンドウクラス
#include "UserControl.h"			// ユーザコントロールクラス

// スタンダードウィンドウクラスCStandardWindow
class CStandardWindow : public CMenuWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		CUserControl *m_pUserControl;	// CUserControl *型ユーザコントロールオブジェクトポインタm_pUserControl

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// ウィンドウクラス登録関数RegisterClass(メニュー指定)

		// コンストラクタ・デストラクタ
		CStandardWindow();	// コンストラクタCStandardWindow()
		virtual ~CStandardWindow();	// デストラクタ~CStandardWindow()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.

};