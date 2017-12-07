#include"GameAction.h"
#include<iostream>

GameAction::GameAction(GameStatus* status)
{
	socketActionScript = new SocketAction();
	statusScript = status;
	std::cout << "メインループ開始" << std::endl;
	MainLoop();
	std::cout << "メインループ終了" << std::endl;
	delete socketActionScript;
}

//////////////////////////////////
//ゲーム開始した時の最初に各ユーザに送るデータの処理
//////////////////////////////////
void GameAction::IniShafule()
{
	std::vector<int> checkmasslist;
	std::string senddata = "i";
	CompornentSendData(senddata);
	for (int playercount = 0; playercount < statusScript->GetPlayerCount(); playercount++)
	{
		for (int count = 0; count < statusScript->GetIniCount(); count++)
		{
			int random = rand() % statusScript->GetMaxMassNumber();
			bool result = CheckMassList(checkmasslist, random);
			if (result)
			{
				checkmasslist.push_back(random);
				CompornentSendData(random);
			}
		}
	}
	std::vector<int> socketList = statusScript->GetSocketList();
	std::string data = statusScript->GetSendData();
	std::cout << "送る内容" << data << std::endl;
	for (int playercount = 0; playercount < socketList.size(); playercount++)
	{
		socketActionScript->SocketWrite(socketList[playercount], data);//初期のマスを送信
	}

	std::cout << "初期のマスのデータ送信完了" << std::endl;
	statusScript->ClearSendData();
	for (int playercount = 0; playercount < socketList.size(); playercount++)
	{
		std::string recv = "";
		socketActionScript->SocektRead(socketList[playercount], recv);//受け取ったかどうかの返答
		std::cout << recv << std::endl;
	}

	std::cout << "プレイヤーナンバーを送信します" << std::endl;
	for (int playercount = 0; playercount < socketList.size(); playercount++)
	{
		std::string playernumber = "ip/";
		playernumber += std::to_string(playercount + 1);
		socketActionScript->SocketWrite(socketList[playercount], playernumber);//プレイヤーのidを送信
	}
	std::cout << "プレイヤーナンバーを完了" << std::endl;
}

///////////////////////////////////////
//同じマスでないかの確認
///////////////////////////////////////
bool GameAction::CheckMassList(std::vector<int> masslist, int checknumber)
{
	for (int count = 0; count < masslist.size(); count++)
	{
		if (masslist[count] == checknumber)
		{
			return false;
		}
	}
	return true;
}

/////////////////////////////////////////////
//ユーザに送るデータを生成の処理
/////////////////////////////////////////////
void GameAction::CompornentSendData(int data)
{
	std::string send = statusScript->GetSendData();
	std::string stringdata = std::to_string(data);
	send += stringdata;
	send += statusScript->GetSymbol();
	statusScript->SetSendData(send);
}

void GameAction::CompornentSendData(std::string data)
{
	std::string send = statusScript->GetSendData();
	send += data;
	send += statusScript->GetSymbol();
	statusScript->SetSendData(send);
}

//////////////////////////////////
//ゲームのメイン部分の処理
//////////////////////////////////
bool GameAction::MainLoop()
{
	GameStatus::Status status = statusScript->GetStatus();
	while (status != GameStatus::Status::Finish) {
		int count = statusScript->GetGameTurn();
		if (count <= 0)
		{
			std::cout << "ゲームが終了しました" << std::endl;
			status = GameStatus::Status::End;
		}
		switch (status)
		{
		case GameStatus::Status::Ini:
			IniShafule();
			status = GameStatus::Status::Player1;
			break;

		case GameStatus::Status::Player1:
			status = GameStatus::Status::Player2;
			statusScript->SetStatus(status);
			std::cout << "P1にRead:P2にSend" << std::endl;
			MassDataReadSend(1, 0);
			break;

		case GameStatus::Status::Player2:
			status = GameStatus::Status::Player1;
			std::cout << "P2にRead:P1にSend" << std::endl;
			MassDataReadSend(0, 1);
			count--;
			statusScript->SetGameTurn(count);
			std::cout << "残りのターン数" << count << "です。" << std::endl;
			break;

		case GameStatus::Status::End:
			std::cout << "ゲーム終了の設定をします" << std::endl;
			GameResult();
			status = GameStatus::Status::Finish;
			return false;
		}
	}
}

//////////////////////////////////
//ユーザーが送ってきたデータを中継して送る
//////////////////////////////////
void GameAction::MassDataReadSend(int sendindex, int readindex)
{
	std::cout << "ゆーざとの中継を開始します" << std::endl;
	int count = statusScript->GetGameTurn();
	std::vector<int> socketlist = statusScript->GetSocketList();
	std::string readdata;
	std::string symbol = "m/";
	std::string senddata = symbol;
	socketActionScript->SocektRead(socketlist[readindex], readdata);
	std::cout << "受け取った内容 =" << readdata << std::endl;
	senddata += readdata;
	socketActionScript->SocketWrite(socketlist[sendindex], senddata);
	GameStatus::Status status = statusScript->GetStatus();
	std::cout << "データを送信します" << std::endl;
	std::cout << "ターン終了" << std::endl;
}

void GameAction::GameResult()
{
	std::vector<int> socketlist = statusScript->GetSocketList();
	std::string end = "e/";
	std::cout << "ゲーム終了のお知らせを送信します" << std::endl;
	for (int index = 0; index < socketlist.size(); index++)
	{
		socketActionScript->SocketWrite(socketlist[index], end);
	}
	std::cout << "ゲーム終了のお知らせを送信しました。" << std::endl;
	std::string readdataarray[2];
	std::cout << "マスの数を受け取ります" << std::endl;
	for (int index = 0; index < socketlist.size(); index++)
	{
		socketActionScript->SocektRead(socketlist[index], readdataarray[index]);
		readdataarray[index] += "/";
	}
	std::cout << "マスの数を受け取り終了します。" << std::endl;
	std::string resultsenddata = "r/";
	for (int index = 0; index < socketlist.size(); index++)
	{
		resultsenddata += readdataarray[index];
	};
	std::cout << "結果を送信します" << std::endl;
	for (int index = 0; index < socketlist.size(); index++)
	{
		socketActionScript->SocketWrite(socketlist[index], resultsenddata);
	}
	std::cout << "結果を送信しました" << std::endl;

	for (int index = 0; index < socketlist.size();index++) 
	{
		std::string result = "";
		socketActionScript->SocektRead(socketlist[index],result);
	}
}