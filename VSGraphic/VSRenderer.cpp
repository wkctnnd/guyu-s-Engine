#include "VSRenderer.h"
#include "VSFont.h"
#include "VSVShader.h"
#include "VSPShader.h"
#include "VSVertexBuffer.h"
#include "VSGeometry.h"
#include "VSTexture.h"
#include "VS2DTexture.h"
#include "VSTexAllState.h"
#include "VSMaterial.h"
#include "VSDepthStencil.h"
#include "VSCubeTexture.h"
#include "VSVertexFormat.h"
#include "VSMeshDate.h"
#include "VSShaderStringFactory.h"
#include "VSAABB3.h"
#include "VSOBB3.h"
#include "VSSphere3.h"
#include "VSTriangleSet.h"
#include "VSLineSet.h"
#include "VSGraphicInclude.h"
#include "VSRenderTarget.h"
#include "VSProfiler.h"
using namespace VSEngine2;
VSRenderer * VSRenderer::ms_pRenderer = NULL;
VSString VSRenderer::ms_IncludeShader;

VSString VSRenderer::ms_DynamicShader;

VSAdapterInfo	VSRenderer::ms_AdapterInfo[5];
UINT VSRenderer::ms_uiAdapterNum = 0;
VSString VSRenderer::ms_VShaderProgramMain = _T("VSMain");
VSString VSRenderer::ms_PShaderProgramMain = _T("PSMain");
unsigned int VSRenderer::ms_uiBytesPerPixel[SFT_MAX] =
{
	4,  
	2,
	4,
	4,
	16,
	8,
	4,
	2,
	4,
	4,
	4,
	8,
	2,
	3,
	16,
	16
};
unsigned int VSRenderer::ms_uiChannelPerPixel[SFT_MAX] =
{
	4,  
	1,
	2,
	1,
	4,
	4,
	2,
	1,
	1,
	4,
	2,
	2,
	3,
	3,
	4,
	4
};
VSRenderer::SCREEN_QUAD_TYPE VSRenderer::ms_FullScreen[4] = 
{
	{VSVector3(-1.0f,  1.0f, 0.0f),VSVector2(0.0f, 0.0f)},
	{VSVector3( 1.0f,  1.0f, 0.0f),VSVector2(1.0f, 0.0f)},
	{VSVector3( 1.0f, -1.0f, 0.0f),VSVector2(1.0f, 1.0f)},
	{VSVector3(-1.0f, -1.0f, 0.0f),VSVector2(0.0f, 1.0f)}	
	
};
VSUSHORT_INDEX VSRenderer::ms_FullScreenI[6] = { 0, 1, 3, 1, 2, 3 };
unsigned int VSRenderer::GetBytesPerPixel(unsigned int uiFormatType)
{
	if (uiFormatType >= SFT_MAX)
	{
		return 0;
	}
	return ms_uiBytesPerPixel[uiFormatType];
}
unsigned int VSRenderer::GetChannelPerPixel(unsigned int uiFormatType)
{
	if (uiFormatType >= SFT_MAX)
	{
		return 0;
	}
	return ms_uiChannelPerPixel[uiFormatType];
}
const VSAdapterInfo* VSRenderer::GetAdapterInfo(unsigned int & uiAdapterNum)
{
	uiAdapterNum = ms_uiAdapterNum;
	return ms_AdapterInfo;
}
const VSString & VSRenderer::GetVShaderProgramMain()
{
	return ms_VShaderProgramMain;
}
const VSString & VSRenderer::GetPShaderProgramMain()
{
	return ms_PShaderProgramMain;
}

