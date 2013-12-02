#ifndef _BULLETLAYER_H_
#define _BULLETLAYER_H_

#include "cocos2d.h"
#include "Bullet.h"

class BulletLayer : public cocos2d::CCLayer
{
private:
	cocos2d::CCSpriteBatchNode *bulletBatchNode;
	cocos2d::CCArray *bullets;

public:
	BulletLayer();
	~BulletLayer();
	static BulletLayer* create();
	virtual bool init();
	void update(float delta);
	void addBullet(cocos2d::CCPoint position);

	static BulletLayer *sharedBulletLayer;
};

#endif