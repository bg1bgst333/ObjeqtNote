// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainMenuBar.h"	// ���C�����j���[�o�[�N���X
#include "MainWindow.h"		// ���C���E�B���h�E�N���X
#include "BinaryFile.h"		// �o�C�i���t�@�C���N���X

// �R���X�g���N�^CMainMenuBar()
CMainMenuBar::CMainMenuBar() : CMenuBar(){

}

// �R���X�g���N�^CMainMenuBar(HWND hWnd)
CMainMenuBar::CMainMenuBar(HWND hWnd) : CMenuBar(hWnd){

}

// "�J��"�I�����̓Ǝ��n���h��OnFileOpen.
void CMainMenuBar::OnFileOpen() {

	// ���C���E�B���h�E�I�u�W�F�N�g�̎擾
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]��pMainWindow���擾.(�r��dynamic_cast���Ă���.)
	if (pMainWindow != NULL) {	// �L���X�g����.

		// �}��.
		HINSTANCE hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWL_HINSTANCE);	// GetWindowLong��hInstance���擾.
		pMainWindow->m_pWindowListControl->Insert(_T("0"), 0, 50, hInstance);	// pMainWindow->m_pWindowListControl->Insert��0�ԖڂɃE�B���h�E��}��.

	}

}

// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
void CMainMenuBar::OnFileSaveAs(){

	// ���C���E�B���h�E�I�u�W�F�N�g�̎擾
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]��pMainWindow���擾.(�r��dynamic_cast���Ă���.)
	if (pMainWindow != NULL) {	// �L���X�g����.

	}

}