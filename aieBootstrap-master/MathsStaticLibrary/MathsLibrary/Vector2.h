#pragma once
class Vector2
{
public:
	Vector2();
	~Vector2();
	Vector2(float inputArray2[2]);
	Vector2(float a, float b);

	Vector2 translate(const Vector2& Vector);
	Vector2 scale(float scalar);
	float dot(Vector2& secondVector);
	float magnitude();
	float magnitude2();
	void normalise();

	// Operator overload
	Vector2 operator + (const Vector2& secondVector)
	{
		Vector2 resultantVector;
		resultantVector.x = x + secondVector.x;
		resultantVector.y = y + secondVector.y;
		return resultantVector;
	}

	Vector2 operator - (const Vector2& secondVector)
	{
		Vector2 resultantVector;
		resultantVector.x = x - secondVector.x;
		resultantVector.y = y - secondVector.y;
		return resultantVector;
	}

	Vector2 operator * (float scalarValue)
	{
		Vector2 resultantVector;
		resultantVector.x = x * scalarValue;
		resultantVector.y = y * scalarValue;
		return resultantVector;
	}

	// Operator overload where vector is on the right hand side
	friend Vector2 operator * (float scalarValue, Vector2& thisVector)
	{
		Vector2 resultantVector;
		resultantVector.x = thisVector.x*scalarValue;
		resultantVector.y = thisVector.y*scalarValue;
		return resultantVector;
	}

	Vector2 operator / (float scalarValue)
	{
		Vector2 resultantVector;
		resultantVector.x = x / scalarValue;
		resultantVector.y = y / scalarValue;
		return resultantVector;
	}

	// Operator subscript overload
	float& operator [] (int subscript)
	{
		if (subscript == 0)
			return x;
		else if (subscript == 1)
			return y;
	}

	Vector2 operator + (float scalarValue)
	{
		Vector2 resultantVector;
		resultantVector.x = x + scalarValue;
		resultantVector.y = y + scalarValue;
		return resultantVector;
	}

	Vector2 operator - (float scalarValue)
	{
		Vector2 resultantVector;
		resultantVector.x = x - scalarValue;
		resultantVector.y = y - scalarValue;
		return resultantVector;
	}

	bool operator < (Vector2& secondVector)
	{
		if (x < secondVector.x || y < secondVector.y)
			return true;
		else
			return false;
	}

	bool operator > (Vector2& secondVector)
	{
		if (x > secondVector.x || y > secondVector.y)
			return true;
		else
			return false;
	}

	bool operator <= (Vector2& secondVector)
	{
		if (x <= secondVector.x || y <= secondVector.y)
			return true;
		else
			return false;
	}

	bool operator >= (Vector2& secondVector)
	{
		if (x >= secondVector.x || y >= secondVector.y)
			return true;
		else
			return false;
	}

	operator float* ()
	{
		return &x;
	}

	union {
		struct {
			float x;
			float y;
		};
		float vector2x1[1][2];
	};
};