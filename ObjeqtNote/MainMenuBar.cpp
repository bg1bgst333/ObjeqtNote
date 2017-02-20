// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainMenuBar.h"	// ���C�����j���[�o�[�N���X
#include "MainWindow.h"		// ���C���E�B���h�E�N���X
#include "TextFile.h"		// �e�L�X�g�t�@�C���N���X

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
		if (pMainWindow->m_pEditBox != NULL) {	// �G�f�B�b�g�{�b�N�X�������ς݂̏ꍇ.

			// �I�u�W�F�N�g�̐錾
			CTextFile *pTextFile;	// �e�L�X�g�t�@�C���|�C���^CTextFile *�^pTextFile.

			// CTextFile�I�u�W�F�N�g�Ńe�L�X�g��ۑ�.
			pTextFile = new CTextFile();	// CTextFile�I�u�W�F�N�g���쐬��, �|�C���^��pTextFile�Ɋi�[.

			// �J���t�@�C����I��.
			// �t�B���^������̍쐬.
			TCHAR tszFilter[1024] = { 0 };	// �g���q�Ńt�B���^�����O����t�B���^tszFilter.
			_tcscat_s(tszFilter, 1024, FILTER_TEXT_BIN_FILE);	// "�o�C�i���t�@�C��"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// ��؂蕶��
			_tcscat_s(tszFilter, 1024, FILTER_RULE_BIN_FILE);	// "*.bin"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// ��؂蕶��
			_tcscat_s(tszFilter, 1024, FILTER_TEXT_ALL_FILE);	// "���ׂẴt�@�C��"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// ��؂蕶��
			_tcscat_s(tszFilter, 1024, FILTER_RULE_ALL_FILE);	// "*.*"
			_tcscat_s(tszFilter, 1024, FILTER_END);				// �I������
			// �t�@�C���I���_�C�A���O�̕\��.
			if (pTextFile->GetOpenFileName(pTextFile->m_tszFileName, 1024, tszFilter, m_hWnd)) {	// �I�����ꂽ��.

				// pTextFile->m_tszFileName���J��.
				if (pTextFile->Open(pTextFile->m_tszFileName, GENERIC_READ, OPEN_EXISTING)) {	// pTextFile->Open�Ńt�@�C�����J������.

					// pTextFile->m_tszFileName����ǂݍ��񂾃e�L�X�g��UNICODE�ɕϊ�.
					pMainWindow->m_pEditBox->m_iLen = pTextFile->Read(&pMainWindow->m_pEditBox->m_ptszText, CTextFile::SHIFT_JIS);	// pTextFile->Read�œǂݍ����pMainWindow->m_pEditBox->m_ptszText�Ƀe�L�X�g���i�[, ������pMainWindow->m_pEditBox->m_iLen�Ɋi�[.

					// ����.
					pTextFile->Close();	// pTextFile->Close�ŕ���.

				}

			}

			// �I�u�W�F�N�g�̉��.
			delete pTextFile;	// delete��pTextFile�����.

			// �G�f�B�b�g�{�b�N�X�̃e�L�X�g��ݒ�.
			pMainWindow->m_pEditBox->SetWindowText();	// pMainWindow->m_pEditBox->SetWindowText�ŃG�f�B�b�g�{�b�N�X�̃e�L�X�g��ݒ�.

		}
	}

}

// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
void CMainMenuBar::OnFileSaveAs(){

	// ���C���E�B���h�E�I�u�W�F�N�g�̎擾
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]��pMainWindow���擾.(�r��dynamic_cast���Ă���.)
	if (pMainWindow != NULL) {	// �L���X�g����.
		if (pMainWindow->m_pEditBox != NULL) {	// �G�f�B�b�g�{�b�N�X�������ς݂̏ꍇ.
			
			// �I�u�W�F�N�g�̐錾
			CTextFile *pTextFile;	// �e�L�X�g�t�@�C���|�C���^CTextFile *�^pTextFile.

			// �G�f�B�b�g�{�b�N�X�̃e�L�X�g���擾.
			pMainWindow->m_pEditBox->GetWindowText();	// pMainWindow->m_pEditBox->GetWindowText�ŃG�f�B�b�g�{�b�N�X�̃e�L�X�g���擾.

			// CTextFile�I�u�W�F�N�g�Ńe�L�X�g��ۑ�.
			pTextFile = new CTextFile();	// CTextFile�I�u�W�F�N�g���쐬��, �|�C���^��pTextFile�Ɋi�[.

			// �ۑ���̃t�@�C����I��.
			// �t�B���^������̍쐬.
			TCHAR tszFilter[1024] = { 0 };	// �g���q�Ńt�B���^�����O����t�B���^tszFilter.
			_tcscat_s(tszFilter, 1024, FILTER_TEXT_BIN_FILE);	// "�o�C�i���t�@�C��"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// ��؂蕶��
			_tcscat_s(tszFilter, 1024, FILTER_RULE_BIN_FILE);	// "*.bin"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// ��؂蕶��
			_tcscat_s(tszFilter, 1024, FILTER_TEXT_ALL_FILE);	// "���ׂẴt�@�C��"
			_tcscat_s(tszFilter, 1024, FITLER_DELIMITER);		// ��؂蕶��
			_tcscat_s(tszFilter, 1024, FILTER_RULE_ALL_FILE);	// "*.*"
			_tcscat_s(tszFilter, 1024, FILTER_END);				// �I������
			// �t�@�C���I���_�C�A���O�̕\��.
			if (pTextFile->GetSaveFileName(pTextFile->m_tszFileName, 1024, tszFilter, m_hWnd)) {	// �I�����ꂽ��.

				// pTextFile->m_tszFileName���J��.
				if (pTextFile->Open(pTextFile->m_tszFileName, GENERIC_WRITE, OPEN_ALWAYS)) {	// pTextFile->Open�Ńt�@�C�����J������.

					// pTextFile->m_tszFileName�ɃG�f�B�b�g�{�b�N�X�̃e�L�X�g��SHIFT_JIS�ɕϊ��������̂���������.
					pTextFile->Write(pMainWindow->m_pEditBox->m_ptszText, CTextFile::EncodeType::SHIFT_JIS);	// pTextFile->Write��pMainWindow->m_pEditBox->m_ptszText��SHIFT_JIS�ŏ�������.

					// ����.
					pTextFile->Close();	// pTextFile->Close�ŕ���.

				}

			}

			// �I�u�W�F�N�g�̉��.
			delete pTextFile;	// delete��pTextFile�����.

		}

	}

}