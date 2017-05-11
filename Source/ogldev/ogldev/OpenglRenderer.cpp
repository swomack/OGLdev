#include "OpenglRenderer.h"
#include "RenderObject.h"
#include "RenderScene.h"
#include "RenderMesh.h"
#include "Camera.h"
#include "RenderMaterial.h"
#include "RenderGeometry.h"
#include "ShaderMaterial.h"

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

	if (scene == NULL || camera == NULL)
		return;


	// update the world matrices of all the elements
	scene->updateWorldMatrix();

	vector<RenderMesh*> transparent;
	vector<RenderMesh*> opaque;

	// fill the transparent mesh and opaque mesh list and draw them
	fillTransparent(scene, transparent);
	fillOpaque(scene, opaque);

	//render opaque first, then transparent
	renderOpaque(opaque, camera);
	renderTransparent(transparent, camera);
}

void OpenglRenderer::setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a);
}

GLuint OpenglRenderer::initializeVertexBuffer(RenderGeometry * geometry)
{
	GLuint VBO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, geometry->getVerticesPositionAttributeSize(), geometry->getVerticesPositionAttributeReference(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return VBO;
}

GLuint OpenglRenderer::initializeIndexBuffer(RenderGeometry * geometry)
{
	GLuint IBO;

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, geometry->getIndicesSize(), geometry->getIndices(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	return IBO;
}

void OpenglRenderer::drawMesh(RenderMesh * mesh, Camera * camera)
{
	if (mesh == NULL)
		return;

	RenderGeometry* geom = mesh->getGeometry();
	RenderMaterial* material = mesh->getMaterial();

	if (geom == NULL)
		return;

	const string string_id = geom->get_string_id();
	if (uuid_VBO_map[string_id] == NULL)
	{
		uuid_VBO_map[string_id] = initializeVertexBuffer(geom);
	}

	if (geom->getDrawType() == draw_type::DRAW_ELEMENTS)
	{
		if (uuid_IBO_map[string_id] == NULL)
		{
			uuid_IBO_map[string_id] = initializeIndexBuffer(geom);
		}


		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, uuid_IBO_map[string_id]);
	}
	else
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	glBindBuffer(GL_ARRAY_BUFFER, uuid_VBO_map[string_id]);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	if (material)
		initiateMaterial(material);

	updateTransformationMatrixUniforms(mesh, material, camera);

	if (geom->getDrawType() == draw_type::DRAW_ELEMENTS)
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(geom->getPrimitiveType(), 0, geom->getNumberofDrawableVertices());

	glDisableVertexAttribArray(0);
}

void OpenglRenderer::initiateMaterial(RenderMaterial * material)
{
	ShaderMaterial* shader_material = dynamic_cast<ShaderMaterial*> (material);
	initiateShaderMaterial(shader_material);
}

void OpenglRenderer::updateTransformationMatrixUniforms(RenderMesh * object, RenderMaterial* material, Camera* camera)
{
	ShaderMaterial* shader_material = dynamic_cast<ShaderMaterial*> (material);
	GLuint gWorldLocation = glGetUniformLocation(shader_material->getShaderProgram(), world_matrix.c_str());
	GLuint gProjectionLocation = glGetUniformLocation(shader_material->getShaderProgram(), projection_matrix.c_str());

	if (gWorldLocation != 0xFFFFFFFF)
	{
		glUniformMatrix4fv(gWorldLocation, 1, GL_TRUE, &object->world_matrix.m[0][0]);
	}

	if (gProjectionLocation != 0xFFFFFFFF)
	{
		Matrix4f m = camera->get_projection_matrix();
		glUniformMatrix4fv(gProjectionLocation, 1, GL_TRUE, &m.m[0][0]);
	}
}

void OpenglRenderer::initiateShaderMaterial(ShaderMaterial * shader_material)
{
	if (shader_material == NULL || shader_material->getShaderProgram() == 0)
		return;

	GLuint shader_program = shader_material->getShaderProgram();
	glUseProgram(shader_program);

	if (shader_material->getUniformNeedsUpdate())
	{
		updateUniforms(shader_material);
		shader_material->setUniformNeedsUpdate(false);
	}
		
}

void OpenglRenderer::updateUniforms(ShaderMaterial * shader_material)
{
	if (shader_material == NULL || shader_material->getShaderProgram() == 0)
		return;

	auto integer_uniforms = shader_material->getUniforms1i();

	for_each(integer_uniforms.begin(), integer_uniforms.end(), [shader_material](auto element) {
		GLuint location = glGetUniformLocation(shader_material->getShaderProgram(), element.first.c_str());

		if (location == 0xFFFFFFFF)
			return;

		glUniform1i(location, element.second);
	});

	auto float_uniforms = shader_material->getUniforms1f();

	for_each(float_uniforms.begin(), float_uniforms.end(), [shader_material](auto element) {
		GLuint location = glGetUniformLocation(shader_material->getShaderProgram(), element.first.c_str());

		if (location == 0xFFFFFFFF)
			return;

		glUniform1f(location, element.second);
	});
}

void OpenglRenderer::fillTransparent(RenderObject * obj, std::vector<RenderMesh*>& transparent)
{
	if (obj == NULL)
		return;

	RenderMesh* mesh = dynamic_cast<RenderMesh*> (obj);

	if (mesh != NULL && mesh->getTransparent() == true)
		transparent.push_back(mesh);

	vector<RenderObject*> children = obj->getChildren();
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

	vector<RenderObject*> children = obj->getChildren();
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
