#include "Vector3.h"
#include <cmath>


Vector3::Vector3()
{
}


Vector3::~Vector3()
{
}

Vector3::Vector3(float inputArray3[3])
{
	for (int i = 0; i < 3; i++)
		vector3x1[1][i] = inputArray3[i];
}

Vector3::Vector3(float a, float b, float c) :x(a), y(b), z(c)
{

}

Vector3 Vector3::translate(const Vector3& secondVector)
{
	Vector3 resultantVector;
	resultantVector.x = x + secondVector.x;
	resultantVector.y = y + secondVector.y;
	resultantVector.z = z + secondVector.z;
	return resultantVector;
}

Vector3 Vector3::scale(float scalar)
{
	Vector3 resultantVector;
	resultantVector.x = x * scalar;
	resultantVector.y = y * scalar;
	resultantVector.z = z * scalar;
	return resultantVector;

}

Vector3 Vector3::cross(Vector3& secondVector)
{
	Vector3 resultantVector;
	resultantVector.x = y*secondVector.z - z*secondVector.y;
	resultantVector.y = z*secondVector.x - x*secondVector.z;
	resultantVector.z = x*secondVector.y - y*secondVector.x;
	return resultantVector;
}

float Vector3::dot(Vector3& secondVector)
{
	return x * secondVector.x + y * secondVector.y + z * secondVector.z;
}

float Vector3::magnitude()
{
	return sqrt(x*x + y*y + z*z);
}

void Vector3::normalise()
{
	float length = magnitude();
	x = x / length;
	y = y / length;
	z = z / length;
}