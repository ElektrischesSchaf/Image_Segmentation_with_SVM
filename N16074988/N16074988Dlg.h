
// N16074988Dlg.h : ���Y��
//

#pragma once


// CN16074988Dlg ��ܤ��
class CN16074988Dlg : public CDialogEx
{
// �غc
public:
	CN16074988Dlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_N16074988_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnUpdateMEditctrl();
//	afx_msg void OnEnableMStrtextctrl();
	afx_msg void OnEnChangeeditctrl();
	afx_msg void OnStnClickedstrtextctrl();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
};
