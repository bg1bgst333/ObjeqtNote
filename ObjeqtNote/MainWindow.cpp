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
	m_pUserControl = NULL;			// m_pUserControl��NULL�ŏ�����.
	m_pEditBox = NULL;				// m_pEditBox��NULL�ŏ�����.
	m_pPictureBox = NULL;			// m_pPictureBox��NULL�ŏ�����.
	m_pWindowListControl = NULL;	// m_pWindowListControl��NULL�ŏ�����.

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŕj��.
	if (m_pPictureBox != NULL) {
		delete m_pPictureBox;		// delete��m_pPictureBox�����.
		m_pPictureBox = NULL;		// m_pPictureBox��NULL�Ŗ��߂�.
	}
	if (m_pEditBox != NULL) {
		delete m_pEditBox;			// delete��m_pEditBox�����.
		m_pEditBox = NULL;			// m_pEditBox��NULL�Ŗ��߂�.
	}
	if (m_pUserControl != NULL) {
		delete m_pUserControl;		// delete��m_pUserControl�����.
		m_pUserControl = NULL;		// m_pUserControl��NULL�Ŗ��߂�.
	}

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �����ɗ���ꍇ�̓E�B���h�E�N���X"MainWindow"�̃E�B���h�E�Ƃ��č쐬.
	return CWindow::Create(_T("MainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��"MainWindow"�ɂ���Create�̃t���o�[�W�������Ă�.

}

// �E�B���h�E�j���֐�Destroy
void CMainWindow::Destroy() {

	// �q�E�B���h�E�̔j��.
	if (m_pWindowListControl != NULL) {
		m_pWindowListControl->Destroy();	// m_pWindowListControl�̃E�B���h�E��j��.
		delete m_pWindowListControl;		// m_pWindowListControl�����.
		m_pWindowListControl = NULL;		// m_pWindowListControl��NULL�Ŗ��߂�.
	}

	// �����̃E�B���h�E���j��.
	CWindow::Destroy();	// CWindow::Destroy�Ŏ��g�̃E�B���h�E���j��.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���C�����j���[�o�[�̍쐬.(�E�B���h�E�N���X�o�^����ID���w�肵���ꍇ.)
	m_pMenuBar = new CMainMenuBar(hwnd);	// CMainMenuBar�̃R���X�g���N�^��hwnd��n���ăI�u�W�F�N�g���쐬��, �|�C���^��m_pMenuBar�Ɋi�[.

	// �E�B���h�E���X�g�R���g���[���̍쐬.
	m_pWindowListControl = new CWindowListControl();	// // CWindowListControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pWindowListControl�Ɋi�[.
	m_pWindowListControl->Create(_T(""), WS_HSCROLL | WS_VSCROLL, 50, 50, 400, 300, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Create�ŃE�B���h�E���X�g�R���g���[�����쐬.(���̎��_�ł�, �܂�WS_BORDER��t���Ă���.)

	// �E�B���h�E���X�g�A�C�e���̑}��.
	m_pWindowListControl->Insert(_T("0"), 0, 50, lpCreateStruct->hInstance);	// 0�Ԗڂɍ���50�̃A�C�e����}��.
	m_pWindowListControl->Insert(_T("1"), 1, 50, lpCreateStruct->hInstance);	// 1�Ԗڂɍ���50�̃A�C�e����}��.
	m_pWindowListControl->Insert(_T("2"), 0, 50, lpCreateStruct->hInstance);	// 0�Ԗڂɍ���50�̃A�C�e����}��.
	m_pWindowListControl->Insert(_T("3"), 1, 50, lpCreateStruct->hInstance);	// 1�Ԗڂɍ���50�̃A�C�e����}��.
	m_pWindowListControl->Insert(_T("4"), 0, 50, lpCreateStruct->hInstance);	// 0�Ԗڂɍ���50�̃A�C�e����}��.

	// �E�B���h�E���X�g�A�C�e���̍폜.
	m_pWindowListControl->Remove(0);	// 0�Ԗڂ��폜.
	m_pWindowListControl->Remove(3);	// 3�Ԗڂ��폜.
	m_pWindowListControl->Remove(1);	// 1�Ԗڂ��폜.

	// ����.
	return 0;	// �����Ȃ̂�0��Ԃ�.

}

// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

}