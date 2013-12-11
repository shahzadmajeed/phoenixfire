#include "GameScene.h"

USING_NS_CC;

bool GameScene::init()
{
	if(!CCScene::init()) return false;

	// Preparing BackgroundLayer
	BackgroundLayer *backgroundLayer = BackgroundLayer::create();
	if(!backgroundLayer) return false;
	this->addChild(backgroundLayer);

	// Preparing HeroLayer, which need a subclass of Hero to create itself
	TestHero1 *hero = TestHero1::create();
	HeroLayer *heroLayer = HeroLayer::create(hero);
	if(!heroLayer) return false;
	this->addChild(heroLayer);

	return true;
}