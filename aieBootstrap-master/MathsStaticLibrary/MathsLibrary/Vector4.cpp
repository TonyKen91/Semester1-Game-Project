#include "Vector4.h"
#include <cmath>


Vector4::Vector4()
{
}


Vector4::~Vector4()
{
}

Vector4::Vector4(float inputArray4[4])
{
	for (int i = 0; i < 4; i++)
		vector4x1[1][i] = inputArray4[i];
}

Vector4::Vector4(float a, float b, float c, float d) :x(a), y(b), z(c), w(d)
{

}



Vector4 Vector4::translate(const Vector4& secondVector)
{
	if (w + secondVector.w == 1)
	{
		Vector4 resultantVector;
		resultantVector.x = x + secondVector.x;
		resultantVector.y = y + secondVector.y;
		resultantVector.z = z + secondVector.z;
		resultantVector.w = w + secondVector.w;
		return resultantVector;
	}
}

Vector4 Vector4::scale(float scalar)
{
	Vector4 resultantVector;
	resultantVector.x = x * scalar;
	resultantVector.y = y * scalar;
	resultantVector.z = z * scalar;
	resultantVector.w = w;
	return resultantVector;

}

Vector4 Vector4::cross(Vector4& secondVector)
{
	Vector4 resultantVector;
	resultantVector.x = y*secondVector.z - z*secondVector.y;
	resultantVector.y = z*secondVector.x - x*secondVector.z;
	resultantVector.z = x*secondVector.y - y*secondVector.x;
	resultantVector.w = 0;			// According to the Maths Library Brief, this method should result in a vector
	return resultantVector;
}

float Vector4::dot(Vector4& secondVector)
{
	return x * secondVector.x + y * secondVector.y + z * secondVector.z;
}

float Vector4::magnitude()
{
	return sqrt(x*x + y*y + z*z);
}

void Vector4::normalise()
{
	float length = magnitude();
	x = x / length;
	y = y / length;
	z = z / length;
}