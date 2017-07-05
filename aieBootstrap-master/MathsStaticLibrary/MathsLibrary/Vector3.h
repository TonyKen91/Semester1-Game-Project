#pragma once
class Vector3
{
public:
	Vector3();
	~Vector3();
	Vector3(float inputArray3[3]);
	Vector3(float a, float b, float c);

	Vector3 translate(const Vector3& secondVector);
	Vector3 scale(float scalar);
	Vector3 cross(Vector3& secondVector);
	float dot(Vector3& secondVector);
	float magnitude();
	void normalise();


	// Operator overload
	Vector3 operator + (const Vector3& secondVector)
	{
		Vector3 resultantVector;
		resultantVector.x = x + secondVector.x;
		resultantVector.y = y + secondVector.y;
		resultantVector.z = z + secondVector.z;
		return resultantVector;
	}

	Vector3 operator - (const Vector3& secondVector)
	{
		Vector3 resultantVector;
		resultantVector.x = x - secondVector.x;
		resultantVector.y = y - secondVector.y;
		resultantVector.z = z - secondVector.z;
		return resultantVector;
	}

	Vector3 operator * (float scalarValue)
	{
		Vector3 resultantVector;
		resultantVector.x = x * scalarValue;
		resultantVector.y = y * scalarValue;
		resultantVector.z = z * scalarValue;
		return resultantVector;
	}

	friend Vector3 operator * (float scalarValue, Vector3& thisVector)
	{
		Vector3 resultantVector;
		resultantVector.x = thisVector.x*scalarValue;
		resultantVector.y = thisVector.y*scalarValue;
		resultantVector.z = thisVector.z*scalarValue;
		return resultantVector;
	}

	Vector3 operator / (float scalarValue)
	{
		Vector3 resultantVector;
		resultantVector.x = x / scalarValue;
		resultantVector.y = y / scalarValue;
		resultantVector.z = z / scalarValue;
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
		};
		float vector3x1[1][3];
	};

};

