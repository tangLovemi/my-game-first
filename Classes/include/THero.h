#pragma once
#include "TActor.h"

class THero : public TActor
{
public:
	THero(void);
	~THero(void);

	bool init(const char* imgName);
	static THero* create(const char* imgName);

	CC_SYNTHESIZE(float, m_speed, Speed);
};

