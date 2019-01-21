#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* rendererToUse, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int x;
	int y;

	SDL_Texture* objectTexture;
	SDL_Rect sourceRect, destinationRect;
	SDL_Renderer* renderer;
};

