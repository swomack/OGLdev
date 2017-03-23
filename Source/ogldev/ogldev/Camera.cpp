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

	float tanHalfOfFOV = tanf(ogldev_math_utility::degreeToRad(this->fov / 2.0f));
	float zRange = this->near - this->far;

	projection_matrix.m[0][0] = 1 / (this->aspect_ratio * tanHalfOfFOV); projection_matrix.m[0][1] = 0.0f;				projection_matrix.m[0][2] = 0.0f;									projection_matrix.m[0][3] = 0.0f;
	projection_matrix.m[1][0] = 0.0f;									 projection_matrix.m[1][1] = 1 / tanHalfOfFOV;	projection_matrix.m[1][2] = 0.0f;									projection_matrix.m[1][3] = 0.0f;
	projection_matrix.m[2][0] = 0.0f;									 projection_matrix.m[2][1] = 0.0f;				projection_matrix.m[2][2] = (- this->near - this->far) / zRange;	projection_matrix.m[2][3] = 2.0f * this->far * this->near / zRange;
	projection_matrix.m[3][0] = 0.0f;									 projection_matrix.m[3][1] = 0.0f;				projection_matrix.m[3][2] = 1.0f;									projection_matrix.m[3][3] = 0.0f;
}
