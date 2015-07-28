#pragma once
#include "cocos2d.h"
USING_NS_CC;

#include <TDefine.h>
#include <TGameScene.h>

class CityDelegate
{
public:
	virtual void gotoGame() = 0;
};

class TCityUILayer :public CCLayer
{
public:
	TCityUILayer(void);
	~TCityUILayer(void);
	CREATE_FUNC(TCityUILayer);

	bool init();
	void StartGameOnClick(CCObject* psender);

	CC_SYNTHESIZE(CityDelegate*, m_delegate, Delegate);
};

