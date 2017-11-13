
// ISPTool.cpp : �w�q���ε{�������O�欰�C
//

#include "stdafx.h"
#include "NuvoISPTool.h"
#include "DlgNuvoISP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CISPToolApp

BEGIN_MESSAGE_MAP(CISPToolApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CISPToolApp �غc

CISPToolApp::CISPToolApp()
{
    // TODO: �b���[�J�غc�{���X�A
    // �N�Ҧ����n����l�]�w�[�J InitInstance ��
}


// �Ȧ����@�� CISPToolApp ����

CISPToolApp theApp;


// CISPToolApp ��l�]�w

BOOL CISPToolApp::InitInstance()
{
    CWinApp::InitInstance();
    AfxInitRichEdit();
    //AllocConsole();
    //SetConsoleTitle(_T("[Clientside dumper]: Console"));
    //freopen("CONOUT$", "w+t", stdout);
    //freopen("CONOUT$", "w+t", stderr);
    //freopen("CONIN$", "r+t", stdin);
    // �إߴ߼h�޲z���A�H����ܤ���]�t
    // ����߼h���˵��δ߼h�M���˵�����C
    //CShellManager *pShellManager = new CShellManager;
    // �зǪ�l�]�w
    // �p�G�z���ϥγo�ǥ\��åB�Q���
    // �̫᧹�����i�����ɤj�p�A�z�i�H
    // �q�U�C�{���X�������ݭn����l�Ʊ`���A
    // �ܧ��x�s�]�w�Ȫ��n�����X
    // TODO: �z���ӾA�׭ק惡�r��
    // (�Ҧp�A���q�W�٩β�´�W��)
    SetRegistryKey(_T("NuvotonISP"));
    CNuvoISPDlg MainDlg;
    MainDlg.DoModal();

    // �R���W���ҫإߪ��߼h�޲z���C
    //if (pShellManager != NULL) {
    //    delete pShellManager;
    //}

    //FreeConsole();
    // �]���w�g������ܤ���A�Ǧ^ FALSE�A�ҥH�ڭ̷|�������ε{���A
    // �ӫD���ܶ}�l���ε{�����T���C
    return FALSE;
}
