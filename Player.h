#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include"Follower.h"

class Player {
private:
	int PlayerID;
	string PlayerName;
	int PlayerVictory;
	int PlayerDefeat;
public:
	Player(int PlayerID, string PlayerName, int PlayerVictory, int PlayerDefeat);
	void SetPlayerID(int PlayerID);
	int GetPlayerID();

	void SetPlayerName(string PlayerName);
	string GetPlayerName();

	void SetPlayerVictory(int PlayerVictory);
	int GetPlayerVictory();

	void SetPlayerDefeat(int PlayerDefeat);
	int GetPlayerDefeat();

	friend ostream & operator << (ostream &  out, Player &p);
};

void AddPlayerCardLibrary();
void AddPlayerLibrary(vector<Player *> &PlayerLibrary, int &PlayerID);
bool DeletePlayerLibrary(vector<Player *>&PlayerLibrary);
#endif