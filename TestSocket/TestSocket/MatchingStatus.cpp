#include"MatchingStatus.h"
MatchingStatus::MatchingStatus()
{
	MatchingAction* action = new MatchingAction(this);
}

int MatchingStatus::GetSocket()
{
	return sock;
}

sockaddr_in MatchingStatus::GetAddr()
{
	return addr;
}

void MatchingStatus::SetAcceptList(int& set)
{
	acceptList.push_back(set);
}

int MatchingStatus::GetAcceptListSize()
{
	return acceptList.size();
}

std::vector<int> MatchingStatus::GetAcceptList()
{
	return acceptList;
}
int MatchingStatus::GetMatchingCount()
{
	return matchingcCount;
}

