#ifndef FOLLOWER_H
#define FOLLOWER_H
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Follower {
private:
	int FollowerID;//随从编号
	string FollowerName;//随从名字
	int FollowerHealth;//随从生命值
	int FollowerAttack;//随从攻击力
	//int FollowPosition;//随从位置
	int FollowCostcystal;//随从花费水晶的数量
	//FollowerStatus FStatusl;//随从基本技能 //0为睡眠、1正常、2嘲讽等
	//vector<FollowerSkill*> FSkill;//随从技能

public:
	Follower(int FollowerID,string FollowerName, int FollowerHealth, int FollowerAttack, 
	 int FollowCostcystal);

	void SetFollowerID(int ID);
	int GetFollowerID();

	void SetFollowerName(string FollowerName);
	string GetFollowerName();

	void SetFollowerHealth(int FolloweHealth);
	int GetFollowerHealth();

	void SetFollowerAttack(int FollowerAttack);
	int GetFollowerAttack();

	//void SetFollowPosition(int FollowPosition);
	//int GetFollowPosition();

	void SetFollowCostcystal(int FollowCostcystal);
	int GetFollowCostcystal();

	


	friend ostream & operator << (ostream &  out, Follower &a);
};
class FollowerSkill {

};
class FollowerStatus {




};


void AddFollowerLibrary(vector<Follower *> &FollowerLibrary, int &FollowerID);
bool DeleteFollowerLibrary(vector<Follower *> &FollowerLibrary);

#endif // !FOLLOWER_H
