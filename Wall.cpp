#include "Wall.h"
#include "Engine.h"

AWall::AWall()
{
	{
		Depth = EDepth::Actor;
		CollisionType = ECollisionType::Collision;
		Color = { 128, 128, 128, 0 };

		Surface = SDL_LoadBMP("Data/Wall.bmp");
		Texture = SDL_CreateTextureFromSurface(GEngine->NewRenderer, Surface);
	}
}

AWall::~AWall()
{
}
