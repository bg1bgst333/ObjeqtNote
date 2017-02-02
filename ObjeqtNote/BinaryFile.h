// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �o�C�i���t�@�C���N���XCBinaryFile
class CBinaryFile {

	// public�����o
	public:

		// public�����o�ϐ�
		TCHAR m_tszFileName[1024];	// �t�@�C����TCHAR�^�z��m_tszFileName
		HANDLE m_hFile;	// �t�@�C���n���h��HANDLE�^m_hFile
		BYTE *m_pByte;	// �o�C�i���f�[�^�ւ̃|�C���^BYTE *�^m_pByte

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CBinaryFile();	// �R���X�g���N�^CBinaryFile()
		virtual ~CBinaryFile();	// �f�X�g���N�^~CBinaryFile()

		// �����o�֐�
		BOOL Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition);	// �t�@�C���̍쐬����уt�@�C�����J��������s�������o�֐�Open.
		void Close();	// �t�@�C������郁���o�֐�Close.
		BOOL Write(BYTE *pBytes, UINT nCount);	// �t�@�C�����������ރ����o�֐�Write.(pBytes�͊O���Ńo�b�t�@�������Ă���ꍇ�̏������ݑΏۃo�C�g��.)

};