VSRenderer::~VSRenderer()
{
	VSMAC_DELETEA(m_pChildWindowInfo);
	m_pVertexBuffer = NULL;
	m_pVertexFormat = NULL;
	m_pIndexBuffer = NULL;
	m_pVShader = NULL;
	m_pPshader = NULL;
	m_pFont		= NULL;
	m_pQuadVertexFormat = NULL;

	m_pBlendState = NULL;
	m_pDepthStencilState = NULL;
	m_pRasterizerState = NULL;

}
void VSRenderer::RenderStateToDefault()
{
// 	VSMAC_ASSERT(m_uiMaxTexture);
// 	for(unsigned int i = 0 ; i < m_uiMaxTexture ; i++)
// 	{		
// 		m_pPSamplerState[i] = (VSSamplerState *)VSSamplerState::GetDefault();
// 	}
// 	VSMAC_ASSERT(m_uiMaxVTexture);
// 	for(unsigned int i = 0 ; i < m_uiMaxVTexture ; i++)
// 	{
// 		
// 	}

	
// 	m_pBlendState = (VSBlendState *) VSBlendState::GetDefault();
// 	m_pDepthStencilState = (VSDepthStencilState *) VSDepthStencilState::GetDefault();
// 	m_pRasterizerState = (VSRasterizerState *) VSRasterizerState::GetDefault();
// 	m_bClipPlaneEnable = false;
// 	m_bScissorRectEnable = false;
// 	m_pVertexFormat = NULL;


	VSMAC_ASSERT(m_uiMaxTexture);
	for(unsigned int i = 0 ; i < m_uiMaxTexture ; i++)
	{		
		SetSamplerState(NULL,i);
	}
	VSMAC_ASSERT(m_uiMaxVTexture);
	for(unsigned int i = 0 ; i < m_uiMaxVTexture ; i++)
	{

	}

	SetBlendState(NULL);
	SetDepthStencilState(NULL);
	SetRasterizerState(NULL);
	if (m_bScissorRectEnable)
	{
		VSArray<VSRect2> Temp;
		SetScissorRect(Temp,false);
		m_bScissorRectEnable = false;
	}

	if (m_bClipPlaneEnable)
	{
		VSArray<VSPlane3> Temp;
		SetClipPlane(Temp,false);
		m_bClipPlaneEnable = false;
	}
	SetVertexFormat(NULL);

}
bool VSRenderer::SetDefaultValue()
{
	VSMAC_ASSERT(m_uiMaxTexture);

	for(unsigned int i = 0 ; i < m_uiMaxTexture ; i++)
	{
		m_pPTex[i] = NULL;

		m_pPSamplerState[i] = (VSSamplerState *)VSSamplerState::GetDefault();
	}
	VSMAC_ASSERT(m_uiMaxVTexture);

	for(unsigned int i = 0 ; i < m_uiMaxVTexture ; i++)
	{
		m_pVTex[i] = NULL;
	}

	m_pBlendState = (VSBlendState *) VSBlendState::GetDefault();
	m_pDepthStencilState = (VSDepthStencilState *) VSDepthStencilState::GetDefault();
	m_pRasterizerState = (VSRasterizerState *) VSRasterizerState::GetDefault();
	m_bClipPlaneEnable = false;
	m_bScissorRectEnable = false;

	m_pFont = (VSFont*)VSFont::GetDefalut();
	LoadFont(m_pFont);

	SetTexture(VSTexAllState::GetDefalut()->m_pTex,0);

	VSArray<VSVertexFormat::VERTEXFORMAT_TYPE> ForamtArray;
	VSVertexFormat::VERTEXFORMAT_TYPE Pos;
	Pos.DateType = VSDataBuffer::DT_FLOAT32_3;
	Pos.OffSet = 0;
	Pos.Semantics = VSVertexFormat::VF_POSITION;
	Pos.SemanticsIndex = 0;
	ForamtArray.AddElement(Pos);

	VSVertexFormat::VERTEXFORMAT_TYPE TextureCode;
	TextureCode.DateType = VSDataBuffer::DT_FLOAT32_2;
	TextureCode.OffSet = 12;
	TextureCode.Semantics = VSVertexFormat::VF_TEXCOORD;
	TextureCode.SemanticsIndex = 0;
	ForamtArray.AddElement(TextureCode);
	m_pQuadVertexFormat = VSResourceManager::LoadVertexFormat(NULL, &ForamtArray);
	
	VSResourceManager::LoadDefaultResource(VSRenderer::RAT_DIRECTX9);
	return 1;
}
VSRenderer::ChildWindowInfo * VSRenderer::GetChildWindowInfo(int uiID)
{
	if(!m_bWindowed)
		return NULL;
	else if(uiID >= m_iNumChildWindow)
		return NULL;
	else if (uiID < 0)
	{
		return NULL;
	}
	return &m_pChildWindowInfo[uiID];
}

bool VSRenderer::ReleaseDefaultValue()
{
	ReleaseBindObjectResource();


	return 1;
}
bool VSRenderer::ReleaseBindObjectResource()
{
	for (unsigned int i = 0 ; i < VSBind::ms_BindArray.GetNum() ; i++)
	{
		VSBind * pBind  = VSBind::ms_BindArray[i];
		if (!pBind)
		{
			continue;
		}
		if(!pBind->ReleaseResource())
		{
			VSMAC_ASSERT(0);
			return false;
		}
	}
	return true;
}

