// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainMenuBar.h"	// ���C�����j���[�o�[�N���X

// �R���X�g���N�^CMainMenuBar()
CMainMenuBar::CMainMenuBar() : CMenuBar() {

}

// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
void CMainMenuBar::OnFileSaveAs() {

	// �Ƃ肠�������b�Z�[�W�{�b�N�X��"CMainMenuBar::OnFileSaveAs()"�\��.
	MessageBox(NULL, _T("CMainMenuBar::OnFileSaveAs()"), _T("ObjeqtNote"), MB_OK);	// MessageBox��"CMainMenuBar::OnFileSaveAs()"�ƕ\��.

}