// �w�b�_�̃C���N���[�h
#include "MainMenu.h"	// ���C�����j���[�N���X

// �R���X�g���N�^CMainMenu
CMainMenu::CMainMenu(HWND hWnd) : CMenu(hWnd) {	// ���ۂ͐��CMenu���Ă�, hWnd��n��.

}

// ���j���[�I�����̓Ǝ��n���h��OnCommandMenuItem.
BOOL CMainMenu::OnCommandMenuItem(WPARAM wParam, LPARAM lParam) {

	// ���j���[����
	switch (LOWORD(wParam)) {	// LOWORD(wParam)�łǂ̃��j���[�A�C�e�����I�����ꂽ��, ID���Ԃ��Ă���.

		// "�V�K"(IDM_FILE_NEW)
		case IDM_FILE_NEW:

			// IDM_FILE_NEW�u���b�N
			{

				// OnFileNew�ɔC����.
				OnFileNew();

			}

			// ����̏���
			break;	// break�Ŕ�����.

		// "�J��"(IDM_FILE_OPEN)
		case IDM_FILE_OPEN:

			// IDM_FILE_OPEN�u���b�N
			{

				// OnFileOpen�ɔC����.
				OnFileOpen();

			}

			// ����̏���
			break;	// break�Ŕ�����.

		// "�ۑ�"(IDM_FILE_SAVE)
		case IDM_FILE_SAVE:

			// IDM_FILE_SAVE�u���b�N
			{

				// OnFileSave�ɔC����.
				OnFileSave();

			}

			// ����̏���
			break;	// break�Ŕ�����.

		// "���O��t���ĕۑ�"(IDM_FILE_SAVEAS)
		case IDM_FILE_SAVEAS:

			// IDM_FILE_SAVEAS�u���b�N
			{

				// OnFileSaveAs�ɔC����.
				OnFileSaveAs();

			}

			// ����̏���
			break;	// break�Ŕ�����.

		// "�A�v���P�[�V�����̏I��"(IDM_APP_EXIT)
		case IDM_APP_EXIT:

			// IDM_APP_EXIT�u���b�N
			{

				// OnAppExit�ɔC����.
				OnAppExit();

			}

			// ����̏���
			break;	// break�Ŕ�����.

		// ����ȊO
		default:

			// fALSE��Ԃ�.
			return FALSE;

	}

	// �ǂꂩ�̃n���h�����������ꂽ���TRUE��Ԃ�.
	return TRUE;

}

// "�V�K"�I�����̓Ǝ��n���h��OnFileNew.
void CMainMenu::OnFileNew() {

	// "OnFileNew"�ƕ\��.
	MessageBox(NULL, _T("OnFileNew"), _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);	// MessageBox��"OnFileNew"�ƕ\��.

}

// "�J��"�I�����̓Ǝ��n���h��OnFileOpen.
void CMainMenu::OnFileOpen() {

	// "OnFileOpen"�ƕ\��.
	MessageBox(NULL, _T("OnFileOpen"), _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);	// MessageBox��"OnFileOpen"�ƕ\��.

}

// "�ۑ�"�I�����̓Ǝ��n���h��OnFileSave.
void CMainMenu::OnFileSave() {

	// "OnFileSave"�ƕ\��.
	MessageBox(NULL, _T("OnFileSave"), _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);	// MessageBox��"OnFileSave"�ƕ\��.

}

// "���O��t���ĕۑ�"�I�����̓Ǝ��n���h��OnFileSaveAs.
void CMainMenu::OnFileSaveAs() {

	// "OnFileSaveAs"�ƕ\��.
	MessageBox(NULL, _T("OnFileSaveAs"), _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);	// MessageBox��"OnFileSaveAs"�ƕ\��.

}

// "�A�v���P�[�V�����̏I��"�I�����̓Ǝ��n���h��OnAppExit.
void CMainMenu::OnAppExit() {

	// "OnAppExit"�ƕ\��.
	MessageBox(NULL, _T("OnAppExit"), _T("ObjeqtNote"), MB_OK | MB_ICONASTERISK);	// MessageBox��"OnAppExit"�ƕ\��.

}