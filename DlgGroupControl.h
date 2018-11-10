#pragma once
#include "afxwin.h"


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
public:
	CListBox m_lstLayerNames;
	CListBox m_lstGroupNames;
	CButton m_btnLayersPick;
	CButton m_btnLayersSelectAll;
	CButton m_btnLayersRemoveAll;
	CButton m_btnGroupsNew;
	CButton m_btnGroupsDelete;
	CButton m_btnGroupsRename;
	CButton m_btnGroupsUpdate;
	CButton m_btnGroupsLoad;
	CButton m_btnGroupsSave;
	CButton m_btnGroupsNone;
	CButton m_btnApplyLayerTable;
	CButton m_btnApplyViewport;
	CButton m_btnOneStep;
	CButton m_chkLayersOff;
	CButton m_chkLayersLocked;
	CButton m_chkLayersVPFrozen;
	CButton m_chkLayersFrozen;
	CButton m_chkLayersNVPFrozen;
};
