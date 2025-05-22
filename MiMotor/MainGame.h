#pragma once
#include <SDL3/SDL.h>
#include <GL/eglew.h>
#include <EGL/eglplatform.h>
#include <KHR/khrplatform.h>
#include "sprite.h"
#include "GLSProgram.h"
#include <vector>
#include "InputManager.h"
#include "Camera2D.h"
enum class GameState {

	PLAY, EXIT
};
class MainGame
{
private:
	int width;
	int height ;
	InputManager inputManager;
	Camera2D camera2D;
	float time= 0;  
	Sprite sprite;
	vector<Sprite*>sprites;
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