void VSRenderer::SetUseState(VSRenderState & RenderState,unsigned int uiRenderStateInheritFlag)
{
	m_UseState.GetAll(&RenderState);
	m_uiRenderStateInheritFlag = uiRenderStateInheritFlag;
}
void VSRenderer::ClearUseState()
{
	m_uiRenderStateInheritFlag = 0;	
}
void VSRenderer::SetRenderState(VSRenderState & RenderState)
{
	
	SetBlendState(RenderState.m_pBlendState);

	SetDepthStencilState(RenderState.m_pDepthStencilState);

	SetRasterizerState(RenderState.m_pRasterizerState);

	if (RenderState.m_RasterizerDesc.m_bClipPlaneEnable && RenderState.m_Plane.GetNum() > 0)
	{
		m_bClipPlaneEnable = true;
		SetClipPlane(RenderState.m_Plane,m_bClipPlaneEnable);
	}
	else
	{
		if (m_bClipPlaneEnable)
		{
			m_bClipPlaneEnable = false;
			SetClipPlane(RenderState.m_Plane,m_bClipPlaneEnable);
		}
	}
	if (RenderState.m_RasterizerDesc.m_bScissorTestEnable && RenderState.m_RectArray.GetNum() > 0)
	{
		m_bScissorRectEnable = true;
		SetScissorRect(RenderState.m_RectArray,m_bScissorRectEnable);
	}
	else
	{
		if (m_bScissorRectEnable)
		{
			m_bScissorRectEnable = false;
			SetScissorRect(RenderState.m_RectArray,m_bScissorRectEnable);
		}
	}

	
}
FORCEINLINE const VSFont *VSRenderer::GetFont()const
{
	return m_pFont;
}

bool VSRenderer::SetVShaderProgram(VSVShader*	pVShaderProgram)
{
	if(!pVShaderProgram)
		return 0;
	if(!LoadVShaderProgram(pVShaderProgram))
		return 0;

	/*VSResourceIdentifier * pID = pVShaderProgram->GetIdentifier(this);
	if(!pID)
		return 0;*/
	
	return 1;
}


bool VSRenderer::SetPShaderProgram(VSPShader*	pPShaderProgram)
{
	if(!pPShaderProgram)
		return 0;
	if(!LoadPShaderProgram(pPShaderProgram))
		return 0;

	/*VSResourceIdentifier * pID = pPShaderProgram->GetIdentifier(this);
	if(!pID)
		return 0;*/

	
	return 1;
}
void VSRenderer::EnableTextureRTUsed(VSTexture * pTexture)
{
	if (!pTexture)
	{
		return;
	}
	if (pTexture->GetTexType() == VSTexture::TT_2D)
	{
		((VS2DTexture *)pTexture)->m_bRtUsed = true;
	}
	else if (pTexture->GetTexType() == VSTexture::TT_CUBE)
	{
		((VS2DTexture *)pTexture)->m_bRtUsed = true;
	}
}
void VSRenderer::DisableTextureRTUsed(VSTexture * pTexture)
{
	if (!pTexture)
	{
		return;
	}
	if (pTexture->GetTexType() == VSTexture::TT_2D)
	{
		((VS2DTexture *)pTexture)->m_bRtUsed = false;
	}
	else if (pTexture->GetTexType() == VSTexture::TT_CUBE)
	{
		((VS2DTexture *)pTexture)->m_bRtUsed = false;
	}
}
bool VSRenderer::SetRenderTarget(VSRenderTarget *pRenderTarget,unsigned int i)
{
	if(!pRenderTarget)
	{
		return 0;
	}
	if (i >= m_uiMaxRTNum)
	{
		return 0;
	}

	if(!LoadRenderTarget(pRenderTarget))
		return 0;
	m_uiCurRTWidth = pRenderTarget->GetWidth();
	m_uiCurRTHeight = pRenderTarget->GetHeight();
	EnableTextureRTUsed(pRenderTarget->GetCreateBy());
	return 1;
}
bool VSRenderer::EndRenderTarget(VSRenderTarget *pRenderTarget,unsigned int i)
{
	if(!pRenderTarget)
		return 0;

	if (i >= m_uiMaxRTNum)
	{
		return 0;
	}


	if(!LoadRenderTarget(pRenderTarget))
		return 0;
	m_uiCurRTWidth = m_uiScreenWidth;
	m_uiCurRTHeight = m_uiScreenHeight;
	DisableTextureRTUsed(pRenderTarget->GetCreateBy());
	return 1;
}
bool VSRenderer::SetDepthStencilBuffer(VSDepthStencil * pDepthStencilBuffer)
{
	if(!pDepthStencilBuffer)
		return 0;

	if(!LoadDepthStencil(pDepthStencilBuffer))
		return 0;
	return 1;
}
bool VSRenderer::EndDepthStencilBuffer(VSDepthStencil * pDepthStencilBuffer)
{
	if(!pDepthStencilBuffer)
		return 0;

	if(!LoadDepthStencil(pDepthStencilBuffer))
		return 0;
	return 1;
}
unsigned int VSRenderer::SetVBuffer(VSVertexBuffer * pVBuffer)
{
	
	
	if(pVBuffer && !pVBuffer->IsStatic())
	{
		pVBuffer->UnLock();
		
	}
	if(m_pVertexBuffer == pVBuffer)
	{
		if (!pVBuffer)
		{
			return FRI_SAMERESOURCE;
		}
		else if (pVBuffer  && pVBuffer->GetSwapChainNum() == 1)
		{
			return FRI_SAMERESOURCE;
		}
	}
		
	if(!pVBuffer)
	{
		m_pVertexBuffer = NULL;
		SetVertexFormat(NULL);
		return FRI_FAIL;
	}
	if(!LoadVBuffer(pVBuffer))
	{
		m_pVertexBuffer = NULL;
		SetVertexFormat(NULL);
		return FRI_FAIL;
	}
	SetVertexFormat(pVBuffer->GetVertexFormat());
	m_pVertexBuffer = pVBuffer;
	
	return FRI_SUCCESS;
}
unsigned int VSRenderer::SetVertexFormat(VSVertexFormat * pVertexFormat)
{
	if(m_pVertexFormat == pVertexFormat)
		return FRI_SAMERESOURCE;
	m_pVertexFormat = pVertexFormat;
	if (!pVertexFormat)
	{
		return FRI_FAIL;
	}
	return FRI_SUCCESS;
}
bool VSRenderer::CopyResourceBuffer(VS2DTexture * pSource,VSCubeTexture * pDest,unsigned int uiFace)
{
	if (!pSource || !pDest || uiFace >= VSCubeTexture::F_MAX)
	{
		return false;
	}
	if (pSource->GetWidth(0) != pSource->GetHeight(0) && pSource->GetWidth(0) != pDest->GetWidth(0))
	{
		return false;
	}
	if (pSource->GetMipLevel() != pDest->GetMipLevel())
	{
		return false;
	}
	if (pSource->GetFormatType() != pDest->GetFormatType())
	{
		return false;
	}
	return true;
}
unsigned int VSRenderer::SetIBuffer (VSIndexBuffer* pIBuffer)
{

	
	if(pIBuffer && !pIBuffer->IsStatic())
	{
		pIBuffer->UnLock();
		
	}

	if(m_pIndexBuffer == pIBuffer)
	{
		if (!pIBuffer)
		{
			return FRI_SAMERESOURCE;
		}
		else if (pIBuffer && pIBuffer->GetSwapChainNum() == 1)
		{
			return FRI_SAMERESOURCE;
		}
			
	}
	if(!pIBuffer)
	{
		m_pIndexBuffer = NULL;
		return FRI_FAIL;
	}
	if(!LoadIBuffer(pIBuffer))
	{
		m_pIndexBuffer = NULL;
		return FRI_FAIL;
	}
	
	m_pIndexBuffer = pIBuffer;
	
	return FRI_SUCCESS;
}

