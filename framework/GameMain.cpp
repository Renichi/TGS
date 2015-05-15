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
		//�匳�̏���
		_bg->update( );

		_fw->end( ); //�Q�[���̏I������
	}
}
