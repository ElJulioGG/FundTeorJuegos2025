#pragma once
#include <SDL3/SDL.h>
#include <GL/eglew.h>
#include <EGL/eglplatform.h>
#include <KHR/khrplatform.h>
#include "sprite.h"

enum class GameState {

	PLAY, EXIT
};
class MainGame
{
private:
	int width;
	int height ;
	Sprite sprite;
	SDL_Window* window;
	void init();
	void processInpout();

public:
	MainGame();
	~MainGame();
	GameState gamestate;
	void run();
	void update();
	void draw();



};

