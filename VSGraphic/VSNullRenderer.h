#ifndef NULLRENDERER_H
#define NULLRENDERER_H
#include "VSRenderer.h"
namespace VSEngine2
{
	class VSGRAPHIC_API VSNullRenderer : public VSRenderer
	{
	public:
		VSNullRenderer();
		virtual ~VSNullRenderer();
		virtual int GetRendererType() const{ return RAT_NULL; }
		virtual void ClearBuffers(unsigned int uiClearFlag);
		virtual void ClearBackBuffer();
		virtual void ClearZBuffer();
		virtual void ClearStencilBuffer();
		virtual void ClearBuffers();

		virtual void ClearBuffers(unsigned int uiClearFlag, int iXPos, int iYPos, int iWidth,
			int iHeight);
		virtual void ClearBackBuffer(int iXPos, int iYPos, int iWidth,
			int iHeight);
		virtual void ClearZBuffer(int iXPos, int iYPos, int iWidth,
			int iHeight);
		virtual void ClearStencilBuffer(int iXPos, int iYPos, int iWidth,
			int iHeight);
		virtual void ClearBuffers(int iXPos, int iYPos, int iWidth,
			int iHeight);

		virtual bool SetViewPort(VSViewPort *pViewPort, unsigned int uiRtWidth, unsigned int uiRtHeight);
		virtual void DrawTextForProfile(VSFont* pFont, int iX, int iY, const VSColorRGBA& rColor, const TCHAR* acText, ...);
		virtual bool UseWindow(int uiWindowID = -1);

		virtual bool CooperativeLevel();
		virtual bool BeginRendering();
		virtual bool EndRendering();

		virtual void DeviceLost();
		virtual void ResetDevice();
		virtual bool ChangeScreenSize(unsigned int uiWidth, unsigned int uiHeight, bool bWindow);
		virtual bool DrawMesh(VSGeometry * pGeometry, VSRenderState * pRenderState, VSVShader * pVShader, VSPShader * pPShader);
		virtual bool DrawScreen(SCREEN_QUAD_TYPE ScreenQuad[4]);
		virtual bool DrawScreen(SCREEN_QUAD_TYPE * pScreenBuffer, unsigned int uiVertexNum,
			VSUSHORT_INDEX * pIndexBuffer, unsigned int uiIndexNum);
		void SetRenderState(VSRenderState & RenderState);
		virtual unsigned int SetBlendState(VSBlendState * pBlendState);
		virtual unsigned int SetDepthStencilState(VSDepthStencilState * pDepthStencilState);
		virtual unsigned int SetRasterizerState(VSRasterizerState * pRasterizerState);
		virtual void SetClipPlane(VSArray<VSPlane3> &Plane, bool bEnable);
		virtual void SetScissorRect(VSArray<VSRect2> &Rect, bool bEnable);

		virtual unsigned int SetVShader(VSVShader * pVShader);
		virtual unsigned int SetPShader(VSPShader * pPShader);
		virtual unsigned int SetVBuffer(VSVertexBuffer * pVBuffer);

		virtual unsigned int SetIBuffer(VSIndexBuffer* pIBuffer);
		virtual unsigned int SetTexture(VSTexture* pTexture, unsigned int i);
		virtual unsigned int SetVTexture(VSTexture* pTexture, unsigned int i);

		virtual unsigned int SetSamplerState(VSSamplerState * pSamplerState, unsigned int i);

		virtual bool SetRenderTarget(VSRenderTarget *pRenderTarget, unsigned int i);
		virtual bool EndRenderTarget(VSRenderTarget *pRenderTarget, unsigned int i);
		virtual bool SetDepthStencilBuffer(VSDepthStencil * pDepthStencilBuffer);
		virtual bool EndDepthStencilBuffer(VSDepthStencil * pDepthStencilBuffer);
		virtual unsigned int GetTextureCompressLen(unsigned int uiLen);
	protected:
		virtual bool SetVProgramConstant(unsigned int uiStartRegister, void * pDate,
			unsigned int RegisterNum, unsigned int uiType);
		virtual bool SetPProgramConstant(unsigned int uiStartRegister, void * pDate,
			unsigned int RegisterNum, unsigned int uiType);

		virtual bool SetVShaderProgram(VSVShader*	pVShaderProgram);
		virtual bool SetPShaderProgram(VSPShader*pPShaderProgram);
		//Load Release
		virtual bool OnLoadVShaderProgram(VSVShader * pVShaderProgram, VSResourceIdentifier *&pID);
		virtual bool OnReleaseVShaderProgram(VSResourceIdentifier * pVShaderProgramID);

		virtual bool OnLoadPShaderProgram(VSPShader* pPShaderProgram, VSResourceIdentifier *&pID);
		virtual bool OnReleasePShaderProgram(VSResourceIdentifier* pPShaderProgramID);

