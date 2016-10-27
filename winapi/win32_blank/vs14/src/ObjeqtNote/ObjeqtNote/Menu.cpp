// �w�b�_�̃C���N���[�h
#include "Menu.h"	// ���j���[�N���X

// �R���X�g���N�^CMenu
CMenu::CMenu(HWND hWnd){
	// �����o�̏�����
	m_hWnd = hWnd;	// m_hWnd��hWnd���Z�b�g.
}

// �f�X�g���N�^~CMenu
CMenu::~CMenu() {

}

// ���j���[���[�h�֐�LoadMenu
BOOL CMenu::LoadMenu(UINT nIDResource){

	// �ϐ��̐錾
	HINSTANCE hInstance;	// �C���X�^���X�n���h��hInstance

	// �A�v���P�[�V�����C���X�^���X�n���h�����擾.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWL_HINSTANCE);	// GetWindowLong��hInstance�擾.

	// ���j���[�A�C�e��nIDResource�����[�h.
	m_hMenu = ::LoadMenu(hInstance, MAKEINTRESOURCE(nIDResource));	// LoadMenu��nIDResource�����[�h��, ���j���[�n���h����m_hMenu�Ɋi�[.
	if (m_hMenu == NULL) {	// NULL�Ȃ烍�[�h���s.

		// FALSE��Ԃ�.
		return FALSE;

	}

	// �����Ȃ�TRUE��Ԃ�.
	return TRUE;

}

// ���j���[�Z�b�g�֐�SetMenu
BOOL CMenu::SetMenu() {

	// ���j���[�̃Z�b�g.
	return ::SetMenu(m_hWnd, m_hMenu);	// SetMenu��m_hWnd��m_hMenu���Z�b�g��, �߂�l�����̂܂ܕԂ�.

}