#include "glew.h"
#include "glut.h"
#include "window_manager.h"
#include "OpenglRenderer.h"
#include "RenderObject.h"
#include "RenderScene.h"
#include "RenderMesh.h"
#include "RenderGeometry.h"
#include "Math3D.h"
#include "PrimitiveDefinitions.h"
#include "ShaderMaterial.h"

#include <vector>

using namespace std;


window_manager window;
OpenglRenderer renderer;

RenderScene *main_scene = NULL;


void update_uniform()
{
	static float scale = 0.0f;

	scale += 0.01f;

	if (main_scene)
	{
		RenderMesh* mesh = dynamic_cast<RenderMesh*> (main_scene->getObjectByName("ScaleMesh"));

		if (mesh)
		{
			mesh->setPosition(sinf(scale), 0.0f, 0.0f);
		}
	}
}

void render()
{
	update_uniform();
	renderer.renderScene(main_scene);
	glutSwapBuffers();
}


void initializeRenderer()
{
	renderer.setClearColor(1.0, 0.0, 0.0, 1.0);
}

void initializeWindow(int argc, char** argv)
{
	window.initialize_window(argv, argc);
	window.set_params(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH, 1024, 768, 50, 20);
	window.create_window("Tutorial 1");
	window.set_render_function(render);
	window.set_idle_function(render);
}

bool initializeGlew()
{
	GLenum res = glewInit();

	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(res));
		return false;
	}

	return true;
}

void startMessageLoop()
{
	window.start_message_loop();
}

void createScene()
{
	main_scene = new RenderScene();

	vector<Vector3> vertices(3);
	vertices[0] = Vector3(0.0f, 1.0f, 0.0f);
	vertices[1] = Vector3(-1.0f, -1.0f, 0.0f);
	vertices[2] = Vector3(1.0f, -1.0f, 0.0f);
	

	RenderGeometry* geom = new RenderGeometry();
	geom->setPosition(vertices);
	geom->setPrimitiveType(TRIANGLE_PRIMITIVE);

	ShaderMaterial* material = new ShaderMaterial("Shaders/VertexShader.txt", "Shaders/FragmentShader.txt");
	RenderMesh* mesh = new RenderMesh("ScaleMesh");
	mesh->setGeometry(geom);
	mesh->setMaterial(material);

	main_scene->addChild(mesh);
}

int main(int argc, char** argv)
{
	initializeWindow(argc, argv);
	bool res = initializeGlew();

	if (!res)
		return 1;

	initializeRenderer();

	createScene();

	startMessageLoop();
}