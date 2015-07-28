#include "TCityUILayer.h"


TCityUILayer::TCityUILayer(void)
{
}


TCityUILayer::~TCityUILayer(void)
{
}


bool TCityUILayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	CCMenuItem* startMenu = CCMenuItemFont::create(
			"StartGame", this, menu_selector(TCityUILayer::StartGameOnClick)
		);
	startMenu->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	CCMenu* menu = CCMenu::createWithItem(startMenu);
	menu->setPosition(ccp(0, 0));
	this->addChild(menu);

	return true;
}

void TCityUILayer::StartGameOnClick(CCObject* psender)
{
	m_delegate->gotoGame();
}