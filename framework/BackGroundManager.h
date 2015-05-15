#pragma once
#include "framework.h"

class BackGroundManager {
public:
	BackGroundManager(void);
	~BackGroundManager(void);
	void update( );
private:
	framework* _fw;
	int _back_ground;
};

