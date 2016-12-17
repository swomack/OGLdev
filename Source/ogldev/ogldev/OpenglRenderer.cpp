#include "OpenglRenderer.h"
#include "RenderObject.h"
#include "RenderScene.h"
#include "RenderMesh.h"
#include "Camera.h"
#include "RenderMaterial.h"
#include "RenderGeometry.h"
#include <vector>

using namespace std;

OpenglRenderer::OpenglRenderer()
{
}

OpenglRenderer::~OpenglRenderer()
{
}

void OpenglRenderer::renderScene(RenderScene * scene, Camera * camera)
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (scene == NULL)
		return;


	vector<RenderMesh*> transparent;
	vector<RenderMesh*> opaque;

	// fill the transparent mesh and opaque mesh list and draw them

}

void OpenglRenderer::setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a);
}

void OpenglRenderer::drawMesh(RenderMesh * mesh, Camera * camera, bool transparent)
{

}
