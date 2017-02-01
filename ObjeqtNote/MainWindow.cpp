// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "MainWindow.h"		// ���j���[�E�B���h�E�N���X	
#include "MainMenuBar.h"	// ���C�����j���[�o�[�N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// �E�B���h�E�N���X�̓o�^
	return CWindow::RegisterClass(hInstance, _T("MainWindow"), nID);	// CWindow::RegisterClass(���j���[�w��)�ŃE�B���h�E�N���X"MainWindow"��o�^.

}

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow() : CStandardWindow() {

	// �����o�̏�����
	m_pUserControl = NULL;		// m_pUserControl��NULL�ŏ�����.
	m_pEditBox = NULL;			// m_pEditBox��NULL�ŏ�����.

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow() {

	// �����o�̏I������.
	if (m_pEditBox != NULL) {
		delete m_pEditBox;			// delete��m_pEditBox�����.
		m_pEditBox = NULL;			// m_pEditBox��NULL�Ŗ��߂�.
	}
	if (m_pUserControl != NULL) {
		delete m_pUserControl;	// delete��m_pUserControl�����.
		m_pUserControl = NULL;	// m_pUserControl��NULL�Ŗ��߂�.
	}

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �����ɗ���ꍇ�̓E�B���h�E�N���X"MainWindow"�̃E�B���h�E�Ƃ��č쐬.
	return CWindow::Create(_T("MainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��"MainWindow"�ɂ���Create�̃t���o�[�W�������Ă�.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���C�����j���[�o�[�̍쐬.(�E�B���h�E�N���X�o�^����ID���w�肵���ꍇ.)
	m_pMenuBar = new CMainMenuBar(hwnd);	// CMainMenuBar�̃R���X�g���N�^��hwnd��n���ăI�u�W�F�N�g���쐬��, �|�C���^��m_pMenuBar�Ɋi�[.

	// ���[�U�R���g���[���̍쐬.
	m_pUserControl = new CUserControl();	// CUserControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pUserControl�Ɋi�[.
	m_pUserControl->Create(_T("UserControl"), _T(""), WS_BORDER, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// m_pUserControl->Create�ŃE�B���h�E�N���X��"UserControl"�ȃE�B���h�E���쐬.

	// �G�f�B�b�g�{�b�N�X�̍쐬.
	m_pEditBox = new CEditBox();	// CEditBox�I�u�W�F�N�g���쐬��, �|�C���^��m_pEditBox�Ɋi�[.
	m_pEditBox->Create(_T(""), WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 150, 150, 200, 50, hwnd, (HMENU)IDC_EDITBOX1, lpCreateStruct->hInstance);	// m_pEditBox->Create�ŃG�f�B�b�g�{�b�N�X���쐬.

	// ����.
	return 0;	// �����Ȃ̂�0��Ԃ�.

}