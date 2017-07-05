#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Vector3.h"
#include "IPrototype.h"
#include "ResourceBase.h"
#include "ResourceManager.h"

namespace aie {
	class Texture;
	class Renderer2D;
}

class AlienBlob : public IPrototype
{
public:
	// Constructors depending on the input
	AlienBlob(const std::string name, std::shared_ptr<ResourceBase> texture);
	AlienBlob(const std::string name, const char* filename);
	AlienBlob(const AlienBlob& other);

	// Destructor
	~AlienBlob();

	AlienBlob& operator= (const AlienBlob& other);

	void setPos(float x, float y);											// set position using float
	void setVel(float x, float y);											// set velocity using float
	void setAcc(float x, float y);											// set acceleration using float
	void setPos(Vector3 position);											// set position using vector
	void setVel(Vector3 velocity);											// set velocity using vector
	void setAcc(Vector3 acceleration);										// set acceleration using vector
	
	virtual std::shared_ptr<IPrototype> clone();							// clones the prototype
	virtual std::string getName();											// returns the name of the object
	
	
	void update(float dt, float windowWidth, float windowHeight);			// updates the object
	void draw(aie::Renderer2D* renderer);									// draws the object
	
		
	// outputs the position, velocity or acceleration
	Vector3 getPos();
	Vector3 getVel();
	Vector3 getAcc();

private:
	std::shared_ptr<ResourceBase> m_texture;
	std::string m_name;

	// object parameters
	Vector3 m_position;
	Vector3 m_velocity;
	Vector3 m_acceleration;
	float m_radius = 15.0f;
	float health;
};