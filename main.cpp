//#include "SDL.h"
//#define M_PI 3.141592
//
//#pragma comment(lib, "SDL2")
//#pragma comment(lib, "SDL2main")
//
//int SDL_main(int agrc, char* agrv[])
//{
//	SDL_Init(SDL_INIT_EVERYTHING);
//
//	SDL_Window* NewWindow = SDL_CreateWindow("New Window", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
//
//	SDL_Renderer* NewRenderer = SDL_CreateRenderer(NewWindow, -1, SDL_RENDERER_ACCELERATED 
//		| SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
//	//SDL_CreateRenderer(NewWindow, -1, SDL_RENDERER_SOFTWARE 
//	// | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
//
//
//	int X = 300;
//	int Y = 300;
//	int r = 100;
//
//	int RectX = 100;
//	int RectY = 100;
//
//	bool bIsRunning = true;
//	bool bCircle = true;
//	SDL_Event NewEvent;
//
//	while (bIsRunning)
//	{
//		SDL_PollEvent(&NewEvent);
//		switch (NewEvent.type)
//		{
//		case SDL_QUIT:
//			bIsRunning = false;
//			break;
//		case SDL_KEYDOWN:
//			switch (NewEvent.key.keysym.sym)
//			{
//			case SDLK_UP:
//				Y--;
//				break;
//			case SDLK_DOWN:
//				Y++;
//				break;
//			case SDLK_RIGHT:
//				X++;
//				break;
//			case SDLK_LEFT:
//				X--;
//				break;
//			case SDLK_w:
//				RectY--;
//				break;
//			case SDLK_s:
//				RectY++;
//				break;
//			case SDLK_a:
//				RectX--;
//				break;
//			case SDLK_d:
//				RectX++;
//				break;
//			}
//		}
//		SDL_Rect NewRect = { RectX, RectY, 100, 100 };
//
//		SDL_SetRenderDrawColor(NewRenderer, 255, 255, 255, 255);
//		SDL_RenderClear(NewRenderer);
//
//		SDL_SetRenderDrawColor(NewRenderer, 255, 0, 0, 0);
//		SDL_RenderDrawRect(NewRenderer, &NewRect);
//		SDL_RenderFillRect(NewRenderer, &NewRect);
//
//	
//		for (int i = 0; i < 360; i += 1)
//		{
//			double Angle = i;
//			double Radian = Angle * 3.141592 / 180.0;
//			double Radian1 = (Angle + 20) * 3.141592 / 180.0;
//
//			for (r = 100; r > 0; r -= 1)
//			{
//
//				int dX = r * cos(Radian) + X;
//				int dY = r * sin(Radian) + Y;
//				int dX1 = r * cos(Radian1) + X;
//				int dY1 = r * sin(Radian1) + Y;
//
//				SDL_RenderDrawLineF(NewRenderer, dX, dY, dX1, dY1);
//				//SDL_RenderDrawLine(NewRenderer, X, Y, dX, dY);
//				//SDL_RenderDrawLineF(NewRenderer, X, Y, dX1, dY1);
//			}
//		}
//
//		SDL_RenderPresent(NewRenderer);
//	}
//
//
//	SDL_DestroyRenderer(NewRenderer);
//	SDL_DestroyWindow(NewWindow);
//
//	SDL_Quit();
//
//	return 0;
//}

#include "Engine.h"

int SDL_main(int agrc, char* agrv[])
{
	GEngine->LoadLevel("Level01.Map");

	GEngine->Run();//
	return 0;
}