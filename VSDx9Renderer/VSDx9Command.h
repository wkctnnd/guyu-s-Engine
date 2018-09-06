#ifndef VSDX9COMMAND_H
#define VSDX9COMMAND_H
#include <d3d9.h>
#include "VSRenderThread.h"
namespace VSEngine2
{
#define DX9_API_FUN_END \
	ENQUEUE_UNIQUE_RENDER_COMMAND_END \
	VSMAC_ASSERT(!FAILED(hResult)); \
	return !FAILED(hResult); \
}	
#define DX9_API_FUN_ONEPARAMETER(FunctionName,ParamType1,ParamName1) \
	bool FunctionName(ParamType1 ParamName1) \
	{\
		struct TypeStruct \
		{ \
			ParamType1 ParamName1; \
		}; \
		HRESULT hResult = NULL; \
		TypeStruct TypeStructValue; \
		TypeStructValue.ParamName1 = ParamName1; \
		ENQUEUE_UNIQUE_RENDER_COMMAND_TWOPARAMETER(VS##FunctionName, \
		TypeStruct,TypeStructValue,TypeStructValue,LPDIRECT3DDEVICE9,m_pDevice,m_pDevice, \
		{ \
			HRESULT hResult = NULL; \
			hResult = m_pDevice->FunctionName(TypeStructValue.ParamName1); \
			VSMAC_ASSERT(!FAILED(hResult)); \
		}) \
			hResult = m_pDevice->FunctionName(ParamName1);

#define DX9_API_FUN_TWOPARAMETER(FunctionName,ParamType1,ParamName1,ParamType2,ParamName2) \
	bool FunctionName(ParamType1 ParamName1,ParamType2 ParamName2) \
	{\
		struct TypeStruct \
		{ \
			ParamType1 ParamName1; \
			ParamType2 ParamName2; \
		}; \
		HRESULT hResult = NULL; \
		TypeStruct TypeStructValue; \
		TypeStructValue.ParamName1 = ParamName1; \
		TypeStructValue.ParamName2 = ParamName2; \
		ENQUEUE_UNIQUE_RENDER_COMMAND_TWOPARAMETER(VS##FunctionName, \
		TypeStruct,TypeStructValue,TypeStructValue,LPDIRECT3DDEVICE9,m_pDevice,m_pDevice, \
		{ \
			HRESULT hResult = NULL; \
			hResult = m_pDevice->FunctionName(TypeStructValue.ParamName1,TypeStructValue.ParamName2); \
			VSMAC_ASSERT(!FAILED(hResult)); \
		}) \
		hResult = m_pDevice->FunctionName(ParamName1,ParamName2);
}
#endif