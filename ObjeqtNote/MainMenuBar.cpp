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

// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
void CMainMenuBar::OnFileSaveAs(){

	// ���C���E�B���h�E�I�u�W�F�N�g�̎擾
	CMainWindow *pMainWindow = dynamic_cast<CMainWindow *>(CWindow::m_mapWindowMap[m_hWnd]);	// CWindow::m_mapWindowMap[m_hWnd]��pMainWindow���擾.(�r��dynamic_cast���Ă���.)
	if (pMainWindow != NULL) {	// �L���X�g����.
		if (pMainWindow->m_pEditBox != NULL) {	// �G�f�B�b�g�{�b�N�X�������ς݂̏ꍇ.
			
			// �I�u�W�F�N�g�̐錾
			CBinaryFile *pBinaryFile;	// �o�C�i���t�@�C���|�C���^CBinaryFile *�^pBinaryFile.
			int iMultiByteLen;	// �}���`�o�C�g�ɕϊ������Ƃ��̒���iMultiByteLen.
			char *pBuf;	// char *�^pBuf.

			// �G�f�B�b�g�{�b�N�X�̃e�L�X�g���擾.
			pMainWindow->m_pEditBox->GetWindowText();	// pMainWindow->m_pEditBox->GetWindowText�ŃG�f�B�b�g�{�b�N�X�̃e�L�X�g���擾.
			
			// �����R�[�h�ϊ�(���C�h��������}���`�o�C�g�����֕ϊ������Ƃ��ɕK�v�ȃo�b�t�@�T�C�Y�����߂�.)
			iMultiByteLen = WideCharToMultiByte(CP_ACP, 0, pMainWindow->m_pEditBox->m_ptszText, -1, NULL, 0, NULL, NULL);	// WideCharToMultiByte�ŕϊ���̃o�b�t�@�T�C�Y�����߂�.

			// �o�b�t�@���m��.
			pBuf = new char[iMultiByteLen];	// char�^�z��𐶐���, �|�C���^��pBuf�Ɋi�[.

			// �����R�[�h�ϊ�(���C�h��������}���`�o�C�g������.)
			WideCharToMultiByte(CP_ACP, 0, pMainWindow->m_pEditBox->m_ptszText, -1, pBuf, iMultiByteLen, NULL, NULL);	// WideCharToMultiByte�ŕϊ�����.

			// �e�L�X�g��"test1.txt"�ɕۑ�.
			pBinaryFile = new CBinaryFile();	// CBinaryFile�I�u�W�F�N�g���쐬��, �|�C���^��pBinaryFile�Ɋi�[.
			
			// "test1.txt"���J��.
			if (pBinaryFile->Open(_T("test1.txt"), GENERIC_WRITE, OPEN_ALWAYS)) {	// pBinaryFile->Open�Ńt�@�C�����J������.

				// "test1.txt"��pBuf(pMainWindow->m_pEditBox->m_ptszText�̓��e��ϊ���������.)����������.
				pBinaryFile->Write((BYTE *)pBuf, iMultiByteLen - 1);	// pBinaryFile->Write�ŏ�������.

				// ����.
				pBinaryFile->Close();	// pBinaryFile->Close�ŕ���.

			}
			
			// �o�b�t�@�����.
			delete[] pBuf;	//delete��pBuf�����.

			// �o�C�i���t�@�C���I�u�W�F�N�g�����.
			delete[] pBinaryFile;	// delete��pBinaryFile�����.

		}

	}

}