		virtual bool OnLoadTexture(VSTexture * pTexture, VSResourceIdentifier *&pID);
		virtual bool OnReleaseTexture(VSResourceIdentifier * pTextureID);

		virtual bool OnLoadDepthStencil(VSDepthStencil * pDepthStencil, VSResourceIdentifier *&pID);
		virtual bool OnReleaseDepthStencil(VSResourceIdentifier * pDepthStencilID);

		virtual bool OnLoadRenderTarget(VSRenderTarget * pRenderTarget, VSResourceIdentifier *&pID);
		virtual bool OnReleaseRenderTarget(VSResourceIdentifier * pRenderTarget);

		virtual bool OnLoadVBufferDate(VSVertexBuffer * pVBuffer, VSResourceIdentifier *&pID);
		virtual bool OnReleaseVBufferDate(VSResourceIdentifier* pVBufferID);

		virtual bool OnLoadVBufferFormat(VSVertexFormat * pVertexFormat, VSResourceIdentifier *&pID);
		virtual bool OnReleaseVBufferFormat(VSResourceIdentifier* pVBufferID);

		virtual bool OnLoadIBuffer(VSIndexBuffer* pIBuffer, VSResourceIdentifier *&pID);
		virtual bool OnReleaseIBuffer(VSResourceIdentifier* pIBufferID);

		virtual bool OnLoadFont(VSFont * pFont, VSResourceIdentifier *&pID);
		virtual bool OnReleaseFont(VSResourceIdentifier * pFontID);

		virtual bool OnLoadBlendState(VSBlendState * pBlendState, VSResourceIdentifier *&pID);
		virtual bool OnReleaseBlendState(VSResourceIdentifier * pBlendStateID);

		virtual bool OnLoadDepthStencilState(VSDepthStencilState * pDepthStencilState, VSResourceIdentifier *&pID);
		virtual bool OnReleaseDepthStencilState(VSResourceIdentifier * pDepthStencilStateID);

		virtual bool OnLoadRasterizerState(VSRasterizerState * pRasterizerState, VSResourceIdentifier *&pID);
		virtual bool OnReleaseRasterizerState(VSResourceIdentifier * pRasterizerStateID);

		virtual bool OnLoadSamplerState(VSSamplerState * pSamplerState, VSResourceIdentifier *&pID);
		virtual bool OnReleaseSamplerState(VSResourceIdentifier * pSamplerStateID);

		virtual unsigned int SetVertexFormat(VSVertexFormat * pVertexFormat);

		virtual void * Lock(VSVertexBuffer * pVertexBuffer);
		virtual void UnLock(VSVertexBuffer * pVertexBuffer);

		virtual void * Lock(VSIndexBuffer * pIndexBuffer);
		virtual void UnLock(VSIndexBuffer * pIndexBuffer);

		virtual void * Lock(VSTexture * pTexture, unsigned int uiLevel, unsigned int uiFace);
		virtual void UnLock(VSTexture * pTexture, unsigned int uiLevel, unsigned int uiFace);
		virtual bool CopyResourceBuffer(VS2DTexture * pSource, VSCubeTexture * pDest, unsigned int uiFace);

		virtual void OnDrawText(int iX, int iY, const VSColorRGBA& rColor, VSString & String);
	public:
		//shader function
		virtual VSString TexColorBuffer(const VSColorBuffer * pColorBuffer) const;
		virtual VSString Tex2D(const VS2DTexSampler * p2DTexSampler) const;
		virtual VSString Tex1D(const VS1DTexSampler * p1DTexSampler) const;
		virtual VSString Mul(const VSMul * pMul) const;
		virtual VSString Div(const VSDiv * pDiv) const;
		virtual VSString Dot(const VSDot * pDot) const;
		virtual VSString Sub(const VSSub * pSub) const;
		virtual VSString Add(const VSAdd * pAdd) const;
		virtual VSString MakeValue(const VSMakeValue * pMakeValue) const;
		virtual VSString Saturate(const VSSaturate * pSaturate) const;
		VSString Float(unsigned int uiIndex)const;
		virtual VSString Sampler(unsigned int uiType)const;
		virtual VSString Float()const;
		virtual VSString Float2()const;
		virtual VSString Float3()const;
		virtual VSString Float4()const;
		virtual VSString Return()const;

		virtual VSString FloatConst(const VSString & Value1)const;
		virtual VSString Float2Const(const VSString & Value1, const VSString & Value2)const;
		virtual VSString Float3Const(const VSString & Value1,
			const VSString & Value2, const VSString & Value3)const;
		virtual VSString Float4Const(const VSString & Value1, const VSString & Value2,
			const VSString & Value3, const VSString & Value4)const;