bool VSRenderer::LoadVShaderProgram (VSVShader * pVShaderProgram)
{
	if(!pVShaderProgram)
		return 0;

	return pVShaderProgram->LoadResource(this);
}
bool VSRenderer::ReleaseVShaderProgram(VSVShader * pVShaderProgram)
{

	
	if(!pVShaderProgram)
		return 0;
	return pVShaderProgram->ReleaseResource();
}

bool VSRenderer::LoadPShaderProgram (VSPShader* pPShaderProgram)
{
	if(!pPShaderProgram)
		return 0;

	return pPShaderProgram->LoadResource(this);

}
bool VSRenderer::ReleasePShaderProgram (VSPShader* pPShaderProgram)
{
	
	if(!pPShaderProgram)
		return 0;

	return pPShaderProgram->ReleaseResource();

}

bool VSRenderer:: LoadTexture (VSTexture * pTexture)
{
	if(!pTexture)
		return 0;

	return pTexture->LoadResource(this);
}
bool VSRenderer::ReleaseTexture (VSTexture * pTexture)
{

	if(!pTexture)
		return 0;

	return pTexture->ReleaseResource();

}
bool VSRenderer::LoadDepthStencil(VSDepthStencil * pDepthStencil)
{
	if(!pDepthStencil)
		return 0;

	return pDepthStencil->LoadResource(this);
}
bool VSRenderer::ReleaseDepthStencil(VSDepthStencil * pDepthStencil)
{
	if(!pDepthStencil)
		return 0;

	return pDepthStencil->ReleaseResource();
}
bool VSRenderer::LoadRenderTarget (VSRenderTarget  * pRenderTarget)
{
	if (!pRenderTarget)
	{
		return 0;
	}
	pRenderTarget->LoadResource(this);
	return 1;
}
bool VSRenderer::ReleaseRenderTarget  (VSRenderTarget * pRenderTarget)
{
	if (!pRenderTarget)
	{
		return 0;
	}
	pRenderTarget->ReleaseResource();
	return 1;
}
bool VSRenderer::LoadBlendState (VSBlendState * pBlendState)
{
	if (!pBlendState)
	{
		return 0;
	}
	if (GetRendererType() == RAT_DIRECTX9)
	{
		return 1;
	}
	pBlendState->LoadResource(this);
	return 1;
}
bool VSRenderer::ReleaseBlendState  (VSBlendState * pBlendState)
{
	if (!pBlendState)
	{
		return 0;
	}
	pBlendState->ReleaseResource();
	return 1;
}

