// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �}�N���̒�`
#define FITLER_DELIMITER _T("|")
#define FITLER_DELIMITER_CHAR _T('|')
#define FILTER_END  _T("||")
#define FILTER_TEXT_BIN_FILE _T("�o�C�i���t�@�C��(*.bin)")
#define FILTER_RULE_BIN_FILE _T("*.bin")
#define FILTER_TEXT_ALL_FILE _T("���ׂẴt�@�C��(*.*)")
#define FILTER_RULE_ALL_FILE _T("*.*")

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
		BOOL GetSaveFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd);	// "���O��t���ĕۑ�"�̃t�@�C���_�C�A���O��\����, �I�����ꂽ�t�@�C�������擾���郁���o�֐�GetSaveFileName.

};