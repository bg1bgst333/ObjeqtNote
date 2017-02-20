// 独自のヘッダ
#include "TextFile.h"	// テキストファイルクラス

// コンストラクタCTextFile()
CTextFile::CTextFile() : CBinaryFile() {

}

// デストラクタ~CTextFile()
CTextFile::~CTextFile(){

}

// ファイルを書き込むメンバ関数Write.(lpctszTextは変換前のUNICODE文字列.eEncodeTypeで文字コード指定.)
BOOL CTextFile::Write(LPCTSTR lpctszText, EncodeType eEncodeType){

	// 変数の宣言
	int iMultiByteLen;	// マルチバイトに変換したときの長さiMultiByteLen.

	// 文字コード変換.
	iMultiByteLen = Encode(&m_pByte, lpctszText, eEncodeType);	// Encodeでワイド文字からeEncodeTypeなバイト列に変換.

	// 書き込み
	return CBinaryFile::Write(m_pByte, iMultiByteLen - 1);	// CBinaryFile::Writeでm_pByteを書き込み.

}

// ファイルを読み込むメンバ関数Read.(lpctszTextは変換後のUNICODEバッファ.eEncodeTypeで文字コード指定.)
BOOL CTextFile::Read(TCHAR **ppText, EncodeType eEncodeType){

	// 変数の宣言・初期化
	DWORD dwFileSize;		// ファイルサイズdwFileSize.
	DWORD dwFileSizeHigh;	// ファイルサイズの上位ワードdwFileSizeHigh.
	BOOL bRet = FALSE;		// bRetをFALSEに初期化.

	// ファイルサイズの取得.
	dwFileSize = GetFileSize(&dwFileSizeHigh);	// GetFileSizeでファイルサイズを取得.
	
	// バッファの作成.
	m_pByte = new BYTE[dwFileSize + 1];	// dwFileSize + 1のバッファを作成し, ポインタをm_pByteに格納.

	// 読み込み
	bRet = CBinaryFile::Read(m_pByte, dwFileSize);	// CBinaryFile::Readでm_pByteを読み込み.
	if (!bRet) {
		delete[] m_pByte;	// m_pByteを解放.
		m_pByte = NULL;	// NULLで埋める.
		return 0;	// 0を返す.
	}
	m_pByte[dwFileSize] = '\0';	// NULL終端.

	// 文字コード変換
	return Decode(ppText, m_pByte, eEncodeType);	// DecodeでeEncodeTypeなバイト列からワイド文字に変換.

}

// 指定の文字コードのバイト列に変換する関数Encode.(バッファメモリはppBufの指すバッファに内部で割り当てる.)
int CTextFile::Encode(BYTE ** ppBuf, LPCTSTR lpctszText, EncodeType eEncodeType){

	// 変数の宣言
	int iMultiByteLen;	// マルチバイトに変換したときの長さiMultiByteLen.

	// Shift_JIS
	if (eEncodeType == EncodeType::SHIFT_JIS) {	// Shift_JISの場合.

		// 文字コード変換(ワイド文字からマルチバイト文字へ変換したときに必要なバッファサイズを求める.)
		iMultiByteLen = WideCharToMultiByte(CP_ACP, 0, lpctszText, -1, NULL, 0, NULL, NULL);	// WideCharToMultiByteで変換後のバッファサイズを求める.

		// バッファを確保.
		*ppBuf = new BYTE[iMultiByteLen];	// BYTE型配列を生成し, ポインタを*ppBufに格納.

		// 文字コード変換(ワイド文字からマルチバイト文字へ.)
		iMultiByteLen = WideCharToMultiByte(CP_ACP, 0, lpctszText, -1, (char *)*ppBuf, iMultiByteLen, NULL, NULL);	// WideCharToMultiByteで変換する.

	}

	// iMultiByteLenを返す.
	return iMultiByteLen;

}

// 指定の文字コードバイト列からUNICODEに変換する関数Decode.(UNICODEバッファメモリはppTextの指すバッファに内部で割り当てる.)
int CTextFile::Decode(TCHAR ** ppText, BYTE * pBuf, EncodeType eEncodeType){

	// 変数の宣言
	int iWideCharLen;	// ワイド文字に変換した時の長さiWideCharLen.

	// Shift_JIS
	if (eEncodeType == EncodeType::SHIFT_JIS) {	// Shift_JISの場合.

		// 文字コード変換(マルチバイト文字からワイド文字へ変換した時に必要なバッファサイズを求める.)
		iWideCharLen = MultiByteToWideChar(CP_ACP, 0, (char *)pBuf, -1, NULL, 0);	//  MultiByteToWideCharで変換後のバッファサイズを求める.

		// バッファを確保.
		*ppText = new TCHAR[iWideCharLen];	// TCHAR型配列を生成し, ポインタを*ppTextに格納.

		// 文字コード変換(マルチバイトからワイド文字へ.)
		iWideCharLen = MultiByteToWideChar(CP_ACP, 0, (char *)pBuf, -1, (TCHAR *)*ppText, iWideCharLen);	// MultiByteToWideCharで変換する.

	}

	// 長さを返す.
	return iWideCharLen - 1;	// NULL文字の分は引いて返す.

}