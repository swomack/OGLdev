#include "Camera.h"

Camera::Camera() : projection_matrix_needs_update(false)
{
	projection_matrix.set_identity();
}

Camera::~Camera()
{
}

void Camera::set_camera_parameter(float fov, float aspect_ratio, float near, float far)
{
	this->fov = fov;
	this->aspect_ratio = aspect_ratio;
	this->near = near;
	this->far = far;

	projection_matrix_needs_update = true;
}

Matrix4f & Camera::get_projection_matrix()
{
	if (projection_matrix_needs_update)
		calculate_projection_matrix();

	return projection_matrix;
}

void Camera::calculate_projection_matrix()
{
	projection_matrix_needs_update = false;
}
