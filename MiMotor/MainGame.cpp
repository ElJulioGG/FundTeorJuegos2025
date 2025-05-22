#include "MainGame.h"
#include "iostream"

using namespace std;
void MainGame::init()
{
	SDL_Init(SDL_INIT_HAPTIC |  SDL_INIT_CAMERA |SDL_INIT_EVENTS);
	window = SDL_CreateWindow("Hola", width, height, SDL_WINDOW_OPENGL);


	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {

	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.4f, 1.0f, 1.0f);
	initShaders(); 
}

void MainGame::processInpout()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_EVENT_QUIT:
			gamestate = GameState::EXIT;
			break;
		case SDL_EVENT_MOUSE_MOTION:
			inputManager.setMouseCoords(event.motion.x, event.motion.y);
			//cout << " Pos x:" << event.motion.x << " Pos y:" << event.motion.y << endl;
			break;
		case SDL_EVENT_KEY_DOWN:
			inputManager.pressKey(event.key.key);
			break;
		case SDL_EVENT_KEY_UP:
			inputManager.releaseKey(event.key.key);
			break;
		}
	}
}

void MainGame::initShaders()
{
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPosition");
	program.addAtribute("vertexColor");
	program.addAtribute("vertexUV");
	program.linkShader();
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

void MainGame::run()
{	
	
	width = 800;
	height = 600;
	gamestate = GameState::PLAY;
	init();
	//sprite.init(-1, -1, 1, 1, "Images/ricotofen.png");

	sprites.push_back(new Sprite());
	sprites.back()->init(-0.5f, -1.0f, 1.0f, 1.0f, "Images/ricotofen.png"); 
	sprites.push_back(new Sprite());
	sprites.back()->init(-0.5f, 0, 1.0f, 1.0f, "Images/instak.png");

	update();
}

void MainGame::update()
{
	while (gamestate != GameState::EXIT) {
		processInpout();
		draw();
	}
}

void MainGame::draw()
{
	
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	time += 0.02f;
	program.use();
	glActiveTexture(GL_TEXTURE0);	
	GLuint timeLocation = program.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	GLuint textureLocation = program.getUniformLocation("myImage");
	glUniform1i(textureLocation, 0);

	for (size_t i = 0; i < sprites.size(); i++) {
		sprites[i]->draw();
	}

	program.unuse();
	SDL_GL_SwapWindow(window);
}
