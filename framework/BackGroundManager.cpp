#include "BackGroundManager.h"
#include "framework.h"

BackGroundManager::BackGroundManager(void) {
	_fw = framework::getInstance( );
	_back_ground = _fw->loadfGraph( "images/works_dummy_thumnail_1.gif" );
}


BackGroundManager::~BackGroundManager(void) {
}


void BackGroundManager::update( ) {
	_fw->drawGraphBackGround( _back_ground );
}