#pragma once
#include<vector>
#include<string>
#include"GameAction.h"

class GameAction;
////////////////////////////////////
//ゲーム実行でのパラメータを管理するクラス
////////////////////////////////////
class GameStatus 
{
public:
	enum Status//ゲーム進行状態のクラス
	{
		Ini,
		Player1,
		Player2,
		End,
		Finish
	};
private:
	Status status;
	std::vector<int> socketList;
	int gameTurn;//現在のゲームのターン数
	const int MAX_GAME_TURN = 2;//ゲーム中の回数
	const int MAX_INI_COUNT = 5;//
	const int MAX_MASS_NUMBER = 36;//生成するマスの数
	const char SPLIT_SYMBOL = '/';//データを送る時の区切り文字
	std::string senddata;//ユーザーに送るデータ
public:
	GameStatus(std::vector<int> set);
	std::vector<int> GetSocketList();//接続しているユーザのソケットの配列
	int GetIniCount();
	Status GetStatus();
	int GetPlayerCount();
	int GetMaxMassNumber();
	char GetSymbol();
	std::string GetSendData();
	int GetGameTurn();
	std::string SetSendData(std::string& set);
	void SetGameTurn(int set);
	void SetStatus(Status set);
	void ClearSendData();
};

