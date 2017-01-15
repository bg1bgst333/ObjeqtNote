// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "StandardApplication.h"	// �X�^���_�[�h�A�v���P�[�V�����N���X
#include "MenuWindow.h"				// ���j���[�E�B���h�E�N���X
#include "resource.h"				// ���\�[�X

// �R���X�g���N�^CStandardApplication()
CStandardApplication::CStandardApplication() : CBasicApplication() {

}

// �A�v���P�[�V�����������֐�InitInstance
BOOL CStandardApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// ������
	CBasicApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CBasicApplication::InitInstance���Ă�.

	// ���j���[�E�B���h�E�N���X�̓o�^
	CMenuWindow::RegisterClass(hInstance, IDR_MAINMENU);	// CMenuWindow::RegisterClass�Ń��j���[ID��IDR_MAINMENU�ȃE�B���h�E�N���X"MenuWindow"��o�^.

	// ���j���[�E�B���h�E�I�u�W�F�N�g�̐���
	m_pMainWindow = new CMenuWindow();	// CMenuWindow�I�u�W�F�N�g���쐬��, �A�h���X��m_pMainWindow�Ɋi�[.

	// �E�B���h�E�쐬
	if (!m_pMainWindow->Create(_T("ObjeqtNote"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWindow->Create�ł̍쐬�����s�Ȃ�.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �E�B���h�E�\��
	m_pMainWindow->ShowWindow(SW_SHOW);	// m_pMainWindow->ShowWindow�ŕ\��.

	// �����Ȃ̂�TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}