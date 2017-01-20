// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "BasicWindow.h"	// �x�[�V�b�N�E�B���h�E�N���X
#include "MenuBar.h"		// ���j���[�o�[�N���X
#include "resource.h"		// ���\�[�X

// ���j���[�E�B���h�E�N���XCMenuWindow
class CMenuWindow : public CBasicWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		CMenuBar *m_pMenuBar;	// CMenuBar�I�u�W�F�N�g�|�C���^m_pMenuBar.

		// public�����o�֐�	
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)

		// �R���X�g���N�^�E�f�X�g���N�^
		CMenuWindow();	// �R���X�g���N�^CMenuWindow()
		virtual ~CMenuWindow();	// �f�X�g���N�^~CMenuWindow()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h�������̃n���h��OnCommand.

};