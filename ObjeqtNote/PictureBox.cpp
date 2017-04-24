// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "PictureBox.h"	// �s�N�`���[�{�b�N�X�N���X

// �R���X�g���N�^CPictureBox()
CPictureBox::CPictureBox() {

	// ������
	m_hBitmap = NULL;		// m_hBitmap��NULL���Z�b�g.
	m_hMemDC = NULL;		// m_hMemDC��NULL���Z�b�g.
	m_iPictureWidth = 0;	// m_iPictureWidth��0���Z�b�g.
	m_iPictureHeight = 0;	// m_iPictureHeight��0���Z�b�g.

}

// �f�X�g���N�^~CPictureBox()
CPictureBox::~CPictureBox() {

	// �I������
	m_iPictureHeight = 0;	// m_iPictureHeight��0���Z�b�g.
	m_iPictureWidth = 0;	// m_iPictureWidth��0���Z�b�g.
	if (m_hMemDC != NULL) {
		DeleteDC(m_hMemDC);			// DelteDC��m_hMemDC���폜.
		m_hMemDC = NULL;			// m_hMemDC��NULL���Z�b�g.
	}
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

	// ���ƍ����������o�ɃZ�b�g.
	m_iPictureWidth = iWidth;	// m_iPictureWidth��iWidth���Z�b�g.
	m_iPictureHeight = iHeight;	// m_iPictureHeight��iHeight���Z�b�g.

	// �C���X�^���X�n���h���̎擾.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWLP_HINSTANCE);	// GetWindowLong�ŃC���X�^���X�n���h�����擾.

	// �摜�̃��[�h.(�ЂƂ܂��r�b�g�}�b�v�̂�.)
	m_hBitmap = (HBITMAP)LoadImage(hInstance, lpctszFileName, IMAGE_BITMAP, m_iPictureWidth, m_iPictureHeight, LR_LOADFROMFILE);	// LoadImage�Ńr�b�g�}�b�v�����[�h.
	if (m_hBitmap == NULL) {	// NULL�Ȃ�.

		// ���s.
		return FALSE;	// ���s�Ȃ̂�FALSE��Ԃ�.

	}

	// ����.
	return TRUE;	// �����Ȃ̂�TRUE��Ԃ�.

}

// �摜���Z�b�g(�\��)����֐�SetImage.
void CPictureBox::SetImage() {

	// �ϐ��̐錾
	HDC hDC;	// �f�o�C�X�R���e�L�X�g�n���h��HDC�^hDC.

	// �f�o�C�X�R���e�L�X�g�̎擾.
	hDC = GetDC(m_hWnd);	// GetDC�Ńf�o�C�X�R���e�L�X�g���擾.

	// �������f�o�C�X�R���e�L�X�g�̍쐬.
	m_hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDC�Ń������f�o�C�X�R���e�L�X�g�쐬.

	// �摜���Z�b�g����.
	SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_hBitmap);	// SendMessage��STM_SETIMAGE�𑗐M���邱�Ƃ�m_hBitmap���Z�b�g����.

	// �f�o�C�X�R���e�L�X�g�̉��.
	ReleaseDC(m_hWnd, hDC);	// ReleaseDC�Ńf�o�C�X�R���e�L�X�g���.

}

// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
void CPictureBox::OnPaint() {

	// �ϐ��̐錾
	HDC hDC;			// �f�o�C�X�R���e�L�X�g�n���h��HDC�^hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT�\���̕ϐ�ps.
	HBITMAP hOld;		// �ȑO�̃r�b�g�}�b�v�n���h��hOld.
	int iDrawWidth;		// ���ۂ̕`�敝.
	int iDrawHeight;	// ���ۂ̕`�捂��.

	// �`��J�n.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaint�ŕ`��J�n.

	// �r�b�g�}�b�v�̑I��.
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObject��m_hBitmap��I��.

	// �r�b�g�]���ɂ��`��.
	iDrawWidth = m_iWidth - SCROLLBAR_THICKNESS;	// ���ۂɂ̓R���g���[���� - �X�N���[���o�[�̌���.
	iDrawHeight = m_iHeight - SCROLLBAR_THICKNESS;	// ���ۂɂ̓R���g���[������ - �X�N���[���o�[�̌���.
	BitBlt(hDC, 0, 0, iDrawWidth, iDrawHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBlt��m_hMemDC����hDC�Ƀr�b�g�]�����邱�Ƃŕ`�悳���.

	// �Â��r�b�g�}�b�v���đI�����Ė߂�.
	SelectObject(m_hMemDC, hOld);	// SelectObject��hOld��I��.

	// �`��I��.
	EndPaint(m_hWnd, &ps);	// EndPaint�ŕ`��I��.

}