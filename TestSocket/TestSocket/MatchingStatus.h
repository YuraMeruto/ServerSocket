///////////////////////////////////
//製作者　名越大樹
//クラス　マッチングをステータスを管理するクラス
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
	int GetAcceptListSize();//アクセスした数を返す処理
	std::vector<int> GetAcceptList();
	int GetMatchingCount();//アクセスした数を返す処理
};