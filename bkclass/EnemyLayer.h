#ifndef _ENEMYLAYER_H_
#define _ENEMYLAYER_H_

#include "cocos2d.h"
#include "Enemy.h"
#include "EnemyBulletLayer.h"

class EnemyLayer : public cocos2d::CCLayer
{
private:
	EnemyBulletLayer *bulletLayer;

public:
	static EnemyLayer* create(EnemyBulletLayer *layer);
	virtual bool init();
	void update(float delta);

	void addEnemy();
	void removeEnemies(cocos2d::CCArray *enemiesToDelete);
	void setBulletLayer(EnemyBulletLayer *layer);
};

#endif