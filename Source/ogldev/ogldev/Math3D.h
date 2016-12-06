#pragma once

#include <cmath>

class Vector2
{
public:
	float x, y;

public:

	Vector2()
	{
		x = 0;
		y = 0;
	}


	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2 operator + (Vector2& operand)
	{
		Vector2 result(x + operand.x, y + operand.y);
		return result;
	}

	Vector2& operator += (Vector2& operand)
	{
		this->x += operand.x;
		this->y += operand.y;
		return *this;
	}

	Vector2 operator - (Vector2& operand)
	{
		Vector2 result(x - operand.x, y - operand.y);
		return result;
	}

	Vector2& operator -= (Vector2& operand)
	{
		this->x -= operand.x;
		this->y -= operand.y;
		return *this;
	}

	Vector2 operator * (float scalar)
	{
		Vector2 result(x * scalar, y * scalar);
		return result;
	}

	Vector2& operator *= (float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	float length()
	{
		return sqrt(x*x + y*y);
	}

	void normalize()
	{
		x /= length();
		y /= length();
	}

	void negate()
	{
		x *= -1;
		y *= -1;
	}
};

class Vector3
{
public:
	float x, y, z;

public:

	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}


	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3 operator + (Vector3& operand)
	{
		Vector3 result(x + operand.x, y + operand.y, z + operand.z);
		return result;
	}

	Vector3& operator += (Vector3& operand)
	{
		this->x += operand.x;
		this->y += operand.y;
		this->z += operand.z;
		return *this;
	}

	Vector3 operator - (Vector3& operand)
	{
		Vector3 result(x - operand.x, y - operand.y, z - operand.z);
		return result;
	}

	Vector3& operator -= (Vector3& operand)
	{
		this->x -= operand.x;
		this->y -= operand.y;
		this->z -= operand.z;
		return *this;
	}

	Vector3 operator * (float scalar)
	{
		Vector3 result(x * scalar, y * scalar, z * scalar);
		return result;
	}

	Vector3& operator *= (float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	float length()
	{
		return sqrt(x*x + y*y + z*z);
	}

	void normalize()
	{
		x /= length();
		y /= length();
		z /= length();
	}

	void negate()
	{
		x *= -1;
		y *= -1;
		z *= -1;
	}
};

