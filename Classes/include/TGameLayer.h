#pragma once
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

#include <TDefine.h>
#include <TControlLayer.h>
#include <TInfoLayer.h>
#include <THero.h>

class TGameLayer :public CCLayer, public TControlLayerDelegate
{
public:
	TGameLayer(void);
	~TGameLayer(void);

	CREATE_FUNC(TGameLayer);
	bool init();

	virtual void update(float time);

	void moveBG();
	void moveHero();

	virtual void skillOnClick(int skillid);
private:

	TControlLayer* m_controlLayer;
	TInfoLayer* m_infoLayer;

	CCSprite* m_bg;
	THero* m_hero;

	CCSize m_bgSize;
	CCSize m_heroSize;
	bool m_isHeroCenter;
	bool m_isBgMoving;
};

