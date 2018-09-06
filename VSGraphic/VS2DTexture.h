#ifndef VS2DTEXTURE_H
#define VS2DTEXTURE_H
#include "VSTexture.h"
namespace VSEngine2
{
	class VSRenderTarget;
	class VSGRAPHIC_API VS2DTexture:public VSTexture
	{
		//PRIORITY
		
		//RTTI
		DECLARE_RTTI;
	public:
		VS2DTexture(unsigned int uiWidth, unsigned int uiHeight,unsigned int uiFormatType,
					unsigned int uiMipLevel /*= 0*/,bool bIsStatic/* = true*/);
		VS2DTexture(unsigned int uiWidth, unsigned int uiHeight,unsigned int uiFormatType,unsigned int uiMipLevel = 1);
		virtual ~VS2DTexture();

		virtual unsigned int GetTexType()const{return TT_2D;}
		FORCEINLINE bool IsRenderTarget()const
		{
			return m_bRenderTarget;
		}
		virtual void SetMipLevel();
		bool SaveToFile(TCHAR * pSaveName);
		virtual void CreateRAMDate();

		DECLARE_INITIAL

		//�жϵ�ǰtexture�Ƿ���ʹ�ã������ʹ�ò�����rendertarget texture ����VSResoureManager::GetRenderTarget�ǲ����ȡ����
		//Ҳ����˵��ȡ����rendertarget����������texture һ����û���õģ������������rendertarget�����ˣ�Ȼ����ͬʱ������texture
		//�������������Ϊ��ɵģ�����ϵͳ�������
		bool m_bRTTextureUsed;

		//���������֤���rendertarget���ý�ȥ����texture���������ã������������ʾ��
		bool m_bRtUsed;
	public:
		friend class VSRenderer;
		friend class VSTexAllState;
	protected:
		VS2DTexture();
		bool m_bRenderTarget;
		
	
	};
	DECLARE_Ptr(VS2DTexture);
	VSTYPE_MARCO(VS2DTexture);
}
#endif