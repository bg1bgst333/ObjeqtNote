// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "UserControl.h"	// ���[�U�R���g���[���N���X

// �E�B���h�E���X�g�R���g���[���N���XCWindowListControl
class CWindowListControl : public CUserControl {

	// public�����o
	public:

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass

		// �R���X�g���N�^�E�f�X�g���N�^
		CWindowListControl();	// �R���X�g���N�^CWindowListControl()
		virtual ~CWindowListControl();	// �f�X�g���N�^~CWindowListControl()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create

};