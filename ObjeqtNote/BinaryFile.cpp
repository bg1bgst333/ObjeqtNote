// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BinaryFile.h"	// �o�C�i���t�@�C���N���X

// �R���X�g���N�^CBinaryFile()
CBinaryFile::CBinaryFile(){

	// �����o�ϐ��̏�����
	m_hFile = NULL;	// m_hFile��NULL�ŏ�����.
	m_pByte = NULL;	// m_pByte��NULL�ŏ�����.
	ZeroMemory(m_tszFileName, sizeof(TCHAR) * 1024);	// ZeroMemory��m_tszFileName��0�Ŗ��߂�.

}

// �f�X�g���N�^~CBinaryFile()
CBinaryFile::~CBinaryFile(){

	// �����o�ϐ��̏I������
	if (m_pByte != NULL) {	// NULL�łȂ����.
		delete[] m_pByte;	// delete��m_pByte�����.
	}
	if (m_hFile != NULL) {	// NULL�łȂ����.
		Close();	// ����.
	}

}

// �t�@�C���̍쐬����уt�@�C�����J��������s�������o�֐�Open.
BOOL CBinaryFile::Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition){

	// �t�@�C�����������o�ɃZ�b�g.
	_tcscpy_s(m_tszFileName, 1024, lpctszFileName);	// _tcscpy_s�ň����������o�ɃR�s�[.(��2������WORD�P�ʂł̃T�C�Y.)

	// �t�@�C�����J��.
	m_hFile = CreateFile(m_tszFileName, dwDesiredAccess, 0, NULL, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile�Ńt�@�C��m_tszFileName���J��.
	if (m_hFile == INVALID_HANDLE_VALUE) {	// ���s.
		return FALSE;	// FALSE��Ԃ�.
	}

	// ����
	return TRUE;	// TRUE��Ԃ�.

}

// �t�@�C������郁���o�֐�Close.
void CBinaryFile::Close(){

	// �t�@�C�������.
	CloseHandle(m_hFile);	// CloseHandle��m_hFile�����.
	m_hFile = NULL;	// NULL���Z�b�g.

}
// �t�@�C�����������ރ����o�֐�Write.(pBytes�͊O���Ńo�b�t�@�������Ă���ꍇ�̏������ݑΏۃo�C�g��.)
BOOL CBinaryFile::Write(BYTE * pBytes, UINT nCount){

	// �ϐ��̏�����
	DWORD dwBytes = 0;	// DWORD�^dwBytes��0�ŏ�����.

	// pBytes����������.
	return WriteFile(m_hFile, pBytes, nCount, &dwBytes, NULL);	// WriteFile��pBytes�̓��e����������.

}
