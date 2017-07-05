#pragma once
#include <vector>
#include <memory>
#include "Resource.h"
#include "ResourceBase.h"

class ResourceManager 

{

public: 
	// Define an enum to allow us to specify what type of resource we want to get from the Resource Manager
	enum ResourceType {
		TEXTURE = 0,
		FONT,
		AUDIO
	};

	std::vector <std::shared_ptr <ResourceBase> > m_resources;

	ResourceManager() {};
	ResourceManager(const ResourceManager&) {};
	ResourceManager& operator= (const ResourceManager&) {};

public:
	static ResourceManager& getInstance() {
		static ResourceManager instance;
		return instance;
	}
	~ResourceManager() {};


	std::shared_ptr <ResourceBase> get(const std::string filename,
									ResourceType type);

	void collectGarbage();
	int getCount();

};