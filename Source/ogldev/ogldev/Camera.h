#pragma once

#include "RenderObject.h"
#include "Math3D.h"

class Camera : public RenderObject
{
public:
	Camera();
	~Camera();

	virtual void set_camera_parameter(float fov, float aspect_ratio, float near, float far);

	Matrix4f& get_projection_matrix();

protected:

	virtual void calculate_projection_matrix();

protected:
	float fov;
	float near;
	float far;
	float aspect_ratio;

	bool projection_matrix_needs_update;
	Matrix4f projection_matrix;
};
