// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "UserControl.h"	// ユーザコントロールクラス
#include "WindowListItemsPanel.h"	// ウィンドウリストアイテムズパネルクラス
#include "resource.h"			// リソース

// ウィンドウリストコントロールクラスCWindowListControl
class CWindowListControl : public CUserControl {

	// publicメンバ
	public:

		// publicメンバ変数
		HPEN m_hPen;		// ペンHPEN型m_hPen.
		HBRUSH m_hBrush;	// ブラシHBRUSH型m_hBrush.
		CWindowListItemsPanel *m_pWindowListItemsPanel;	// CWindowListItemsPanel *型ウィンドウリストアイテムズパネルオブジェクトポインタm_pWindowListItemsPanel

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass

		// コンストラクタ・デストラクタ
		CWindowListControl();	// コンストラクタCWindowListControl()
		virtual ~CWindowListControl();	// デストラクタ~CWindowListControl()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual void Destroy();	// ウィンドウ破棄関数Destroy
		virtual BOOL Insert(int iIndex);	// アイテム挿入関数Insert
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnPaint();	// ウィンドウの描画を要求された時のハンドラOnPaint.

};