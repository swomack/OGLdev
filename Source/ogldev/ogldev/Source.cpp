#include "glew.h"
#include "glut.h"
#include "window_manager.h"
#include "OpenglRenderer.h"
#include "RenderObject.h"
#include "RenderScene.h"
#include "RenderMesh.h"
#include "RenderGeometry.h"
#include "Math3D.h"
#include <vector>

using namespace std;


window_manager window;
OpenglRenderer renderer;

RenderScene *main_scene = NULL;

void render()
{
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

	vector<Vector3> points;
	Vector3 point(0.0f, 0.0f, 0.0f);
	points.push_back(point);

	RenderGeometry* geom = new RenderGeometry();
	geom->setPosition(points);

	RenderMesh* mesh = new RenderMesh();
	mesh->setGeometry(geom);

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