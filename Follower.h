#ifndef FOLLOWER_H
#define FOLLOWER_H
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Follower {
private:
	int FollowerID;//��ӱ��
	string FollowerName;//�������
	int FollowerHealth;//�������ֵ
	int FollowerAttack;//��ӹ�����
	//int FollowPosition;//���λ��
	int FollowCostcystal;//��ӻ���ˮ��������
	//FollowerStatus FStatusl;//��ӻ������� //0Ϊ˯�ߡ�1������2�����
	//vector<FollowerSkill*> FSkill;//��Ӽ���

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
