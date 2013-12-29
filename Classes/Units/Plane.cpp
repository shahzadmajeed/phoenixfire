#include "Plane.h"

USING_NS_CC;

void Plane::initPlane()
{
	this->setLife(100);
	this->setStatus(Plane::Status::ALIVE);
}

void Plane::setStatus(Status status)
{
	this->status = status;
}

Plane::Status Plane::getStatus()
{
	return status;
}

void Plane::setLife(float life)
{
	if (life < 0) life = 0;
	this->life = life;
}

float Plane::getLife()
{
	return this->life;
}

void Plane::decreaseLife(float value)
{
	this->life -= value;
	if (life <= 0){
		this->setStatus(Plane::DEAD);
		this->life = 0;
	}
}