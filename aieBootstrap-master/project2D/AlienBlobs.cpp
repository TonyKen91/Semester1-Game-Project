#include "AlienBlobs.h"
#include "Vector3.h"
#include <Texture.h>
#include <Renderer2D.h>
#include "ResourceManager.h"

AlienBlob::AlienBlob(const std::string name, std::shared_ptr<ResourceBase> texture)
{
	m_velocity.x = m_velocity.y = 0;
	m_position.x = m_position.y = 0;
	m_acceleration.x = m_acceleration.y = 0;
	m_name = name;
	m_texture = texture;
}

AlienBlob::AlienBlob(const std::string name, const char* filename)
{
	m_velocity.x = m_velocity.y = 0;
	m_position.x = m_position.y = 0;
	m_acceleration.x = m_acceleration.y = 0;
	m_name = name;
	m_texture = ResourceManager::getInstance().get(filename, ResourceManager::TEXTURE);
}

AlienBlob::AlienBlob(const AlienBlob& other)
{
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_acceleration = other.m_acceleration;
	m_name = other.m_name;
	m_texture = other.m_texture;
}


AlienBlob::~AlienBlob()
{

}

AlienBlob& AlienBlob::operator=(const AlienBlob& other) {
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_acceleration = other.m_acceleration;
	m_name = other.m_name;
	m_texture = other.m_texture;
	return *this;
}



void AlienBlob::setPos(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = 0;
}

void AlienBlob::setVel(float x, float y)
{
	m_velocity.x = x;
	m_velocity.y = y;
	m_velocity.z = 0;
}

void AlienBlob::setAcc(float x, float y)
{
	m_acceleration.x = x;
	m_acceleration.y = y;
	m_acceleration.z = 0;
}

void AlienBlob::setPos(Vector3 position)
{
	m_position = position;
}
void AlienBlob::setVel(Vector3 velocity)
{
	m_velocity = velocity;
}
void AlienBlob::setAcc(Vector3 acceleration)
{
	m_acceleration = acceleration;
}


Vector3 AlienBlob::getPos()
{
	return m_position;
}

Vector3 AlienBlob::getVel()
{
	return m_velocity;
}

Vector3 AlienBlob::getAcc()
{
	return m_acceleration;
}

std::shared_ptr<IPrototype> AlienBlob::clone()
{
	return std::shared_ptr <IPrototype>(new AlienBlob(*this));
}

std::string AlienBlob::getName()
{
	return m_name;
}

void AlienBlob::update(float dt, float windowWidth, float windowHeight)
{
	m_velocity.x += m_acceleration.x*dt;
	m_velocity.y += m_acceleration.y*dt;
	m_position.x += m_velocity.x*dt;
	m_position.y += m_velocity.y*dt;
	if (m_position.x + m_radius > windowWidth)
	{
		setPos(windowWidth - m_radius, m_position.y);
		setVel(-m_velocity.x, m_velocity.y);
	}
	else if (m_position.x + m_radius <= 0)
	{
		setPos(0 + m_radius, m_position.y);
		setVel(-m_velocity.x, m_velocity.y);
	}

	if (m_position.y + m_radius > windowHeight)
	{
		setPos(m_position.x, windowHeight - m_radius);
		setVel(m_velocity.x, -m_velocity.y);
	}
	else if (m_position.y - m_radius < 0)
	{
		setPos(m_position.x, 0 + m_radius);
		setVel(m_velocity.x, -m_velocity.y);
	}

}

void AlienBlob::draw(aie::Renderer2D* renderer)
{
	renderer->drawCircle(m_position.x, m_position.y, m_radius);
}
