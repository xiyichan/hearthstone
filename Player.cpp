#include"Player.h"
#include<vector>
#include"File.h"
#include<functional>
#include<algorithm>
#include"Bool.h"
Player::Player(int PlayerID, string PlayerName, int PlayerVictory, int PlayerDefeat) {
	this->PlayerID = PlayerID;
	this->PlayerName = PlayerName;
	this->PlayerVictory = PlayerVictory;
	this->PlayerDefeat = PlayerDefeat;
}
void Player::SetPlayerID(int PlayerID) {
	this->PlayerID = PlayerID;
}
int Player::GetPlayerID() {
	return this->PlayerID;
}

void Player::SetPlayerName(string PlayerName) {
	this->PlayerName=PlayerName;
}
string Player::GetPlayerName() {
	return this->PlayerName;
}

void Player::SetPlayerVictory(int PlayerVictory) {
	this->PlayerVictory = PlayerVictory;
}
int Player::GetPlayerVictory() {
	return this->PlayerVictory;
}

void Player::SetPlayerDefeat(int PlayerDefeat) {
	this->PlayerDefeat = PlayerDefeat;
}
int Player::GetPlayerDefeat() {
	return this->PlayerDefeat;
}

void AddPlayerLibrary(vector<Player *> &PlayerLibrary, int &PlayerID) {
	vector<Player*>::iterator v = PlayerLibrary.begin();
	//int PlayerID;
	string PlayerName;
	int PlayerVictory=0;
	int PlayerDefeat=0;


	cout << "请输入一下信息" << endl;
	cout << "PlayerID:";
	cout << PlayerID << endl;
	cout << "PlayerName:";
	cin >> PlayerName;
	PlayerLibrary.push_back((new Player(PlayerID, PlayerName, PlayerVictory, PlayerDefeat)));
	PlayerID++;
	WritePlayerID(PlayerID);
	v = PlayerLibrary.end();
	v--;
	WritePlayerLibrary(v);
}

bool DeletePlayerLibrary(vector<Player *>&PlayerLibrary) {
	vector<Player *>::iterator v = PlayerLibrary.begin();
	int PlayerID = 0;
	cin >> PlayerID;
	v = find_if(PlayerLibrary.begin(), PlayerLibrary.end(), bind(BoolPlayerID, placeholders::_1, PlayerID));
	if (v == PlayerLibrary.end()) {
		return false;
}
	else {
		PlayerLibrary.erase(v);
		v = PlayerLibrary.begin();
		WritePlayerLibrary(v);
		return true;
	}

}

ostream & operator<<(ostream &out, Player &p) {

	out <<p.PlayerID << "\t";
	out <<p.PlayerName << "\t\t";
	out <<p.PlayerVictory << "\t";
	out <<p.PlayerDefeat  << endl;
	return out;

}