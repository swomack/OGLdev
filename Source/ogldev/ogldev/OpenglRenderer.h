#pragma once

#include "glew.h"
#include "GodObject.h"
#include <iostream>
#include <unordered_map>

class RenderScene;
class RenderGeometry;
class RenderMesh;
class Camera;
class RenderObject;

class OpenglRenderer : public GodObject
{
public:
	OpenglRenderer();
	~OpenglRenderer();

	void renderScene(RenderScene* scene = NULL, Camera* camera = NULL);

	// set states
	void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

protected:

	void drawMesh(RenderMesh* mesh, Camera* camera);

	void fillTransparent(RenderObject* obj, std::vector<RenderMesh*> &transparent);
	void fillOpaque(RenderObject* obj, std::vector<RenderMesh*> &opaque);

	void renderTransparent(std::vector<RenderMesh*> &transparent, Camera* camera);
	void renderOpaque(std::vector<RenderMesh*> &opaque, Camera* camera);

	std::unordered_map<std::string, RenderGeometry*> uuid_geometry_map;
};
