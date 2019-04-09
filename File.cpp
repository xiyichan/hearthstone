#include<iostream>
#include"Follower.h"
#include<fstream>
#include<functional>
#include<algorithm>
#include<string>
#include"Role.h"
#include"Player.h"
using namespace std;
void WriteFollowerLibrary(vector<Follower *>::iterator v){
	ofstream app("FollowerLibrary.txt", ofstream::app);
	app <<*(*v);
	app.close();
}
void ReadFollowerLibrary(vector<Follower *> &FollowerLibrary) {
	vector<Follower *>::iterator v;
	char c;
	int id=0;
	int FollowerID;//随从编号
	string FollowerName;//随从名字
	int FollowerHealth;//随从生命值
	int FollowerAttack;//随从攻击力
	int FollowerCostcystal;//随从花费水晶的数量
	ifstream in("FollowerLibrary.txt");
	if (in) {
		while (true){
			

			in >> FollowerID;
			in >> FollowerName;
			in >> FollowerHealth;
			in >> FollowerAttack;
			in >> FollowerCostcystal;
			if (in.eof())
				break;
			
			FollowerLibrary.push_back(new Follower(FollowerID, FollowerName, FollowerHealth, FollowerAttack,
				FollowerCostcystal));
			
		} 

	}
	in.close();
}

void WritePlayerLibrary(vector<Player *>::iterator v) {
	ofstream app("PlayerLibrary.txt", ofstream::app);
	app << *(*v);
	app.close();
}
void ReadPlayerLibrary(vector<Player *> &PlayerLibrary) {
	vector<Player *>::iterator v;
	int PlayerID;
	string PlayerName;
	int PlayerVictory;
	int PlayerDefeat;
	ifstream in("PlayerLibrary.txt");
	if (in) {
		while (true) {
			in >> PlayerID;
			in >> PlayerName;
			in >> PlayerVictory;
			in >> PlayerDefeat;
			if (in.eof())
				break;
			PlayerLibrary.push_back(new Player(PlayerID, PlayerName, PlayerVictory, PlayerDefeat));
		}
	}
	in.close();
}


void WriteFollowerID(int &FollowerID)
{
	ofstream outf("FollowerID.txt");
	outf << FollowerID;
	outf.close();
}
void ReadFollowerID(int &FollowerID)
{
	ifstream inf("FollowerID.txt");
	inf >> FollowerID;
	inf.close();
}

void WritePlayerID(int &PlayerID)
{
	ofstream outf("FollowerID.txt");
	outf << PlayerID;
	outf.close();
}
void ReadPlayerID(int &PlayerID)
{
	ifstream inf("FollowerID.txt");
	inf >> PlayerID;
	inf.close();
}


void WriteRoleLibrary(vector <Role*>::iterator v) {
	ofstream app("RoleLibrary.txt", ofstream::app);
	app << *(*v);
	app.close();
}
void ReadRoleLibrary(vector<Role *> &RoleLibrary)
{
	vector<Role *>::iterator v;
	int RoleID;
	string RoleName;//角色名
	int RoleHealth;//角色血量
	int RoleAttack;//角色攻击力
	int RoleStatusl;//角色水晶数量
	int RoleProfession;
	ifstream in("RoleLibrary.txt");
	if (in) {
		while (true) {
			in >> RoleID;
			in >> RoleName;
			in >> RoleHealth;
			in >> RoleAttack;
			in >> RoleStatusl;
			in >> RoleProfession;
			if (in.eof())
				break;
			RoleLibrary.push_back(new Role(RoleID, RoleName, RoleHealth, RoleAttack, RoleStatusl,(enum Profession)RoleProfession));
		}
	}
	in.close();

}

void WriteRoleID(int &RoleID)
{
	ofstream outf("RoleID.txt");
	outf << RoleID;
	outf.close();
}
void ReadRoleID(int &RoleID)
{
	ifstream inf("RoleID.txt");
	inf >> RoleID;
	inf.close();
}