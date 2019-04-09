#ifndef ROLE_H
#define ROLE_H
#include<string>
#include<iostream>
#include"Follower.h"
#include<list>
#include<vector>
using namespace std;
enum Profession { Mage = 1, Hunter = 2};
class Role {
private :
	int RoleID;
	string RoleName;//角色名
	int RoleHealth;//角色血量
	int RoleAttack;//角色攻击力

	int RoleStatusl;//角色水晶数量
	 enum Profession RoleProfession;
	
	//RoleSkill RSkill;//英雄技能
	

public:
	vector<Follower *> RoleCard;//角色手牌随从,上限十个
	vector<Follower *> RoleCardLibrary;//角色牌库随从，上限30
	vector<Follower *> RoleThrowCardLibrary;//角色弃牌牌库，上限30
	list<Follower *> RoleFollwer;//当前场上随从，上限7个					
								
								//Role();
	Role(int RoleID,string RoleName,int RoleHealth,int RoleAttack,int RoleStatusl,enum Profession RoleProfession);
	//~Role();

	void SetRoleID(int RoleID);
	int GetRoleID();

	void SetRoleName(string RoleName);
	string GetRoleName();
	
	void SetRoleAttack(int RoleAttack);
	int GetRoleAttack();

	void SetRoleHealth(int RoleHealth);
	int GetRoleHealth();

	void SetRoleStatusl(int RoleStatusl);
	int GetRoleStatusl();

	friend ostream & operator << (ostream &  out, Role &r);
};
void AddRoleLibrary(vector<Role *>RoleLibrary, int &RoleID);
bool DeleteFollowerLibrary(vector<Follower *> &FollowerLibrary);

class RoleSkill {
private:
	int RoleSkillAttack;//英雄技能伤害

public:
	void HunterSkill();
	void MageSkill();





};




#endif 