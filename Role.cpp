#include"Role.h"
#include"Follower.h"
#include<vector>
#include"File.h"
#include<algorithm>
#include<functional>
#include"Bool.h"
using namespace std;


Role::Role(int RoleID,string RoleName, int RoleHealth, int RoleAttack, int RoleStatusl, enum Profession RoleProfession) {
	this->RoleID = RoleID;
	this->RoleName = RoleName;
	this->RoleHealth = RoleHealth;
	this->RoleAttack = RoleAttack;
	this->RoleStatusl = RoleStatusl;
	this->RoleProfession = RoleProfession;

}

void Role::SetRoleID(int RoleID) {
	this->RoleID = RoleID;
}
int Role::GetRoleID() {
	return this->RoleID;
}

void Role::SetRoleName(string RoleName) {
	this->RoleName = RoleName;
}
string Role::GetRoleName() {
	return this->RoleName;
}

void Role::SetRoleAttack(int RoleAttack) {
	this->RoleAttack = RoleAttack;
}
int Role::GetRoleAttack() {
	return this->RoleAttack;
}

void Role::SetRoleHealth(int RoleHealth) {
	this->RoleHealth = RoleHealth;
}
int Role::GetRoleHealth() {
	return this->RoleHealth;
}

void Role::SetRoleStatusl(int RoleStatusl) {
	this->RoleStatusl = RoleStatusl; 
}
int Role::GetRoleStatusl() {
	return this->RoleStatusl;
}

void AddRoleLibrary(vector<Role *>RoleLibrary, int &RoleID) {
	vector<Role*>::iterator v = RoleLibrary.begin();
	
	//int RoleID;
	string RoleName;//角色名
	int RoleHealth;//角色血量
	int RoleAttack;//角色攻击力
	int RoleStatusl;//角色水晶数量
	int RoleProfession;//职业

	cout << "请输入一下信息" << endl;
	cout << "RoleID:";
	cout << RoleID << endl;
	cout << "RoleName:";
	cin >> RoleName;
	cout << "RoleAttack:";
	cin >> RoleAttack;
	cout << "RoleHealth:";
	cin >> RoleHealth;
	cout << "RoleStatusl:";
	cin >> RoleStatusl;
	cout << "RoleProfession:"<<endl;
	cout << "1.mage  2.hunter" << endl;
	cin >> RoleProfession;

	RoleLibrary.push_back(new Role(RoleID, RoleName, RoleHealth, RoleAttack, RoleStatusl, (enum Profession)RoleProfession));
	RoleID++;
	WriteRoleID(RoleID);
	v = RoleLibrary.end();
	v--;
	WriteRoleLibrary(v);
}

bool DeleteFollowerLibrary(vector<Role *> &RoleLibrary) {
	vector<Role *>::iterator v = RoleLibrary.begin();
	int RoleID = 0;
	cin >> RoleID;
	v = find_if(RoleLibrary.begin(), RoleLibrary.end(), bind(BoolRoleID, placeholders::_1, RoleID));
	if (v == RoleLibrary.end()) {
		return false;
	}
	else {
		RoleLibrary.erase(v);

		v = RoleLibrary.begin();
		WriteRoleLibrary(v);
		return true;
	}

}
ostream & operator<<(ostream &out, Role &r) {

	out <<r.GetRoleID()  << "\t";
	out << r.GetRoleName() << "\t";
	out << r.GetRoleAttack() << "\t";
	out << r.GetRoleHealth() << "\t";
	out << r.GetRoleStatusl() << endl;
	return out;

}