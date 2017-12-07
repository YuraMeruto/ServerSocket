#include"MatchingAction.h"

MatchingAction::MatchingAction(MatchingStatus* status)
{
	////////////////////////////////////////////
	//ソケットの初期化の処理
	////////////////////////////////////////////
	int sock = status->GetSocket();
	sock = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in addr = status->GetAddr();
	SocketSet(addr);
	SocketBind(sock,addr);
	SocketListen(sock,100);
	std::cout << "マッチング開始" << std::endl;
	/////////////////////////////////////////////
	/////////////////////////////////////////////

	//////////////////////////////////////
	//マッチングに関する処理開始
	//////////////////////////////////////
	while (status->GetAcceptListSize() <= status->GetMatchingCount()) 
	{
		int clientsock;
		SocketAccept(sock, clientsock, addr);
		status->SetAcceptList(clientsock);
	}
	////////////////////////////////////
	//マッチングに関する処理終了
	/////////////////////////////////////

	//////////////////////////////////////////
	//ゲーム開始する処理
	//////////////////////////////////////////
	std::vector<int> socklist = status->GetAcceptList();
	DebugLog("ゲーム開始");
	GameManager* game = new GameManager(status->GetAcceptList());
	for(int index = 0; index < socklist.size(); index++)
	{
		SocketClose(socklist[index]);
	}
	//////////////////////////////////////////////////
	//////////////////////////////////////////////////
	SocketClose(sock);
}

////////////////////////////////////////////
//デバック処理
////////////////////////////////////////////
void MatchingAction::DebugLog(std::string log)
{
	std::cout << log << std::endl;

}

/////////////////////////////////////////////
//ソケットのデータの設定の処理
/////////////////////////////////////////////
bool MatchingAction::SocketSet(sockaddr_in& address)
{
	address.sin_family = AF_INET;
	address.sin_port = htons(10001);
	address.sin_addr.s_addr = INADDR_ANY;
	return true;
}


/////////////////////////////////////////////
//ソケットをバインドする処理
/////////////////////////////////////////////
bool MatchingAction::SocketBind(int& sock, sockaddr_in& addr) 
{
	DebugLog("バインド開始");
	bind(sock, (struct sockaddr *)&addr, sizeof(addr));
	DebugLog("バインド終了");
	return true;
}

/////////////////////////////
//ソケットをクローズする処理
/////////////////////////////
bool MatchingAction::SocketClose(int& sock)
{
	DebugLog("クローズ開始");
	close(sock);
	DebugLog("クローズ終了");
	return true;
}

bool MatchingAction::SocketListen(int& sock,int limit)
{
	DebugLog("Listen開始");
	listen(sock, limit);
	DebugLog("Listen終了");
	return true;
}

bool MatchingAction::SocketAccept(int& serversock, int& clientsock,sockaddr_in& addr)
{
	sockaddr_in client = addr;
	DebugLog("接続待ち開始");
	int len = sizeof(client);
	clientsock = accept(serversock,(struct sockaddr *)&client,(socklen_t *)&len);
	DebugLog("接続待ち終了");
	return true;
}
