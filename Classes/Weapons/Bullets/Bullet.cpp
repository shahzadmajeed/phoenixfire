#include "Bullet.h"

USING_NS_CC;

void Bullet::initBullet()
{
	damage = 1;
	scheduleUpdate();
}

void Bullet::setDamage(float damage)
{
	this->damage = damage;
}

float Bullet::getDamage()
{
	return damage;
}