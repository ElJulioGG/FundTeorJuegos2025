#pragma once
#include "GLTexture.h"
#include <string>

using namespace std;

class ImageLoader
{
public:
	static GLTexture loadPNG( string filePath);
	static GLTexture loadBMP(const string& filePath);
	static void clear(); 
};