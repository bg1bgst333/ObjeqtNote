// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "BinaryFile.h"	// �o�C�i���t�@�C���N���X

// �e�L�X�g�t�@�C���N���XCTextFile
class CTextFile : public CBinaryFile {

	// public�����o
	public:

		// public�����o�ϐ�
		// �񋓌^�̒�`.
		enum EncodeType {
			SHIFT_JIS,
			UTF_16LE
		};
		// �񋓌^�����o�ϐ��̐錾.
		enum EncodeType m_eEncodeType;	// EncodeType�񋓌^m_eEncodeType.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CTextFile();	// �R���X�g���N�^CTextFile()
		virtual ~CTextFile();	// �f�X�g���N�^~CTextFile()

		// �����o�֐�
		BOOL Write(LPCTSTR lpctszText, EncodeType eEncodeType);	// �t�@�C�����������ރ����o�֐�Write.(lpctszText�͕ϊ��O��UNICODE������.eEncodeType�ŕ����R�[�h�w��.)

};