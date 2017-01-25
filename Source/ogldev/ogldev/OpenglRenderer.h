#pragma once

#include "glew.h"
#include "GodObject.h"
#include "VertexShaderTransformationUniforms.h"
#include <iostream>
#include <unordered_map>

class RenderScene;
class RenderGeometry;
class RenderMesh;
class Camera;
class RenderObject;
class RenderMaterial;
class ShaderMaterial;


class OpenglRenderer : public GodObject
{
public:
	OpenglRenderer();
	~OpenglRenderer();

	void renderScene(RenderScene* scene = NULL, Camera* camera = NULL);

	// set states
	void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

protected:

	GLuint initializeVertexBuffer(RenderGeometry* geometry);
	void drawMesh(RenderMesh* mesh, Camera* camera);
	void initiateMaterial(RenderMaterial* material);
	void updateTransformationMatrixUniforms(RenderMesh* mesh, RenderMaterial* material);
	void initiateShaderMaterial(ShaderMaterial* shader_material);
	void updateUniforms(ShaderMaterial* shader_material);

	void fillTransparent(RenderObject* obj, std::vector<RenderMesh*> &transparent);
	void fillOpaque(RenderObject* obj, std::vector<RenderMesh*> &opaque);

	void renderTransparent(std::vector<RenderMesh*> &transparent, Camera* camera);
	void renderOpaque(std::vector<RenderMesh*> &opaque, Camera* camera);

	std::unordered_map<std::string, GLuint> uuid_VBO_map;
};