		virtual void CustomPointLightUseString(VSString & PointLightUseString, VSString & PointAttenuationDivString);

		virtual void CustomSpotLightUseString(VSString & SpotLightUseString, VSString & SpotAttenuationDivString);


		virtual VSString GetValueElement(const VSPutNode * pPutNode,
			unsigned char uiVE)const;
		virtual VSString GetValueElement(const VSString & InputString,
			unsigned char uiVE)const;
		virtual VSString SetRegister(unsigned int uiRegisterType, unsigned int uiRegisterIndex)const;


		//shader custom function
		virtual void CreateVInputDeclare(MaterialShaderPara &MSPara, unsigned int uiPassType,
			VSString & OutString);
		virtual void CreateVOutputDeclare(MaterialShaderPara &MSPara, unsigned int uiPassType,
			VSString & OutString);
		virtual void CreateVUserConstant(VSVShader * pVShader, MaterialShaderPara &MSPara, unsigned int uiPassType,
			VSString & OutString);
		virtual void CreateVFuntion(MaterialShaderPara &MSPara, unsigned int uiPassType,
			VSString & OutString);

		virtual void SetMaterialVShaderConstant(MaterialShaderPara &MSPara, unsigned int uiPassType, VSVShader *pVShader);

		virtual void CreatePInputDeclare(MaterialShaderPara &MSPara, unsigned int uiPassType,
			VSString & OutString);
		virtual void CreatePOutputDeclare(MaterialShaderPara &MSPara, unsigned int uiPassType,
			VSString & OutString);
		virtual void CreatePUserConstant(VSPShader * pPShader, MaterialShaderPara &MSPara, unsigned int uiPassType,
			VSString & OutString);
		virtual void CreatePFuntion(MaterialShaderPara &MSPara, unsigned int uiPassType,
			VSString & OutString);

		virtual void SetMaterialPShaderConstant(MaterialShaderPara &MSPara, unsigned int uiPassType, VSPShader *pPShader);



		virtual void GetIncludeShader(VSString &OutString);

		virtual void GetDynamicShader(VSString &OutString);


		virtual void SkyLight(const VSString &WorldNormal, const VSString &UpColor, const VSString & DownColor, const VSString & DiffuseColor, VSString & OutString);
		virtual void DirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
			const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void CustomDirectionalLight(int iLightNum, const VSString &CustomString, VSArray<VSString> ShadowString, VSString & OutString)const;

		virtual void OrenNayarDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &RoughnessSquared,
			const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void MinnaertDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Power,
			const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void StraussDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &Smoothness,
			const VSString &Metalness, const VSString &Transparency, const VSString &K,
			const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void ShirleyDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &NU, const VSString &NV, const VSString &Rs,
			const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void SchlickDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
			const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void CookTorranceDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &Roughness, const VSString &C, const VSString &R,
			const VSString &WorldNormal, const VSString &WorldCameraDir, unsigned int uiSpecularType, VSArray<VSString> ShadowString,
			VSString & OutString)const;

		virtual void IsotropicWardDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &Roughness,
			const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void AnisotropicWardDirectionalLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &RoughnessX, const VSString &RoughnessY,
			const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;

		virtual void PointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void CustomPointLight(int iLightNum, const VSString &CustomString, const VSString & WorldPos, VSArray<VSString> ShadowString, VSString & OutString)const;

