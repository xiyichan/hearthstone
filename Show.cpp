#include"Follower.h"
#include"File.h"
void ShowFollowerLibrary(vector<Follower*> &FollowerLibrary) {
	cout << "ID\tName\t\tAttack\tHealth\tCostcystal" << endl;
		for (vector<Follower *>::iterator fo = FollowerLibrary.begin(); fo != FollowerLibrary.end();fo++) {
		cout << (*fo)->GetFollowerID() << "\t";
		cout << (*fo)->GetFollowerName() << "\t\t";
		cout << (*fo)->GetFollowerAttack() << "\t";
		cout << (*fo)->GetFollowerHealth() << "\t";
		cout << (*fo)->GetFollowCostcystal() << endl;
	}
}
void ShowPlayerLibrary(vector<Player*>&PlayerLibrary) {
	cout << "ID\tName\tVictory\tDefeat" << endl;
	for (vector<Player*>::iterator v = PlayerLibrary.begin(); v != PlayerLibrary.end(); v++) {
		cout << (*v)->GetPlayerID() << "\t";
		cout << (*v)->GetPlayerName() << "\t";
		cout << (*v)->GetPlayerVictory() << "\t";
		cout << (*v)->GetPlayerDefeat() << endl;
	}



}