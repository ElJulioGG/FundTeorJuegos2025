#include "TextureCache.h"
#include "ImageLoader.h"
#include"iostream"
using namespace std;
TextureCache::TextureCache()
{
	// Constructor
}
TextureCache::~TextureCache()
{
	// Destructor
}
GLTexture TextureCache::getTexture(string texturePath)
{
	
	//map<string, GLTexture>::iterator ite = textureMap.find(texturePath);
	auto ite = textureMap.find(texturePath);
	if (ite == textureMap.end()) {
		cout << "Cargando la imagenTexture desde la path: " << texturePath << endl;
		GLTexture texture = ImageLoader::loadPNG(texturePath);
		textureMap[texturePath] = texture;
		return texture;
		//pair<string, GLTexture> newPair(texturePath, texture); 
		//textureMap.insert(newPair);
	}
	
	cout << "Imagen cargando desde la cache" << endl;
	return ite->second;
}