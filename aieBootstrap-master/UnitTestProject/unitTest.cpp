#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MyVector.h"
#include "MyList.h"
#include <assert.h>
#include <iostream>
#include <memory>
#include <vector>

// For custom dynamic array or vector container
TEST_CASE("Check if PushBack method and [] operator in vector container are working properly") {
	MyVector<int> testVector;
	for (int i = 0; i < 5; i++)
		testVector.pushBack(i + 2);
	for (int i = 0; i < 5; i++)
		REQUIRE(testVector[i] == i + 2);
	testVector[0] = 20;
	REQUIRE(testVector[0] == 20);
}

TEST_CASE("Check if the vector container throws an exception when accessing element out of range") {
	MyVector <int> testVector;
	CHECK_THROWS(testVector[-20] == 20);
	CHECK_THROWS(testVector[20] == 20);

}

TEST_CASE("Checking assignment and copy operator of vector container") {
	MyVector<int> testVector;
	testVector.pushBack(1);
	MyVector<int> tester;
	tester.pushBack(12);
	testVector = tester;
	REQUIRE(testVector[0] == 12);
}

TEST_CASE("check if popBack and size functions of vector container are both working properly") {
	MyVector <int> testVector;
	for (int i = 0; i < 3; i++)
		testVector.pushBack(i * 3);
	testVector.popBack();
	testVector.popBack();
	REQUIRE(testVector.size() == 1);
}

TEST_CASE("Check if begin and end functions of vector container are working properly") {
	MyVector <int> testVector;
	for (int i = 0; i < 3; i++)
		testVector.pushBack(i * 3);
	*(testVector.begin()) = 13;
	REQUIRE(testVector[0] == 13);
	*(testVector.end()) = 9;
	REQUIRE(testVector[3] == 9);
}

TEST_CASE("Check if front and back functions of vector container are working properly") {
	MyVector <int> testVector;
	for (int i = 0; i < 3; i++)
		testVector.pushBack(i * 3);
	REQUIRE(testVector.front() == 0);
	REQUIRE(testVector.back() == 6);
}

TEST_CASE("check if resize and empty functions of vector container are working") {
	MyVector <int> testVector;
	testVector.resize(30);
	REQUIRE(testVector.size() == 30);
	REQUIRE(testVector.empty() == false);
}


// For custom linked list container
TEST_CASE("Check if PushBack, first and last functions in linked list container are working properly") {
	MyList<int> testList;
	for (int i = 0; i < 5; i++)
		testList.pushBack(i + 2);
	REQUIRE(testList.first() == 2);
	REQUIRE(testList.last() == 6);
}

TEST_CASE("Check if pushFront function in linked list container is working properly") {
	MyList<int> testList;
	for (int i = 0; i < 5; i++)
		testList.pushFront(i + 2);
	REQUIRE(testList.first() == 6);
	REQUIRE(testList.last() == 2);
}


TEST_CASE("Check if begin and end functions in linked list container are working properly") {
	MyList<int> testList;
	for (int i = 0; i < 5; i++)
		testList.pushFront(i + 2);
	testList.begin()->value == 6;
	REQUIRE(testList.begin()->value == 6);
	REQUIRE(testList.end() == nullptr);
}
