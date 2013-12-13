#ifndef BACKGROUNDLAYER_H
#define BACKGROUNDLAYER_H

#include "cocos2d.h"

class BackgroundLayer : public cocos2d::CCLayerColor
{
private:
    virtual bool init();

public:
    CREATE_FUNC(BackgroundLayer);
};

#endif
