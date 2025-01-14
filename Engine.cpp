#define _CRT_SECURE_NO_WARNINGS
#include "Engine.h"

#include <conio.h>
#include <stdio.h>
#include <Windows.h>

#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Floor.h"
#include "Goal.h"
#include "GameMode.h"
#include "SDL.h"

#include <algorithm>

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

Engine* Engine::Instance = nullptr;

Engine::Engine()
{
	{
		KeyCode = 0;
		bIsRunning = true;
		bWillStop = false;

		Init();
	}
}

void Engine::Init()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	NewWindow = SDL_CreateWindow("NewWindow", 100, 100, 600, 600, SDL_WINDOW_OPENGL);
	NewRenderer = SDL_CreateRenderer(NewWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	//SDL_Renderer* NewRenderer =  SDL_CreateRenderer(NewWindow, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
}

void Engine::Term()
{
	SDL_DestroyRenderer(NewRenderer);
	SDL_DestroyWindow(NewWindow);

	SDL_Quit();
}

Engine::~Engine()
{
	for (auto& Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();

	Term();
}



void Engine::Input()
{
	//KeyCode = _getch();

	SDL_PollEvent(&NewEvent);
}

void Engine::Render()
{
	//system("cls");

	SDL_SetRenderDrawColor(NewRenderer, 255, 255, 255, 255);
	SDL_RenderClear(NewRenderer);

	//AllActorofClass->Render();
	//for (int i = 0; i < Actors.size(); ++i)
	//{
	//	Actors[i]->Render();
	//}

	for (const auto& Selected : Actors)
	{
		Selected->Render();
	}

	SDL_RenderPresent(NewRenderer);

}

void Engine::BeginPlay()
{
	for (const auto& Selected : Actors)
	{
		Selected->BeginPlay();
	}
}

void Engine::Run()
{
	Uint64 StartTime;
	Uint64 EndTime;

	BeginPlay();
	while (bIsRunning)
	{
		StartTime = SDL_GetTicks64();
		Input();

		Tick();

		Render();

		if (bWillStop)
		{
			bIsRunning = true;
			break;
		}
		EndTime = SDL_GetTicks64();
		DeltaSeconds = EndTime - StartTime;
	}
}

void Engine::SpawnActor(AActor* SpawnedActor)
{
	Actors.push_back(SpawnedActor);
}

void Engine::LoadLevel(const char* MapName)
{
	GEngine->SpawnActor(new AGameMode());

	FILE* MapFile = fopen(MapName, "r");

	char Line[100] = { 0, };
	int Y = 0;
	while (fgets(Line, 100, MapFile) != nullptr)
	{
		for (int X = 0; X < strlen(Line); ++X)
		{
			if (Line[X] == '*')
			{
				AWall* Wall = new AWall();
				Wall->SetX(X);
				Wall->SetY(Y);
				Wall->SetStaticMesh(Line[X]);
				GEngine->SpawnActor(Wall);
			}
			else if (Line[X] == 'P')
			{
				APlayer* MyPlayer = new APlayer();
				MyPlayer->SetX(X);
				MyPlayer->SetY(Y);
				MyPlayer->SetStaticMesh(Line[X]);
				GEngine->SpawnActor(MyPlayer);
			}
			else if (Line[X] == 'M')
			{
				AMonster* Monster = new AMonster();
				Monster->SetX(X);
				Monster->SetY(Y);
				Monster->SetStaticMesh(Line[X]);
				GEngine->SpawnActor(Monster);
			}
			/*else if (Line[X] == ' ')
			{
				AFloor* Floor = new AFloor();
				Floor->SetX(X);
				Floor->SetY(Y);
				Floor->SetStaticMesh(Line[X]);
				GEngine->SpawnActor(Floor);
			}*/
			else if (Line[X] == 'G')
			{
				AGoal* Goal = new AGoal();
				Goal->SetX(X);
				Goal->SetY(Y);
				Goal->SetStaticMesh(Line[X]);
				GEngine->SpawnActor(Goal);
			}

			if (Line[X] != '\n')
			{
				AFloor* Floor = new AFloor();
				Floor->SetX(X);
				Floor->SetY(Y);
				Floor->SetStaticMesh(Line[X]);
				GEngine->SpawnActor(Floor);
			}
		}
		Y++;
	}

	fclose(MapFile);

	std::sort(Actors.begin(), Actors.end(), [&](AActor* A, AActor* B) {
		return (int)A->GetDepth() < (int)B->GetDepth();
		});
}

void Engine::Tick()
{
	//AllActorofClass->Tick();

	switch (NewEvent.type)
	{
	case SDL_QUIT:
		Stop();
	case SDL_KEYDOWN:
		switch (NewEvent.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			Stop();
		}
	}

	/*if (KeyCode == 27)
	{
		bIsRunning = false;
	}*/

	for (int i = 0; i < Actors.size(); ++i)
	{
		Actors[i]->Tick(KeyCode);
	}
}