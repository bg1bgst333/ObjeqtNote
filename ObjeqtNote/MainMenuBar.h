// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MenuBar.h"	// ���j���[�o�[�N���X

// ���C�����j���[�o�[�N���XCMainMenuBar
class CMainMenuBar : public CMenuBar {

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMainMenuBar();	// �R���X�g���N�^CMainMenuBar()
		CMainMenuBar(HWND hWnd);	// �R���X�g���N�^CMainMenuBar(HWND hWnd)

		// �����o�֐�
		virtual void OnFileSaveAs();	// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.

};