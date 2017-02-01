// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainMenuBar.h"	// ���C�����j���[�o�[�N���X
#include "MainWindow.h"	// ���C���E�B���h�E�N���X

// �R���X�g���N�^CMainMenuBar()
CMainMenuBar::CMainMenuBar() : CMenuBar() {

}

// �R���X�g���N�^CMainMenuBar(HWND hWnd)
CMainMenuBar::CMainMenuBar(HWND hWnd) : CMenuBar(hWnd) {

}

// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
void CMainMenuBar::OnFileSaveAs() {

	// ���C���E�B���h�E�I�u�W�F�N�g�̎擾
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]��pMainWindow���擾.(�r��dynamic_cast���Ă���.)
	if (pMainWindow != NULL) {	// �L���X�g����.
		if (pMainWindow->m_pEditBox != NULL) {	// �G�f�B�b�g�{�b�N�X�������ς݂̏ꍇ.
			pMainWindow->m_pEditBox->GetWindowText();	// pMainWindow->m_pEditBox->GetWindowText�ŃG�f�B�b�g�{�b�N�X�̃e�L�X�g���擾.
			MessageBox(NULL, pMainWindow->m_pEditBox->m_ptszText, _T("ObjeqtNote"), MB_OK);	// MessageBox��pMainWindow->m_pEditBox->m_ptszText��\��.
		}
	}

}