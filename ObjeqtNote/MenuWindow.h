// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "BasicWindow.h"	// �x�[�V�b�N�E�B���h�E�N���X

// ���j���[�E�B���h�E�N���XCMenuWindow
class CMenuWindow : public CBasicWindow {

	// public�����o
	public:

		// public�����o�֐�	
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)

		// �R���X�g���N�^�E�f�X�g���N�^
		CMenuWindow();	// �R���X�g���N�^CMenuWindow()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)

};