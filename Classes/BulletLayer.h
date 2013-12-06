#ifndef _BULLETLAYER_H_
#define _BULLETLAYER_H_

#include "cocos2d.h"

class BulletLayer
{
public:
	void addBullet(cocos2d::CCPoint position);
	cocos2d::CCArray* getAllBullets();
	void removeBullets(cocos2d::CCArray *bulletsToDelete);
};

#endif