#include "TGameLayer.h"


TGameLayer::TGameLayer(void)
{
}


TGameLayer::~TGameLayer(void)
{
}


bool TGameLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	//背景层
	m_bg = CCSprite::create("bg/bg1.png");
	m_bg->setAnchorPoint(ccp(0, 0));
	m_bgSize = m_bg->getContentSize();
	this->addChild(m_bg, ZORDER_MAP);

	//AI角色层（主角和怪物）
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("animation/role_ac_monkey.plist");
	m_hero = THero::create("");
	m_hero->setSpeed(5);
	m_heroSize = m_hero->getContentSize();
	m_hero->setPosition(ccp(m_heroSize.width/2, m_heroSize.height/2));
	m_hero->runIdleAction();
	this->addChild(m_hero, ZORDER_AI);



	//信息层（主角的血量等信息）
	m_infoLayer = TInfoLayer::create();
	this->addChild(m_infoLayer, ZORDER_INFO);

	//控制层（方向摇杆，技能按钮，暂停按钮等交互）
	m_controlLayer = TControlLayer::create();
	m_controlLayer->setDelegate(this);
	this->addChild(m_controlLayer, ZORDER_IO);

	scheduleUpdate();

	return true;
}


void TGameLayer::update(float time)
{
	if(m_controlLayer->isMoving())
	{
		moveHero();
		moveBG();
	}
}


void TGameLayer::moveHero()
{
	CCPoint disHero = ccpMult(m_controlLayer->getCurDirection(), m_hero->getSpeed());
	CCPoint nextPos = ccpAdd(m_hero->getPosition(), disHero);
	m_isHeroCenter = false;
	CCLOG("hero x = %f" , m_hero->getPositionX());
	if(m_hero->getPositionX() > SCREEN_CENTER_X - m_hero->getSpeed() && m_hero->getPositionX() < SCREEN_CENTER_X + m_hero->getSpeed())
	{
		m_isHeroCenter = true;
	}
	if(m_isBgMoving == false || m_isHeroCenter == false)
	{
		if(m_controlLayer->isGoRight() && nextPos.x < SCREEN_WIDTH - m_heroSize.width/2 || m_controlLayer->isGoRight() == false && nextPos.x > m_heroSize.width/2)
		{
			m_hero->setPositionX(nextPos.x);
		}
	}

	if(nextPos.y >= m_heroSize.height/2 && nextPos.y <= SCREEN_HEIGHT - m_heroSize.height/2)
	{
		m_hero->setPositionY(nextPos.y);
	}
}

void TGameLayer::moveBG()
{
	m_isBgMoving = false;
	if(m_isHeroCenter)
	{
		CCPoint disHero = ccpMult(m_controlLayer->getCurDirection(), m_hero->getSpeed());
		if(m_controlLayer->isGoRight())
		{
			if(m_bg->getPositionX() - disHero.x > -(m_bgSize.width - SCREEN_WIDTH))
			{
				m_isBgMoving = true;
				m_bg->setPosition(ccp(m_bg->getPositionX() - disHero.x, m_bg->getPositionY()));
			}
		}else
		{
			if(m_bg->getPositionX() - disHero.x < 0)
			{
				m_isBgMoving = true;
				m_bg->setPosition(ccp(m_bg->getPositionX() - disHero.x, m_bg->getPositionY()));
			}
		}
	}
}


void TGameLayer::skillOnClick(int skillid)
{

}