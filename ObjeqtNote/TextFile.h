// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "BinaryFile.h"	// バイナリファイルクラス

// テキストファイルクラスCTextFile
class CTextFile : public CBinaryFile {

	// publicメンバ
	public:

		// publicメンバ変数
		// 列挙型の定義.
		enum EncodeType {
			SHIFT_JIS,
			UTF_16LE
		};
		// 列挙型メンバ変数の宣言.
		enum EncodeType m_eEncodeType;	// EncodeType列挙型m_eEncodeType.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CTextFile();	// コンストラクタCTextFile()
		virtual ~CTextFile();	// デストラクタ~CTextFile()

		// メンバ関数
		BOOL Write(LPCTSTR lpctszText, EncodeType eEncodeType);	// ファイルを書き込むメンバ関数Write.(lpctszTextは変換前のUNICODE文字列.eEncodeTypeで文字コード指定.)
		int Read(TCHAR **ppText, EncodeType eEncodeType);	// ファイルを読み込むメンバ関数Read.(ppTextは変換後のUNICODEバッファポインタのポインタ.eEncodeTypeで文字コード指定.)
		int Encode(BYTE **ppBuf, LPCTSTR lpctszText, EncodeType eEncodeType);	// 指定の文字コードのバイト列に変換する関数Encode.(バッファメモリはppBufの指すバッファに内部で割り当てる.)
		int Decode(TCHAR **ppText, BYTE *pBuf, EncodeType eEncodeType);	// 指定の文字コードバイト列からUNICODEに変換する関数Decode.(UNICODEバッファメモリはppTextの指すバッファに内部で割り当てる.)

};