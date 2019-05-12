#include "Follower.h"
#include "File.h"
void ShowFollowerLibrary(vector<Follower *> &FollowerLibrary)
{
	cout << "ID\tName\t\tAttack\tHealth\tCostcystal\tStatus\tProfession" << endl;
	for (vector<Follower *>::iterator fo = FollowerLibrary.begin(); fo != FollowerLibrary.end(); fo++)
	{
		cout << (*fo)->GetFollowerID() << "\t";
		cout << (*fo)->GetFollowerName() << "\t\t";
		cout << (*fo)->GetFollowerAttack() << "\t";
		cout << (*fo)->GetFollowerHealth() << "\t";
		cout << (*fo)->GetFollowCostcystal() << "\t\t";
		cout << (*fo)->GetFollowerStatus() << "\t";
		cout << (*fo)->GetFollowerProfession() << endl;
	}
}
void ShowPlayerLibrary(vector<Player *> &PlayerLibrary)
{
	cout << "ID\tName\tVictory\tDefeat" << endl;
	for (vector<Player *>::iterator v = PlayerLibrary.begin(); v != PlayerLibrary.end(); v++)
	{
		cout << (*v)->GetPlayerID() << "\t";
		cout << (*v)->GetPlayerName() << "\t";
		cout << (*v)->GetPlayerVictory() << "\t";
		cout << (*v)->GetPlayerDefeat() << endl;
	}
}
void ShowRoleLibrary(vector<Role *> &RoleLibrary)
{
	cout << "ID\tName\tHelath\tAttack\tStatusl\tProfession" << endl;
	for (vector<Role *>::iterator v = RoleLibrary.begin(); v != RoleLibrary.end(); v++)
	{
		cout << (*v)->GetRoleID() << "\t";
		cout << (*v)->GetRoleName() << "\t";
		cout << (*v)->GetRoleHealth() << "\t";
		cout << (*v)->GetRoleAttack() << "\t";
		cout << (*v)->GetRoleStatusl() << "\t";
		cout << (*v)->GetRoleProfession() << endl;
	}
}
void ShowRole(Role &r)
{
	cout << "ID\tName\tHelath\tAttack\tCostcystal\tProfession" << endl;
	cout << r.GetRoleID() << "\t";
	cout << r.GetRoleName() << "\t";
	cout << r.GetRoleHealth() << "\t";
	cout << r.GetRoleAttack() << "\t";
	cout << r.GetRoleStatusl() << "\t";
	cout << r.GetRoleProfession() << endl;
}
void ShowFollower(Follower &f)
{
	cout << "ID\tName\t\tAttack\tHealth\tCostcystal\tStatus\tProfession" << endl;
	cout << f.GetFollowerID() << "\t";
	cout << f.GetFollowerName() << "\t\t";
	cout << f.GetFollowerAttack() << "\t";
	cout << f.GetFollowerHealth() << "\t";
	cout << f.GetFollowCostcystal() << "\t\t";
	cout << f.GetFollowerStatus() << "\t";
	cout << f.GetFollowerProfession() << endl;
}
void ShowPlayer(Player &p)
{
	cout << "ID\tName\tVictory\tDefeat" << endl;
	cout << p.GetPlayerID() << "\t";
	cout << p.GetPlayerName() << "\t";
	cout << p.GetPlayerVictory() << "\t";
	cout << p.GetPlayerDefeat() << endl;
}