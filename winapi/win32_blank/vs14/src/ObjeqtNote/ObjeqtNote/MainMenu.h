// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Menu.h"	// ���j���[�N���X
#include "resource.h"		// ���\�[�XID

// ���C�����j���[�N���XCMainMenu
class CMainMenu : public CMenu {

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMainMenu(HWND hWnd);	// �R���X�g���N�^CMainMenu
		virtual BOOL OnCommandMenuItem(WPARAM wParam, LPARAM lParam);	// ���j���[�I�����̓Ǝ��n���h��OnCommandMenuItem.

		// �����o�֐�
		void OnFileNew();		// "�V�K"�I�����̓Ǝ��n���h��OnFileNew.
		void OnFileOpen();		// "�J��"�I�����̓Ǝ��n���h��OnFileOpen.
		void OnFileSave();		// "�㏑���ۑ�"�I�����̓Ǝ��n���h��OnFileSave.
		void OnFileSaveAs();	// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
		void OnAppExit();		// "�A�v���P�[�V�����̏I��"�I�����̓Ǝ��n���h��OnAppExit.

};