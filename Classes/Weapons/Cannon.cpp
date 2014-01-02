#include "Cannon.h"

#include "Bullets/Bullet.h"
#include "Game.h"

USING_NS_CC;

bool Cannon::init(float fireinterval, bool Rotatable, const char *bulletType, float speed, float damage)
{
	if(!initWithSpriteFrameName("cannon.png")) return false;

	initWeapon();

	setFireInterval(fireinterval);
	if (Rotatable) enableRotate();
	
	this->bulletType = bulletType;
	this->bulletSpeed = speed;
	this->bulletDamage = damage;

	this->scheduleUpdate();

	return true;
}

void Cannon::update(float delta)
{
	rotateWeapon();

	if (weaponReady(delta)) {
		//Bullet *bullet = Bullet::create();
		Bullet *bullet = Bullet::create(bulletType.c_str(), bulletSpeed, bulletDamage);
		//TO BE DONE: let create method input bullet start point
		bullet->setPosition(convertToWorldSpace(ccp(60, 22)));
		bullet->setRotation(getRotation());

		GameLayer *layer = (GameLayer*)Game::sharedGame->getLayer("GameLayer");
		layer->addBullet(bullet);
	}
}