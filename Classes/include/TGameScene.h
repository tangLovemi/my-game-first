#pragma once
#include "cocos2d.h"
USING_NS_CC;

#include <TGameLayer.h>

class TGameScene :
	public CCScene
{
public:
	TGameScene(void);
	~TGameScene(void);

	CREATE_FUNC(TGameScene);
	bool init();

	TGameLayer* m_gameLayer;
};

