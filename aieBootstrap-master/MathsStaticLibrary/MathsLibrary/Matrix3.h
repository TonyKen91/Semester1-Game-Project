#pragma once
#include "Vector3.h"

// A 3x3 Matrix class
class Matrix3
{
public:
	Matrix3();
	~Matrix3();
	Matrix3(float inputArray3x3[][3]);	// Matrix constructor that takes in an array of floats as input
	Matrix3(float a, float b, float c,	// Matrix constructor that takes in floats as input
			float d, float e, float f,
			float g, float h, float i);

	// Set the matrix as rotation matrix
	void setRotateX(float angle);		// Rotation matrix around the x axis
	void setRotateY(float angle);		// Rotation matrix around the y axis
	void setRotateZ(float angle);		// Rotation matrix around the z axis

	// Operator overload for multiplying with another matrix
	Matrix3 operator * (Matrix3& rhs)
	{
		Matrix3 tempMatrix;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				tempMatrix.matrix3x3[j][i] = matrix3x3[0][i] * rhs.matrix3x3[j][0] + matrix3x3[1][i] * rhs.matrix3x3[j][1] + matrix3x3[2][i] * rhs.matrix3x3[j][2];
			}
		}
		return tempMatrix;
	}

	// Operator overload for multiplying with a vector
	Vector3 operator * (Vector3& rhs)
	{
		Vector3 resultantVector;
		for (int i = 0; i < 3; i++)
		{
				resultantVector[i] = matrix3x3[0][i] * rhs.x + matrix3x3[1][i] * rhs.y + matrix3x3[2][i] * rhs.z;
		}
		return resultantVector;
	}

	// Operator overload for matrix subscript operator
	Vector3& operator [] (int subscript)
	{
		return columnVectors[subscript];
	}

	// Operator float cast overload
	operator float* ()
	{
		return xAxis;	// Returns the first element of the matrix
	}

	// Union for more flexible access of data
	union {
		struct {
			float xAxis[3];
			float yAxis[3];
			float zAxis[3];
		};
		Vector3 columnVectors[3];
		float matrix3x3[3][3];	// 2 dimensional array for a 3x3 matrix
	};
};

