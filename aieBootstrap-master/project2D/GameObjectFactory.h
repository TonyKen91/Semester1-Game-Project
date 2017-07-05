#pragma once
#include <vector>
#include <memory>

class IPrototype;

class GameObjectFactory
{
public:
	GameObjectFactory();
	~GameObjectFactory();

	void addPrototype(std::shared_ptr<IPrototype> prototype);	// add prototype to the factory
	std::shared_ptr<IPrototype> create(const char* name);		// create a clone of prototype passed to it

private:
	std::vector<std::shared_ptr<IPrototype> > m_prototypes;
};