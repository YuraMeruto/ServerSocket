#pragma once
#include<vector>
#include<string>
#include"GameAction.h"

class GameAction;
////////////////////////////////////
//�Q�[�����s�ł̃p�����[�^���Ǘ�����N���X
////////////////////////////////////
class GameStatus 
{
public:
	enum Status//�Q�[���i�s��Ԃ̃N���X
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
	int gameTurn;//���݂̃Q�[���̃^�[����
	const int MAX_GAME_TURN = 2;//�Q�[�����̉�
	const int MAX_INI_COUNT = 5;//
	const int MAX_MASS_NUMBER = 36;//��������}�X�̐�
	const char SPLIT_SYMBOL = '/';//�f�[�^�𑗂鎞�̋�؂蕶��
	std::string senddata;//���[�U�[�ɑ���f�[�^
public:
	GameStatus(std::vector<int> set);
	std::vector<int> GetSocketList();//�ڑ����Ă��郆�[�U�̃\�P�b�g�̔z��
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

