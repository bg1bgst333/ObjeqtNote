// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MenuWindow.h"	// ���j���[�E�B���h�E�N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)
BOOL CMenuWindow::RegisterClass(HINSTANCE hInstance, UINT nID){

	// �E�B���h�E�N���X�̓o�^
	return CWindow::RegisterClass(hInstance, _T("MenuWindow"), nID);	// CWindow::RegisterClass(���j���[�w��)�ŃE�B���h�E�N���X"MenuWindow"��o�^.

}

// �R���X�g���N�^CMenuWindow()
CMenuWindow::CMenuWindow() : CBasicWindow(){

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CMenuWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �����ɗ���ꍇ�̓E�B���h�E�N���X"MenuWindow"�̃E�B���h�E�Ƃ��č쐬.
	return CWindow::Create(_T("MenuWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��"MenuWindow"�ɂ���Create�̃t���o�[�W�������Ă�.

}