#define _USE_MATH_DEFINES

#include "Matrix2.h"
#include <cmath>

Matrix2::Matrix2()
{
}


Matrix2::~Matrix2()
{
}

Matrix2::Matrix2(float inputArray2x2[][2])
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			matrix2x2[i][j] = inputArray2x2[i][j];
}

Matrix2::Matrix2(float a, float b, float c, float d)
{
	float tempMatrix[2][2] = { a, b,
							  c, d };
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			matrix2x2[i][j] = tempMatrix[i][j];
}



Matrix2 Matrix2::setRotate(float angle)
{
	float rotationMatrix[2][2] = {
		cos(angle), sin(angle),
		-sin(angle), cos(angle)
	};
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			matrix2x2[i][j] = rotationMatrix[i][j];
	return rotationMatrix;
}
