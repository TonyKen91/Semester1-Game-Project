#pragma once
#include "Vector2.h"

// A 2x2 Matrix class
class Matrix2
{
public:
	Matrix2();										// Matrix default constructor
	~Matrix2();										// Matrix default destructor
	Matrix2(float inputArray2x2[][2]);				// Matrix constructor for an input of array of floats
	Matrix2(float a, float b, float c, float d);	// Matrix constructor for float input

	// Sets rotation matrix
	Matrix2 setRotate(float angle);

	// Operator * overload for multiplying two matrices
	Matrix2 operator * (Matrix2& rhs)
	{
		Matrix2 tempMatrix;							// Temporary matrix for the result which will outputted by the operator
		
		// Loop for allocating the product of the two matrices to each member
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				tempMatrix.matrix2x2[i][j] = matrix2x2[i][0] * rhs.matrix2x2[0][j] + matrix2x2[i][1] * rhs.matrix2x2[1][j];
			}
		}
		return tempMatrix;
	}

	// Operator * overload for multiplying matrix with a vector
	Vector2 operator * (Vector2& rhs)
	{
		Vector2 resultantVector;
		for (int i = 0; i < 2; i++)
		{
			resultantVector[i] = matrix2x2[0][i] * rhs.x + matrix2x2[1][i] * rhs.y;
		}
		return resultantVector;
	}
	
	// Subscript operator overload
	Vector2& operator [] (int subscript)
	{
		return columnVectors[subscript];
	}

	// Overloads float cast operator
	operator float* ()
	{
		return xAxis;
	}

	// Matrix data
	union {
		struct {
			float xAxis[2];
			float yAxis[2];
		};
		Vector2 columnVectors[2];
		float matrix2x2[2][2];
	};

};

