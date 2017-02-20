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

};