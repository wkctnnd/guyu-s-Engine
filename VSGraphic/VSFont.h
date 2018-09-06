#ifndef VSFONT_H
#define VSFONT_H
#include "VSObject.h"
#include "VSBind.h"
namespace VSEngine2
{
	class VSStream;
	class VSGRAPHIC_API VSFont : public VSBind
	{
		//PRIORITY
		
		//RTTI
		DECLARE_RTTI;
		DECLARE_INITIAL
	public:
		VSFont(const TCHAR* acFace, unsigned int uiSize, bool bBold,
				bool bItalic);
		virtual ~VSFont();
	protected:
		VSFont();
	public:


		static bool InitialDefaultState();
		static bool TerminalDefaultState();

	protected:
		
		static VSPointer<VSFont> Default;
	public:
		friend class VSRenderer;
		static const VSFont *GetDefalut()
		{
			return Default;
		}
		FORCEINLINE const VSString & GetFace()const {return m_Face;}
		FORCEINLINE unsigned int GetSize()const {return m_uiSize;}
		FORCEINLINE bool GetBold()const {return m_bBold;}
		FORCEINLINE bool GetItalic()const {return m_bItalic;}
	protected:
		VSString m_Face;
		unsigned int m_uiSize;
		bool m_bBold;
		bool m_bItalic;
	protected:
		virtual bool OnLoadResource(VSResourceIdentifier *&pID);		
		virtual bool OnReleaseResource(VSResourceIdentifier *pID);
	};
	DECLARE_Ptr(VSFont);
	VSTYPE_MARCO(VSFont);

}
#endif