#include "TInfoLayer.h"


TInfoLayer::TInfoLayer(void)
{
}


TInfoLayer::~TInfoLayer(void)
{
}


bool TInfoLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	return true;
}