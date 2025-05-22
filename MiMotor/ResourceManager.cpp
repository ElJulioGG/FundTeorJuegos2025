#include "ResourceManager.h"
TextureCache ResourceManager::textureCache; // Initialize static member

GLTexture ResourceManager::getTexture(string texturePath)
{
	return textureCache.getTexture(texturePath);
}
