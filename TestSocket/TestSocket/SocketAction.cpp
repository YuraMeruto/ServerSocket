#include"SocketAction.h"


SocketAction::SocketAction()
{

}

/////////////////////////////////////////////
//デバックするために使用
//////////////////////////////////////////////
void SocketAction::DebugLog(std::string log)
{
	std::cout << log << std::endl;
}

////////////////////////////////////////////////
//接続したソケットのデータの読み込み
/////////////////////////////////////////////////
bool SocketAction::SocektRead(int& sock, std::string& readdata)
{
	std::cout << "データを受信します" << std::endl;
	char buf[20];
	bool result = false;
	while (!result)
	{
		memset(buf, 0, sizeof(buf));
		try {
			recv(sock, buf, sizeof(buf), 0);
		}
		catch (int &sock)
		{
			close(sock);
		}
		readdata = buf;
		if (readdata != "")
		{
			result = true;
		}
	}
	std::cout << "受け取った内容" << readdata << std::endl;
	std::cout << "データを受信終了" << std::endl;
	return true;
}

////////////////////////////////////////////////
//接続したソケットのデータの書き込み処理
/////////////////////////////////////////////////
bool SocketAction::SocketWrite(int& sock, std::string senddata)
{
	std::cout << "データを送信します。" << std::endl;
	std::cout << "送信内容 =" << senddata << std::endl;
	int sendsize = senddata.size();
	int result = -1;
	while (result <= 0)
	{
		try {
			result = write(sock, senddata.c_str(), sendsize);
		}

		catch (int& sock) {
			close(sock);
		}
	}
	std::cout << "データを送信完了しました。" << std::endl;
	return true;
}

