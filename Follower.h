#ifndef FOLLOWER_H
#define FOLLOWER_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
enum FollowerProfession
{
	fNormal=0,
	fMage = 1,
	fHunter = 2
};

class Follower
{
private:
	int FollowerID;
	string FollowerName;
	int FollowerHealth;
	int FollowerAttack;
	int FollowCostcystal;
	int FollowerStatus;
	enum FollowerProfession FollowerProfession;

public:
	Follower();
	Follower(int FollowerID, string FollowerName, int FollowerHealth, int FollowerAttack,
			 int FollowCostcystal, int FollowerStatus, enum FollowerProfession FollowerProfession);

	void SetFollowerID(int ID);
	int GetFollowerID();

	void SetFollowerName(string FollowerName);
	string GetFollowerName();

	void SetFollowerHealth(int FolloweHealth);
	int GetFollowerHealth();

	void SetFollowerAttack(int FollowerAttack);
	int GetFollowerAttack();

	void SetFollowCostcystal(int FollowCostcystal);
	int GetFollowCostcystal();

	void SetFollowerStatus(int FollowerStatus);
	int GetFollowerStatus();

	void SetFollowerProfession(enum FollowerProfession FollowerProfession);
	enum FollowerProfession GetFollowerProfession();

	friend ostream &operator<<(ostream &out, Follower &a);
};

void AddFollowerLibrary(vector<Follower *> &FollowerLibrary, int &FollowerID);
bool DeleteFollowerLibrary(vector<Follower *> &FollowerLibrary);

#endif // !FOLLOWER_H
