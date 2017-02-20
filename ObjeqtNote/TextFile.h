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
		int Read(TCHAR **ppText, EncodeType eEncodeType);	// �t�@�C����ǂݍ��ރ����o�֐�Read.(ppText�͕ϊ����UNICODE�o�b�t�@�|�C���^�̃|�C���^.eEncodeType�ŕ����R�[�h�w��.)
		int Encode(BYTE **ppBuf, LPCTSTR lpctszText, EncodeType eEncodeType);	// �w��̕����R�[�h�̃o�C�g��ɕϊ�����֐�Encode.(�o�b�t�@��������ppBuf�̎w���o�b�t�@�ɓ����Ŋ��蓖�Ă�.)
		int Decode(TCHAR **ppText, BYTE *pBuf, EncodeType eEncodeType);	// �w��̕����R�[�h�o�C�g�񂩂�UNICODE�ɕϊ�����֐�Decode.(UNICODE�o�b�t�@��������ppText�̎w���o�b�t�@�ɓ����Ŋ��蓖�Ă�.)

};