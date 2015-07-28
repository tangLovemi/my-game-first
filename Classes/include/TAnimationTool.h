#pragma once
#include "cocos2d.h"
USING_NS_CC;

class TAnimationTool
{
public:
	TAnimationTool(void);
	~TAnimationTool(void);

	static CCAnimate* animationWithFrameName(const char *frameName, float delay, int loops);
	static CCAnimate* animationWithFramNameOfPart(const char* frameName, int from, int to, float delay, int loops);

};

