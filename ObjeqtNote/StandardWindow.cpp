// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "StandardWindow.h"	// �X�^���_�[�h�E�B���h�E�N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)
BOOL CStandardWindow::RegisterClass(HINSTANCE hInstance, UINT nID) {

	// �E�B���h�E�N���X�̓o�^
	return CWindow::RegisterClass(hInstance, _T("StandardWindow"), nID);	// CWindow::RegisterClass(���j���[�w��)�ŃE�B���h�E�N���X"StandardWindow"��o�^.

}

// �R���X�g���N�^CStandardWindow()
CStandardWindow::CStandardWindow() : CMenuWindow() {

	// �����o�̏�����.
	m_pMenuBar = NULL;	// m_pMenuBar��NULL�ŏ�����.

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CStandardWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �����ɗ���ꍇ�̓E�B���h�E�N���X"StandardWindow"�̃E�B���h�E�Ƃ��č쐬.
	return CWindow::Create(_T("StandardWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��"StandardWindow"�ɂ���Create�̃t���o�[�W�������Ă�.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CStandardWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ���j���[�o�[�̍쐬.(�E�B���h�E�N���X�o�^����ID���w�肵���ꍇ.)
	m_pMenuBar = new CMenuBar();	// CMenuBar�I�u�W�F�N�g���쐬��, �|�C���^��m_pMenuBar�Ɋi�[.

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ̂�0��Ԃ�.

}