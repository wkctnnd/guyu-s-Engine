#include "VSTexture.h"
#include "VSShaderStringFactory.h"
#include "VSGraphicInclude.h"
#include "VSStream.h"
using namespace VSEngine2;
IMPLEMENT_RTTI_NoCreateFun(VSTexture,VSBind)
IMPLEMENT_INITIAL_NO_CLASS_FACTORY_BEGIN(VSTexture)
IMPLEMENT_INITIAL_NO_CLASS_FACTORY_END
BEGIN_ADD_PROPERTY(VSTexture,VSBind)
REGISTER_PROPERTY(m_uiFormatType,FormatType,VSProperty::F_SAVE_LOAD_CLONE);
REGISTER_PROPERTY(m_uiWidth,Width,VSProperty::F_SAVE_LOAD_CLONE);
REGISTER_PROPERTY(m_uiHeight,Height,VSProperty::F_SAVE_LOAD_CLONE);
REGISTER_PROPERTY(m_uiLenght,Lenght,VSProperty::F_SAVE_LOAD_CLONE);
REGISTER_PROPERTY(m_uiMipLevel,MipLevel,VSProperty::F_SAVE_LOAD_CLONE);
REGISTER_PROPERTY_DATA(m_pBufferArray[0], m_BufferSize[0],BufferArray0);
REGISTER_PROPERTY_DATA(m_pBufferArray[1], m_BufferSize[1], BufferArray1);
REGISTER_PROPERTY_DATA(m_pBufferArray[2], m_BufferSize[2], BufferArray2);
REGISTER_PROPERTY_DATA(m_pBufferArray[3], m_BufferSize[3], BufferArray3);
REGISTER_PROPERTY_DATA(m_pBufferArray[4], m_BufferSize[4], BufferArray4);
REGISTER_PROPERTY_DATA(m_pBufferArray[5], m_BufferSize[5], BufferArray5);
REGISTER_PROPERTY_DATA(m_pBufferArray[6], m_BufferSize[6], BufferArray6);
REGISTER_PROPERTY_DATA(m_pBufferArray[7], m_BufferSize[7], BufferArray7);
REGISTER_PROPERTY_DATA(m_pBufferArray[8], m_BufferSize[8], BufferArray8);
REGISTER_PROPERTY_DATA(m_pBufferArray[9], m_BufferSize[9], BufferArray9);
REGISTER_PROPERTY_DATA(m_pBufferArray[10], m_BufferSize[10], BufferArray10);
REGISTER_PROPERTY_DATA(m_pBufferArray[11], m_BufferSize[11], BufferArray11);
REGISTER_PROPERTY_DATA(m_pBufferArray[12], m_BufferSize[12], BufferArray12);
REGISTER_PROPERTY_DATA(m_pBufferArray[13], m_BufferSize[13], BufferArray13);
END_ADD_PROPERTY
VSTexture::VSTexture(unsigned int uiFormatType,unsigned int uiWidth,
					 unsigned int uiHeight,unsigned int uiLength,unsigned int uiMipLevel,bool bIsStatic)
{
	VSMAC_ASSERT(uiWidth && uiHeight);
	VSMAC_ASSERT(uiFormatType < VSRenderer::SFT_MAX);
	m_uiFormatType = uiFormatType;
	m_uiHeight = uiHeight;
	m_uiWidth = uiWidth;
	m_uiLenght = uiLength;
	for (unsigned int i = 0 ; i < MAX_MIP_LEVEL ; i++)
	{
		for (unsigned int j = 0 ; j < 6 ; j++)
		{
			m_pLockDate[i][j] = NULL;
		}
	}
	for (unsigned int i = 0; i < MAX_MIP_LEVEL; i++)
	{
		m_pBufferArray[i] = NULL;
		m_BufferSize[i] = 0;
	}
	m_bIsStatic = bIsStatic;
	m_uiMipLevel = uiMipLevel;
	
	
}
VSTexture::VSTexture()
{
	for (unsigned int i = 0 ; i < MAX_MIP_LEVEL ; i++)
	{
		for (unsigned int j = 0 ; j < 6 ; j++)
		{
			m_pLockDate[i][j] = NULL;
		}
	}
	for (unsigned int i = 0; i < MAX_MIP_LEVEL; i++)
	{
		m_pBufferArray[i] = NULL;
		m_BufferSize[i] = 0;
	}
}
VSTexture::~VSTexture()
{
	ReleaseResource();
	for (unsigned int i = 0; i < MAX_MIP_LEVEL; i++)
	{
		VSMAC_DELETEA(m_pBufferArray[i]);
		m_BufferSize[i] = 0;
	}
}

void VSTexture::ClearInfo()
{
	if(m_uiSwapChainNum == m_InfoArray.GetNum())
	{
		if (m_uiMemType == MT_VRAM)
		{
			for (unsigned int i = 0 ; i < MAX_MIP_LEVEL ; i++)
			{
				VSMAC_DELETEA(m_pBufferArray[i]);
				m_BufferSize[i] = 0;
			}
		}
	}

}
bool VSTexture::LoadResource(VSRenderer * pRender)
{
	if (!VSBind::LoadResource(pRender))
	{
		return false;
	}

	return true;
}
bool VSTexture::OnLoadResource(VSResourceIdentifier *&pID)
{
	if(!m_pUser)
		return 0;
	if(!m_pUser->OnLoadTexture(this,pID))
		return 0;
	return 1;

}
bool VSTexture::OnReleaseResource(VSResourceIdentifier *pID)
{
	if(!m_pUser)
		return 0;
	if(!m_pUser->OnReleaseTexture(pID))
		return 0;
	return 1;
}
void *VSTexture::Lock(unsigned int uiLevel,unsigned int uiFace)
{
	if (m_pLockDate[uiLevel][uiFace] || m_bIsStatic)
	{
		return NULL;
	}
	if (m_pUser)
	{
		m_pLockDate[uiLevel][uiFace] = m_pUser->Lock(this,uiLevel,uiFace);
	}

	return m_pLockDate[uiLevel][uiFace];
}
void VSTexture::UnLock(unsigned int uiLevel,unsigned int uiFace)
{
	if (!m_pLockDate[uiLevel][uiFace] || m_bIsStatic)
	{
		return;
	}
	if (m_pUser)
	{
		m_pUser->UnLock(this,uiLevel,uiFace);
	}
	m_pLockDate[uiLevel][uiFace] = NULL;
}
void VSTexture::CreateRAMDate()
{
	for (unsigned int i = 0 ; i < m_uiMipLevel ; i++)
	{
		VSMAC_DELETEA(m_pBufferArray[i]);
		m_BufferSize[i] = GetByteSize(i);
		if (m_BufferSize[i] == 0)
		{
			continue;
		}
		m_pBufferArray[i] = VS_NEW unsigned char[m_BufferSize[i]];
	}
}