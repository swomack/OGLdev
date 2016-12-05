#include "glew.h"
#include "glut.h"
#include "window_manager.h"
#include "OpenglRenderer.h"


window_manager window;
OpenglRenderer renderer;



void render()
{
	renderer.renderScene();
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

void startMessageLoop()
{
	window.start_message_loop();
}

int main(int argc, char** argv)
{
	initializeWindow(argc, argv);
	initializeRenderer();
	startMessageLoop();
}