#ifndef ENGINEFIRE_H
#define ENGINEFIRE_H

#include "cocos2d.h"
#include "particle_nodes/CCParticleSystemQuad.h"

class Enginefire : public cocos2d::CCParticleSystemQuad
{
private:
	cocos2d::CCNode *plane;
	float rotation;
	float scale;
	cocos2d::CCPoint posFix;

	bool init(cocos2d::CCNode *plane, float rotation, float scale, cocos2d::CCPoint posFix);
	void update(float delta);

public:
	static Enginefire* create(cocos2d::CCNode *plane, float rotation, float scale, cocos2d::CCPoint posFix)
	{
		Enginefire *pRet = new Enginefire();
		if (pRet && pRet->init(plane, rotation, scale, posFix))
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}
};

#endif