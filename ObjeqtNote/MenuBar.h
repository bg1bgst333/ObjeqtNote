// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
// �Ǝ��̃w�b�_
#include "resource.h"	// ���\�[�X

// ���j���[�o�[�N���XCMenuBar
class CMenuBar {

	// public�����o
	public:

		// public�����o�ϐ�
		HMENU m_hMenu;	// ���j���[�n���h��m_hMenu
		HWND m_hWnd;	// �E�B���h�E�n���h��m_hWnd

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMenuBar();	// �R���X�g���N�^CMenuBar()
		CMenuBar(HWND hWnd);	// �R���X�g���N�^CMenuBar(HWND hWnd)
		virtual ~CMenuBar();	// �f�X�g���N�^~CMenuBar()

		// �����o�֐�
		virtual BOOL LoadMenu(HINSTANCE hInstance, UINT nID);	// ���j���[���[�h�֐�LoadMenu.
		virtual BOOL SetMenu(HWND hwnd);	// ���j���[�Z�b�g�֐�SetMenu.
		virtual BOOL OnCommandMenuItem(WPARAM wParam, LPARAM lParam);	// ���j���[�I�����̃n���h��OnCommandMenuItem.
		virtual void OnFileNew();		// "�V�K"�I�����̓Ǝ��n���h��OnFileNew.
		virtual void OnFileOpen();		// "�J��"�I�����̓Ǝ��n���h��OnFileOpen.
		virtual void OnFileSave();		// "�㏑���ۑ�"�I�����̓Ǝ��n���h��OnFileSave.
		virtual void OnFileSaveAs();	// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
		virtual void OnAppExit();		// "�A�v���P�[�V�����̏I��"�I�����̓Ǝ��n���h��OnAppExit.

};