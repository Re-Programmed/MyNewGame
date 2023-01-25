#include "AssetManager.h"
#include "../base64.h"

Texture2d AssetManager::DecodePNG(std::string b64, bool alpha)
{	
	std::vector<BYTE> myData = base64_decode(b64);

	Texture2d t;

	t.InternalFormat = GL_RGBA;
	t.ImageFormat = GL_RGBA;

	t.Generate(16, 16, &myData);

	for (int i = 0; i < myData.size(); i++)
	{
		std::cout << myData[i];
	}

	std::cout << std::endl;
	
	return t;
}
