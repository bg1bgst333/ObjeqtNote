// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "MenuWindow.h"	// ���j���[�E�B���h�E�N���X

// �X�^���_�[�h�E�B���h�E�N���XCStandardWindow
class CStandardWindow : public CMenuWindow {

	// public�����o
	public:

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)

		// �R���X�g���N�^�E�f�X�g���N�^
		CStandardWindow();	// �R���X�g���N�^CStandardWindow()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.

};