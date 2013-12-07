#include "plane.h"

USING_NS_CC;

Plane* Plane::create(const char *pszFileName, float fireInterval)
{
	Plane *plane = new Plane();
	if(plane && plane->initWithFile(pszFileName))
	{
		plane->setFireInterval(fireInterval);
		plane->initFireEnergyBar();
		plane->autorelease();
		return plane;
	}
	CC_SAFE_DELETE(plane);
	return NULL;
}

void Plane::moveTo(CCPoint destination)
{
	runAction(CCEaseIn::create(CCMoveTo::create(0.5f, destination), 0.19f));
}

void Plane::fire(float deltaTime)
{
	if((fireEnergyBar += deltaTime) > fireInterval)
	{
		initFireEnergyBar();
		bulletLayer->addBullet(ccpAdd(getPosition(), ccp(0, 20)));
	}
}

void Plane::setBulletLayer(HeroBulletLayer *layer)
{
	this->bulletLayer = layer;
}

void Plane::setFireInterval(float fireInterval)
{
	this->fireInterval = fireInterval;
}

void Plane::initFireEnergyBar()
{
	fireEnergyBar = 0;
}

boolean Plane::detectCollusion(Bullet *bullet)
{
	CCRect area = boundingBox();
	CCPoint center = ccp(
		area.getMidX(),
		area.getMinY() + area.size.width / 2 + 20);
	float radius = area.size.width / 6;
	if(bullet->getPosition().getDistance(center) < radius)
	{
		this->life -= bullet->getDamage();
		return true;
	}
	return false;
}

void Plane::setLife(float life)
{
	this->life = life;
}

float Plane::getLife()
{
	return this->life;
}