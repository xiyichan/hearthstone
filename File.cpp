#include<iostream>
#include"Follower.h"
#include<fstream>
#include<functional>
#include<algorithm>
#include<string>
#include"Role.h"
#include"Player.h"
#include<direct.h>
#include<io.h>
using namespace std;
void WriteFollowerLibrary(vector<Follower *>::iterator v,string path){
	ofstream app(path, ofstream::app);
	app <<*(*v);
	app.close();
}
void ReadFollowerLibrary(vector<Follower *> &FollowerLibrary,string path) {
	vector<Follower *>::iterator v;
	char c;
	int id=0;
	int FollowerID;
	string FollowerName;
	int FollowerHealth;
	int FollowerAttack;
	int FollowerCostcystal;
	int FollowerStatus;
	int FollowerProfession;
	ifstream in(path);
	if (in) {
		while (true){
			

			in >> FollowerID;
			in >> FollowerName;
			in >> FollowerHealth;
			in >> FollowerAttack;
			in >> FollowerCostcystal;
			in>>FollowerStatus;
			in>>FollowerProfession;
			if (in.eof())
				break;
			
			FollowerLibrary.push_back(new Follower(FollowerID, FollowerName, FollowerHealth, FollowerAttack,
				FollowerCostcystal,FollowerStatus,(enum FollowerProfession)FollowerProfession));
			
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
	ofstream outf("PlayerID.txt");
	outf << PlayerID;
	outf.close();
}
void ReadPlayerID(int &PlayerID)
{
	ifstream inf("PlayerID.txt");
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
	string RoleName;
	int RoleHealth;
	int RoleAttack;
	int RoleStatusl;
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


void getAllFileNames(const string& folder_path)
{
	_finddata_t file;
	long flag;
	string filename = folder_path + "\\*.txt";
	if ((flag = _findfirst(filename.c_str(), &file)) == -1)
	{
		cout << "There is no such type file" << endl;
	}
	else
	{
		string name = folder_path + "\\" + file.name;
		cout << name << endl;
		while (_findnext(flag, &file) == 0)
		{
			string name = string(folder_path + "\\" + string(file.name));
			cout << name << endl;
		}
	}
	_findclose(flag);
}