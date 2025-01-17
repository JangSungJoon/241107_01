#include "Floor.h"
#include "SDL.h"
#include "Engine.h"

AFloor::AFloor()
{
	Depth = EDepth::Floor;
	CollisionType = ECollisionType::NoCollision;
	Color = { 185, 122, 87, 255 };

	Surface = SDL_LoadBMP("Data/floor.bmp");
	Texture = SDL_CreateTextureFromSurface(GEngine->NewRenderer, Surface);
}

AFloor::~AFloor()
{
}