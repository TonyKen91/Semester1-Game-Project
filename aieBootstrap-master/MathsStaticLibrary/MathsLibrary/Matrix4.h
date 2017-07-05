#pragma once
#include "Vector4.h"

// 3D Homogeneous Matrix
class Matrix4
{
public:
	Matrix4();
	~Matrix4();
	Matrix4(float inputArray4x4[][4]);				// Matrix constructor for input array
	Matrix4(float a, float b, float c, float d,		// Matrix constructor for float input
			float e, float f, float g, float h,
			float i, float j, float k, float l,
			float m, float n, float o, float p);


	// Set the matrix as rotation matrix
	void setRotateX(float angle);					// Rotation matrix around the x axis
	void setRotateY(float angle);					// Rotation matrix around the x axis
	void setRotateZ(float angle);					// Rotation matrix around the x axis

	// Operator overload for multiplying with another matrix
	Matrix4 operator * (Matrix4& rhs)
	{
		Matrix4 tempMatrix;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				tempMatrix.matrix4x4[j][i] = matrix4x4[0][i] * rhs.matrix4x4[j][0] + matrix4x4[1][i] * rhs.matrix4x4[j][1] + matrix4x4[2][i] * rhs.matrix4x4[j][2] + matrix4x4[3][i] * rhs.matrix4x4[j][3];
			}
		}
		return tempMatrix;
	}

	// Operator overload for multiplying with a vector
	Vector4 operator * (Vector4& rhs)
	{
		Vector4 resultantVector;
		for (int i = 0; i < 4; i++)
		{
			resultantVector[i] = matrix4x4[0][i] * rhs.x + matrix4x4[1][i] * rhs.y + matrix4x4[2][i] * rhs.z + matrix4x4[3][i] * rhs.w;
		}
		return resultantVector;
	}

	// Operator overload for matrix subscript operator
	Vector4& operator [] (int subscript)
	{
		return columnVectors[subscript];
	}

	// Operator float cast overload
	operator float* ()
	{
		return xAxis;
	}

	union {
		struct {
			float xAxis[4];
			float yAxis[4];
			float zAxis[4];
			float wAxis[4];
		};
		Vector4 columnVectors[4];
		float matrix4x4[4][4];
	};
};

