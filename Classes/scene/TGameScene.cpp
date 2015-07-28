#include "TGameScene.h"


TGameScene::TGameScene(void)
{
}


TGameScene::~TGameScene(void)
{
}

bool TGameScene::init()
{
	if(!CCScene::init())
	{
		return false;
	}

	m_gameLayer = TGameLayer::create();
	this->addChild(m_gameLayer);

	return true;
}
