#include "Enginefire.h"

USING_NS_CC;

bool Enginefire::init(cocos2d::CCNode *plane, float rotation, float scale, cocos2d::CCPoint posFix)
{
	if(!initWithFile("enginefire.plist")) return false;

	setRotation(rotation);
	setScale(scale);

	this->plane = plane;
	this->posFix = posFix;

	return true;
}

void Enginefire::update(float delta)
{
	CCParticleSystemQuad::update(delta);

	setPosition(ccpAdd(plane->getPosition(), posFix));
}