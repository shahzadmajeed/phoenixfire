#include "GameLayer.h"
#include "Bullet.h"

USING_NS_CC;

bool GameLayer::init()
{
	if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)) )
    {
        return false;
    }
    
    return true;
}