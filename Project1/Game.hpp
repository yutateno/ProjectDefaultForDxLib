#pragma once
#include "DxLib.h"
#include "LoadThread.hpp"



class Game
{
private:
	LoadThread* mp_loadThread;
	bool m_isLoadNow;


	// 調整はここ以下から弄ればいい


public:
	Game();
	~Game();


	void RunLoop();
	void GameUpdate();


	// 調整はここ以下から弄ればいい

};

