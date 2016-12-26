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
	fillTransparent(scene, transparent);
	fillOpaque(scene, transparent);

	//render opaque first, then transparent
	renderOpaque(opaque, camera);
	renderTransparent(transparent, camera);
}

void OpenglRenderer::setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a);
}

void OpenglRenderer::drawMesh(RenderMesh * mesh, Camera * camera)
{

}

void OpenglRenderer::fillTransparent(RenderObject * obj, std::vector<RenderMesh*>& transparent)
{
	if (obj == NULL)
		return;

	RenderMesh* mesh = dynamic_cast<RenderMesh*> (obj);

	if (mesh != NULL && mesh->getTransparent() == true)
		transparent.push_back(mesh);

	vector<RenderObject*> children = obj->get_children();
	for_each(children.begin(), children.end(), [this, &transparent](auto element) {
		this->fillTransparent(element, transparent);
	});
}

void OpenglRenderer::fillOpaque(RenderObject * obj, std::vector<RenderMesh*>& opaque)
{
	if (obj == NULL)
		return;

	RenderMesh* mesh = dynamic_cast<RenderMesh*> (obj);

	if (mesh != NULL && mesh->getTransparent() == false)
		opaque.push_back(mesh);

	vector<RenderObject*> children = obj->get_children();
	for_each(children.begin(), children.end(), [this, &opaque](auto element) {
		this->fillOpaque(element, opaque);
	});
}

void OpenglRenderer::renderTransparent(std::vector<RenderMesh*>& transparent, Camera* camera)
{
	glEnable(GL_BLEND);
	glDisable(GL_BLEND);
}

void OpenglRenderer::renderOpaque(std::vector<RenderMesh*>& opaque, Camera* camera)
{
	for_each(opaque.begin(), opaque.end(), [this, camera](auto element) {
		this->drawMesh(element, camera);
	});
}
