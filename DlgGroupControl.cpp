// DlgVplayer.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "DlgGroupControl.h"
#include "afxdialogex.h"


// CDlgVplayer dialog

IMPLEMENT_DYNAMIC(CDlgGroupControl, CDialogEx)

void DDVPlayer(void)
{
	CAcModuleResourceOverride * myResources = new CAcModuleResourceOverride;

	Acad::ErrorStatus es;
	bool bDocActivation = acDocManager->isDocumentActivationEnabled();
	es = acDocManager->disableDocumentActivation();

	CDlgGroupControl dlg;
	bool bCont = true;
	while (bCont)
	{
		if (dlg.DoModal() != IDOK)
			bCont = false;

		switch (dlg.GetAction())
		{
		case (CDlgGroupControl::eProcessOneStep):
			break;
		case (CDlgGroupControl::eProcessVPLayerState):
			break;
		case (CDlgGroupControl::eEntitySelect):
			break;
		default:
			bCont = false;
		}
	}
	if (bDocActivation)
		es = acDocManager->enableDocumentActivation();
}

CDlgGroupControl::CDlgGroupControl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_DDVPLAYER, pParent), m_nAction(eNone)
{

}

CDlgGroupControl::~CDlgGroupControl()
{
}

BOOL CDlgGroupControl::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_nAction = eNone;
	return TRUE;
}

void CDlgGroupControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_GC_LAYERS, m_lstLayerNames);
	DDX_Control(pDX, IDC_LIST_GC_GROUPS, m_lstGroupNames);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_PICK_ENTITIES, m_btnLayersPick);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_SELECTALL, m_btnLayersSelectAll);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_REMOVEALL, m_btnLayersRemoveAll);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_NEW, m_btnGroupsNew);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_DELETE, m_btnGroupsDelete);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_RENAME, m_btnGroupsRename);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_UPDATE, m_btnGroupsUpdate);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_LOAD, m_btnGroupsLoad);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_SAVE, m_btnGroupsSave);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_NONE, m_btnGroupsNone);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_APPLY_LAYERTABLE, m_btnApplyLayerTable);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_APPLY_VIEWPORT, m_btnApplyViewport);
	DDX_Control(pDX, IDC_BUTTON_GC_LAYERS_ONESTEP, m_btnOneStep);
	DDX_Control(pDX, IDC_CHECK_GC_LAYERS_OFF, m_chkLayersOff);
	DDX_Control(pDX, IDC_CHECK_GC_LAYERS_LOCKED, m_chkLayersLocked);
	DDX_Control(pDX, IDC_CHECK_GC_LAYERS_VP_FROZEN, m_chkLayersVPFrozen);
	DDX_Control(pDX, IDC_CHECK_GC_LAYERS_FROZEN, m_chkLayersFrozen);
	DDX_Control(pDX, IDC_CHECK_GC_LAYERS_NVP_FROZEN, m_chkLayersNVPFrozen);
}


BEGIN_MESSAGE_MAP(CDlgGroupControl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GC_LAYERS_ONESTEP, &CDlgGroupControl::OnBnClickedButtonGcLayersOnestep)
	ON_BN_CLICKED(IDC_BUTTON_GC_LAYERS_PICK_ENTITIES, &CDlgGroupControl::OnBnClickedButtonGcLayersPickEntities)
	ON_BN_CLICKED(IDC_BUTTON_GC_LAYERS_APPLY_VIEWPORT, &CDlgGroupControl::OnBnClickedButtonGcLayersApplyViewport)
END_MESSAGE_MAP()


// CDlgVplayer message handlers


UINT32 CDlgGroupControl::GetAction()
{
	return m_nAction;
}


void CDlgGroupControl::OnBnClickedButtonGcLayersOnestep()
{
	m_nAction = eProcessOneStep;
	CDialog::OnOK();
}


void CDlgGroupControl::OnBnClickedButtonGcLayersPickEntities()
{
	m_nAction = eEntitySelect;
	CDialog::OnOK();
}


void CDlgGroupControl::OnBnClickedButtonGcLayersApplyViewport()
{
	m_nAction = eProcessVPLayerState;
	CDialog::OnOK();
}
