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

	void SetRoleProfeesion(enum Profession RoleProfession);
	enum Profession GetRoleProfession();
	
	friend ostream & operator << (ostream &  out, Role &r);
};
void AddRoleLibrary(vector<Role *>&RoleLibrary, int &RoleID);
bool DeleteRoleLibrary(vector<Role *> &RoleLibrary);

class RoleSkill {
private:
	int RoleSkillAttack;//英雄技能伤害

public:
	void HunterSkill();
	void MageSkill();





};




#endif 