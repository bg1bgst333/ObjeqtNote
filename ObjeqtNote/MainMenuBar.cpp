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

// "�V�K"�I�����̓Ǝ��n���h��OnFileNew.
void CMainMenuBar::OnFileNew() {

	// ���C���E�B���h�E�I�u�W�F�N�g�̎擾
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]��pMainWindow���擾.(�r��dynamic_cast���Ă���.)
	if (pMainWindow != NULL) {	// �L���X�g����.

		// 1�Ԗڂ̃A�C�e�����擾.
		CWindowListItem * pItem = pMainWindow->m_pWindowListControl->Get(1);	// pMainWindow->m_pWindowListControl->Get��1�Ԗڂ��擾.
		if (pItem != NULL) {
			// �G�f�B�b�g�{�b�N�X���A�C�e���̎q�E�B���h�E�ɂ���.
			HINSTANCE hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWL_HINSTANCE);	// GetWindowLong��hInstance���擾.
			CEditBox *pEditBox = new CEditBox();	// �G�f�B�b�g�{�b�N�X�쐬.
			pEditBox->Create(_T(""), WS_BORDER, 30, 10, 100, 30, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, hInstance);	// Create�Ő���.
			pItem->m_mapChildMap.insert(std::make_pair(_T("EditBox"), pEditBox));	// pItem->m_mapChildMap.insert�Ń}�b�v�o�^.
		}

	}

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
void CMainMenuBar::OnFileSaveAs() {

	// ���C���E�B���h�E�I�u�W�F�N�g�̎擾
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]��pMainWindow���擾.(�r��dynamic_cast���Ă���.)
	if (pMainWindow != NULL) {	// �L���X�g����.

		// �폜.
		pMainWindow->m_pWindowListControl->Remove(0);	// pMainWindow->m_pWindowListControl->Remove��0�Ԗڂ��폜.

	}

}