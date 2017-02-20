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
	iMultiByteLen = Encode(&m_pByte, lpctszText, eEncodeType);	// Encode��eEncodeType�ȃo�C�g��ɕϊ�.

	// ��������
	return CBinaryFile::Write(m_pByte, iMultiByteLen - 1);	// CBinaryFile::Write��m_pByte����������.

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