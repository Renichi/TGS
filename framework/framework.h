#pragma once

class framework {
private:
	framework( ){};
	~framework( ){};
public:
	static framework* getInstance( );
	static void deleteInstance( );
	static framework* checkInstance( );
	void init( );
	void end( );
	int loadfGraph( char *fileName );
	void drawGraphBackGround( int filename );
private:
	static framework* s_instance;
};

