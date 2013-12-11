#include "BackgroundLayer.h"

USING_NS_CC;

bool BackgroundLayer::init()
{
	if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)) )
    {
        return false;
    }
    
    return true;
}