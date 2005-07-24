// TortoiseSVN - a Windows shell extension for easy version control

// Copyright (C) 2003-2005 - Stefan Kueng

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//
#pragma once
#include "StandAloneDlg.h"
#include "SVNStatusListCtrl.h"


// CResolveDlg dialog

class CResolveDlg : public CResizableStandAloneDialog
{
	DECLARE_DYNAMIC(CResolveDlg)

public:
	CResolveDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CResolveDlg();

// Dialog Data
	enum { IDD = IDD_RESOLVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnBnClickedSelectall();
	afx_msg void OnBnClickedHelp();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();

private:
	static UINT ResolveThreadEntry(LPVOID pVoid);
	UINT ResolveThread();

	DECLARE_MESSAGE_MAP()

public:
	CTSVNPathList	m_pathList;

private:
	CSVNStatusListCtrl	m_resolveListCtrl;
	bool			m_bThreadRunning;
	CButton			m_SelectAll;
};
