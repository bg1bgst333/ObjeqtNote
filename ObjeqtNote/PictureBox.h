// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "CustomControl.h"	// �J�X�^���R���g���[���N���X

// �s�N�`���[�{�b�N�X�N���XCPictureBox
class CPictureBox : public CCustomControl {

	// public�����o
	public:

		// �����o�ϐ�
		HBITMAP m_hBitmap;	// ���[�h����r�b�g�}�b�v�̃n���h��HBITMAP�^m_hBitmap.

		// �R���X�g���N�^�E�f�X�g���N�^
		CPictureBox();	// �R���X�g���N�^CPictureBox()
		virtual ~CPictureBox();	// �f�X�g���N�^~CPictureBox()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual BOOL Load(LPCTSTR lpctszFileName, int iWidth, int iHeight);	// �摜�����[�h����֐�Load.
		virtual void SetImage();	// �摜���Z�b�g(�\��)����֐�SetImage.

};