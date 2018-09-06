#ifndef VSPREZPASS_H
#define VSPREZPASS_H
#include "VSPShader.h"
#include "VSVShader.h"
#include "VSMatrix3X3W.h"
#include "VSPass.h"
namespace VSEngine2
{

	class VSGRAPHIC_API VSPrezPass : public VSPass
	{
		//PRIORITY
		
		//RTTI
		DECLARE_RTTI;
		DECLARE_INITIAL
	public:
		VSPrezPass();
		virtual ~VSPrezPass();
		

	protected:
		static VSPointer<VSPrezPass>	Default;
		static bool InitialDefaultState();
		static bool TerminalDefaultState();
	protected:
		VSRenderState m_RenderState;
	public:
		virtual bool Draw(VSRenderer * pRenderer);
		
		static VSPrezPass * GetDefault()
		{
			return Default;
		}
		virtual unsigned int GetPassType()
		{
			return PT_PREZ;
		}

	};
	DECLARE_Ptr(VSPrezPass);
	VSTYPE_MARCO(VSPrezPass);
}
#endif