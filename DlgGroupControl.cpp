// DlgVplayer.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "DlgGroupControl.h"
#include "afxdialogex.h"


// CDlgVplayer dialog

IMPLEMENT_DYNAMIC(CDlgGroupControl, CDialogEx)

CDlgGroupControl::CDlgGroupControl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_DDVPLAYER, pParent)
{

}

CDlgGroupControl::~CDlgGroupControl()
{
}

void CDlgGroupControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgGroupControl, CDialogEx)
END_MESSAGE_MAP()


// CDlgVplayer message handlers
