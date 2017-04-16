// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "CustomControl.h"	// カスタムコントロールクラス

// ピクチャーボックスクラスCPictureBox
class CPictureBox : public CCustomControl {

	// publicメンバ
	public:

		// メンバ変数
		HBITMAP m_hBitmap;	// ロードするビットマップのハンドルHBITMAP型m_hBitmap.

		// コンストラクタ・デストラクタ
		CPictureBox();	// コンストラクタCPictureBox()
		virtual ~CPictureBox();	// デストラクタ~CPictureBox()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)
		virtual BOOL Load(LPCTSTR lpctszFileName, int iWidth, int iHeight);	// 画像をロードする関数Load.
		virtual void SetImage();	// 画像をセット(表示)する関数SetImage.

};