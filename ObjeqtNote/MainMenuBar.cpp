// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainMenuBar.h"	// ���C�����j���[�o�[�N���X

// �R���X�g���N�^CMainMenuBar()
CMainMenuBar::CMainMenuBar() : CMenuBar() {

}

// �R���X�g���N�^CMainMenuBar(HWND hWnd)
CMainMenuBar::CMainMenuBar(HWND hWnd) : CMenuBar(hWnd) {

}

// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
void CMainMenuBar::OnFileSaveAs() {

	// �ϐ��̐錾
	HWND hEdit;			// �G�f�B�b�g�{�b�N�X�̃E�B���h�E�n���h��HWND�^hEdit.
	int iLen;			// �G�f�B�b�g�{�b�N�X�̃e�L�X�g�̒���int�^iLen.
	TCHAR *ptszText;	// �e�L�X�g�̃|�C���^TCHAR *�^ptszText.

	// �G�f�B�b�g�{�b�N�X�̃e�L�X�g���擾����, ���b�Z�[�W�{�b�N�X�ŕ\��.
	hEdit = GetDlgItem(m_hWnd, IDC_EDITBOX1);	// GetDlgItem��IDC_EDITBOX1�̎w���G�f�B�b�g�{�b�N�X�̃E�B���h�E�n���h��hEdit���擾.
	iLen = GetWindowTextLength(hEdit);	// GetWindowTextLength��hEdit�̃e�L�X�g�̒���iLen���擾.
	ptszText = new TCHAR[iLen + 1];	// TCHAR�^���I�z���new�ō쐬��, �|�C���^��ptszText�Ɋi�[.(����iLen + 1)
	GetWindowText(hEdit, ptszText, iLen + 1);	// GetWindowText�Ńe�L�X�g���擾��, ptszText�Ɋi�[.
	MessageBox(NULL, ptszText, _T("ObjeqtNote"), MB_OK);	// MessageBox��ptszText��\��.
	delete[] ptszText;	// delete��ptszText�����.

}