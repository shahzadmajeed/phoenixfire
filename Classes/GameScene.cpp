#include "GameScene.h"

#include "CocoStudio/Armature/utils/CCArmatureDataManager.h"
#include "Layers/BackgroundLayer.h"
#include "Game.h"

USING_NS_CC;

bool GameScene::init()
{
	if(!CCScene::init()) return false;

	// add texture
	extension::CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("hero1/hero10.png","hero1/hero10.plist","hero1/hero1.ExportJson");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("gameTexture.plist");

	// Preparing BackgroundLayer
	BackgroundLayer *backgroundLayer = BackgroundLayer::create();
	if(!backgroundLayer) return false;
	this->addChild(backgroundLayer);
	Game::sharedGame->addLayer("BackgroundLayer", backgroundLayer);

	// Preparing GameLayer.
	GameLayer *gameLayer = GameLayer::create();
	if(!gameLayer) return false;
	this->addChild(gameLayer);
	Game::sharedGame->addLayer("GameLayer", gameLayer);

	return true;
}