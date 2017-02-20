// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// マクロの定義
#define FITLER_DELIMITER _T("|")
#define FITLER_DELIMITER_CHAR _T('|')
#define FILTER_END  _T("||")
#define FILTER_TEXT_BIN_FILE _T("バイナリファイル(*.bin)")
#define FILTER_RULE_BIN_FILE _T("*.bin")
#define FILTER_TEXT_ALL_FILE _T("すべてのファイル(*.*)")
#define FILTER_RULE_ALL_FILE _T("*.*")

// バイナリファイルクラスCBinaryFile
class CBinaryFile {

	// publicメンバ
	public:

		// publicメンバ変数
		TCHAR m_tszFileName[1024];	// ファイル名TCHAR型配列m_tszFileName
		HANDLE m_hFile;	// ファイルハンドルHANDLE型m_hFile
		BYTE *m_pByte;	// バイナリデータへのポインタBYTE *型m_pByte

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CBinaryFile();	// コンストラクタCBinaryFile()
		virtual ~CBinaryFile();	// デストラクタ~CBinaryFile()

		// メンバ関数
		BOOL Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition);	// ファイルの作成およびファイルを開く操作を行うメンバ関数Open.
		void Close();	// ファイルを閉じるメンバ関数Close.
		BOOL Write(BYTE *pBytes, UINT nCount);	// ファイルを書き込むメンバ関数Write.(pBytesは外部でバッファを持っている場合の書き込み対象バイト列.)
		BOOL GetSaveFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd);	// "名前を付けて保存"のファイルダイアログを表示し, 選択されたファイル名を取得するメンバ関数GetSaveFileName.

};