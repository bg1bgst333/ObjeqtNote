// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WindowListControl.h"	// �E�B���h�E���X�g�R���g���[���N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CWindowListControl::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E���X�g�A�C�e���Y�p�l����o�^.
	CWindowListItemsPanel::RegisterClass(hInstance);	// �q�E�B���h�E��o�^.

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("WindowListControl"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"WindowListControl"��o�^.

}

// �R���X�g���N�^CWindowListControl()
CWindowListControl::CWindowListControl() : CUserControl() {

	// �����o�̏�����
	m_pWindowListItemsPanel = NULL;	// m_pWindowListItemsPanel��NULL�ŏ�����.

}

// �f�X�g���N�^~CWindowListControl()
CWindowListControl::~CWindowListControl() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŕj��.

}

// �E�B���h�E�쐬�֐�Create
BOOL CWindowListControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	return CUserControl::Create(_T("WindowListControl"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"WindowListControl"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�j���֐�Destroy
void CWindowListControl::Destroy() {

	// �q�E�B���h�E�̔j��.
	if (m_pWindowListItemsPanel != NULL) {
		m_pWindowListItemsPanel->Destroy();	// m_pWindowListItemsPanel�̃E�B���h�E��j��.
		delete m_pWindowListItemsPanel;		// m_pWindowListItemsPanel�����.
		m_pWindowListItemsPanel = NULL;		// m_pWindowListItemsPanel��NULL�Ŗ��߂�.
	}

	// �y���ƃu���V�̔j��.
	DeleteObject(m_hBrush);	// �u���V�̔j��.
	DeleteObject(m_hPen);	// �y���̔j��.

	// �����̃E�B���h�E���j��.
	CWindow::Destroy();	// CWindow::Destroy�Ŏ��g�̃E�B���h�E���j��.

}

// �A�C�e���}���֐�Insert
BOOL CWindowListControl::Insert(int iIndex) {

	// �A�C�e���Y�p�l���̃T�C�Y��傫������.
	m_pWindowListItemsPanel->MoveWindow(TRUE, 0, 50);	// m_pWindowListItemsPanel->MoveWindow�ő��ΓI��50���₷.

	// �����Ȃ̂�TRUE��Ԃ�.
	return TRUE;

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CWindowListControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �y���ƃu���V�̍쐬.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0x7f, 0));		// ��(�Z)�̃y�����쐬.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0xff, 0));		// ��(�W)�̃u���V���쐬.

	// �E�B���h�E���X�g�A�C�e���Y�p�l���N���X�̍쐬.
	m_pWindowListItemsPanel = new CWindowListItemsPanel();	// CWindowListItemsPanel�I�u�W�F�N�g���쐬��, �|�C���^��m_pWindowListItemsPanel�Ɋi�[.
	m_pWindowListItemsPanel->Create(_T(""), 0, 30, 0, 300, 50, hwnd, (HMENU)IDC_WINDOWLISTITEMSPANEL1, lpCreateStruct->hInstance);	// m_pWindowListItemsPanel->Create�ŃE�B���h�E���X�g�A�C�e���Y�p�l�����쐬.(�e�E�B���h�E��菬����.)

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
void CWindowListControl::OnPaint() {

	// �ϐ��̐錾
	HDC hDC;			// �f�o�C�X�R���e�L�X�g�n���h��HDC�^hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT�\���̕ϐ�ps.

	// �`��J�n.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaint�ŕ`��J�n.
	// �y���ƃu���V�̑I��.
	HPEN hOldPen = (HPEN)SelectObject(hDC, m_hPen);		// �΂̃y����I��.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, m_hBrush);	// �΂̃u���V��I��.
	// ��`��`��.(�N���C�A���g�̈�̓X�N���[���o�[���܂܂Ȃ�.)
	RECT rc;
	GetClientRect(m_hWnd, &rc);	// GetClientRect�ŃN���C�A���g�̈�̋�`���擾.
	Rectangle(hDC, 0, 0, rc.right - rc.left, rc.bottom - rc.top);	// Rectangle�ŋ�`��`��.
	// �y���ƃu���V�̕���
	SelectObject(hDC, hOldBrush);		// �Â��u���V��I��.
	SelectObject(hDC, hOldPen);		// �Â��y����I��.
	// �`��I��.
	EndPaint(m_hWnd, &ps);	// EndPaint�ŕ`��I��.

}