// ヘッダのインクルード
// 独自のヘッダ
#include "BinaryFile.h"	// バイナリファイルクラス

// コンストラクタCBinaryFile()
CBinaryFile::CBinaryFile(){

	// メンバ変数の初期化
	m_hFile = NULL;	// m_hFileをNULLで初期化.
	m_pByte = NULL;	// m_pByteをNULLで初期化.
	ZeroMemory(m_tszFileName, sizeof(TCHAR) * 1024);	// ZeroMemoryでm_tszFileNameを0で埋める.

}

// デストラクタ~CBinaryFile()
CBinaryFile::~CBinaryFile(){

	// メンバ変数の終了処理
	if (m_pByte != NULL) {	// NULLでなければ.
		delete[] m_pByte;	// deleteでm_pByteを解放.
	}
	if (m_hFile != NULL) {	// NULLでなければ.
		Close();	// 閉じる.
	}

}

// ファイルの作成およびファイルを開く操作を行うメンバ関数Open.
BOOL CBinaryFile::Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition){

	// ファイル名をメンバにセット.
	_tcscpy_s(m_tszFileName, 1024, lpctszFileName);	// _tcscpy_sで引数をメンバにコピー.(第2引数はWORD単位でのサイズ.)

	// ファイルを開く.
	m_hFile = CreateFile(m_tszFileName, dwDesiredAccess, 0, NULL, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileでファイルm_tszFileNameを開く.
	if (m_hFile == INVALID_HANDLE_VALUE) {	// 失敗.
		return FALSE;	// FALSEを返す.
	}

	// 成功
	return TRUE;	// TRUEを返す.

}

// ファイルを閉じるメンバ関数Close.
void CBinaryFile::Close(){

	// ファイルを閉じる.
	CloseHandle(m_hFile);	// CloseHandleでm_hFileを閉じる.
	m_hFile = NULL;	// NULLをセット.

}
// ファイルを書き込むメンバ関数Write.(pBytesは外部でバッファを持っている場合の書き込み対象バイト列.)
BOOL CBinaryFile::Write(BYTE * pBytes, UINT nCount){

	// 変数の初期化
	DWORD dwBytes = 0;	// DWORD型dwBytesを0で初期化.

	// pBytesを書き込む.
	return WriteFile(m_hFile, pBytes, nCount, &dwBytes, NULL);	// WriteFileでpBytesの内容を書き込む.

}
