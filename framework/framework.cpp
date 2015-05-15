#include "framework.h"
#include "GameMain.h"
#include "DxLib.h"

///////////////////////////////////////////////////////////////////////////////
//
//
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
         LPSTR lpCmdLine, int nCmdShow ) {

	framework *fw;
	fw = framework::getInstance( );
	fw->init();

	if( DxLib_Init() == -1 )    // �c�w���C�u��������������
    {
         return -1;    // �G���[���N�����璼���ɏI��
    }
	GameMain *gm;
	gm = new GameMain;
	gm->update( );

	return 0;
}

framework* framework::s_instance = NULL;

///////////////////////////////////////////////////////////////////////////////
//�|�C���^�[�̎擾
//
framework* framework::getInstance( ) {
	if ( !s_instance  ) {
		s_instance = new framework( );
	}

	return s_instance;
};

///////////////////////////////////////////////////////////////////////////////
//�|�C���^�[�̍폜
//
void framework::deleteInstance( ) {
	if( s_instance ) {
		delete s_instance;
		s_instance = NULL;
	}
}

///////////////////////////////////////////////////////////////////////////////
//�|�C���^�[�̗L���̊m�F
framework* framework::checkInstance( ) {
	return s_instance;
}

///////////////////////////////////////////////////////////////////////////////
//framework�̏����ݒ�
//
void framework::init( ){
	int Cr ;

    // �E�C���h�E���[�h�ɕύX
    ChangeWindowMode( TRUE ) ;

	//��ʉ𑜓x�̎擾
	int screen_size_x;
	int screen_size_y;
	GetDefaultState( &screen_size_x, &screen_size_y, NULL );

    // ���F�̒l���擾
    Cr = GetColor( 255 , 255 , 255 ) ;
	
	//�E�C���h�E�T�C�Y�̐؂�ւ�
#if _DEBUG
	SetGraphMode( screen_size_x / 2, screen_size_y / 2, 32 );
#else
	SetGraphMode( screen_size_x, screen_size_y, 32 );
#endif
}

///////////////////////////////////////////////////////////////////////////////
//framework�̏I������
//
void framework::end( ) {
	if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
		DxLib_End() ;        // �c�w���C�u�����g�p�̏I������
		deleteInstance( );
	}
}

///////////////////////////////////////////////////////////////////////////////
//�O�t�B�b�N�̃��[�h
//
int framework::loadfGraph( char *fileName ) {
	return LoadGraph( fileName );
}

///////////////////////////////////////////////////////////////////////////////
//�o�b�N�O���E���h�̕`��
//
void framework::drawGraphBackGround( int filename ) {
	DrawGraph( 0, 0, filename, TRUE  );
}