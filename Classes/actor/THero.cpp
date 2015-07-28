#include "THero.h"


THero::THero(void)
{
}


THero::~THero(void)
{
}

THero* THero::create(const char* imgName)
{
	THero *pRet = new THero();
	if (pRet && pRet->init(imgName))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool THero::init(const char* imgName)
{
	if(!TActor::init())
	{
		return false;
	}

	m_imageName = imgName;
	const char* initImg = NULL;
	if(imgName != "")
	{
		initImg = CCString::createWithFormat("%s-%s-1.png", m_imageName, ACTION_KEY_IDLE)->getCString();
	}else
	{
		initImg = CCString::createWithFormat("%s-1.png", ACTION_KEY_IDLE)->getCString();
	}
	this->initWithSpriteFrameName(initImg);
	return true;
}