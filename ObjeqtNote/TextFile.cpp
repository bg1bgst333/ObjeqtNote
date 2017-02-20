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
	iMultiByteLen = Encode(&m_pByte, lpctszText, eEncodeType);	// EncodeでeEncodeTypeなバイト列に変換.

	// 書き込み
	return CBinaryFile::Write(m_pByte, iMultiByteLen - 1);	// CBinaryFile::Writeでm_pByteを書き込み.

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