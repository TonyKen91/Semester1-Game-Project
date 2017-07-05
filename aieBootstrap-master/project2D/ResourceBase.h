#pragma once
#include <memory>
#include <vector>
#include "Resource.h"


class ResourceBase
{
protected: 
	ResourceBase(const std::string& filename) : m_filename(filename) {}

public:
	~ResourceBase() {};

	std::string getFilename() {return m_filename; }
	virtual void* getData() = 0;

	template <typename T>
	T* as() { return (T*)getData(); }

protected: 
	std::string m_filename;
};