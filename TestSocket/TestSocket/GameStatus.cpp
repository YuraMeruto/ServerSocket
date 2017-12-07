#include"GameStatus.h"
#include<iostream>
GameStatus::GameStatus(std::vector<int> set)
{
	socketList = set;
	gameTurn = MAX_GAME_TURN;
	status = Status::Ini;
	std::cout << "GameAction¶¬" << std::endl;
	GameAction* gameStart = new GameAction(this);
}


GameStatus::Status GameStatus::GetStatus() 
{
	return status;
}
int GameStatus::GetIniCount()
{
	return MAX_INI_COUNT;
}

int GameStatus::GetMaxMassNumber()
{
	return MAX_MASS_NUMBER;
}

std::string GameStatus::GetSendData() 

{
	return senddata;
}

std::string GameStatus::SetSendData(std::string& set)
{
	senddata = set;
}
char GameStatus::GetSymbol()
{
	return SPLIT_SYMBOL;
}
int GameStatus::GetPlayerCount()
{
	return socketList.size();
}

std::vector<int> GameStatus::GetSocketList()
{
	return socketList;
}

void GameStatus::SetGameTurn(int set)
{
	gameTurn = set;
}

int GameStatus::GetGameTurn() 
{
	return gameTurn;
}

void GameStatus::SetStatus(Status set)
{
	status = set;
}

void GameStatus::ClearSendData()
{
	senddata.clear();
}