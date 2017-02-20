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

	// �����R�[�h���ƂɐU�蕪����.
	if (eEncodeType == EncodeType::SHIFT_JIS) {	// SHIFT_JIS�̏ꍇ.

		// �ϐ��̐錾
		int iMultiByteLen;	// �}���`�o�C�g�ɕϊ������Ƃ��̒���iMultiByteLen.

		// �����R�[�h�ϊ�(���C�h��������}���`�o�C�g�����֕ϊ������Ƃ��ɕK�v�ȃo�b�t�@�T�C�Y�����߂�.)
		iMultiByteLen = WideCharToMultiByte(CP_ACP, 0, lpctszText, -1, NULL, 0, NULL, NULL);	// WideCharToMultiByte�ŕϊ���̃o�b�t�@�T�C�Y�����߂�.

		// �o�b�t�@���m��.
		m_pByte = new BYTE[iMultiByteLen];	// BYTE�^�z��𐶐���, �|�C���^��m_pByte�Ɋi�[.

		// �����R�[�h�ϊ�(���C�h��������}���`�o�C�g������.)
		WideCharToMultiByte(CP_ACP, 0, lpctszText, -1, (char *)m_pByte, iMultiByteLen, NULL, NULL);	// WideCharToMultiByte�ŕϊ�����.

		// ��������
		return CBinaryFile::Write(m_pByte, iMultiByteLen - 1);	// CBinaryFile::Write��m_pByte����������.

	}

	// �ǂ�ɂ����Ă͂܂�Ȃ��ꍇ�͎��s.
	return FALSE;	// FALSE��Ԃ�.

}