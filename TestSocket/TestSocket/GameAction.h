////////////////////////////////////
//製作者　名越大樹
//クラス名　ゲーム内での実行に関するクラス
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
	void IniShafule();//ゲーム開始時の最初の処理
	bool CheckMassList(std::vector<int> maslist,int checknumber);//同じ数字が重複して田舎のチェック
	void CompornentSendData(int data);//userに送るデータをまとめる関数
//	void SendData();
	bool MainLoop();
	void MassDataReadSend(int sendindex,int readindex);//ユーザー間とのデータをやり取りを中継する処理
	void CompornentSendData(std::string data);
	void GameResult();

};