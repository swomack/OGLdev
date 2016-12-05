#pragma once

class RenderScene;
class Camera;

class OpenglRenderer
{
public:
	OpenglRenderer();
	~OpenglRenderer();

	void renderScene(RenderScene* scene, Camera* camera);
};
