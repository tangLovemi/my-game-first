#include "TActor.h"


TActor::TActor(void)
{
	setStatus(NONE);
	m_direction = LEFT;
}


TActor::~TActor(void)
{
}

void TActor::setDirection(Direction dir)
{
	if(m_direction != dir)
	{
		m_direction = dir;
		if(m_direction == LEFT)
		{
			setFlipX(0);
		}else if(m_direction == RIGHT)
		{
			setFlipX(-1);
		}
	}
}

CCAction* TActor::createAnimate(const char* key)
{
	CCString* name = NULL;
	if(m_imageName != "")
	{
		name = CCString::createWithFormat("%s-%s-", m_imageName, key);
	}else
	{
		name = CCString::createWithFormat("%s-", key);
	}
	CCAnimate* animate = TAnimationTool::animationWithFrameName(name->getCString(), 0.1f, 1);
	CCAction* callback = CCCallFuncN::create(this, callfuncN_selector(TActor::callBackAction));
	
	return CCSequence::create(animate, callback, NULL);
}

void TActor::runIdleAction()
{
	if(m_status != IDLE)
	{
		this->stopAllActions();
		setStatus(IDLE);
		this->runAction(createAnimate(ACTION_KEY_IDLE));
	}
}

void TActor::runWalkAction()
{
	if(m_status == NONE || m_status == IDLE)
	{
		this->stopAllActions();
		setStatus(WALK);
		this->runAction(createAnimate(ACTION_KEY_WALK));
	}
}

void TActor::runAtkAction()
{
	if(m_status != ATK && m_status != HURT && m_status != DEAD)
	{
		this->stopAllActions();
		setStatus(IDLE);
		setCanMove(false);
		this->runAction(createAnimate(ACTION_KEY_ATK));
	}
}

void TActor::runHurtAction()
{
	if(m_status != HURT)
	{
		this->stopAllActions();
		setStatus(IDLE);
		this->runAction(createAnimate(ACTION_KEY_HURT));
	}
}

void TActor::runDeadAction()
{
	if(m_status != DEAD)
	{
		this->stopAllActions();
		setStatus(IDLE);
		this->runAction(createAnimate(ACTION_KEY_DEAD));
	}
}

void TActor::callBackAction(CCNode* sender)
{
	if(sender != NULL)
	{
		setStatus(NONE);
		setCanMove(true);
		runIdleAction();
	}
}
