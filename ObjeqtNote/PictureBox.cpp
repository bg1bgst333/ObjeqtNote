// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "PictureBox.h"	// �s�N�`���[�{�b�N�X�N���X

// �R���X�g���N�^CPictureBox()
CPictureBox::CPictureBox() {

	// ������
	m_hBitmap = NULL;	// m_hBitmap��NULL���Z�b�g.

}

// �f�X�g���N�^~CPictureBox()
CPictureBox::~CPictureBox() {

	// �I������
	if (m_hBitmap != NULL) {
		DeleteObject(m_hBitmap);	// DeleteObject��m_hBitmap���폜.
		m_hBitmap = NULL;			// m_hBitmap��NULL���Z�b�g.
	}

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CPictureBox::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�̍쐬.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ŃE�B���h�E���쐬��, ���̖߂�l��return�ŕԂ�.

}

// �摜�����[�h����֐�Load.
BOOL CPictureBox::Load(LPCTSTR lpctszFileName, int iWidth, int iHeight) {

	// �ϐ��̐錾.
	HINSTANCE hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h��hInstance.

	// �C���X�^���X�n���h���̎擾.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWLP_HINSTANCE);	// GetWindowLong�ŃC���X�^���X�n���h�����擾.

	// �摜�̃��[�h.(�ЂƂ܂��r�b�g�}�b�v�̂�.)
	m_hBitmap = (HBITMAP)LoadImage(hInstance, lpctszFileName, IMAGE_BITMAP, iWidth, iHeight, LR_LOADFROMFILE);	// LoadImage�Ńr�b�g�}�b�v�����[�h.
	if (m_hBitmap == NULL) {	// NULL�Ȃ�.

		// ���s.
		return FALSE;	// ���s�Ȃ̂�FALSE��Ԃ�.

	}

	// ����.
	return TRUE;	// �����Ȃ̂�TRUE��Ԃ�.

}

// �摜���Z�b�g(�\��)����֐�SetImage.
void CPictureBox::SetImage() {

	// �摜���Z�b�g����.
	SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_hBitmap);	// SendMessage��STM_SETIMAGE�𑗐M���邱�Ƃ�m_hBitmap���Z�b�g����.

}