bool VSRenderer::LoadDepthStencilState (VSDepthStencilState * pDepthStencilState)
{
	if (!pDepthStencilState)
	{
		return 0;
	}
	if (GetRendererType() == RAT_DIRECTX9)
	{
		return 1;
	}
	pDepthStencilState->LoadResource(this);
	return 1;
}
bool VSRenderer::ReleaseDepthStencilState  (VSDepthStencilState * pDepthStencilState)
{
	if (!pDepthStencilState)
	{
		return 0;
	}
	pDepthStencilState->ReleaseResource();
	return 1;
}

bool VSRenderer::LoadRasterizerState(VSRasterizerState * pRasterizerState)
{
	if (!pRasterizerState)
	{
		return 0;
	}
	if (GetRendererType() == RAT_DIRECTX9)
	{
		return 1;
	}
	pRasterizerState->LoadResource(this);
	return 1;
}
bool VSRenderer::ReleaseRasterizerState  (VSRasterizerState * pRasterizerState)
{
	if (!pRasterizerState)
	{
		return 0;
	}
	pRasterizerState->ReleaseResource();
	return 1;
}
bool VSRenderer::LoadSamplerState(VSSamplerState * pSamplerState)
{
	if (!pSamplerState)
	{
		return 0;
	}
	if (GetRendererType() == RAT_DIRECTX9)
	{
		return 1;
	}
	pSamplerState->LoadResource(this);
	return 1;
}
bool VSRenderer::ReleaseSamplerState  (VSSamplerState * pSamplerState)
{
	if (!pSamplerState)
	{
		return 0;
	}
	pSamplerState->ReleaseResource();
	return 1;
}
bool VSRenderer::LoadVBuffer(VSVertexBuffer * pVBuffer)
{
	if(!pVBuffer)
		return 0;

	return pVBuffer->LoadResource(this);
}
bool VSRenderer::ReleaseVBuffer(VSVertexBuffer * pVBuffer)
{

	if(!pVBuffer)
		return 0;

	return pVBuffer->ReleaseResource();
}
bool VSRenderer::LoadIBuffer (VSIndexBuffer* pIBuffer)
{
	if(!pIBuffer)
		return 0;

	return pIBuffer->LoadResource(this);

}
bool VSRenderer::ReleaseIBuffer (VSIndexBuffer* pIBuffer)
{
	if(!pIBuffer)
		return 0;

	return pIBuffer->ReleaseResource();

}
bool VSRenderer::LoadFont(VSFont *pFont)
{
	if(!pFont)
		return 0;
	
	return pFont->LoadResource(this);
}
bool VSRenderer::ReleaseFont(VSFont *pFont)
{
	if(!pFont)
		return 0;

	return pFont->ReleaseResource();
}
unsigned int VSRenderer::SetVShader(VSVShader * pVShader)
{
	return FRI_SUCCESS;
}
unsigned int VSRenderer::SetPShader(VSPShader * pPShader)
{
	
	return FRI_SUCCESS;
}
unsigned int VSRenderer::SetMesh(VSMeshDate *pMeshDate)
{

	VSMAC_ASSERT(pMeshDate);
	if(!pMeshDate)
	{	
		return FRI_FAIL;
	}
	

	if(!SetVBuffer(pMeshDate->GetVertexBuffer()))
		return 0;
	if(!SetIBuffer(pMeshDate->GetIndexBuffer()))
		return 0;
	return FRI_SUCCESS;

}
bool VSRenderer::DrawMesh(VSGeometry * pGeometry,VSRenderState * pRenderState,VSVShader * pVShader, VSPShader * pPShader)
{

	if (!pGeometry || !pGeometry->GetMeshDate())
		return 0;

	m_LocalRenderState.GetAll(pRenderState);

	if (pGeometry->IsSwapCull())
	{
		m_LocalRenderState.SwapCull();
	}
	if (m_uiRenderStateInheritFlag)
	{

		m_LocalRenderState.Inherit(&m_UseState, m_uiRenderStateInheritFlag);


	}
	SetRenderState(m_LocalRenderState);
	if (!SetVShader(pVShader))
	{
		return 0;
	}

	if (!SetPShader(pPShader))
	{
		return 0;
	}
	if (SetMesh(pGeometry->GetMeshDate()) == FRI_FAIL)
		return 0;

	return 1;
}	
void VSRenderer::SetVTexAllState(VSTexAllState * pTexAllState,unsigned int i)
{
	if(i >= m_uiMaxVTexture)
		return;
	if(pTexAllState)
	{
		SetVTexture(pTexAllState->m_pTex,i);

	}
	else
	{
		SetVTexture(NULL,i);

	}
}
void VSRenderer::SetTexAllState(VSTexAllState * pTexAllState,unsigned int i)
{
	VSMAC_ASSERT(i < TEXLEVEL);
	if(i >= m_uiMaxTexture)
		return;
	if(pTexAllState)
	{
		SetTexture(pTexAllState->m_pTex,i);
		SetSamplerState(pTexAllState->m_pSamplerState,i);
	}
	else
	{
		SetTexture(NULL,i);
		SetSamplerState(NULL,i);
	}
}
void VSRenderer::EnableTextureRTTextureUsed(VSTexture * pTexture)
{
	if (!pTexture)
	{
		return ;
	}
	if (pTexture->GetTexType() == VSTexture::TT_2D)
	{
		if(((VS2DTexture*)pTexture)->IsRenderTarget())
		{
			((VS2DTexture*)pTexture)->m_bRTTextureUsed = true;
		}
	}
	else if(pTexture->GetTexType() == VSTexture::TT_CUBE)
	{
		if(((VSCubeTexture*)pTexture)->IsRenderTarget())
		{
			((VSCubeTexture*)pTexture)->m_bRTTextureUsed = true;
		}
	}
}
void VSRenderer::DisableTextureRTTextureUsed(VSTexture * pTexture)
{
	if (!pTexture)
	{
		return ;
	}
	if (pTexture->GetTexType() == VSTexture::TT_2D)
	{
		if(((VS2DTexture*)pTexture)->IsRenderTarget())
		{
			((VS2DTexture*)pTexture)->m_bRTTextureUsed = false;
		}
	}
	else if(pTexture->GetTexType() == VSTexture::TT_CUBE)
	{
		if(((VSCubeTexture*)pTexture)->IsRenderTarget())
		{
			((VSCubeTexture*)pTexture)->m_bRTTextureUsed = false;
		}
	}
}
bool VSRenderer::CheckIsTextureCanSet(VSTexture * pTexture)
{
	if (!pTexture)
	{
		return true;
	}
	if (pTexture->GetTexType() == VSTexture::TT_2D)
	{
		if(((VS2DTexture*)pTexture)->IsRenderTarget())
		{
			if(((VS2DTexture*)pTexture)->m_bRtUsed == true)
			{
				VSMAC_ASSERT(0);
				return false;
			}
			else
			{
				return true;		
			}
		}
	}
	else if(pTexture->GetTexType() == VSTexture::TT_CUBE)
	{
		if(((VSCubeTexture*)pTexture)->m_bRtUsed == true)
		{
			VSMAC_ASSERT(0);
			return false;
		}
		else
		{
			return true;		
		}
	}
	return true;
}
unsigned int VSRenderer::SetVTexture (VSTexture* pTexture,unsigned int i)
{

	if (!CheckIsTextureCanSet(pTexture))
	{
		return FRI_FAIL;
	}
	if (m_pVTex[i] == pTexture)
	{
		if (!pTexture)
		{
			return FRI_SAMERESOURCE;
		}
		else if (pTexture && pTexture->GetSwapChainNum() == 1)
		{
			return FRI_SAMERESOURCE;
		}
	}
	if(!pTexture)
	{
		DisableTextureRTTextureUsed(m_pVTex[i]);
		m_pVTex[i] = NULL;
		return FRI_FAIL;
	}
	if(!LoadTexture(pTexture))
	{
		m_pVTex[i] = NULL;
		return FRI_FAIL;
	}
	if(pTexture && !pTexture->IsStatic())
	{

		if (pTexture->GetTexType() == VSTexture::TT_CUBE)
		{
			for (unsigned int i = 0 ; i < pTexture->GetMipLevel() ; i++)
			{
				for(unsigned int j = 0 ; j < VSCubeTexture::F_MAX ; j++)
				{
					VSMAC_ASSERT(!pTexture->GetLockDatePtr(i,j));
					pTexture->UnLock(i,j);
				}
			}

		}
		else
		{
			for (unsigned int i = 0 ; i < pTexture->GetMipLevel() ; i++)
			{
				VSMAC_ASSERT(!pTexture->GetLockDatePtr(i));
				pTexture->UnLock(i);
			}
		}


	}
	DisableTextureRTTextureUsed(m_pVTex[i]);
	EnableTextureRTTextureUsed(pTexture);
	m_pVTex[i] = pTexture;
	return 1;
}
unsigned int VSRenderer::SetTexture (VSTexture* pTexture,unsigned int i)
{
	
	VSMAC_ASSERT(i < TEXLEVEL);
	if (!CheckIsTextureCanSet(pTexture))
	{
		return FRI_FAIL;
	}
	if (m_pPTex[i] == pTexture)
	{
		if (!pTexture)
		{
			return FRI_SAMERESOURCE;
		}
		else if (pTexture && pTexture->GetSwapChainNum() == 1)
		{
			return FRI_SAMERESOURCE;
		}
		
	}
	if(!pTexture)
	{
		DisableTextureRTTextureUsed(m_pPTex[i]);
		m_pPTex[i] = NULL;
		return FRI_FAIL;
	}
	if(!LoadTexture(pTexture))
	{
		m_pPTex[i] = NULL;
		return FRI_FAIL;
	}
	if(pTexture && !pTexture->IsStatic())
	{

		if (pTexture->GetTexType() == VSTexture::TT_CUBE)
		{
			for (unsigned int i = 0 ; i < pTexture->GetMipLevel() ; i++)
			{
				for(unsigned int j = 0 ; j < VSCubeTexture::F_MAX ; j++)
				{
					VSMAC_ASSERT(!pTexture->GetLockDatePtr(i,j));
					pTexture->UnLock(i,j);
				}
			}

		}
		else
		{
			for (unsigned int i = 0 ; i < pTexture->GetMipLevel() ; i++)
			{
				VSMAC_ASSERT(!pTexture->GetLockDatePtr(i));
				pTexture->UnLock(i);
			}
		}


	}
	DisableTextureRTTextureUsed(m_pPTex[i]);
	EnableTextureRTTextureUsed(pTexture);
	m_pPTex[i] = pTexture;
	return 1;
}
unsigned int VSRenderer::SetSamplerState(VSSamplerState * pSamplerState,unsigned int i)
{
	if (!pSamplerState)
	{
		pSamplerState = (VSSamplerState *) VSSamplerState::GetDefault();
	}
	if (!m_pPSamplerState[i])
	{
		m_pPSamplerState[i] = (VSSamplerState *) VSSamplerState::GetDefault();
	}
	if (m_pPSamplerState[i] == pSamplerState)
	{
		return FRI_SAMERESOURCE;
	}
	if(!LoadSamplerState(pSamplerState))
	{
		return FRI_FAIL;
	}
	
	return FRI_SUCCESS;
}
unsigned int VSRenderer::SetBlendState(VSBlendState * pBlendState)
{
	if(!pBlendState)
	{
		pBlendState = (VSBlendState *) VSBlendState::GetDefault();
	}
	if(!m_pBlendState)
	{
		m_pBlendState = (VSBlendState *) VSBlendState::GetDefault();
	}
	if (m_pBlendState == pBlendState)
	{
		return FRI_SAMERESOURCE;
	}
	if(!LoadBlendState(pBlendState))
	{
		return FRI_FAIL;
	}
	
	return FRI_SUCCESS;
}
unsigned int VSRenderer::SetDepthStencilState(VSDepthStencilState * pDepthStencilState)
{
	if(!pDepthStencilState)
	{
		pDepthStencilState = (VSDepthStencilState *) VSDepthStencilState::GetDefault();
	}
	if(!m_pDepthStencilState)
	{
		m_pDepthStencilState = (VSDepthStencilState *) VSDepthStencilState::GetDefault();
	}
	if (m_pDepthStencilState == pDepthStencilState)
	{
		return FRI_SAMERESOURCE;
	}
	if(!LoadDepthStencilState(pDepthStencilState))
	{
		return FRI_FAIL;
	}
	
	return FRI_SUCCESS;
}
unsigned int VSRenderer::SetRasterizerState(VSRasterizerState * pRasterizerState)
{
	if(!pRasterizerState)
	{
		pRasterizerState = (VSRasterizerState *) VSRasterizerState::GetDefault();
	}
	if(!m_pRasterizerState)
	{
		m_pRasterizerState = (VSRasterizerState *) VSRasterizerState::GetDefault();
	}
	if (m_pRasterizerState == pRasterizerState)
	{
		return FRI_SAMERESOURCE;
	}
	if(!LoadRasterizerState(pRasterizerState))
	{
		return FRI_FAIL;
	}
	
	return FRI_SUCCESS;
}
void VSRenderer::SetClipPlane(VSArray<VSPlane3> &Plane,bool bEnable)
{

}
void VSRenderer::SetScissorRect(VSArray<VSRect2> &Rect,bool bEnable)
{

}	
VSRenderer::VSRenderer()
{

	m_pChildWindowInfo = NULL;
	m_ClearColor.Set(1.0f,1.0f,1.0f,1.0f);
	m_fClearDepth = 1.0f;
	m_uiClearStencil = 0;

	m_iNumChildWindow = 0;        
	m_iCurWindowID = -1;
	m_bIsRendering = false;



	m_pBlendState = (VSBlendState *) VSBlendState::GetDefault();
	m_pDepthStencilState = (VSDepthStencilState *) VSDepthStencilState::GetDefault();
	m_pRasterizerState = (VSRasterizerState *) VSRasterizerState::GetDefault();
	m_bClipPlaneEnable = false;
	m_bScissorRectEnable = false;
	m_pFont			= NULL;//VSFont::Default;

	m_pVertexBuffer = NULL;
	m_pVertexFormat = NULL;
	m_pIndexBuffer = NULL;
	m_pVShader = NULL;
	m_pPshader = NULL;
	m_pQuadVertexFormat = NULL;
	m_uiRenderStateInheritFlag = 0;
	VSRenderer::ms_pRenderer = this;
	
}
bool VSRenderer::UseWindow(int uiWindowID)
{
	if(!m_bWindowed)
		return 0;
	else if(uiWindowID >= m_iNumChildWindow)
		return 0;
	else if (uiWindowID < -1)
	{
		return 0;
	}
	m_iCurWindowID = uiWindowID;
	return 1;
}
bool VSRenderer::BeginRendering()
{
	ClearBuffers();
	m_bIsRendering = true;
	return true;
}
bool VSRenderer::EndRendering()
{
	m_bIsRendering = false;
	return true;
}
void VSRenderer::DeviceLost()
{
	
}
void VSRenderer::ResetDevice()
{

}
bool VSRenderer::ChangeScreenSize(unsigned int uiWidth,unsigned int uiHeight,bool bWindow)
{
	if (m_uiScreenHeight == uiHeight && m_uiScreenWidth == uiWidth && m_bWindowed == bWindow)
	{
		
		
		return false;
	}
	if (!bWindow)
	{
		bool bFlag = false;
		for (unsigned int i = 0 ; i < ms_AdapterInfo[0].DisplayMode.GetNum() ; i++)
		{
			if (ms_AdapterInfo[0].DisplayMode[i].uiHeight == uiHeight
				&& ms_AdapterInfo[0].DisplayMode[i].uiWidth == uiWidth
				&& ms_AdapterInfo[0].DisplayMode[i].uiBitFormat == 32)
			{
				bFlag = true;
				break;
			}
		}
		if (!bFlag)
		{
			return false;
		}
	}
	
	
	m_bWindowed = bWindow;
	m_uiScreenHeight = uiHeight;
	m_uiScreenWidth = uiWidth;
	m_uiCurRTWidth = uiWidth;
	m_uiCurRTHeight = uiHeight;
	return true;
}
bool VSRenderer::DrawScreen(SCREEN_QUAD_TYPE ScreenQuad[4])
{
	SetVertexFormat(m_pQuadVertexFormat);
	m_pVertexBuffer = NULL;
	m_pIndexBuffer = NULL;
	return 1;
}
bool VSRenderer::DrawScreen(SCREEN_QUAD_TYPE * pScreenBuffer,unsigned int uiVertexNum,
							VSUSHORT_INDEX * pIndexBuffer,unsigned int uiIndexNum)
{
	VSMAC_ASSERT(pScreenBuffer && uiVertexNum && pIndexBuffer && uiIndexNum);
	if (!pScreenBuffer || !uiVertexNum || !pIndexBuffer || !uiIndexNum)
	{
		return false;
	}
	SetVertexFormat(m_pQuadVertexFormat);
	m_pVertexBuffer = NULL;
	m_pIndexBuffer = NULL;
	return 1;
}
VSString VSRenderer::Float(unsigned int uiIndex)const
{
	if (uiIndex == FI_1)
	{
		return Float();
	}
	else if (uiIndex == FI_2)
	{
		return Float2();
	}
	else if (uiIndex == FI_3)
	{
		return Float3();
	}
	else if (uiIndex == FI_4)
	{
		return Float4();
	}
	else
		VSMAC_ASSERT(1);
	return VSString();


}


void VSRenderer::GetIncludeShader(VSString &OutString)
{
	OutString = ms_IncludeShader;
}

void VSRenderer::GetDynamicShader(VSString &OutString)
{
	OutString = ms_DynamicShader;
}
void VSRenderer::DrawText(VSFont* pFont,int iX, int iY, const VSColorRGBA& rColor,
						  const TCHAR* acText, ...)
{
	if(!acText)
		return; 
	if (!pFont)
	{
		pFont = (VSFont *)VSFont::GetDefalut();
	}
	if(!LoadFont(pFont))
		return ;
	m_pFont = pFont;
	
	TCHAR cch[1024];
	char *pArgs;
	pArgs = (char*) &acText + sizeof(acText);
	VSSprintf(cch, 1024,acText, pArgs);
	VSString String = cch;
	OnDrawText(iX,iY,rColor,String);
}
void DrawTextForProfile(VSFont* pFont, int iX, int iY, const VSColorRGBA& rColor, const TCHAR* acText, ...)
{

}