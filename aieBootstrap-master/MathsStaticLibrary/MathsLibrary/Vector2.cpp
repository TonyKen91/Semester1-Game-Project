#include "Vector2.h"
#include <cmath>


Vector2::Vector2()
{
}


Vector2::~Vector2()
{
}

Vector2::Vector2(float inputArray2[2]) 
{
	for (int i = 0; i < 2; i++)
		vector2x1[1][i] = inputArray2[i];
}

Vector2::Vector2(float a, float b) : x(a), y(b)
{
}


Vector2 Vector2::translate(const Vector2& secondVector)
{
	Vector2 resultantVector;
	resultantVector.x = x + secondVector.x;
	resultantVector.y = y + secondVector.y;
	return resultantVector;
}

Vector2 Vector2::scale(float scalar)
{
	Vector2 resultantVector;
	resultantVector.x = x * scalar;
	resultantVector.y = y * scalar;
	return resultantVector;

}

float Vector2::dot(Vector2& secondVector)
{
	return x * secondVector.x + y * secondVector.y;
}

float Vector2::magnitude()
{
	return sqrt(x*x + y*y);
}

float Vector2::magnitude2()
{
	return x*x + y*y;
}

void Vector2::normalise()
{
	float length = magnitude();
	x = x / length;
	y = y / length;
}