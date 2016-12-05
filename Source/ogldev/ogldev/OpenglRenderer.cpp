#include "OpenglRenderer.h"
#include "RenderObject.h"
#include "RenderScene.h"
#include "RenderMesh.h"
#include "Camera.h"
#include "RenderMaterial.h"
#include "RenderGeometry.h"

OpenglRenderer::OpenglRenderer()
{
}

OpenglRenderer::~OpenglRenderer()
{
}

void OpenglRenderer::renderScene(RenderScene * scene, Camera * camera)
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (scene == NULL || camera == NULL)
		return;
}

void OpenglRenderer::setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a);
}
