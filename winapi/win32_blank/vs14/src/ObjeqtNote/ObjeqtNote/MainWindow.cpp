// �w�b�_�̃C���N���[�h
#include "MainWindow.h"	// ���C���E�B���h�E�N���X
#include "MainMenu.h"	// ���C�����j���[�N���X

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���C�����j���[�̍쐬.
	m_pMainMenu = new CMainMenu(hwnd);	// CMainMenu�I�u�W�F�N�g���쐬��, �|�C���^��m_pMainMenu�Ɋi�[.

	// ���C�����j���[�̃��[�h.
	m_pMainMenu->LoadMenu(IDR_MAINMENU);	// m_pMainMenu->LoadMenu��IDR_MAINMENU�����[�h.

	// ���C�����j���[�̃Z�b�g
	m_pMainMenu->SetMenu();	// m_pMainMenu->SetMenu�Ń��j���[���Z�b�g.

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �E�B���h�E�j�����̃n���h��OnDestroy
void CMainWindow::OnDestroy() {

	// ���C�����j���[�̔j��.
	if (m_pMainMenu != NULL) {	// NULL�łȂ����.

		// m_pMainMenu�̉��.
		delete m_pMainMenu;	// delete��m_pMainMenu�����.
		m_pMainMenu = NULL;	// m_pMainMenu��NULL�ɃZ�b�g.

	}

	// ���b�Z�[�W���[�v�I��.
	PostQuitMessage(0);	// PostQuitMessage�Ń��b�Z�[�W���[�v�𔲂�������.

}

// �R�}���h�������̃n���h��OnCommand.
BOOL CMainWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	// ���j���[���I�����ꂽ�ꍇ.
	if (HIWORD(wParam) == 0) {	// HIWORD(wParam)��0�Ȃ烁�j���[���I�����ꂽ�Ƃ�������.

		// ���j���[�I�u�W�F�N�g�����邩�`�F�b�N.
		if (m_pMainMenu != NULL) {	// ����.

			// m_pMainMenu��OnCommandMenuItem�ɔC����.
			return m_pMainMenu->OnCommandMenuItem(wParam, lParam);

		}
		else {	// ����ȊO.

		}

	}
	else {	// ����ȊO.

	}

	// FALSE��Ԃ�.
	return FALSE;

}