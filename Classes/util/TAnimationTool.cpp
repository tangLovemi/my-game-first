#include "TAnimationTool.h"


TAnimationTool::TAnimationTool(void)
{
}


TAnimationTool::~TAnimationTool(void)
{
}

CCAnimate* TAnimationTool::animationWithFrameName(const char *frameName, float delay, int loops)
{
	CCSpriteFrame* frame = NULL;
	int index = 1;
	CCAnimation* animation = CCAnimation::create();
	do 
	{
		CCString* name = CCString::createWithFormat("%s%d.png", frameName, index++);
		frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name->getCString());
		if(frame == NULL)
		{
			break;
		}
		animation->addSpriteFrame(frame);
	} while (true);
	animation->setDelayPerUnit(delay);
	animation->setLoops(loops);
	animation->setRestoreOriginalFrame(true);
	CCAnimate* animate = CCAnimate::create(animation);
	return animate;
}


CCAnimate* TAnimationTool::animationWithFramNameOfPart(const char* frameName, int from, int to, float delay, int loops)
{
	CCSpriteFrame* frame = NULL;
	CCAnimation* animation = CCAnimation::create();
	for (int i = from; i <= to; i++)
	{
		CCString* name = CCString::createWithFormat("%s%d", frameName, i);
		frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name->getCString());
		if(frame == NULL)
		{
			break;
		}
		animation->addSpriteFrame(frame);
	}
	animation->setDelayPerUnit(delay);
	animation->setLoops(loops);
	animation->setRestoreOriginalFrame(true);
	CCAnimate* animate = CCAnimate::create(animation);
	return animate;
}
