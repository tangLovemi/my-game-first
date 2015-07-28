#include "TControlLayer.h"


TControlLayer::TControlLayer(void)
{
}


TControlLayer::~TControlLayer(void)
{
}

bool TControlLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	this->setTouchEnabled(true);
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);

	m_uiLayout = TouchGroup::create();
	Widget* panel = GUIReader::shareReader()->widgetFromJsonFile(CCString::createWithFormat("%s%s", PATH_UI, "ControlUI.json")->getCString());
	m_uiLayout->addWidget(panel);
	this->addChild(m_uiLayout);
	
	m_control1 = dynamic_cast<UIImageView*>(m_uiLayout->getWidgetByName("control1_img"));
	m_control1 = dynamic_cast<UIImageView*>(m_uiLayout->getWidgetByName("control2_img"));
	m_controlSize1 = m_control1->getContentSize();
	m_controlSize2 = m_control2->getContentSize();
	m_isMoving = false;
	m_isGoRight = false;


	m_atkBtn = dynamic_cast<UIButton*>(m_uiLayout->getWidgetByName("atk_btn"));
	m_skillBtn_1 = dynamic_cast<UIButton*>(m_uiLayout->getWidgetByName("skill_btn_1"));
	m_skillBtn_2 = dynamic_cast<UIButton*>(m_uiLayout->getWidgetByName("skill_btn_2"));
	m_skillBtn_3 = dynamic_cast<UIButton*>(m_uiLayout->getWidgetByName("skill_btn_3"));
	m_skillBtn_1->setTag(TAG_BASE_SKILL_BTN + 1);
	m_skillBtn_2->setTag(TAG_BASE_SKILL_BTN + 2);
	m_skillBtn_3->setTag(TAG_BASE_SKILL_BTN + 3);
	m_atkBtn->addTouchEventListener(this, SEL_TouchEvent(TControlLayer::atkBtnOnClick));
	m_skillBtn_1->addTouchEventListener(this, SEL_TouchEvent(TControlLayer::skillBtnOnClick));
	m_skillBtn_2->addTouchEventListener(this, SEL_TouchEvent(TControlLayer::skillBtnOnClick));
	m_skillBtn_3->addTouchEventListener(this, SEL_TouchEvent(TControlLayer::skillBtnOnClick));

	return true;
}

bool TControlLayer::isMoving()
{
	return m_isMoving;
}

bool TControlLayer::isGoRight()
{
	return m_isGoRight;
}

CCPoint TControlLayer::getCurDirection()
{
	return m_curDir;
}


bool TControlLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint pos = pTouch->getLocation();
	if(canPutControlOnLeft(pos))
	{
		addControl(pos);
	}
	return true;
}

void TControlLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint pos = pTouch->getLocation();

	if(m_isMoving)
	{
		updateDirection(pos);
		resetControlPos(pos);
	}
}

void TControlLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	removeControl();
}



void TControlLayer::updateDirection(CCPoint touchPos)
{
	float disFromBegin = ccpDistance(touchPos, m_controlPos);
	m_curDir = ccpMult(ccpSub(touchPos, m_controlPos), 1/disFromBegin);
	m_isGoRight = m_curDir.x >= 0;
}



void TControlLayer::resetControlPos(CCPoint touchPos)
{
	float disFromBegin = ccpDistance(touchPos, m_controlPos);
	if(disFromBegin >= 0 && disFromBegin <= (m_controlSize1.width - m_controlSize2.width)/2)
	{
		m_control2->setPosition(touchPos);
	}else
	{
		CCPoint diff = ccpSub(touchPos, m_controlPos);
		float per = (m_controlSize1.width/2 - m_controlSize2.width/2)/disFromBegin;
		CCPoint pos = ccpAdd(ccpMult(diff, per), m_controlPos);
		m_control2->setPosition(pos);
	}
}

void TControlLayer::removeControl()
{
	if(m_isMoving)
	{
		m_isMoving = false;
		m_control1->setVisible(false);
		m_control2->setVisible(false);
	}
}

void TControlLayer::addControl(CCPoint pos)
{
	if(m_isMoving == false)
	{
		m_isMoving = true;
		m_controlPos = pos;
		m_control1->setPosition(pos);
		m_control2->setPosition(pos);
		m_control1->setVisible(true);
		m_control2->setVisible(true);
	}
}

bool TControlLayer::canPutControlOnLeft(CCPoint touchPos)
{
	int x = touchPos.x;
	int y = touchPos.y;
	if(x >= 10 && x <= SCREEN_CENTER_X - m_controlSize1.width/2)
	{
		if(y >= 10 && y <= SCREEN_HEIGHT - m_controlSize1.height/2)
		{
			return true;
		}
	}
	return false;
}

void TControlLayer::draw()
{
	CCLayer::draw();
	glLineWidth(2);
	ccDrawColor4F(0.0, 1.0, 0.0, 1.0);
	//           ¾àÓÒ£º20 ¾àÉÏ£º10    ¿í£º80 ¸ß£º5
	ccDrawRect(ccp(50, 10), ccp(50, 5));
}


void TControlLayer::atkBtnOnClick(CCObject* psender, TouchEventType eventType)
{

}

void TControlLayer::skillBtnOnClick(CCObject* psender, TouchEventType eventType)
{
	if(eventType == TOUCH_EVENT_ENDED)
	{
		UIButton* btn = dynamic_cast<UIButton*>(psender);
		int index = btn->getTag() - TAG_BASE_SKILL_BTN;
	}
}