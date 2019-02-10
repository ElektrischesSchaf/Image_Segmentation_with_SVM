
// N16074988Dlg.h : 標頭檔
//

#pragma once


// CN16074988Dlg 對話方塊
class CN16074988Dlg : public CDialogEx
{
// 建構
public:
	CN16074988Dlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_N16074988_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
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
