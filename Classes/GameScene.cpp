#include "GameScene.h"

USING_NS_CC;

bool GameScene::init()
{
	if(!CCScene::init()) return false;

	// Preparing BackgroundLayer
	BackgroundLayer *backgroundLayer = BackgroundLayer::create();
	CCLog("BackgroundLayer created");
	if(!backgroundLayer) return false;
	this->addChild(backgroundLayer);
	Game::sharedGame->addLayer("backgroundLayer", backgroundLayer);

	// Preparing HeroLayer, which need a subclass of Hero to create itself
	TestHero1 *hero = TestHero1::create();
	CCLog("Hero created");
	hero->addWeapon(new testWeapon());
	CCLog("Weapon loaded");
	hero->setPosition(ccp(380,100));
	HeroLayer *heroLayer = HeroLayer::create(hero);
	CCLog("HeroLayer created");
	if(!heroLayer) return false;
	this->addChild(heroLayer);
	Game::sharedGame->addLayer("HeroLayer", heroLayer);

	return true;
}