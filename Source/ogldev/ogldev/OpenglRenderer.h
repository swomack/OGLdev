#pragma once

#include "glew.h"
#include "GodObject.h"
#include <iostream>

class RenderScene;
class RenderMesh;
class Camera;

class OpenglRenderer : public GodObject
{
public:
	OpenglRenderer();
	~OpenglRenderer();

	void renderScene(RenderScene* scene = NULL, Camera* camera = NULL);

	// set states
	void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

protected:

	void drawMesh(RenderMesh* mesh, Camera* camera, bool transparent = false);
};
