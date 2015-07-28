#pragma once
#include "cocos2d.h"
USING_NS_CC;
class TInfoLayer :public CCLayer
{
public:
	TInfoLayer(void);
	~TInfoLayer(void);

	CREATE_FUNC(TInfoLayer);
	bool init();
};

