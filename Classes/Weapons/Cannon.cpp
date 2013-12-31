#include "Cannon.h"

#include "Bullets/Bullet.h"
#include "Game.h"

USING_NS_CC;

bool Cannon::init()
{
	if(!initWithSpriteFrameName("cannon.png")) return false;

	initWeapon();
	setFireInterval(0.4f);

	this->scheduleUpdate();

	return true;
}

void Cannon::update(float delta)
{
	rotateWeapon();

	if (weaponReady(delta)) {
		Bullet *bullet = Bullet::create();
		//TO BE DONE: let create method input bullet start point
		bullet->setPosition(convertToWorldSpace(ccp(60, 19)));
		bullet->setRotation(getRotation());

		GameLayer *layer = (GameLayer*)Game::sharedGame->getLayer("GameLayer");
		layer->addBullet(bullet);
	}
}