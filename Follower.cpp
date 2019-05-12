#include "Follower.h"
#include "Role.h"
#include "File.h"
#include <algorithm>
#include <functional>
#include "Bool.h"
using namespace std;

Follower::Follower()
{
}

Follower::Follower(int FollowerID, string FollowerName, int FollowerHealth, int FollowerAttack,
				   int FollowCostcystal, int FollowerStatus, enum FollowerProfession FollowerProfession)
{
	this->FollowerID = FollowerID;
	this->FollowerName = FollowerName;
	this->FollowerHealth = FollowerHealth;
	this->FollowerAttack = FollowerAttack;
	this->FollowCostcystal = FollowCostcystal;
	this->FollowerStatus = FollowerStatus;
	this->FollowerProfession = FollowerProfession;
}
void Follower::SetFollowerID(int ID)
{
	this->FollowerID = FollowerID;
}
int Follower::GetFollowerID()
{
	return this->FollowerID;
}
void Follower::SetFollowerName(string FollowerName)
{
	this->FollowerName = FollowerName;
}
string Follower::GetFollowerName()
{
	return this->FollowerName;
}
void Follower::SetFollowerHealth(int FollowerHealth)
{
	this->FollowerHealth = FollowerHealth;
}
int Follower::GetFollowerHealth()
{
	return this->FollowerHealth;
}
void Follower::SetFollowerAttack(int FollowerAttack)
{
	this->FollowerAttack = FollowerAttack;
}
int Follower::GetFollowerAttack()
{
	return this->FollowerAttack;
}
void Follower::SetFollowCostcystal(int FollowCostcystal)
{
	this->FollowCostcystal = FollowCostcystal;
}
int Follower::GetFollowCostcystal()
{
	return this->FollowCostcystal;
}
void Follower::SetFollowerStatus(int FollowerStatus)
{
	this->FollowerStatus = FollowerStatus;
}
int Follower::GetFollowerStatus()
{
	return this->FollowerStatus;
}

void Follower::SetFollowerProfession(enum FollowerProfession FollowerProfession)
{
	this->FollowerProfession = FollowerProfession;
}
enum FollowerProfession Follower::GetFollowerProfession()
{
	return this->FollowerProfession;
}
void AddFollowerLibrary(vector<Follower *> &FollowerLibrary, int &FollowerID)
{
	vector<Follower *>::iterator v = FollowerLibrary.begin();
	//int FollowerID;
	string FollowerName;
	int FollowerHealth;
	int FollowerAttack;
	int FollowCostcystal;
	int FollowerStatus;
	int FollowerProfession;
	cout << "ÇëÊäÈëËæ´ÓID" << endl;
	cout << "FollowerID:";
	cout << FollowerID << endl;
	cout << "FollowerName:";
	cin >> FollowerName;
	cout << "FollowerAttack:";
	cin >> FollowerAttack;
	cout << "FollowerHealth:";
	cin >> FollowerHealth;
	cout << "FollowCostcystal:";
	cin >> FollowCostcystal;
	cout << "FollowerStatus:";
	cin >> FollowerStatus;
	cout << "FollowerProfession:"<<endl;
	cout << "0.normal 1.mage  2.hunter" << endl;
	cin >> FollowerProfession;
	FollowerLibrary.push_back((new Follower(FollowerID, FollowerName, FollowerHealth, FollowerAttack,
											FollowCostcystal, FollowerStatus, (enum FollowerProfession)FollowerProfession)));
	FollowerID++;
	WriteFollowerID(FollowerID);
	v = FollowerLibrary.end();
	v--;
	string path = "FollowerLibrary.txt";
	WriteFollowerLibrary(v, path);
}

bool DeleteFollowerLibrary(vector<Follower *> &FollowerLibrary)
{
	vector<Follower *>::iterator v = FollowerLibrary.begin();
	string path = "FollowerLibrary.txt";
	int FollowerID = 0;
	cin >> FollowerID;
	v = find_if(FollowerLibrary.begin(), FollowerLibrary.end(), bind(BoolFollowerID, placeholders::_1, FollowerID));
	if (v == FollowerLibrary.end())
	{
		return false;
	}
	else
	{
		FollowerLibrary.erase(v);
		ofstream out("FollowerLibrary.txt");
		v = FollowerLibrary.begin();
		//WriteFollowerLibrary(v,path);
		while (v != FollowerLibrary.end())
		{
			out << *(*v);
			v++;
		}
		out.close();
		return true;
	}
}

ostream &operator<<(ostream &out, Follower &f)
{

	out << f.GetFollowerID() << "\t";
	out << f.GetFollowerName() << "\t";
	out << f.GetFollowerHealth() << "\t";
	out << f.GetFollowerAttack() << "\t";
	out << f.GetFollowCostcystal() << "\t";
	out << f.GetFollowerStatus() << "\t";
	out<<f.GetFollowerProfession()<<endl;
	return out;
}