#define _USE_MATH_DEFINES

#include "Matrix4.h"
#include <cmath>


Matrix4::Matrix4()
{
}


Matrix4::~Matrix4()
{
}


Matrix4::Matrix4(float inputArray4x4[][4])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			matrix4x4[i][j] = inputArray4x4[i][j];
}

Matrix4::Matrix4(float a, float b, float c, float d,
				 float e, float f, float g, float h,
				 float i, float j, float k, float l,
				 float m, float n, float o, float p)
{
	float tempMatrix[4][4] = { a, b, c, d,
							   e, f, g, h,
							   i, j, k, l,
							   m, n, o, p };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			matrix4x4[i][j] = tempMatrix[i][j];
}

void Matrix4::setRotateX(float angle)
{
	float rotationXMatrix[4][4] =
	{
		1,		0,			0,			0,
		0,	cos(angle),  sin(angle),	0,
		0, -sin(angle),	 cos(angle),	0,
		0 ,		0 ,			0 ,			1
	};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			matrix4x4[i][j] = rotationXMatrix[i][j];
}

void Matrix4::setRotateY(float angle)
{
	float rotationYMatrix[4][4] =
	{
		cos(angle),	0, -sin(angle),		0,
		0,			1,			0,		0,
		sin(angle),	0,	cos(angle),		0,
		0,			0,			0,		1
	};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			matrix4x4[i][j] = rotationYMatrix[i][j];
}

void Matrix4::setRotateZ(float angle)
{
	float rotationZMatrix[4][4] =
	{
		cos(angle), sin(angle),	0, 0,
		-sin(angle), cos(angle),0, 0,
		0,		 0,			1 ,	   0,
		0,		 0,			0,	   1
	};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			matrix4x4[i][j] = rotationZMatrix[i][j];
}
