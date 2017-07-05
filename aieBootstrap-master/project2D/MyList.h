#pragma once
#include <assert.h>
template <class DynamicType>
class Node
{
public:
	Node(){}
	~Node() {}

	Node<DynamicType>*			nextNode = nullptr;
	Node<DynamicType>*			previousNode = nullptr;
	DynamicType					value = 0;
};

template <class DynamicType>
class MyList
{
public:

	MyList() {}
	~MyList() {}

	// returns the value of the first node
	DynamicType first()
	{
		assert(firstNode != nullptr && "Cannot return the first node because it is a nullptr meaning list is empty");
		return firstNode->value;
	}

	// returns the value of the last node
	DynamicType last()
	{
		assert(lastNode != nullptr && "Cannot return the last node since it is a nullptr");
		return lastNode->value;
	}

	// returns a pointer to the first node
	Node<DynamicType>* begin()
	{
		assert(firstNode != nullptr && "First Node is a nullptr");
		return firstNode;
	}

	// returns a pointer to the end of the list
	Node<DynamicType>* end()
	{
		return lastNode->nextNode;
	}
	
	// add another node at the start of the list
	void pushFront(DynamicType value)
	{
		// create a new Node

		Node<DynamicType>* newNode = new Node<DynamicType>[1];
		// sets the properties of the new node
		newNode->nextNode = firstNode;
		newNode->previousNode = nullptr;
		newNode->value = value;

		// checking if list is empty and setting the last node
		if (lastNode == nullptr)
			lastNode = newNode;

		// setting the old first node's previous node to this new node
		if (firstNode != nullptr)
			firstNode->previousNode = newNode;

		// set this as the new first node
		firstNode = newNode;
	}

	// add another node at the end of the list
	void pushBack(DynamicType value)
	{
		// create a new Node
		Node<DynamicType>* newNode = new Node<DynamicType>[1];

		// sets the properties of the new node
		newNode->nextNode = nullptr;
		newNode->previousNode = lastNode;
		newNode->value = value;

		// checking if list is empty and setting the first node
		if (firstNode == nullptr)
			firstNode = newNode;

		// setting the old last node's next node to this new node
		if (lastNode != nullptr)
			lastNode->nextNode = newNode;

		// set this as the new first node
		lastNode = newNode;
	}

	// checks if the List is empty or not
	bool empty()
	{
		return firstNode == nullptr && lastNode == nullptr;
	}

private:
	
	Node<DynamicType>* firstNode = nullptr;
	Node<DynamicType>* lastNode = nullptr;
};