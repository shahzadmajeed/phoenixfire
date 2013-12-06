#ifndef _ENEMY_BULLETLAYER_H_
#define _ENEMY_BULLETLAYER_H_

#include "cocos2d.h"
#include "Bullet.h"
#include "BulletLayer.h"
#include "Constants.h"

class EnemyBulletLayer : public cocos2d::CCLayer, public BulletLayer
{
private:
	cocos2d::CCSpriteBatchNode *bulletBatchNode;
	cocos2d::CCArray *bullets;

public:
	EnemyBulletLayer();
	~EnemyBulletLayer();
	static EnemyBulletLayer* create();
	virtual bool init();
	void update(float delta);
	void addBullet(cocos2d::CCPoint position);
	cocos2d::CCArray* getAllBullets();
	void removeBullets(cocos2d::CCArray *bulletsToDelete);
};

#endif