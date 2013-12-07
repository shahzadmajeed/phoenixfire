#include "Cannon.h"

USING_NS_CC;

Cannon* Cannon::create(const char *pszFileName, float fireInterval)
{
	Cannon *connon = new Cannon();
	if(connon && connon->initWithFile(pszFileName))
	{
		connon->setFireInterval(fireInterval);
		connon->initFireEnergyBar();
		connon->autorelease();
		return connon;
	}
	CC_SAFE_DELETE(connon);
	return NULL;
}

void Cannon::fire(float deltaTime)
{
	if((fireEnergyBar += deltaTime) > fireInterval)
	{
		initFireEnergyBar();
		CCPoint p = getPosition();
		bulletLayer->addBullet(ccpAdd(getParent()->convertToWorldSpace(p), ccp(0, -10)));
	}
}

void Cannon::setFireInterval(float fireInterval)
{
	this->fireInterval = fireInterval;
}

void Cannon::initFireEnergyBar()
{
	fireEnergyBar = 0;
}

void Cannon::setBulletLayer(EnemyBulletLayer *layer)
{
	this->bulletLayer = layer;
}