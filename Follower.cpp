#include"Follower.h"
#include"Role.h"
#include"File.h"
#include<algorithm>
#include<functional>
#include"Bool.h"
using namespace std;

Follower::Follower(int FollowerID, string FollowerName, int FollowerHealth, int FollowerAttack,
	int FollowCostcystal)
{
	this->FollowerID = FollowerID;
	this->FollowerName = FollowerName;
	this->FollowerHealth = FollowerHealth;
	this->FollowerAttack = FollowerAttack;
	this->FollowCostcystal = FollowCostcystal;
}
void Follower::SetFollowerID(int ID) {
	this->FollowerID = FollowerID;
}
int Follower::GetFollowerID() {
	return this->FollowerID;
}
void Follower::SetFollowerName(string FollowerName) {
	this->FollowerName = FollowerName;
}
string Follower::GetFollowerName()
{
	return this->FollowerName;
}
void Follower::SetFollowerHealth(int FolloweHealth)
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


void AddFollowerLibrary(vector<Follower *> &FollowerLibrary, int &FollowerID) {
	vector<Follower *>::iterator v = FollowerLibrary.begin();
	//int FollowerID;//随从编号
	string FollowerName;//随从名字
	int FollowerHealth;//随从生命值
	int FollowerAttack;//随从攻击力
	int FollowCostcystal;//随从花费水晶的数量

	cout << "请输入一下信息" << endl;
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

	FollowerLibrary.push_back((new Follower(FollowerID, FollowerName, FollowerHealth, FollowerAttack,
		FollowCostcystal)));
	FollowerID++;
	WriteFollowerID(FollowerID);
	v = FollowerLibrary.end();
	v--;
	WriteFollowerLibrary(v);
}

bool DeleteFollowerLibrary(vector<Follower *> &FollowerLibrary) {
	vector<Follower *>::iterator v = FollowerLibrary.begin();
	int FollowerID = 0;
	cin >> FollowerID;
	v = find_if(FollowerLibrary.begin(), FollowerLibrary.end(), bind(BoolFollowerID, placeholders::_1, FollowerID));
	if (v == FollowerLibrary.end()) {
		return false;
	}
	else {
		FollowerLibrary.erase(v);
		
		v = FollowerLibrary.begin();
		WriteFollowerLibrary(v);
		return true;
	}

}




ostream & operator<<(ostream &out, Follower &f) {

	out << f.FollowerID << "\t";
	out << f.FollowerName << "\t";
	out << f.FollowerHealth << "\t";
	out << f.FollowerAttack << "\t";
	out << f.FollowCostcystal << endl;
	return out;

}