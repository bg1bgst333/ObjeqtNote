// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "StandardWindow.h"		// �X�^���_�[�h�E�B���h�E�N���X
#include "EditBox.h"			// �G�f�B�b�g�{�b�N�X�N���X
#include "PictureBox.h"			// �s�N�`���[�{�b�N�X�N���X
#include "UserControl.h"		// ���[�U�R���g���[���N���X
#include "WindowListControl.h"	// �E�B���h�E���X�g�R���g���[���N���X
#include "resource.h"			// ���\�[�X

// ���C���E�B���h�E�N���XCMainWindow
class CMainWindow : public CStandardWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		CUserControl *m_pUserControl;				// CUserControl *�^���[�U�R���g���[���I�u�W�F�N�g�|�C���^m_pUserControl
		CEditBox *m_pEditBox;						// CEditBox *�^�G�f�B�b�g�{�b�N�X�I�u�W�F�N�g�|�C���^m_pEditBox
		CPictureBox *m_pPictureBox;					// CPictureBox *�^�s�N�`���[�{�b�N�X�I�u�W�F�N�g�|�C���^m_pPictureBox
		CWindowListControl *m_pWindowListControl;	// CWindowListControl *�^�E�B���h�E���X�g�R���g���[���I�u�W�F�N�g�|�C���^m_pWindowListControl

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)

		// �R���X�g���N�^�E�f�X�g���N�^
		CMainWindow();			// �R���X�g���N�^CMainWindow()
		virtual ~CMainWindow();	// �f�X�g���N�^~CMainWindow()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual void Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.

};