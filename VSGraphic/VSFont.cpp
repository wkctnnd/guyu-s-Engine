#include "VSFont.h"
#include "VSGraphicInclude.h"
#include "VSStream.h"
using namespace VSEngine2;
IMPLEMENT_RTTI(VSFont,VSBind)
BEGIN_ADD_PROPERTY(VSFont,VSBind)
REGISTER_PROPERTY(m_Face,Face,VSProperty::F_SAVE_LOAD_CLONE)
REGISTER_PROPERTY(m_uiSize,Size,VSProperty::F_SAVE_LOAD_CLONE)
REGISTER_PROPERTY(m_bBold,Bold,VSProperty::F_SAVE_LOAD_CLONE)
REGISTER_PROPERTY(m_bItalic,Italic,VSProperty::F_SAVE_LOAD_CLONE)
END_ADD_PROPERTY
IMPLEMENT_INITIAL_BEGIN(VSFont)
ADD_INITIAL_FUNCTION(InitialDefaultState)
ADD_TERMINAL_FUNCTION(TerminalDefaultState)
IMPLEMENT_INITIAL_END
VSPointer<VSFont> VSFont::Default;
bool VSFont::InitialDefaultState()
{
	VSFont *p = NULL;
	p = VS_NEW VSFont();

	if(p)
	{
		Default = p;
		
	}
	else
		return 0;
	return 1;
}
bool VSFont::TerminalDefaultState()
{
	Default = NULL;
	return 1;
}
VSFont::VSFont(const TCHAR* acFace, unsigned int uiSize, bool bBold,
				bool bItalic)
{
	m_bIsStatic = bItalic;
	if(acFace)
	{
		m_Face = acFace;
	}
	else
	{
		m_Face = _T("Arial");
	}
	m_uiSize = uiSize;
	m_bBold = bBold;
}
VSFont::~VSFont()
{
	ReleaseResource();

}
VSFont::VSFont()
{
	m_bIsStatic = 1;
	m_Face = _T("Arial");
	m_uiSize = 20;
	m_bBold = 0;
}

bool VSFont::OnLoadResource(VSResourceIdentifier *&pID)
{
	if(!m_pUser)
		return 0;
	if(!m_pUser->OnLoadFont (this,pID))
		return 0;
	return 1;
}
bool VSFont::OnReleaseResource(VSResourceIdentifier *pID)
{
	if(!m_pUser)
		return 0;
	if(!m_pUser->OnReleaseFont(pID))
		return 0;
	return 1;
}