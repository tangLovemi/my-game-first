#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "cocos-ext.h"
USING_NS_CC_EXT;
using namespace cocos2d::ui;

#include <TDefine.h>
#define TAG_BASE_SKILL_BTN 129

class TControlLayer;

class TControlLayerDelegate
{
public:
	virtual void skillOnClick(int skillid) = 0;
};

class TControlLayer :public CCLayer
{
public:
	TControlLayer(void);
	~TControlLayer(void);

	CREATE_FUNC(TControlLayer);
	bool init();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	void atkBtnOnClick(CCObject* psender, TouchEventType eventType);
	void skillBtnOnClick(CCObject* psender, TouchEventType eventType);

	bool canPutControlOnLeft(CCPoint touchPos);
	void updateDirection(CCPoint touchPos);
	void addControl(CCPoint pos);
	void removeControl();
	void resetControlPos(CCPoint touchPos);
	bool isMoving();
	bool isGoRight();
	CCPoint getCurDirection();

	virtual void draw();

private:
	TouchGroup* m_uiLayout;
	UIImageView* m_control1;
	UIImageView* m_control2;
	UIButton* m_atkBtn;
	UIButton* m_skillBtn_1;
	UIButton* m_skillBtn_2;
	UIButton* m_skillBtn_3;
	CCSize m_controlSize1;
	CCSize m_controlSize2;
	CCPoint m_controlPos;
	bool m_isMoving;
	bool m_isGoRight;
	CCPoint m_curDir;

	CC_SYNTHESIZE(TControlLayerDelegate*, m_delegate, Delegate);
};

