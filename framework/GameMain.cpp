#include "GameMain.h"
#include "BackGroundManager.h"

GameMain::GameMain(void) {
	_fw = framework::getInstance( );
	_bg = new BackGroundManager;
}

GameMain::~GameMain(void) {
}

void GameMain::update( void ) {
	while( true ) {
		if ( !_fw->checkInstance( ) ) {
			break;
		}
		//‘åŒ³‚Ìˆ—
		_bg->update( );

		_fw->end( ); //ƒQ[ƒ€‚ÌI—¹ˆ—
	}
}
