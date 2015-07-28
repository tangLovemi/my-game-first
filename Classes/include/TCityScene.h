#pragma once

#include "cocos2d.h"
USING_NS_CC;
#include <TCityUILayer.h>

class TCityScene: public CCScene,public CityDelegate
{
public:
	TCityScene(void);
	~TCityScene(void);

	CREATE_FUNC(TCityScene);
	bool init();

	virtual void gotoGame();

private:
	TCityUILayer* m_uilayer;


};

