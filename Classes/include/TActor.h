#pragma once
#include "cocos2d.h"
USING_NS_CC;

#include <TConfig.h>
#include <TAnimationTool.h>

enum Direction {
	LEFT,
	RIGHT
};

//#define ACTION_KEY_IDLE "idle"
//#define ACTION_KEY_WALK "walk"
//#define ACTION_KEY_ATK "atk"
//#define ACTION_KEY_HURT "hurt"
//#define ACTION_KEY_DEAD "dead"


#define ACTION_KEY_IDLE "39597" //4
#define ACTION_KEY_WALK "39599" //8
#define ACTION_KEY_ATK "39598"  //5
#define ACTION_KEY_HURT "39601" //4
#define ACTION_KEY_DEAD "39601" //10

class TActor : public CCSprite
{
public:
	TActor(void);
	~TActor(void);
	

	const char* m_imageName;

	CC_SYNTHESIZE(float, m_atk, Atk);
	CC_SYNTHESIZE(float, m_def, Def);
	CC_SYNTHESIZE(float, m_hp, HP);
	CC_SYNTHESIZE(float, m_hpTotal, HP_Total);

	Direction m_direction;
	CC_SYNTHESIZE(ActorStatus, m_status, Status);
	CC_SYNTHESIZE(bool, m_canMove, CanMove);

	//the frames count that animation of every status
	CC_SYNTHESIZE(int, m_frameN_idle, FrameN_Idle);
	CC_SYNTHESIZE(int, m_frameN_walk, FrameN_Walk);
	CC_SYNTHESIZE(int, m_frameN_atk, FrameN_Atk);
	CC_SYNTHESIZE(int, m_frameN_hurt, FrameN_Hurt);
	CC_SYNTHESIZE(int, m_frameN_dead, FrameN_Dead);

	CCAction* createAnimate(const char* key);

	virtual void runIdleAction();
	virtual void runWalkAction();
	virtual void runAtkAction();
	virtual void runHurtAction();
	virtual void runDeadAction();
	void callBackAction(CCNode* sender);

	void setDirection(Direction dir);
};

