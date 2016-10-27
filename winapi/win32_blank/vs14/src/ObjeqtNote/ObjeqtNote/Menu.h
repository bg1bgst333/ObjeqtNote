// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// ���j���[�N���XCMenu
class CMenu {

	// public�����o
	public:

		// public�����o�ϐ�
		HMENU m_hMenu;	// ���j���[�n���h��m_hMenu
		HWND m_hWnd;	// �E�B���h�E�n���h��m_hWnd
						
		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMenu(HWND hWnd);	// �R���X�g���N�^CMenu
		virtual ~CMenu();	// �f�X�g���N�^~CMenu

		// �����o�֐�
		virtual BOOL LoadMenu(UINT nIDResource);	// ���j���[���[�h�֐�LoadMenu
		virtual BOOL SetMenu();			// ���j���[�Z�b�g�֐�SetMenu
		virtual BOOL OnCommandMenuItem(WPARAM wParam, LPARAM lParam) = 0;	// ���j���[�I�����̓Ǝ��n���h��OnCommandMenuItem.(�������z�֐�)

};
