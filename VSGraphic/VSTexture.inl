FORCEINLINE unsigned int VSTexture::GetFormatType()const
{
	return m_uiFormatType;
}
FORCEINLINE unsigned int VSTexture::GetBytePerPixel()const
{
	return VSRenderer::GetBytesPerPixel(m_uiFormatType);
}
FORCEINLINE unsigned int VSTexture::GetChannelPerPixel()const
{
	return VSRenderer::GetChannelPerPixel(m_uiFormatType);
}
FORCEINLINE unsigned int VSTexture::GetMipLevel()const
{
	return m_uiMipLevel;
}
FORCEINLINE unsigned char * VSTexture::GetBuffer(unsigned int uiLevel)const
{

	return m_pBufferArray[uiLevel];
}
FORCEINLINE unsigned char * VSTexture::GetBuffer(unsigned int uiLevel,unsigned int i)const
{
	if (IsCompress())
	{
		return NULL;
	}
	return m_pBufferArray[uiLevel] + i * VSRenderer::GetBytesPerPixel(m_uiFormatType);
}
FORCEINLINE unsigned int VSTexture::GetByteSize(unsigned int uiLevel)const
{
	if (uiLevel > m_uiMipLevel)
	{
		return 0;
	}
	if (IsCompress())
	{
		return VSRenderer::GetBytesPerPixel(m_uiFormatType) 
			* VSRenderer::ms_pRenderer->GetTextureCompressLen(GetWidth(uiLevel))
			* VSRenderer::ms_pRenderer->GetTextureCompressLen(GetHeight(uiLevel))
			* VSRenderer::ms_pRenderer->GetTextureCompressLen(GetLength(uiLevel));
	}
	return VSRenderer::GetBytesPerPixel(m_uiFormatType) * GetWidth(uiLevel) * GetHeight(uiLevel) * GetLength(uiLevel);
}

FORCEINLINE unsigned int VSTexture::GetWidth(unsigned int uiLevel)const
{
	if (uiLevel > m_uiMipLevel)
	{
		return 0;
	}
	unsigned int uiWidth = m_uiWidth >> uiLevel;
	if (!uiWidth)
	{
		uiWidth = 1;
	}
	return uiWidth;
}
FORCEINLINE unsigned int VSTexture::GetHeight(unsigned int uiLevel)const
{
	if (uiLevel > m_uiMipLevel)
	{
		return 0;
	}

	unsigned int uiHeight = m_uiHeight >> uiLevel;
	if (!uiHeight)
	{
		uiHeight = 1;
	}

	return uiHeight;

}
FORCEINLINE unsigned int VSTexture::GetLength(unsigned int uiLevel)const
{
	if (uiLevel > m_uiMipLevel)
	{
		return 0;
	}
	unsigned int uiLength = m_uiLenght >> uiLevel;
	if (!uiLength)
	{
		uiLength = 1;
	}
	return uiLength;
}