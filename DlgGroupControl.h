#pragma once


// CDlgVplayer dialog

class CDlgGroupControl : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgGroupControl)

public:
	CDlgGroupControl(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgGroupControl();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DDVPLAYER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
