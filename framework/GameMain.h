#pragma once
#include "framework.h"
#include "BackGroundManager.h"

class GameMain
{
public:
	GameMain(void);
	~GameMain(void);
	void update( );
private:
	framework* _fw;
	BackGroundManager* _bg;
};

