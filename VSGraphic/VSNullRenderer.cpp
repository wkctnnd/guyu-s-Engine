#include "VSNullRenderer.h"
#include "VSGraphicInclude.h"
using namespace VSEngine2;
VSNullRenderer::VSNullRenderer()
{
	
}
VSNullRenderer::~VSNullRenderer()
{

}
void VSNullRenderer::ClearBuffers(unsigned int uiClearFlag){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ClearBackBuffer(){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ClearZBuffer(){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ClearStencilBuffer(){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ClearBuffers(){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ClearBuffers(unsigned int uiClearFlag, int iXPos, int iYPos, int iWidth,
	int iHeight){
	VSMAC_ASSERT(0); return;
}
void VSNullRenderer::ClearBackBuffer(int iXPos, int iYPos, int iWidth,
	int iHeight){
	VSMAC_ASSERT(0); return;
}
void VSNullRenderer::ClearZBuffer(int iXPos, int iYPos, int iWidth,
	int iHeight){
	VSMAC_ASSERT(0); return;
}
void VSNullRenderer::ClearStencilBuffer(int iXPos, int iYPos, int iWidth,
	int iHeight){
	VSMAC_ASSERT(0); return;
}
void VSNullRenderer::ClearBuffers(int iXPos, int iYPos, int iWidth,
	int iHeight){
	VSMAC_ASSERT(0); return;
}
bool VSNullRenderer::SetViewPort(VSViewPort *pViewPort, unsigned int uiRtWidth, unsigned int uiRtHeight){VSMAC_ASSERT(0);return 0;}
void VSNullRenderer::DrawTextForProfile(VSFont* pFont, int iX, int iY, const VSColorRGBA& rColor, const TCHAR* acText, ...){VSMAC_ASSERT(0); return; }
bool VSNullRenderer::UseWindow(int uiWindowID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::CooperativeLevel(){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::BeginRendering(){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::EndRendering(){VSMAC_ASSERT(0);return 0;}

void VSNullRenderer::DeviceLost(){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ResetDevice(){VSMAC_ASSERT(0);return ;}
bool VSNullRenderer::ChangeScreenSize(unsigned int uiWidth, unsigned int uiHeight, bool bWindow){VSMAC_ASSERT(0);return 0 ;}
bool VSNullRenderer::DrawMesh(VSGeometry * pGeometry, VSRenderState * pRenderState, VSVShader * pVShader, VSPShader * pPShader){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::DrawScreen(SCREEN_QUAD_TYPE ScreenQuad[4]){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::DrawScreen(SCREEN_QUAD_TYPE * pScreenBuffer, unsigned int uiVertexNum,
	VSUSHORT_INDEX * pIndexBuffer, unsigned int uiIndexNum){VSMAC_ASSERT(0);return 0;}
void VSNullRenderer::SetRenderState(VSRenderState & RenderState){VSMAC_ASSERT(0);return ;}
unsigned int VSNullRenderer::SetBlendState(VSBlendState * pBlendState){VSMAC_ASSERT(0);return 0;}
unsigned int VSNullRenderer::SetDepthStencilState(VSDepthStencilState * pDepthStencilState){VSMAC_ASSERT(0);return 0;}
unsigned int VSNullRenderer::SetRasterizerState(VSRasterizerState * pRasterizerState){VSMAC_ASSERT(0);return 0 ;}
void VSNullRenderer::SetClipPlane(VSArray<VSPlane3> &Plane, bool bEnable){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::SetScissorRect(VSArray<VSRect2> &Rect, bool bEnable){VSMAC_ASSERT(0);return ;}

unsigned int VSNullRenderer::SetVShader(VSVShader * pVShader){VSMAC_ASSERT(0);return 0;}
unsigned int VSNullRenderer::SetPShader(VSPShader * pPShader){VSMAC_ASSERT(0);return 0;}
unsigned int VSNullRenderer::SetVBuffer(VSVertexBuffer * pVBuffer){VSMAC_ASSERT(0);return 0;}

unsigned int VSNullRenderer::SetIBuffer(VSIndexBuffer* pIBuffer){VSMAC_ASSERT(0);return 0;}
unsigned int VSNullRenderer::SetTexture(VSTexture* pTexture, unsigned int i){VSMAC_ASSERT(0);return 0;}
unsigned int VSNullRenderer::SetVTexture(VSTexture* pTexture, unsigned int i){VSMAC_ASSERT(0);return 0;}

unsigned int VSNullRenderer::SetSamplerState(VSSamplerState * pSamplerState, unsigned int i){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::SetRenderTarget(VSRenderTarget *pRenderTarget, unsigned int i){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::EndRenderTarget(VSRenderTarget *pRenderTarget, unsigned int i){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::SetDepthStencilBuffer(VSDepthStencil * pDepthStencilBuffer){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::EndDepthStencilBuffer(VSDepthStencil * pDepthStencilBuffer){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::SetVProgramConstant(unsigned int uiStartRegister, void * pDate,
	unsigned int RegisterNum, unsigned int uiType){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::SetPProgramConstant(unsigned int uiStartRegister, void * pDate,
	unsigned int RegisterNum, unsigned int uiType){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::SetVShaderProgram(VSVShader*	pVShaderProgram){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::SetPShaderProgram(VSPShader*pPShaderProgram){VSMAC_ASSERT(0);return 0;}
//Load Release
bool VSNullRenderer::OnLoadVShaderProgram(VSVShader * pVShaderProgram, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseVShaderProgram(VSResourceIdentifier * pVShaderProgramID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadPShaderProgram(VSPShader* pPShaderProgram, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleasePShaderProgram(VSResourceIdentifier* pPShaderProgramID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadTexture(VSTexture * pTexture, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseTexture(VSResourceIdentifier * pTextureID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadDepthStencil(VSDepthStencil * pDepthStencil, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseDepthStencil(VSResourceIdentifier * pDepthStencilID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadRenderTarget(VSRenderTarget * pRenderTarget, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseRenderTarget(VSResourceIdentifier * pRenderTarget){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadVBufferDate(VSVertexBuffer * pVBuffer, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseVBufferDate(VSResourceIdentifier* pVBufferID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadVBufferFormat(VSVertexFormat * pVertexFormat, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseVBufferFormat(VSResourceIdentifier* pVBufferID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadIBuffer(VSIndexBuffer* pIBuffer, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseIBuffer(VSResourceIdentifier* pIBufferID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadFont(VSFont * pFont, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseFont(VSResourceIdentifier * pFontID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadBlendState(VSBlendState * pBlendState, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseBlendState(VSResourceIdentifier * pBlendStateID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadDepthStencilState(VSDepthStencilState * pDepthStencilState, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseDepthStencilState(VSResourceIdentifier * pDepthStencilStateID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadRasterizerState(VSRasterizerState * pRasterizerState, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseRasterizerState(VSResourceIdentifier * pRasterizerStateID){VSMAC_ASSERT(0);return 0;}

bool VSNullRenderer::OnLoadSamplerState(VSSamplerState * pSamplerState, VSResourceIdentifier *&pID){VSMAC_ASSERT(0);return 0;}
bool VSNullRenderer::OnReleaseSamplerState(VSResourceIdentifier * pSamplerStateID){VSMAC_ASSERT(0);return 0;}

unsigned int VSNullRenderer::SetVertexFormat(VSVertexFormat * pVertexFormat){VSMAC_ASSERT(0);return 0;}

void * VSNullRenderer::Lock(VSVertexBuffer * pVertexBuffer){VSMAC_ASSERT(0);return NULL;}
void VSNullRenderer::UnLock(VSVertexBuffer * pVertexBuffer){VSMAC_ASSERT(0);return ;}

void * VSNullRenderer::Lock(VSIndexBuffer * pIndexBuffer){ VSMAC_ASSERT(0); return NULL; }
void VSNullRenderer::UnLock(VSIndexBuffer * pIndexBuffer){VSMAC_ASSERT(0);return ;}

void * VSNullRenderer::Lock(VSTexture * pTexture, unsigned int uiLevel, unsigned int uiFace){ VSMAC_ASSERT(0); return NULL; }
void VSNullRenderer::UnLock(VSTexture * pTexture, unsigned int uiLevel, unsigned int uiFace){VSMAC_ASSERT(0);return ;}
bool VSNullRenderer::CopyResourceBuffer(VS2DTexture * pSource, VSCubeTexture * pDest, unsigned int uiFace){VSMAC_ASSERT(0);return 0;}

void VSNullRenderer::OnDrawText(int iX, int iY, const VSColorRGBA& rColor, VSString & String){VSMAC_ASSERT(0);return ;}
VSString VSNullRenderer::Tex2D(const VS2DTexSampler * p2DTexSampler) const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Tex1D(const VS1DTexSampler * p1DTexSampler) const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::TexColorBuffer(const VSColorBuffer * pColorBuffer) const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Mul(const VSMul * pMul) const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Saturate(const VSSaturate * pSaturate) const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Div(const VSDiv * pDiv) const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Dot(const VSDot * pDot) const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Sub(const VSSub * pSub) const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Add(const VSAdd * pAdd) const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::MakeValue(const VSMakeValue * pMakeValue)const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Float(unsigned int uiIndex)const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Sampler(unsigned int uiType)const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Float()const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Float2()const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Float3()const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Float4()const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Return()const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }

VSString VSNullRenderer::FloatConst(const VSString & Value1)const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Float2Const(const VSString & Value1, const VSString & Value2)const{ VSMAC_ASSERT(0); return VSString::ms_StringNULL; }
VSString VSNullRenderer::Float3Const(const VSString & Value1,
	const VSString & Value2, const VSString & Value3)const{
	VSMAC_ASSERT(0); return VSString::ms_StringNULL;
}
VSString VSNullRenderer::Float4Const(const VSString & Value1, const VSString & Value2,
	const VSString & Value3, const VSString & Value4)const{
	VSMAC_ASSERT(0); return VSString::ms_StringNULL;
}

void VSNullRenderer::CustomPointLightUseString(VSString & PointLightUseString, VSString & PointAttenuationDivString){VSMAC_ASSERT(0);return ;}

void VSNullRenderer::CustomSpotLightUseString(VSString & SpotLightUseString, VSString & SpotAttenuationDivString){VSMAC_ASSERT(0);return ;}

VSString VSNullRenderer::SetRegister(unsigned int uiRegisterType, unsigned int uiRegisterIndex)const{VSMAC_ASSERT(0);return VSString::ms_StringNULL;}


//shader custom function
void VSNullRenderer::CreateVInputDeclare(MaterialShaderPara &MSPara, unsigned int uiPassType,
	VSString & OutString){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CreateVOutputDeclare(MaterialShaderPara &MSPara, unsigned int uiPassType,
	VSString & OutString){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CreateVUserConstant(VSVShader * pVShader, MaterialShaderPara &MSPara, unsigned int uiPassType,
	VSString & OutString){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CreateVFuntion(MaterialShaderPara &MSPara, unsigned int uiPassType,
	VSString & OutString){VSMAC_ASSERT(0);return ;}

void VSNullRenderer::SetMaterialVShaderConstant(MaterialShaderPara &MSPara, unsigned int uiPassType, VSVShader *pVShader){VSMAC_ASSERT(0);return ;}

void VSNullRenderer::CreatePInputDeclare(MaterialShaderPara &MSPara, unsigned int uiPassType,
	VSString & OutString){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CreatePOutputDeclare(MaterialShaderPara &MSPara, unsigned int uiPassType,
	VSString & OutString){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CreatePUserConstant(VSPShader * pPShader, MaterialShaderPara &MSPara, unsigned int uiPassType,
	VSString & OutString){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CreatePFuntion(MaterialShaderPara &MSPara, unsigned int uiPassType,
	VSString & OutString){VSMAC_ASSERT(0);return ;}

void VSNullRenderer::SetMaterialPShaderConstant(MaterialShaderPara &MSPara, unsigned int uiPassType, VSPShader *pPShader){VSMAC_ASSERT(0);return ;}



void VSNullRenderer::GetIncludeShader(VSString &OutString){VSMAC_ASSERT(0);return ;}

void VSNullRenderer::GetDynamicShader(VSString &OutString){VSMAC_ASSERT(0);return ;}


void VSNullRenderer::SkyLight(const VSString &WorldNormal, const VSString &UpColor, const VSString & DownColor, const VSString & DiffuseColor, VSString & OutString){VSMAC_ASSERT(0);return ;}
void VSNullRenderer::DirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
	const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CustomDirectionalLight(int iLightNum, const VSString &CustomString, VSArray<VSString> ShadowString, VSString & OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::OrenNayarDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &RoughnessSquared,
	const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::MinnaertDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Power,
	const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::StraussDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &Smoothness,
	const VSString &Metalness, const VSString &Transparency, const VSString &K,
	const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ShirleyDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &NU, const VSString &NV, const VSString &Rs,
	const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::SchlickDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
	const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CookTorranceDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &Roughness, const VSString &C, const VSString &R,
	const VSString &WorldNormal, const VSString &WorldCameraDir, unsigned int uiSpecularType, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::IsotropicWardDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &Roughness,
	const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::AnisotropicWardDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &RoughnessX, const VSString &RoughnessY,
	const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::PointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CustomPointLight(int iLightNum, const VSString &CustomString, const VSString & WorldPos, VSArray<VSString> ShadowString, VSString & OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::OrenNayarPointLight(int iLightNum, const VSString &Diffuse, const VSString &RoughnessSquared,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::MinnaertPointLight(int iLightNum, const VSString &Diffuse, const VSString &Power,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::StraussPointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &Smoothness,
	const VSString &Metalness, const VSString &Transparency, const VSString &K,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ShirleyPointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &NU, const VSString &NV, const VSString &Rs,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::SchlickPointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CookTorrancePointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &Roughness, const VSString &C, const VSString &R,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, unsigned int uiSpecularType, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::IsotropicWardPointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &Roughness,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::AnisotropicWardPointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &RoughnessX, const VSString &RoughnessY,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::SpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CustomSpotLight(int iLightNum, const VSString &CustomString, const VSString & WorldPos, VSArray<VSString> ShadowString, VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::OrenNayarSpotLight(int iLightNum, const VSString &Diffuse, const VSString &RoughnessSquared,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::MinnaertSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Power,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::StraussSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &Smoothness,
	const VSString &Metalness, const VSString &Transparency, const VSString &K,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ShirleySpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &NU, const VSString &NV, const VSString &Rs,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::SchlickSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::CookTorranceSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &Roughness, const VSString &C, const VSString &R,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, unsigned int uiSpecularType, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::IsotropicWardSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &Roughness,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::AnisotropicWardSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
	const VSString &RoughnessX, const VSString &RoughnessY,
	const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
	VSString & OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::LocalToWorldPos(const VSString & LocalPos, VSString &OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::WorldToViewPos(const VSString & LocalPos, VSString &OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::LocalToWorldNormal(const VSString & LocalNormal, VSString &OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::WorldToViewNormal(const VSString & WorldNormal, VSString &OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::GetWorldViewDir(VSString &OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::LocalToViewNormal(const VSString & LocalNormal, VSString &OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::TransProjPos(const VSString & Pos, const VSString & Matrix, VSString &OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::BumpNormal(const VSString &TexNormal, VSString &OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::ComputeDir(const VSString & Orgin, const VSString & End, VSString &OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ComputeLength(const VSString & Orgin, const VSString & End, VSString &OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::ComputeBoneVector(const VSString& BoneIndex, const VSString & BoneWeight, const VSString &BoneVector,
	const  VSString & U, const VSString & V, const VSString &N, VSString &OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::BoneTranPos(const VSString & LocalPos, const  VSString & U, const VSString & V, const VSString &N, VSString &OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::BoneTranNormal(const VSString & LocalNormal, const  VSString & U, const VSString & V, const VSString &N, VSString &OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::DecodeNormal1(const VSString & Normal, VSString &OutString) const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::RecodeNormal1(const VSString & Normal, VSString &OutString) const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::DecodeNormal2(const VSString & Normal, const VSString & Tengent, VSString &OutString) const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::DecodeNormal3(const VSString & Normal, VSString &OutString) const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::RecodeNormal3(const VSString & Normal, VSString &OutString) const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::Reciprocal(const VSString & Value, VSString &OutString)const{ VSMAC_ASSERT(0); return; }
void VSNullRenderer::Clip(const VSString & ClipValue, VSString &OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::GreaterZeroPow(const VSString & Value, VSREAL Exp, VSString &OutString) const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::SaturatePow(const VSString & Value, VSREAL Exp, VSString &OutString) const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::Saturate(const VSString & Value, VSString &OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::PointLightCubeShadow(const VSString & PointLightName, const VSString & CubeShadowSampler, const VSString & ViewMatrix,
	const VSString & WorldPos, VSString& OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::PointLightCubeShadow(const VSString & PointLightName, const VSString & CubeShadowSampler,
	const VSString & WorldPos, VSString& OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::PointLightVolumeShadow(const VSString & PointLightName, const VSString & VolumeShadowSampler,
	const VSString & WorldPos, VSString& OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::PointLightDualParaboloidShadow(const VSString & PointLightName, const VSString & ShadowSampler,
	const VSString & WorldPos, VSString& OutString)const{VSMAC_ASSERT(0);return ;}
void VSNullRenderer::DirectionLightVolumeShadow(const VSString & DirLightName, const VSString & VolumeShadowSampler,
	const VSString & WorldPos, VSString& OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::DirectionLightCSMShadow(const VSString & DirLightName, const VSString & ShadowSampler,
	const VSString & WorldPos, const VSString & ViewPos, const VSString &FarZ, VSString& OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::DirectionLightShadow(const VSString & DirLightName, const VSString & ShadowSampler,
	const VSString & WorldPos, VSString& OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::SpotLightShadow(const VSString & SpotLightName, const VSString & ShadowSampler,
	const VSString & WorldPos, VSString& OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::TranLightToTemp(VSArray<VSLight *> LightArray, VSString & OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::GetLightFunction(VSArray<VSLight *> LightArray, const VSString & WorldPos, VSString & OutString)const{VSMAC_ASSERT(0);return ;}

void VSNullRenderer::EncodeReflect(const VSString & Mip, const VSString & Pow, VSString& OutString){VSMAC_ASSERT(0);return ;}

void VSNullRenderer::DecodeReflect(const VSString & Mip, const VSString & Pow, const VSString & Value, VSString& OutString){VSMAC_ASSERT(0);return ;}
unsigned int VSNullRenderer::GetTextureCompressLen(unsigned int uiLen)
{
	return Max((unsigned int)1, (unsigned int)(uiLen / 4));
}
VSString VSNullRenderer::GetValueElement(const VSPutNode * pPutNode,
	unsigned char uiVE)const
{
	VSMAC_ASSERT(pPutNode);
	if (!pPutNode)
		return VSString::ms_StringNULL;
	VSString Temp = pPutNode->GetNodeName().GetString();
	if (uiVE > 0)
	{
		if (pPutNode->GetValueType() == VSPutNode::VT_1 && (uiVE & VE_R))
		{
			return Temp;
		}
		else if (pPutNode->GetValueType() == VSPutNode::VT_1)
		{
			VSMAC_ASSERT(0);
			return VSString::ms_StringNULL;
		}
		VSString Value[4];
		Value[0] = _T("r");
		Value[1] = _T("g");
		Value[2] = _T("b");
		Value[3] = _T("a");
		unsigned int Mask[4];
		Mask[0] = VE_R;
		Mask[1] = VE_G;
		Mask[2] = VE_B;
		Mask[3] = VE_A;
		Temp += _T(".");

		for (unsigned int i = 0; i < 4; i++)
		{
			if (i <= pPutNode->GetValueType())
			{
				if (uiVE & Mask[i])
				{
					Temp += Value[i];
				}
			}

		}

	}


	return Temp;
}
VSString VSNullRenderer::GetValueElement(const VSString & InputString,
	unsigned char uiVE)const
{
	VSString Temp = InputString;
	if (uiVE > 0)
	{
		VSString Value[4];
		Value[0] = _T("r");
		Value[1] = _T("g");
		Value[2] = _T("b");
		Value[3] = _T("a");
		unsigned int Mask[4];
		Mask[0] = VE_R;
		Mask[1] = VE_G;
		Mask[2] = VE_B;
		Mask[3] = VE_A;
		Temp += _T(".");

		for (unsigned int i = 0; i < 4; i++)
		{
			if (uiVE & Mask[i])
			{
				Temp += Value[i];
			}
		}
	}
	return Temp;
}