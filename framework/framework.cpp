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

	if( DxLib_Init() == -1 )    // ＤＸライブラリ初期化処理
    {
         return -1;    // エラーが起きたら直ちに終了
    }
	GameMain *gm;
	gm = new GameMain;
	gm->update( );

	return 0;
}

framework* framework::s_instance = NULL;

///////////////////////////////////////////////////////////////////////////////
//ポインターの取得
//
framework* framework::getInstance( ) {
	if ( !s_instance  ) {
		s_instance = new framework( );
	}

	return s_instance;
};

///////////////////////////////////////////////////////////////////////////////
//ポインターの削除
//
void framework::deleteInstance( ) {
	if( s_instance ) {
		delete s_instance;
		s_instance = NULL;
	}
}

///////////////////////////////////////////////////////////////////////////////
//ポインターの有無の確認
framework* framework::checkInstance( ) {
	return s_instance;
}

///////////////////////////////////////////////////////////////////////////////
//frameworkの初期設定
//
void framework::init( ){
	int Cr ;

    // ウインドウモードに変更
    ChangeWindowMode( TRUE ) ;

	//画面解像度の取得
	int screen_size_x;
	int screen_size_y;
	GetDefaultState( &screen_size_x, &screen_size_y, NULL );

    // 白色の値を取得
    Cr = GetColor( 255 , 255 , 255 ) ;
	
	//ウインドウサイズの切り替え
#if _DEBUG
	SetGraphMode( screen_size_x / 2, screen_size_y / 2, 32 );
#else
	SetGraphMode( screen_size_x, screen_size_y, 32 );
#endif
}

///////////////////////////////////////////////////////////////////////////////
//frameworkの終了処理
//
void framework::end( ) {
	if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
		DxLib_End() ;        // ＤＸライブラリ使用の終了処理
		deleteInstance( );
	}
}

///////////////////////////////////////////////////////////////////////////////
//グフィックのロード
//
int framework::loadfGraph( char *fileName ) {
	return LoadGraph( fileName );
}

///////////////////////////////////////////////////////////////////////////////
//バックグラウンドの描画
//
void framework::drawGraphBackGround( int filename ) {
	DrawGraph( 0, 0, filename, TRUE  );
}