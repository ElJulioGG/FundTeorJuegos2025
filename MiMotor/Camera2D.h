#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
class Camera2D
{
private:
	glm::mat4 cameraMatrix;
	//glm::mat4 _projectionMatrix;
	glm::mat4 orthoMatrix;
	glm::vec2 position;
	//glm::vec2 resolution;
	float scale;
	bool needsUpdateMatrix;
	int screenWidth;
	int screenHeight;

public:
	void update();
	void init(int screenWidth, int screenHeight);

	void setPosition(const glm::vec2& newPosition) {
		position = newPosition;
		needsUpdateMatrix = true;
	}

	void setScale(float newScale) {
		scale = newScale;
		needsUpdateMatrix = true;
	}

	glm::mat4 getCameraMatrix() {
		return cameraMatrix;
	}
	Camera2D();
	~Camera2D();
};

