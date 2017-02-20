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

	// 文字コードごとに振り分ける.
	if (eEncodeType == EncodeType::SHIFT_JIS) {	// SHIFT_JISの場合.

		// 変数の宣言
		int iMultiByteLen;	// マルチバイトに変換したときの長さiMultiByteLen.

		// 文字コード変換(ワイド文字からマルチバイト文字へ変換したときに必要なバッファサイズを求める.)
		iMultiByteLen = WideCharToMultiByte(CP_ACP, 0, lpctszText, -1, NULL, 0, NULL, NULL);	// WideCharToMultiByteで変換後のバッファサイズを求める.

		// バッファを確保.
		m_pByte = new BYTE[iMultiByteLen];	// BYTE型配列を生成し, ポインタをm_pByteに格納.

		// 文字コード変換(ワイド文字からマルチバイト文字へ.)
		WideCharToMultiByte(CP_ACP, 0, lpctszText, -1, (char *)m_pByte, iMultiByteLen, NULL, NULL);	// WideCharToMultiByteで変換する.

		// 書き込み
		return CBinaryFile::Write(m_pByte, iMultiByteLen - 1);	// CBinaryFile::Writeでm_pByteを書き込み.

	}

	// どれにも当てはまらない場合は失敗.
	return FALSE;	// FALSEを返す.

}