#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* textureSheet, SDL_Renderer* rendererToUse, int xPosition, int yPosition)
{
	renderer = rendererToUse;
	objectTexture = TextureManager::LoadTexture(textureSheet, rendererToUse);
	x = xPosition;
	y = yPosition;
}

void GameObject::Update()
{
	x++;
	y++;
	sourceRect.h = 600;
	sourceRect.w = 800;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destinationRect.x = x;
	destinationRect.y = y;
	destinationRect.w = 64;
	destinationRect.h = 64;

}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objectTexture, &sourceRect, &destinationRect);
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(objectTexture);
	SDL_DestroyRenderer(renderer);
}
