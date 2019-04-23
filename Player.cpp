#include "Player.h"
#include <vector>
#include "File.h"
#include <functional>
#include <algorithm>
#include "Bool.h"
#include "All.h"

Player::Player(){
	
}
Player::Player(int PlayerID, string PlayerName, int PlayerVictory, int PlayerDefeat)
{
	this->PlayerID = PlayerID;
	this->PlayerName = PlayerName;
	this->PlayerVictory = PlayerVictory;
	this->PlayerDefeat = PlayerDefeat;
}
void Player::SetPlayerID(int PlayerID)
{
	this->PlayerID = PlayerID;
}
int Player::GetPlayerID()
{
	return this->PlayerID;
}

void Player::SetPlayerName(string PlayerName)
{
	this->PlayerName = PlayerName;
}
string Player::GetPlayerName()
{
	return this->PlayerName;
}

void Player::SetPlayerVictory(int PlayerVictory)
{
	this->PlayerVictory = PlayerVictory;
}
int Player::GetPlayerVictory()
{
	return this->PlayerVictory;
}

void Player::SetPlayerDefeat(int PlayerDefeat)
{
	this->PlayerDefeat = PlayerDefeat;
}
int Player::GetPlayerDefeat()
{
	return this->PlayerDefeat;
}

void AddPlayerLibrary(vector<Player *> &PlayerLibrary, int &PlayerID)
{
	vector<Player *>::iterator v = PlayerLibrary.begin();
	//int PlayerID;
	string PlayerName;
	int PlayerVictory = 0;
	int PlayerDefeat = 0;
	cout << "input PlayerID" << endl;
	cout << "PlayerID:";
	cout << PlayerID << endl;
	cout << "PlayerName:";
	cin >> PlayerName;
	string dir = to_string(PlayerID) + "Player";
	mkdir(dir.c_str());
	PlayerLibrary.push_back((new Player(PlayerID, PlayerName, PlayerVictory, PlayerDefeat)));
	PlayerID++;
	WritePlayerID(PlayerID);
	v = PlayerLibrary.end();
	v--;
	WritePlayerLibrary(v);
}

bool DeletePlayerLibrary(vector<Player *> &PlayerLibrary)
{
	vector<Player *>::iterator v = PlayerLibrary.begin();
	int PlayerID = 0;
	cin >> PlayerID;
	v = find_if(PlayerLibrary.begin(), PlayerLibrary.end(), bind(BoolPlayerID, placeholders::_1, PlayerID));
	if (v == PlayerLibrary.end())
	{
		return false;
	}
	else
	{
		PlayerLibrary.erase(v);
		v = PlayerLibrary.begin();
		//WritePlayerLibrary(v);
		ofstream out("PlayerLibrary.txt");
		while (v != PlayerLibrary.end())
		{
			out << *(*v);
			v++;
		}
		out.close();
		return true;
	}
}

ostream &operator<<(ostream &out, Player &p)
{

	out << p.PlayerID << "\t";
	out << p.PlayerName << "\t\t";
	out << p.PlayerVictory << "\t";
	out << p.PlayerDefeat << endl;
	return out;
}

void PlayerCardLibrary()
{
	vector<Player *> PlayerLibrary;
	ReadPlayerLibrary(PlayerLibrary);
	int PlayerID;
	string path;
	cout << "Input PlayerID:" << endl;
	cin >> PlayerID;
	for (vector<Player *>::iterator v = PlayerLibrary.begin(); v != PlayerLibrary.end(); v++)
	{
		if ((*v)->GetPlayerID() == PlayerID)
		{
			path = to_string(PlayerID) + "Player";
			//cout<<path<<endl;
			getAllFileNames(path);
		}
	}
	int flag;
	string pro;
	cout << "choose your profession:" << endl;
	cout << "1.mage 2.hunter" << endl;
	cin >> flag;
	if (flag == 1)
	{
		pro = "Mage";
	}
	else if (flag == 2)
	{
		pro = "Hunter";
	}
	string dir;
	cout << "input your card library name:" << endl;
	cin >> dir;
	dir = path + "\\" + dir + "_" + pro + ".txt";
	//cout<<dir<<endl;
	vector<Follower *>::iterator v;
	vector<Follower *> FollowerLibrary;
	vector<Follower *> PlayerCardLibrary;
	ReadFollowerLibrary(FollowerLibrary, "FollowerLibrary.txt");
	ReadFollowerLibrary(PlayerCardLibrary, dir);
	ShowFollowerLibrary(FollowerLibrary);

	char choose = '1';
	while (choose != '0')
	{
		int FollowerID = 1;
		
		cout << "1.add card" << endl;
		cout << "2.detele card" << endl;
		cout << "3.show card" << endl;
		cin >> choose;
		if (choose == '1')
		{	system("cls");
			cout << "ID\tName\t\tAttack\tHealth\tCostcystal\tStatus\tProfession" << endl;
			for (vector<Follower *>::iterator fo = FollowerLibrary.begin(); fo != FollowerLibrary.end(); fo++)
			{	
				if((*fo)->GetFollowerProfession()==flag||(*fo)->GetFollowerProfession()==0){
				cout << (*fo)->GetFollowerID() << "\t";
				cout << (*fo)->GetFollowerName() << "\t\t";
				cout << (*fo)->GetFollowerAttack() << "\t";
				cout << (*fo)->GetFollowerHealth() << "\t";
				cout << (*fo)->GetFollowCostcystal() << "\t\t";
				cout << (*fo)->GetFollowerStatus() << "\t";
				cout << (*fo)->GetFollowerProfession() << endl;
				}
			}

			while (FollowerID > 0)
			{	//system("cls");
				cout << "input your want followerid" << endl;
				cin >> FollowerID;
				for (vector<Follower *>::iterator fo = FollowerLibrary.begin(); fo != FollowerLibrary.end(); fo++)
				{
					if (PlayerCardLibrary.size() <= 30)
					{
						if ((*fo)->GetFollowerID() == FollowerID&&((*fo)->GetFollowerProfession()==flag||(*fo)->GetFollowerProfession()==0))
						{
							PlayerCardLibrary.push_back(*fo);
							v = PlayerCardLibrary.end();
							v--;
							WriteFollowerLibrary(v, dir);
							cout<<"success"<<endl;
							break;
						}
					}
					else
					{
						cout << "cardlibrary have 30 card" << endl;
					}
				}
				//cout << "no card" << endl;
			}
		}
		if (choose == '2')
		{
			while (FollowerID > 0)
			{
				ShowFollowerLibrary(PlayerCardLibrary);
				v = PlayerCardLibrary.begin();
				cout << "input your want followerid" << endl;
				cin >> FollowerID;
				v = find_if(PlayerCardLibrary.begin(), PlayerCardLibrary.end(), bind(BoolFollowerID, placeholders::_1, FollowerID));
				if (v == PlayerCardLibrary.end())
				{
					cout << "no card exist" << endl;
				}
				else
				{
					PlayerCardLibrary.erase(v);
					ofstream out(dir);
					v = PlayerCardLibrary.begin();
					while (v != PlayerCardLibrary.end())
					{
						out << *(*v);
						v++;
					}
					out.close();
				}
			}
		}
		if (choose == '3')
		{	system("cls");
			ShowFollowerLibrary(PlayerCardLibrary);
		}
	}
}