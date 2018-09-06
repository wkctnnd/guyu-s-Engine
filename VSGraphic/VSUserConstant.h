#ifndef VSUSERCONSTANT_H
#define VSUSERCONSTANT_H
#include "VSMemManager.h"
#include "VSMath.h"
#include "VSObject.h"
#include "VSName.h"
namespace VSEngine2
{
class VSStream;
class VSGRAPHIC_API VSUserConstant : public VSObject
{
	//PRIORITY
	
	//RTTI
	DECLARE_RTTI;
	DECLARE_INITIAL
public:
	
	
	enum //Value Tpye
	{			
		VT_FLOAT,
		VT_BOOL,
		VT_INT,	
		VT_STRUCT,
		VT_MAX
	};
public:
	VSUserConstant(const VSUsedName & Name,const void * pDate,unsigned int uiSize,
		unsigned int uiRegisterIndex,unsigned int uiRegisterNum,unsigned int uiValueType = VT_FLOAT);
	virtual ~VSUserConstant();
	bool SetDate(void *pElementDate);
	FORCEINLINE void* GetDate()const;
	FORCEINLINE unsigned int GetValueType()const;
	FORCEINLINE unsigned int GetSize()const;
	FORCEINLINE unsigned int GetRegisterNum()const;
	FORCEINLINE unsigned int GetRegisterIndex()const;
	FORCEINLINE const VSUsedName & GetName()const
	{
		return m_Name;
	}
protected:
	friend class VSRenderer;
	VSUserConstant();

private:
	
	unsigned int m_uiSize;
	unsigned int m_uiValueType;
	unsigned char * m_pDate;
	unsigned int m_uiRegisterIndex;
	unsigned int m_uiRegisterNum;
	VSUsedName m_Name;
};
#include "VSUserConstant.inl"
VSTYPE_MARCO(VSUserConstant);
DECLARE_Ptr(VSUserConstant);
}
#endif