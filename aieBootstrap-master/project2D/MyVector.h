#pragma once
#include <assert.h>
#include <iostream>
#include <exception>
#include <initializer_list>
// Vector-like custom container
template <class DynamicType>
class MyVector
{
public:
	typedef DynamicType* iterator;

	// default constructor
	MyVector() {
		currentSize = 10;
		usedElements = 0;
		data = new DynamicType[currentSize];
	}

	// copy constructor
	MyVector(const MyVector& other)
	{
		DynamicType* newData = new DynamicType[other.currentSize];
		for (int i = 0; i < sizeof(other.data); i++)
		{
			newData[i] = other.data[i];
		}
		data = newData;
		currentSize = other.currentSize;
		usedElements = other.usedElements;
	}
	
	// assignment and copy operator
	MyVector& operator= (const MyVector& other)
	{
		DynamicType* newData = new DynamicType[other.currentSize];
		for (int i = 0; i < sizeof(other.data); i++)
		{
			newData[i] = other.data[i];
		}
		data = newData;
		currentSize = other.currentSize;
		usedElements = other.usedElements;
		return *this;
	}

	// operator overload for operator [] that returns data at element specified in []
	DynamicType& operator[] (size_t element) const
	{
		if (element >= currentSize || element < 0) throw std::out_of_range("Element is out of range");
		assert((element >= 0 && element < currentSize) && "Element out of range");
		return data[element];
	}

	// default destructor
	~MyVector()
	{
		delete[] data;
	}

	// add the element to the end of the array's used space
	void pushBack(DynamicType newElement)
	{
		if (usedElements >= currentSize)
		{
			DynamicType* newData = new DynamicType[currentSize * 2];
			for (int i = 0; i < sizeof(data); i++)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			currentSize *= 2;
		}

		data[usedElements] = newElement;
		usedElements++;
	}

	// technically removes the element from the end of the array in a sense
	void popBack()
	{
		usedElements--;
	}

	// returns a pointer that points to the beginning of the array
	DynamicType* begin()
	{
		return data;
	}

	// returns a pointer that points to 1 pass the end of the array with data
	DynamicType* end()
	{
		return data + usedElements;
	}

	// returns a reference to the start of the array with data
	DynamicType& front()
	{
		return data[0];
	}

	// returns a reference to the end of the array with data
	DynamicType& back()
	{
		return data[usedElements - 1];
	}

	// return a constant reference to the end of the array with data
	const DynamicType& back() const
	{
		return data[usedElements - 1];
	}


	// resizes the array into the amount specified
	void resize(unsigned int numberOfElements)
	{
		usedElements = numberOfElements;
		
		if (currentSize < numberOfElements)
		{
			DynamicType* newData = new DynamicType[numberOfElements];
			for (int i = 0; i < currentSize && i < numberOfElements; i++)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			currentSize = numberOfElements;
		}
	}

	// returns the size of the array
	size_t size() const noexcept
	{
		return usedElements;
	}

	// returns a bool if the array is empty or not
	bool empty() const noexcept
	{
		return usedElements == 0;
	}

private:
	unsigned int currentSize;				// array's current capacity
	DynamicType* data = nullptr;			// pointer to the data in the heap where the dynamic array is located
	unsigned int usedElements;				// array's amount used
};


