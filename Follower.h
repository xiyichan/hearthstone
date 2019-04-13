#ifndef FOLLOWER_H
#define FOLLOWER_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Follower
{
private:
	int FollowerID;		 
	string FollowerName; 
	int FollowerHealth; 
	int FollowerAttack;  
	int FollowCostcystal; 
	int FollowerStatus;  

public:
	Follower();
	Follower(int FollowerID, string FollowerName, int FollowerHealth, int FollowerAttack,
			 int FollowCostcystal,int FollowerStatus);

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

	void SetFollowerStatus(int FollowerStatus);
	int GetFollowerStatus();
	friend ostream &operator<<(ostream &out, Follower &a);
};

void AddFollowerLibrary(vector<Follower *> &FollowerLibrary, int &FollowerID);
bool DeleteFollowerLibrary(vector<Follower *> &FollowerLibrary);

#endif // !FOLLOWER_H
