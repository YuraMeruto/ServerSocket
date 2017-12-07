#include <cstdio>
#include<iostream>
#include"MatchingManager.h"

int main()
{
	std::cout << "開始" << std::endl;
	MatchingManager* manager = new MatchingManager();
	delete manager;
	std::cout << "終了" << std::endl;
	return 0;
}

