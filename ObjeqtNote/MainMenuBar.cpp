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
void CMainMenuBar::OnFileOpen(){

	// ���C���E�B���h�E�I�u�W�F�N�g�̎擾
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]��pMainWindow���擾.(�r��dynamic_cast���Ă���.)
	if (pMainWindow != NULL) {	// �L���X�g����.

		// �t�@�C���I���_�C�A���O�̕\��.
		// �t�B���^������̍쐬.
		TCHAR tszFilter[1024] = { 0 };	// �g���q�Ńt�B���^�����O����t�B���^tszFilter.
		_tcscat_s(tszFilter, 1024, FILTER_TEXT_ALL_FILE);	// "���ׂẴt�@�C��"
		_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// ��؂蕶��
		_tcscat_s(tszFilter, 1024, FILTER_RULE_ALL_FILE);	// "*.*"
		_tcscat_s(tszFilter, 1024, FILTER_END);				// �I������
		TCHAR tszFileName[1024] = { 0 };	// tszFileName��0�Ŗ��߂�.
		TCHAR tszExtension[16] = { 0 };		// tszExtension��0�Ŗ��߂�.
		CBinaryFile::GetOpenFileName(tszFileName, 1024, tszFilter, m_hWnd, tszExtension);	// �X�^�e�B�b�N��CBinaryFile::GetOpenFileName�őI�������t�@�C�������擾.
		if (!_tcsicmp(tszExtension, _T(".txt"))) {	// ".txt"�Ȃ�.
			MessageBox(NULL, _T("�e�L�X�g�t�@�C��"), _T("ObjeqtNote"), MB_OK);	// "�e�L�X�g�t�@�C��"�ƕ\��.
		}
		else if (!_tcsicmp(tszExtension, _T(".bmp"))) {	// ".bmp"�Ȃ�.
			MessageBox(NULL, _T("�r�b�g�}�b�v�t�@�C��"), _T("ObjeqtNote"), MB_OK);	// "�r�b�g�}�b�v�t�@�C��"�ƕ\��.
		}

	}

}

// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
void CMainMenuBar::OnFileSaveAs(){

	// ���C���E�B���h�E�I�u�W�F�N�g�̎擾
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]��pMainWindow���擾.(�r��dynamic_cast���Ă���.)
	if (pMainWindow != NULL) {	// �L���X�g����.

	}

}