#pragma once
#include "DxLib.h"
#include "LoadThread.hpp"



class Game
{
private:
	LoadThread* mp_loadThread;
	bool m_isLoadNow;


	// �����͂����ȉ�����M��΂���


public:
	Game();
	~Game();


	void RunLoop();
	void GameUpdate();


	// �����͂����ȉ�����M��΂���

};

