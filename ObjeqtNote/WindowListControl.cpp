// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WindowListControl.h"	// �E�B���h�E���X�g�R���g���[���N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CWindowListControl::RegisterClass(HINSTANCE hInstance) {

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("WindowListControl"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"WindowListControl"��o�^.

}

// �R���X�g���N�^CWindowListControl()
CWindowListControl::CWindowListControl() : CUserControl() {

}

// �f�X�g���N�^~CWindowListControl()
CWindowListControl::~CWindowListControl() {

}

// �E�B���h�E�쐬�֐�Create
BOOL CWindowListControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	return CUserControl::Create(_T("WindowListControl"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"WindowListControl"�ȃE�B���h�E���쐬.

}