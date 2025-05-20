#pragma once
#include <SDL3/SDL.h>
#include <GL/eglew.h>
#include <EGL/eglplatform.h>
#include <KHR/khrplatform.h>
#include "sprite.h"
#include "GLSProgram.h"
enum class GameState {

	PLAY, EXIT
};
class MainGame
{
private:
	int width;
	int height ;
	float time= 0;  
	Sprite sprites[4]; // Para manejar 4 imágenes

	GLSProgram program;
	SDL_Window* window;
	void init();
	void processInpout();
	void initShaders();

public:
	MainGame();
	~MainGame();
	GameState gamestate;
	void run();
	void update();
	void draw();



};

