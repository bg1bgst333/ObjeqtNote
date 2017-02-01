// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MenuBar.h"	// ���j���[�o�[�N���X

// �R���X�g���N�^CMenuBar()
CMenuBar::CMenuBar(){

	// �����o�̏�����.
	m_hMenu = NULL;	// m_hMenu��NULL�ŏ�����.

}

// �R���X�g���N�^CMenuBar(HWND hWnd)
CMenuBar::CMenuBar(HWND hWnd) {

	// �����o�̏�����.
	m_hMenu = NULL;	// m_hMenu��NULL�ŏ�����.
	m_hWnd = hWnd;	// m_hWnd��hWnd�ŏ�����.

}

// �f�X�g���N�^~CMenuBar()
CMenuBar::~CMenuBar(){

	// �����o�̏I������.
	// �Ƃ肠�����Ȃ��ł���.

}

// ���j���[���[�h�֐�LoadMenu.
BOOL CMenuBar::LoadMenu(HINSTANCE hInstance, UINT nID){

	// ���j���[nID�����[�h.
	m_hMenu = ::LoadMenu(hInstance, MAKEINTRESOURCE(nID));	// LoadMenu��nID�����[�h.
	if (m_hMenu == NULL) {	// m_hMenu��NULL�Ȃ�.

		// ���s�Ȃ̂�FALSE��Ԃ�.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �����Ȃ̂�TRUE��Ԃ�.
	return 0;	// TRUE��Ԃ�.

}

// ���j���[�Z�b�g�֐�SetMenu.
BOOL CMenuBar::SetMenu(HWND hwnd){

	// �����o�Ɉ������Z�b�g.
	m_hWnd = hwnd;	// m_hWnd��hwnd���Z�b�g.

	// ���j���[�̃Z�b�g.
	return ::SetMenu(m_hWnd, m_hMenu);	// SetMenu��m_hMenu���Z�b�g��, �߂�l�����̂܂ܕԂ�.

}

// ���j���[�I�����̃n���h��OnCommandMenuItem.
BOOL CMenuBar::OnCommandMenuItem(WPARAM wParam, LPARAM lParam){

	// ���j���[����
	switch (LOWORD(wParam)) {	// LOWORD(wParam)�łǂ̃��j���[�A�C�e�����I�����ꂽ��, ID���Ԃ��Ă���.

		// ID_FILE_NEW�̎�.
		case ID_FILE_NEW:

			// ID_FILE_NEW�u���b�N
			{

				// OnFileNew�ɔC����.
				OnFileNew();

			}

			// ����̏���
			break;	// break�Ŕ�����.

		// ID_FILE_OPEN�̎�.
		case ID_FILE_OPEN:

			// ID_FILE_OPEN�u���b�N
			{

				// OnFileOpen�ɔC����.
				OnFileOpen();

			}

			// ����̏���
			break;	// break�Ŕ�����.

		// ID_FILE_SAVE�̎�.
		case ID_FILE_SAVE:

			// ID_FILE_SAVE�u���b�N
			{

				// OnFileSave�ɔC����.
				OnFileSave();

			}

			// ����̏���
			break;	// break�Ŕ�����.

		// ID_FILE_SAVEAS�̎�.
		case ID_FILE_SAVEAS:

			// ID_FILE_SAVEAS�u���b�N
			{

				// OnFileSaveAs�ɔC����.
				OnFileSaveAs();

			}

			// ����̏���
			break;	// break�Ŕ�����.

		// ID_APP_EXIT�̎�.
		case ID_APP_EXIT:

			// ID_APP_EXIT�u���b�N
			{

				// OnAppExit�ɔC����.
				OnAppExit();

			}

			// ����̏���
			break;	// break�Ŕ�����.

		// ����ȊO�̎�.
		default:

			// FALSE��Ԃ�.
			return FALSE;

	}

	// �ǂꂩ�̃n���h�����������ꂽ���TRUE��Ԃ�.
	return TRUE;

}

// "�V�K"�I�����̓Ǝ��n���h��OnFileNew.
void CMenuBar::OnFileNew(){

	// "�V�K"�ƕ\��.
	MessageBox(NULL, _T("�V�K"), _T("ObjeqtNote"), MB_OK);	// MessageBox��"�V�K"�ƕ\��.

}

// "�J��"�I�����̓Ǝ��n���h��OnFileOpen.
void CMenuBar::OnFileOpen(){

	// "�J��"�ƕ\��.
	MessageBox(NULL, _T("�J��"), _T("ObjeqtNote"), MB_OK);	// MessageBox��"�J��"�ƕ\��.

}

// "�㏑���ۑ�"�I�����̓Ǝ��n���h��OnFileSave.
void CMenuBar::OnFileSave(){

	// "�㏑���ۑ�"�ƕ\��.
	MessageBox(NULL, _T("�㏑���ۑ�"), _T("ObjeqtNote"), MB_OK);	// MessageBox��"�㏑���ۑ�"�ƕ\��.

}

// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
void CMenuBar::OnFileSaveAs(){

	// "���O��t���ĕۑ�"�ƕ\��.
	MessageBox(NULL, _T("���O��t���ĕۑ�"), _T("ObjeqtNote"), MB_OK);	// MessageBox��"���O��t���ĕۑ�"�ƕ\��.

}

// "�A�v���P�[�V�����̏I��"�I�����̓Ǝ��n���h��OnAppExit.
void CMenuBar::OnAppExit(){

	// "�A�v���P�[�V�����̏I��"�ƕ\��.
	MessageBox(NULL, _T("�A�v���P�[�V�����̏I��"), _T("ObjeqtNote"), MB_OK);	// MessageBox��"�A�v���P�[�V�����̏I��"�ƕ\��.

}
