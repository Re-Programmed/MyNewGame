#pragma once
#include <iostream>
#include <vector>
#include "../../Rendering/Sprites/Texture2d.h"

using namespace Rendering::Sprites;

class AssetManager
{
public:
	enum ResourceType
	{
		DATA = 1,
		PNG_IMAGE = 56,
		AUDIO = 4
	};
	
	enum ResourceInformation
	{
		H_FILE_TYPE = 0, 
		H_FILE_ID = 1,
		H_FILE_ID_D = 0,
		S_FILE_NAME_D = 1,
		S_FILE_DATA = 2
	};

	static Texture2d DecodePNG(std::string b64, bool alpha);
private:
	const std::string PackDIR = "./Assets";
};