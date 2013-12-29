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
	Game::sharedGame->addLayer("BackgroundLayer", backgroundLayer);

	// Preparing GameLayer.
	GameLayer *gameLayer = GameLayer::create();
	CCLog("GameLayer created");
	if(!gameLayer) return false;
	this->addChild(gameLayer);
	Game::sharedGame->addLayer("GameLayer", gameLayer);

	return true;
}