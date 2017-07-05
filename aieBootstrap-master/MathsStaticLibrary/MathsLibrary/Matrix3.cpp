#define _USE_MATH_DEFINES

#include "Matrix3.h"
#include <cmath>


Matrix3::Matrix3()
{
}


Matrix3::~Matrix3()
{
}

Matrix3::Matrix3(float inputArray3x3[][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix3x3[i][j] = inputArray3x3[i][j];
}

Matrix3::Matrix3(float a, float b, float c,
				 float d, float e, float f,
				 float g, float h, float i)
{
	float tempMatrix[3][3] = { a, b, c,
							   d, e, f,
							   g, h, i};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix3x3[i][j] = tempMatrix[i][j];
}

void Matrix3::setRotateX(float angle)
{
	float rotationXMatrix[3][3] =
	{
		1,		0,		0,
		0,	cos(angle), sin(angle),
		0,	-sin(angle), cos(angle)
	};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix3x3[i][j] = rotationXMatrix[i][j];
}

void Matrix3::setRotateY(float angle)
{
	float rotationYMatrix[3][3] =
	{
		cos(angle),	0, -sin(angle),
		0,			1,			0,
		sin(angle),	0,	cos(angle)
	};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix3x3[i][j] = rotationYMatrix[i][j];
}

void Matrix3::setRotateZ(float angle)
{
	float rotationZMatrix[3][3] =
	{
		cos(angle), sin(angle),0,
		-sin(angle), cos(angle), 0,
		0,		 0,			1
	};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix3x3[i][j] = rotationZMatrix[i][j];
}
