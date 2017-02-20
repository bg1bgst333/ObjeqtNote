// �Ǝ��̃w�b�_
#include "TextFile.h"	// �e�L�X�g�t�@�C���N���X

// �R���X�g���N�^CTextFile()
CTextFile::CTextFile() : CBinaryFile() {

}

// �f�X�g���N�^~CTextFile()
CTextFile::~CTextFile(){

}

// �t�@�C�����������ރ����o�֐�Write.(lpctszText�͕ϊ��O��UNICODE������.eEncodeType�ŕ����R�[�h�w��.)
BOOL CTextFile::Write(LPCTSTR lpctszText, EncodeType eEncodeType){

	// �ϐ��̐錾
	int iMultiByteLen;	// �}���`�o�C�g�ɕϊ������Ƃ��̒���iMultiByteLen.

	// �����R�[�h�ϊ�.
	iMultiByteLen = Encode(&m_pByte, lpctszText, eEncodeType);	// Encode�Ń��C�h��������eEncodeType�ȃo�C�g��ɕϊ�.

	// ��������
	return CBinaryFile::Write(m_pByte, iMultiByteLen - 1);	// CBinaryFile::Write��m_pByte����������.

}

// �t�@�C����ǂݍ��ރ����o�֐�Read.(lpctszText�͕ϊ����UNICODE�o�b�t�@.eEncodeType�ŕ����R�[�h�w��.)
BOOL CTextFile::Read(TCHAR **ppText, EncodeType eEncodeType){

	// �ϐ��̐錾�E������
	DWORD dwFileSize;		// �t�@�C���T�C�YdwFileSize.
	DWORD dwFileSizeHigh;	// �t�@�C���T�C�Y�̏�ʃ��[�hdwFileSizeHigh.
	BOOL bRet = FALSE;		// bRet��FALSE�ɏ�����.

	// �t�@�C���T�C�Y�̎擾.
	dwFileSize = GetFileSize(&dwFileSizeHigh);	// GetFileSize�Ńt�@�C���T�C�Y���擾.
	
	// �o�b�t�@�̍쐬.
	m_pByte = new BYTE[dwFileSize + 1];	// dwFileSize + 1�̃o�b�t�@���쐬��, �|�C���^��m_pByte�Ɋi�[.

	// �ǂݍ���
	bRet = CBinaryFile::Read(m_pByte, dwFileSize);	// CBinaryFile::Read��m_pByte��ǂݍ���.
	if (!bRet) {
		delete[] m_pByte;	// m_pByte�����.
		m_pByte = NULL;	// NULL�Ŗ��߂�.
		return 0;	// 0��Ԃ�.
	}
	m_pByte[dwFileSize] = '\0';	// NULL�I�[.

	// �����R�[�h�ϊ�
	return Decode(ppText, m_pByte, eEncodeType);	// Decode��eEncodeType�ȃo�C�g�񂩂烏�C�h�����ɕϊ�.

}

// �w��̕����R�[�h�̃o�C�g��ɕϊ�����֐�Encode.(�o�b�t�@��������ppBuf�̎w���o�b�t�@�ɓ����Ŋ��蓖�Ă�.)
int CTextFile::Encode(BYTE ** ppBuf, LPCTSTR lpctszText, EncodeType eEncodeType){

	// �ϐ��̐錾
	int iMultiByteLen;	// �}���`�o�C�g�ɕϊ������Ƃ��̒���iMultiByteLen.

	// Shift_JIS
	if (eEncodeType == EncodeType::SHIFT_JIS) {	// Shift_JIS�̏ꍇ.

		// �����R�[�h�ϊ�(���C�h��������}���`�o�C�g�����֕ϊ������Ƃ��ɕK�v�ȃo�b�t�@�T�C�Y�����߂�.)
		iMultiByteLen = WideCharToMultiByte(CP_ACP, 0, lpctszText, -1, NULL, 0, NULL, NULL);	// WideCharToMultiByte�ŕϊ���̃o�b�t�@�T�C�Y�����߂�.

		// �o�b�t�@���m��.
		*ppBuf = new BYTE[iMultiByteLen];	// BYTE�^�z��𐶐���, �|�C���^��*ppBuf�Ɋi�[.

		// �����R�[�h�ϊ�(���C�h��������}���`�o�C�g������.)
		iMultiByteLen = WideCharToMultiByte(CP_ACP, 0, lpctszText, -1, (char *)*ppBuf, iMultiByteLen, NULL, NULL);	// WideCharToMultiByte�ŕϊ�����.

	}

	// iMultiByteLen��Ԃ�.
	return iMultiByteLen;

}

// �w��̕����R�[�h�o�C�g�񂩂�UNICODE�ɕϊ�����֐�Decode.(UNICODE�o�b�t�@��������ppText�̎w���o�b�t�@�ɓ����Ŋ��蓖�Ă�.)
int CTextFile::Decode(TCHAR ** ppText, BYTE * pBuf, EncodeType eEncodeType){

	// �ϐ��̐錾
	int iWideCharLen;	// ���C�h�����ɕϊ��������̒���iWideCharLen.

	// Shift_JIS
	if (eEncodeType == EncodeType::SHIFT_JIS) {	// Shift_JIS�̏ꍇ.

		// �����R�[�h�ϊ�(�}���`�o�C�g�������烏�C�h�����֕ϊ��������ɕK�v�ȃo�b�t�@�T�C�Y�����߂�.)
		iWideCharLen = MultiByteToWideChar(CP_ACP, 0, (char *)pBuf, -1, NULL, 0);	//  MultiByteToWideChar�ŕϊ���̃o�b�t�@�T�C�Y�����߂�.

		// �o�b�t�@���m��.
		*ppText = new TCHAR[iWideCharLen];	// TCHAR�^�z��𐶐���, �|�C���^��*ppText�Ɋi�[.

		// �����R�[�h�ϊ�(�}���`�o�C�g���烏�C�h������.)
		iWideCharLen = MultiByteToWideChar(CP_ACP, 0, (char *)pBuf, -1, (TCHAR *)*ppText, iWideCharLen);	// MultiByteToWideChar�ŕϊ�����.

	}

	// ������Ԃ�.
	return iWideCharLen - 1;	// NULL�����̕��͈����ĕԂ�.

}