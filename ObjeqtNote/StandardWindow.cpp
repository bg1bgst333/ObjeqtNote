// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "StandardWindow.h"	// �X�^���_�[�h�E�B���h�E�N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)
BOOL CStandardWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// �E�B���h�E�N���X�̓o�^
	return CWindow::RegisterClass(hInstance, _T("StandardWindow"), nID);	// CWindow::RegisterClass(���j���[�w��)�ŃE�B���h�E�N���X"StandardWindow"��o�^.

}

// �R���X�g���N�^CStandardWindow()
CStandardWindow::CStandardWindow() : CMenuWindow() {

	// �����o�̏�����
	m_pMenuBar = NULL;			// m_pMenuBar��NULL�ŏ�����.
	m_pUserControl = NULL;		// m_pUserControl��NULL�ŏ�����.
	m_pCustomControl = NULL;	// m_pCustomControl��NULL�ŏ�����.

}

// �f�X�g���N�^~CStandardWindow()
CStandardWindow::~CStandardWindow(){

	// �����o�̏I������.
	if (m_pCustomControl != NULL) {
		delete m_pCustomControl;	// delete��m_pCustomControl�����.
		m_pCustomControl = NULL;	// m_pCustomControl��NULL�Ŗ��߂�.
	}
	if (m_pUserControl != NULL) {
		delete m_pUserControl;	// delete��m_pUserControl�����.
		m_pUserControl = NULL;	// m_pUserControl��NULL�Ŗ��߂�.
	}
	if (m_pMenuBar != NULL) {	// m_pMenuBar��NULL�łȂ����.
		delete m_pMenuBar;	// delete��m_pMenuBar�����.
		m_pMenuBar = NULL;	// m_pMenuBar��NULL�Ŗ��߂�.
	}


}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CStandardWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �����ɗ���ꍇ�̓E�B���h�E�N���X"StandardWindow"�̃E�B���h�E�Ƃ��č쐬.
	return CWindow::Create(_T("StandardWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��"StandardWindow"�ɂ���Create�̃t���o�[�W�������Ă�.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CStandardWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ���j���[�o�[�̍쐬.(�E�B���h�E�N���X�o�^����ID���w�肵���ꍇ.)
	m_pMenuBar = new CMenuBar();	// CMenuBar�I�u�W�F�N�g���쐬��, �|�C���^��m_pMenuBar�Ɋi�[.

	// ���[�U�R���g���[���̍쐬.
	m_pUserControl = new CUserControl();	// CUserControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pUserControl�Ɋi�[.
	m_pUserControl->Create(_T("UserControl"), _T(""), WS_BORDER, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// m_pUserControl->Create�ŃE�B���h�E�N���X��"UserControl"�ȃE�B���h�E���쐬.

	// �J�X�^���R���g���[���̍쐬.
	m_pCustomControl = new CCustomControl();	// CCustomControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pCustomControl�Ɋi�[.
	m_pCustomControl->Create(_T("Edit"), _T(""), WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 150, 150, 200, 50, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// m_pCustomControl->Create�ŃE�B���h�E�N���X��"Edit"�ȃE�B���h�E���쐬.

	// ����.
	return 0;	// �����Ȃ̂�0��Ԃ�.

}