// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"		// �E�B���h�E�N���X
#include "Menu.h"	// ���j���[�N���X

// ���C���E�B���h�E�N���X
class CMainWindow : public CWindow {	// CWindow�̔h���N���X

	// public�����o
	public:

		// public�����o�ϐ�
		CMenu *m_pMainMenu;	// CMainMenu�I�u�W�F�N�g�|�C���^m_pMainMenu.

		// public�����o�֐�
		// �����o�֐�
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h�������̃n���h��OnCommand.
	
};