		virtual void OrenNayarPointLight(int iLightNum, const VSString &Diffuse, const VSString &RoughnessSquared,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void MinnaertPointLight(int iLightNum, const VSString &Diffuse, const VSString &Power,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void StraussPointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &Smoothness,
			const VSString &Metalness, const VSString &Transparency, const VSString &K,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void ShirleyPointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &NU, const VSString &NV, const VSString &Rs,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void SchlickPointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void CookTorrancePointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &Roughness, const VSString &C, const VSString &R,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, unsigned int uiSpecularType, VSArray<VSString> ShadowString,
			VSString & OutString)const;

		virtual void IsotropicWardPointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &Roughness,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void AnisotropicWardPointLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &RoughnessX, const VSString &RoughnessY,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;

		virtual void SpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void CustomSpotLight(int iLightNum, const VSString &CustomString, const VSString & WorldPos, VSArray<VSString> ShadowString, VSString & OutString)const;
		virtual void OrenNayarSpotLight(int iLightNum, const VSString &Diffuse, const VSString &RoughnessSquared,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void MinnaertSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Power,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void StraussSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &Smoothness,
			const VSString &Metalness, const VSString &Transparency, const VSString &K,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void ShirleySpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &NU, const VSString &NV, const VSString &Rs,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void SchlickSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular, const VSString &SpecularPow,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void CookTorranceSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &Roughness, const VSString &C, const VSString &R,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, unsigned int uiSpecularType, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void IsotropicWardSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &Roughness,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, bool bLookUpTable, VSArray<VSString> ShadowString,
			VSString & OutString)const;
		virtual void AnisotropicWardSpotLight(int iLightNum, const VSString &Diffuse, const VSString &Specular,
			const VSString &RoughnessX, const VSString &RoughnessY,
			const VSString & WorldPos, const VSString &WorldNormal, const VSString &WorldCameraDir, VSArray<VSString> ShadowString,
			VSString & OutString)const;

		virtual void LocalToWorldPos(const VSString & LocalPos, VSString &OutString)const;
		virtual void WorldToViewPos(const VSString & LocalPos, VSString &OutString)const;

		virtual void LocalToWorldNormal(const VSString & LocalNormal, VSString &OutString)const;

		virtual void WorldToViewNormal(const VSString & WorldNormal, VSString &OutString)const;

		virtual void GetWorldViewDir(VSString &OutString)const;

		virtual void LocalToViewNormal(const VSString & LocalNormal, VSString &OutString)const;
		virtual void TransProjPos(const VSString & Pos, const VSString & Matrix, VSString &OutString)const;
		virtual void BumpNormal(const VSString &TexNormal, VSString &OutString)const;

		virtual void ComputeDir(const VSString & Orgin, const VSString & End, VSString &OutString)const;
		virtual void ComputeLength(const VSString & Orgin, const VSString & End, VSString &OutString)const;
		virtual void ComputeBoneVector(const VSString& BoneIndex, const VSString & BoneWeight, const VSString &BoneVector,
			const  VSString & U, const VSString & V, const VSString &N, VSString &OutString)const;

		virtual void BoneTranPos(const VSString & LocalPos, const  VSString & U, const VSString & V, const VSString &N, VSString &OutString)const;
		virtual void BoneTranNormal(const VSString & LocalNormal, const  VSString & U, const VSString & V, const VSString &N, VSString &OutString)const;

		virtual void DecodeNormal1(const VSString & Normal, VSString &OutString) const;
		virtual void RecodeNormal1(const VSString & Normal, VSString &OutString) const;
		virtual void DecodeNormal2(const VSString & Normal, const VSString & Tengent, VSString &OutString) const;

		virtual void DecodeNormal3(const VSString & Normal, VSString &OutString) const;
		virtual void RecodeNormal3(const VSString & Normal, VSString &OutString) const;

		virtual void Reciprocal(const VSString & Value, VSString &OutString)const;
		virtual void Clip(const VSString & ClipValue, VSString &OutString)const;
		virtual void GreaterZeroPow(const VSString & Value, VSREAL Exp, VSString &OutString) const;
		virtual void SaturatePow(const VSString & Value, VSREAL Exp, VSString &OutString) const;
		virtual void Saturate(const VSString & Value, VSString &OutString)const;

		virtual void PointLightCubeShadow(const VSString & PointLightName, const VSString & CubeShadowSampler, const VSString & ViewMatrix,
			const VSString & WorldPos, VSString& OutString)const;

		virtual void PointLightCubeShadow(const VSString & PointLightName, const VSString & CubeShadowSampler,
			const VSString & WorldPos, VSString& OutString)const;

		virtual void PointLightVolumeShadow(const VSString & PointLightName, const VSString & VolumeShadowSampler,
			const VSString & WorldPos, VSString& OutString)const;

		virtual void PointLightDualParaboloidShadow(const VSString & PointLightName, const VSString & ShadowSampler,
			const VSString & WorldPos, VSString& OutString)const;
		virtual void DirectionLightVolumeShadow(const VSString & DirLightName, const VSString & VolumeShadowSampler,
			const VSString & WorldPos, VSString& OutString)const;

		virtual void DirectionLightCSMShadow(const VSString & DirLightName, const VSString & ShadowSampler,
			const VSString & WorldPos, const VSString & ViewPos, const VSString &FarZ, VSString& OutString)const;

		virtual void DirectionLightShadow(const VSString & DirLightName, const VSString & ShadowSampler,
			const VSString & WorldPos, VSString& OutString)const;

		virtual void SpotLightShadow(const VSString & SpotLightName, const VSString & ShadowSampler,
			const VSString & WorldPos, VSString& OutString)const;

		virtual void TranLightToTemp(VSArray<VSLight *> LightArray, VSString & OutString)const;

		virtual void GetLightFunction(VSArray<VSLight *> LightArray, const VSString & WorldPos, VSString & OutString)const;

		virtual void EncodeReflect(const VSString & Mip, const VSString & Pow, VSString& OutString);

		virtual void DecodeReflect(const VSString & Mip, const VSString & Pow, const VSString & Value, VSString& OutString);

	};
	
}
#endif
