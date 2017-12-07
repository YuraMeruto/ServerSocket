///////////////////////////////////
//����ҁ@���z���
//�N���X�@�}�b�`���O���X�e�[�^�X���Ǘ�����N���X
///////////////////////////////////
#pragma once
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<vector>
#include"MatchingStatus.h"
#include"MatchingAction.h"

class MatchingAction;
class GameManager;
class MatchingStatus 
{
private:
	const int matchingcCount = 1;
	int sock0;
	int len;
	int sock;
	sockaddr_in addr;
	std::vector<int> acceptList;
	bool matchingLoop;
public:
	MatchingStatus();
	int GetSocket();
	void SetAcceptList(int& set);
	sockaddr_in GetAddr();
	int GetAcceptListSize();//�A�N�Z�X��������Ԃ�����
	std::vector<int> GetAcceptList();
	int GetMatchingCount();//�A�N�Z�X��������Ԃ�����
};