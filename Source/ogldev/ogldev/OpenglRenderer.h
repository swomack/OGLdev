#pragma once

#include "glew.h"
#include "GodObject.h"
#include <iostream>

class RenderScene;
class Camera;

class OpenglRenderer : public GodObject
{
public:
	OpenglRenderer();
	~OpenglRenderer();

	void renderScene(RenderScene* scene = NULL, Camera* camera = NULL);

	// set states
	void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
};
