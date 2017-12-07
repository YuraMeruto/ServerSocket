///////////////////////////////////
//製作者　名越大樹
//クラス　プレイヤー同士のマッチングを実行するクラス
///////////////////////////////////
#pragma once
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include "MatchingStatus.h"
#include "GameManager.h"
#include <string>

class GameManager;
class MatchingStatus;
class MatchingAction
{
private:
	void DebugLog(std::string log);
	bool SocketBind(int& sock,sockaddr_in& addr);
	bool SocketSet(sockaddr_in& address);
	bool SocketClose(int& sock);
	bool SocketAccept(int& serversock,int& clientsock, sockaddr_in& addr);
	bool SocketListen(int& sock,int limit);
public:
	MatchingAction(MatchingStatus* status);
};
