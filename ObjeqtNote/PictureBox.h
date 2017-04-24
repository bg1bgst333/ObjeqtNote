// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "CustomControl.h"	// カスタムコントロールクラス

// マクロ定義
#define SCROLLBAR_THICKNESS 16

// ピクチャーボックスクラスCPictureBox
class CPictureBox : public CCustomControl {

	// publicメンバ
	public:

		// メンバ変数
		HBITMAP m_hBitmap;		// ロードするビットマップのハンドルHBITMAP型m_hBitmap.
		HDC m_hMemDC;			// メモリデバイスコンテキストHDC型m_hMemDC.
		int m_iPictureWidth;	// 画像の幅int型m_iPictureWidth.
		int m_iPictureHeight;	// 画像の高さint型m_iPictureHeight.

		// コンストラクタ・デストラクタ
		CPictureBox();	// コンストラクタCPictureBox()
		virtual ~CPictureBox();	// デストラクタ~CPictureBox()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)
		virtual BOOL Load(LPCTSTR lpctszFileName, int iWidth, int iHeight);	// 画像をロードする関数Load.
		virtual void SetImage();	// 画像をセット(表示)する関数SetImage.
		virtual void OnPaint();	// ウィンドウの描画を要求された時のハンドラOnPaint.

};