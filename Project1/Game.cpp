#include "Game.hpp"



/// --------------------------------------------------------------------------------------------------
// ���[�h���
void LoadScreen(const int t_time, const int t_max, const int t_now)
{
	DrawFormatString(0, 0, GetColor(255, 255, 0), "%d\t%d", t_time, t_max - t_now);
}



/// --------------------------------------------------------------------------------------------------
Game::Game()
{
	m_isLoadNow = true;
	std::vector<std::string> mv_loadPath;
	std::vector<ELOADFILE> mv_loadType;

	// ���[�h����摜�Ȃǂ���΂����Œǉ�����
	mv_loadPath.push_back("load.png");
	mv_loadType.push_back(ELOADFILE::graph);
	// ���[�h����摜�Ȃǂ���΂����Œǉ�����

	mp_loadThread = new LoadThread(mv_loadPath.size(), mv_loadPath, mv_loadType, LoadScreen);
}



/// --------------------------------------------------------------------------------------------------
Game::~Game()
{
	delete mp_loadThread;
	mp_loadThread = nullptr;
}



/// --------------------------------------------------------------------------------------------------
void Game::RunLoop()
{
	if (m_isLoadNow)
	{
		mp_loadThread->Process();
		if (mp_loadThread->GetEnd())
		{
			m_isLoadNow = false;
		}
	}
	else
	{
		GameUpdate();
	}
}



/// --------------------------------------------------------------------------------------------------
void Game::GameUpdate()
{
	// �Q�[��������M��̂͂�������
	DrawBox(0, 0, 300, 300, GetColor(255, 255, 0), true);
	DrawGraph(0, 0, mp_loadThread->GetFile().at(0), false);
}
