////////////////////////////////////
//����ҁ@���z���
//�N���X���@�Q�[�����ł̎��s�Ɋւ���N���X
////////////////////////////////////

#pragma once
#include<vector>
#include<cstdlib>
#include"GameStatus.h"
#include"SocketAction.h"

class GameStatus;
class SocketAction;
class GameAction {

private:
	GameStatus* statusScript;
	SocketAction* socketActionScript;
public:
	GameAction(GameStatus* status);
	void IniShafule();//�Q�[���J�n���̍ŏ��̏���
	bool CheckMassList(std::vector<int> maslist,int checknumber);//�����������d�����ēc�ɂ̃`�F�b�N
	void CompornentSendData(int data);//user�ɑ���f�[�^���܂Ƃ߂�֐�
//	void SendData();
	bool MainLoop();
	void MassDataReadSend(int sendindex,int readindex);//���[�U�[�ԂƂ̃f�[�^�������𒆌p���鏈��
	void CompornentSendData(std::string data);
	void GameResult();

};