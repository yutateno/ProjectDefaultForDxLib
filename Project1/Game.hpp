#pragma once
#include "DxLib.h"
#include "LoadThread.hpp"



class Game
{
private:
	LoadThread* mp_loadThread;
	bool m_isLoadNow;


	// ’²®‚Í‚±‚±ˆÈ‰º‚©‚ç˜M‚ê‚Î‚¢‚¢


public:
	Game();
	~Game();


	void RunLoop();
	void GameUpdate();


	// ’²®‚Í‚±‚±ˆÈ‰º‚©‚ç˜M‚ê‚Î‚¢‚¢

};

