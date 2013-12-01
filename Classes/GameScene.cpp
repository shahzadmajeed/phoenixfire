#include "GameScene.h"

GameScene::GameScene()
{
	gameLayer = NULL;

}

GameScene::~GameScene()
{

}

bool GameScene::init()
{
	if(!CCScene::init()) return false;

	gameLayer = GameLayer::create();
	if(!gameLayer) return false;
	this->addChild(gameLayer);

	planeLayer = PlaneLayer::create();
	if(!planeLayer) return false;
	this->addChild(planeLayer);

	bulletLayer = BulletLayer::create();
	if(!bulletLayer) return false;
	this->addChild(bulletLayer);	

	return true;
}