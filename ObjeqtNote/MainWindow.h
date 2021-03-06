// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "StandardWindow.h"		// スタンダードウィンドウクラス
#include "EditBox.h"			// エディットボックスクラス
#include "PictureBox.h"			// ピクチャーボックスクラス
#include "UserControl.h"		// ユーザコントロールクラス
#include "WindowListControl.h"	// ウィンドウリストコントロールクラス
#include "resource.h"			// リソース

// メインウィンドウクラスCMainWindow
class CMainWindow : public CStandardWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		CUserControl *m_pUserControl;				// CUserControl *型ユーザコントロールオブジェクトポインタm_pUserControl
		CEditBox *m_pEditBox;						// CEditBox *型エディットボックスオブジェクトポインタm_pEditBox
		CPictureBox *m_pPictureBox;					// CPictureBox *型ピクチャーボックスオブジェクトポインタm_pPictureBox
		CWindowListControl *m_pWindowListControl;	// CWindowListControl *型ウィンドウリストコントロールオブジェクトポインタm_pWindowListControl

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// ウィンドウクラス登録関数RegisterClass(メニュー指定)

		// コンストラクタ・デストラクタ
		CMainWindow();			// コンストラクタCMainWindow()
		virtual ~CMainWindow();	// デストラクタ~CMainWindow()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)
		virtual void Destroy();	// ウィンドウ破棄関数Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウサイズが変更された時のハンドラOnSize.

};