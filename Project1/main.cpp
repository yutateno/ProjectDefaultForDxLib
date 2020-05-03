#include "DxLib.h"
#include <string>
#include "Game.hpp"



/// --------------------------------------------------------------------------------------------------
// ウィンドウサイズを決める
int winWidth = 0;
int winHeight = 0;
int bitColor = 0;



/// --------------------------------------------------------------------------------------------------
bool Init(const int t_winWidth, const int t_winHeight, const int t_bitColor, std::string t_projectName, bool t_fullScreen)
{
	winWidth = t_winWidth;
	winHeight = t_winHeight;
	bitColor = t_bitColor;

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ログテキスト出力する
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ログテキスト出力しない
#endif


	SetWindowText(t_projectName.c_str());		// メインウインドウのウインドウタイトルを変更する
	SetBackgroundColor(0, 0, 0);				// 背景色を変更
	ChangeWindowMode(TRUE);						// ウィンドウズモードにさせる


	if (t_fullScreen)
	{
		SetGraphMode(winWidth, winHeight, bitColor);			// 画面サイズ設定
		GetDefaultState(&winWidth, &winHeight, &bitColor);		// デフォルトウィンドウ値を得る
		SetWindowSize(winWidth, winHeight);			// デフォルトウィンドウサイズに合わせてゲームサイズを変更
	}


	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return false;			// エラーが起きたら直ちに終了
	}


	SetDrawScreen(DX_SCREEN_BACK);	// 背景描画


	return true;
}



/// --------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (Init(640, 480, 32, "Game", false) == false) return -1;

	Game mp_game = Game();

	// メインループ
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		mp_game.RunLoop();
	}

	mp_game.~Game();

	// 削除
	DxLib_End();		// DXライブラリの後始末


	return 0;
}