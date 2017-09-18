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

#include "Camera.h"

#include <vector>
#include <array>

using namespace std;


const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;

window_manager window;
OpenglRenderer renderer;

RenderScene *main_scene = NULL;
Camera* main_camera = NULL;


void update_uniform()
{
	static float scale = 0.1f;

	if (main_scene)
	{
		RenderMesh* mesh = dynamic_cast<RenderMesh*> (main_scene->getObjectByName("ScaleMesh"));

		if (mesh)
		{
			//mesh->translateZ(scale);
		}
	}
}

void render()
{
	update_uniform();
	renderer.renderScene(main_scene, main_camera);
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


	array<float, 6> box = { -0.5, -0.5, 0.5, 0.5, 0.5, -0.5 };

	vector<Vector3> vertices(8);

	float hight = box[4] - box[1];
	float width = box[3] - box[0];
	float depth = box[5] - box[2];

	// fill the vertex buffer
	/*Vector3 v;
	v.set(box[0], box[1], box[2]);
	vertices.push_back(v);

	Vector3 v1;
	v1.set(box[0], box[1] + hight, box[2]);
	vertices.push_back(v1);

	Vector3 v2;
	v2.set(box[0] - width, box[1] + hight, box[2]);
	vertices.push_back(v2);

	Vector3 v3;
	v3.set(box[0] - width, box[1], box[2]);
	vertices.push_back(v3);

	Vector3 v4;
	v4.set(box[3], box[4], box[5]);
	vertices.push_back(v4);
	

	Vector3 v5;
	v5.set(box[3], box[4] - hight, box[5]);
	vertices.push_back(v5);

	Vector3 v6;
	v6.set(box[3] + width, box[4] - hight, box[5]);
	vertices.push_back(v6);

	Vector3 v7;
	v7.set(box[3] + width, box[4], box[5]);
	vertices.push_back(v7);*/

	vertices[0] = Vector3(0.5f, 0.5f, 0.5f);
	vertices[1] = Vector3(-0.5f, 0.5f, 0.5f);
	vertices[2] = Vector3(-0.5f, 0.5f, -0.5f);
	vertices[3] = Vector3(0.5f, 0.5f, -0.5f);
	vertices[4] = Vector3(0.5f, -0.5f, 0.5f);
	vertices[5] = Vector3(-0.5f, -0.5f, 0.5f);
	vertices[6] = Vector3(-0.5f, -0.5f, -0.5f);
	vertices[7] = Vector3(0.5f, -0.5f, -0.5f);


	RenderGeometry* geom = new RenderGeometry();
	geom->setPosition(move(vertices));

	vector<unsigned int> indices = { 0, 1, 5, 0, 5, 4, 1, 2, 6, 1, 6, 5, 2, 3, 7, 2, 7, 6, 3, 4, 7, 3, 1, 4, 0, 3, 2, 0, 2, 1, 4, 5, 7, 5, 6, 7 };




	geom->setIndices(move(indices));
	geom->setDrawType(draw_type::DRAW_ELEMENTS);
	geom->setPrimitiveType(TRIANGLE_PRIMITIVE);

	ShaderMaterial* material = new ShaderMaterial("Shaders/VertexShader.txt", "Shaders/FragmentShader.txt");
	RenderMesh* mesh = new RenderMesh("ScaleMesh");
	mesh->setGeometry(geom);
	mesh->setMaterial(material);
	mesh->setPosition(0.0, 0.0, 5.0);
	main_scene->addChild(mesh);
}

void addCamera()
{
	main_camera = new Camera();
	main_camera->set_camera_parameter(60.0f, WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.001, 10000);
}

int main(int argc, char** argv)
{
	initializeWindow(argc, argv);
	bool res = initializeGlew();

	if (!res)
		return 1;

	initializeRenderer();

	createScene();

	addCamera();

	startMessageLoop();
}