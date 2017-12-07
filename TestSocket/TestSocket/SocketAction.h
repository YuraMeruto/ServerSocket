#pragma once
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include<unistd.h>
#include<iostream>
#include <string.h>
#include"GameAction.h"
class GameAction;
class SocketAction 
{
public:
	SocketAction();
	void DebugLog(std::string log);
	bool SocketSet(sockaddr_in& address);
	bool SocketClose(int& sock);
	bool SocketWrite(int& sock,std::string senddata);
	bool SocektRead(int& sock,std::string& recvdata);
};