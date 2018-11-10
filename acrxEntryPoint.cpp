// (C) Copyright 2002-2012 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "StdArx.h"
#include "resource.h"
#include "DlgGroupControl.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("rpk")


extern bool g_bWatchOn;

extern bool g_bLayersOff;
extern bool g_bLayersLocked;
extern bool g_bLayersFrozen;
extern bool g_bLayersFrozenVP;
extern bool g_bLayersFrozenVPNew;

// const CString csAppRegistryPath(_T("SOFTWARE\\PK_TOOLS\\"));
const CString csAppName(_T("DDVPlayer"));

#ifdef BRX_APP  // BRX builds
const CString csDllName(_T("DDVPlayerBrx.brx"));
#else           // ARX builds
const CString csDllName(_T("DDVPlayerArx.arx"));
#endif // BRX_APP



AcadApp::ErrorStatus getAppInfo(AcadAppInfo & info)
{
	info.setAppName(csAppName);
	return info.readFromRegistry();
}

AcadApp::ErrorStatus UnregisterArxApp()
{
	AcadAppInfo info;
	info.setAppName(csAppName);
	return info.delFromRegistry();
}

AcadApp::ErrorStatus UnregisterArxApp(AcadAppInfo & info)
{
	info.setAppName(csAppName);
	return info.delFromRegistry();
}

AcadApp::ErrorStatus RegisterArxApp(void)
{
	if (!_hdllInstance)
		return AcadApp::eUnknownError;

	//AcadApp::ErrorStatus es = acrxRegisterApp((AcadApp::LoadReasons) (AcadApp::kOnAutoCADStartup),
	//	pcszAppRegistryPath);


	AcadAppInfo info;
	info.setAppName(csAppName);
	HMODULE hModule = GetModuleHandle(csDllName);
	TCHAR szModulePath[MAX_PATH];
	DWORD dwPathLength = GetModuleFileName(hModule, szModulePath, MAX_PATH);
	if (!dwPathLength)
		return AcadApp::eValueNotFound;


	info.setModuleName(szModulePath);
	info.setLoadReason(
		AcadApp::LoadReasons(AcadApp::kOnAutoCADStartup)
	);
#ifdef BRX_APP  // BRX builds
	info.setManaged(Adesk::kFalse);
	return info.writeToRegistry(false, true);
#else           // ARX builds
	info.setManaged(AcadAppInfo::kUnManaged);
	return info.writeToRegistry();
#endif // BRX_APP

}


//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CBRX18App : public AcRxArxApp {

public:
	CBRX18App () : AcRxArxApp () {}

	virtual AcRx::AppRetCode On_kLoadDwgMsg(void *pkt)
	{		
		return AcRx::kRetOK;
	}

	virtual AcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kInitAppMsg (pkt) ;
		
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);

		// Add code here


		return (retCode) ;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// Add cleanup code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode =AcRxArxApp::On_kUnloadAppMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}
	
	// The ACED_ARXCOMMAND_ENTRY_AUTO macro can be applied to any static member 
	// function of the CBRX18App class.
	// The function should take no arguments and return nothing.
	//
	// NOTE: ACED_ARXCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid and
	// have arguments to define context and command mechanism.
	
	// ACED_ARXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext)
	// ACED_ARXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext)
	// only differs that it creates a localized name using a string in the resource file
	//   locCmdId - resource ID for localized command

	static void rpkGroupLayTblReactorOn() {
		g_bWatchOn = true;
	}

	static void rpkGroupLayTblReactorOff() {
		g_bWatchOn = false;
	}

	static void rpkGroupDDVPlayer() {
		DDVPlayer();
	}

} ;

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CBRX18App)



//ACED_ARXCOMMAND_ENTRY_AUTO(CBRX18App, rpkGroup, LayTblReactorOn, _LayTblReactorOn, ACRX_CMD_MODAL, NULL)
//ACED_ARXCOMMAND_ENTRY_AUTO(CBRX18App, rpkGroup, LayTblReactorOff, _LayTblReactorOff, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CBRX18App, rpkGroup, DDVPlayer, DDVPlayer, ACRX_CMD_MODAL, NULL)

