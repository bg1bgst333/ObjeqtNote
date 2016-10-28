// �w�b�_�̃C���N���[�h
#include "MainWindow.h"	// ���C���E�B���h�E�N���X
#include "MainMenu.h"	// ���C�����j���[�N���X

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CMainWindow::Destroy(){

	// �q�E�B���h�E�̔j��.
	m_pWindowListView->Destroy();	// m_pWindowListView->Destroy�Ŕj��.

	// �E�B���h�E���X�g�r���[�̔j��.
	if (m_pWindowListView != NULL) {	// NULL�łȂ����.

		// m_pWindowListView�̔j��.
		delete m_pWindowListView;	// delete��m_pWindowListView�����.
		m_pWindowListView = NULL;	// m_pWindowListView��NULL�ɃZ�b�g.

	}

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���C�����j���[�̍쐬.
	m_pMainMenu = new CMainMenu(hwnd);	// CMainMenu�I�u�W�F�N�g���쐬��, �|�C���^��m_pMainMenu�Ɋi�[.

	// ���C�����j���[�̃��[�h.
	m_pMainMenu->LoadMenu(IDR_MAINMENU);	// m_pMainMenu->LoadMenu��IDR_MAINMENU�����[�h.

	// ���C�����j���[�̃Z�b�g
	m_pMainMenu->SetMenu();	// m_pMainMenu->SetMenu�Ń��j���[���Z�b�g.

	// �q�E�B���h�E�ƂȂ�E�B���h�E���X�g�r���[�I�u�W�F�N�g�̍쐬.
	m_pWindowListView = new CWindowListView();	// CWindowListView�I�u�W�F�N�gm_pWindowListView�̍쐬.
	
	// �q�E�B���h�E�̍쐬.
	m_pWindowListView->Create(100, 100, 200, 200, hwnd, (HMENU)IDC_WINDOW_LISTVIEW, lpCreateStruct->hInstance);	// m_pWindowListView->Create�ŃE�B���h�E���X�g�r���[���쐬.

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

// �E�B���h�E����鎞�̃n���h��OnClose.
int CMainWindow::OnClose(){

		// �q�E�B���h�E�̔j��.
		Destroy();	// Destroy�Ŏq�E�B���h�E�̔j��.
		return 0;	// 0��Ԃ��ƕ���.

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