#include "GameObject.h"
#include <Texture.h>
#include <Renderer2D.h>
#include "ResourceManager.h"
#include <iostream>

GameObject::GameObject(const std::string name, std::shared_ptr<ResourceBase> texture) : 
	m_name(name), m_texture(texture), m_position(glm::vec2(0, 0)),
m_velocity(glm::vec2(0, 0))
{}

GameObject::GameObject(const std::string name, const char* filename) :
	m_name(name), m_position(glm::vec2(0, 0)),
	m_velocity(glm::vec2(0, 0))
{
	m_texture = ResourceManager::getInstance().get(filename, ResourceManager::TEXTURE);
}

GameObject::GameObject(const GameObject& other) {
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_name = other.m_name;
}

GameObject::~GameObject() {
	//std::cout << m_name << " deallocated" << std::endl;
}

GameObject& GameObject::operator=(const GameObject& other) { 
	m_texture = other.m_texture; 
	m_position = other.m_position; 
	m_velocity = other.m_velocity; 
	m_name = other.m_name; 
	return *this; 
} 

std::shared_ptr<IPrototype> GameObject::clone() { 
	return std::shared_ptr<IPrototype>(new GameObject(*this)); 
}

void GameObject::setPosition(float x, float y) {
	m_position.x = x; 
	m_position.y = y; 
} 

void GameObject::setVelocity(float x, float y) { 
	m_velocity.x = x; 
	m_velocity.y = y; 
} 

void GameObject::update(float dt) { 
	m_position.x += m_velocity.x * dt; 
	m_position.y += m_velocity.y * dt; 
} 

void GameObject::draw(aie::Renderer2D* renderer) { 
	renderer->drawSprite(
		m_texture->as<aie::Texture>(), m_position.x, m_position.y); 
}
