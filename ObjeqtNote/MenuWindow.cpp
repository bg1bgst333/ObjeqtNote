// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MenuWindow.h"	// ���j���[�E�B���h�E�N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)
BOOL CMenuWindow::RegisterClass(HINSTANCE hInstance, UINT nID){

	// �E�B���h�E�N���X�̓o�^
	//return CWindow::RegisterClass(hInstance, _T("MenuWindow"), nID);	// CWindow::RegisterClass(���j���[�w��)�ŃE�B���h�E�N���X"MenuWindow"��o�^.
	return CWindow::RegisterClass(hInstance, _T("MenuWindow"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X"MenuWindow"��o�^.

}

// �R���X�g���N�^CMenuWindow()
CMenuWindow::CMenuWindow() : CBasicWindow(){

	// �����o�̏�����.
	m_pMenuBar = NULL;	// m_pMenuBar��NULL�ŏ�����.

}

// �f�X�g���N�^~CMenuWindow()
CMenuWindow::~CMenuWindow(){

	// �����o�̏I������.
	if (m_pMenuBar != NULL) {	// m_pMenuBar��NULL�łȂ����.
		delete m_pMenuBar;	// delete��m_pMenuBar�����.
		m_pMenuBar = NULL;	// m_pMenuBar��NULL�Ŗ��߂�.
	}

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CMenuWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �����ɗ���ꍇ�̓E�B���h�E�N���X"MenuWindow"�̃E�B���h�E�Ƃ��č쐬.
	return CWindow::Create(_T("MenuWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��"MenuWindow"�ɂ���Create�̃t���o�[�W�������Ă�.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CMenuWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ���j���[�o�[�̍쐬.(���I�ɍ쐬����ꍇ.)
	m_pMenuBar = new CMenuBar();	// CMenuBar�I�u�W�F�N�g���쐬��, �|�C���^��m_pMenuBar�Ɋi�[.

	// ���j���[�̃��[�h.
	m_pMenuBar->LoadMenu(lpCreateStruct->hInstance, IDR_MAINMENU);	// LoadMenu��ID_MAINMENU�����[�h.

	// ���j���[�̃Z�b�g.
	m_pMenuBar->SetMenu(hwnd);	// SetMenu��hwnd�Ƀ��j���[���Z�b�g.

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ̂�0��Ԃ�.

}

// �R�}���h�������̃n���h��OnCommand.
BOOL CMenuWindow::OnCommand(WPARAM wParam, LPARAM lParam){

	// ���j���[�R�}���h�������ꍇ.
	if (HIWORD(wParam) == 0) {	// HIWORD(wParam)��0�Ȃ烁�j���[���I�����ꂽ�Ƃ�������.

		// ���j���[�I�u�W�F�N�g�����邩�`�F�b�N.
		if (m_pMenuBar != NULL) {	// m_pMenuBar��NULL�łȂ��ꍇ.

			// OnCommandMenuItem�ɃR�}���h������C����.
			return m_pMenuBar->OnCommandMenuItem(wParam, lParam);	// OnCommandMenuItem��wParam, lParam��n���Ă��Ƃ͔C��, �߂�l�����̂܂ܕԂ�.

		}

	}

	// FALSE��Ԃ�.
	return TRUE;

}
