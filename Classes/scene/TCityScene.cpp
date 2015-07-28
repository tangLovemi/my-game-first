#include "TCityScene.h"


TCityScene::TCityScene(void)
{
	m_uilayer = NULL;
}


TCityScene::~TCityScene(void)
{
	m_uilayer->removeFromParentAndCleanup(true);
	m_uilayer = NULL;
}

bool TCityScene::init()
{
	if(!CCScene::init())
	{
		return false;
	}

	m_uilayer = TCityUILayer::create();
	m_uilayer->setDelegate(this);
	this->addChild(m_uilayer);

	return true;
}

void TCityScene::gotoGame()
{
	m_uilayer->removeFromParentAndCleanup(true);

	TGameScene* gameScene = TGameScene::create();
	CCDirector::sharedDirector()->replaceScene(CCTransitionShrinkGrow::create(2.0f, gameScene));
}
