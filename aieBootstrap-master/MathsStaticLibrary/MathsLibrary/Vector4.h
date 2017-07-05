#pragma once

// Homogeneous 3D Vector
class Vector4
{
public:
	Vector4();
	~Vector4();
	Vector4(float inputArray4[4]);
	Vector4(float a, float b, float c, float d);

	Vector4 translate(const Vector4& secondVector);
	Vector4 scale(float scalar);
	Vector4 cross(Vector4& secondVector);
	float dot(Vector4& secondVector);
	float magnitude();
	void normalise();


	// Operator overload
	Vector4 operator + (Vector4& secondVector)
	{
		Vector4 resultantVector;
		resultantVector.x = x + secondVector.x;
		resultantVector.y = y + secondVector.y;
		resultantVector.z = z + secondVector.z;
		resultantVector.w = w + secondVector.w;
		//if (w + secondVector.w == 1)
		//{
		//	resultantVector.w = 0;
		//}
		//else if (w + secondVector.w == 2)
		//{
		//	resultantVector.w = 1;
		//}
		//else
		//{
		//	resultantVector.w = 2;   // Returns w = 2 when there's error or it's not possible add
		//}
		return resultantVector;
	}

	Vector4 operator - (Vector4& secondVector)
	{
		Vector4 resultantVector;
		resultantVector.x = x - secondVector.x;
		resultantVector.y = y - secondVector.y;
		resultantVector.z = z - secondVector.z;
		resultantVector.w = w - secondVector.w;
		//if (w + secondVector.w == 1)
		//{
		//	resultantVector.w = 0;
		//}
		//else if (w + secondVector.w == 2)
		//{
		//	resultantVector.w = 1;
		//}
		//else
		//{
		//	resultantVector.w = 2;   // Returns w = 2 when there's error or it's not possible add
		//}
		return resultantVector;
	}

	Vector4 operator * (float scalarValue)
	{
		Vector4 resultantVector;
		resultantVector.x = x * scalarValue;
		resultantVector.y = y * scalarValue;
		resultantVector.z = z * scalarValue;
		resultantVector.w = w;
		return resultantVector;
	}

	friend Vector4 operator * (float scalarValue, Vector4& thisVector)
	{
		Vector4 resultantVector;
		resultantVector.x = thisVector.x*scalarValue;
		resultantVector.y = thisVector.y*scalarValue;
		resultantVector.z = thisVector.z*scalarValue;
		resultantVector.w = thisVector.w;
		return resultantVector;
	}

	Vector4 operator / (float scalarValue)
	{
		Vector4 resultantVector;
		resultantVector.x = x / scalarValue;
		resultantVector.y = y / scalarValue;
		resultantVector.z = z / scalarValue;
		resultantVector.w = w;
		return resultantVector;
	}

	float& operator [] (int subscript)
	{
		if (subscript == 0)
			return x;
		else if (subscript == 1)
			return y;
		else if (subscript == 2)
			return z;
		else if (subscript == 3)
			return w;
	}

	operator float* ()
	{
		return &x;
	}

	union {
		struct {
			float x;
			float y;
			float z;
			float w;
		};
		float vector4x1[1][4];
	};

};

