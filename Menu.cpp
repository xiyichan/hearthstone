#include"Menu.h"
#include"File.h"
#include"Show.h"
#include"Player.h"
void FollowerLibraryMenu() {
	int FollowerID = 1;
	vector<Follower *> FollowerLibrary;
	ReadFollowerLibrary(FollowerLibrary);
	ReadFollowerID(FollowerID);
	char choose = '1';
	while (choose != '0') {

		do {
			cout << "choose:" << endl;
			cout << "1.AddFollowerLibrary" << endl;
			cout << "2.DeleteFollowerLibrary" << endl;
			cout << "3.ShowFollowerLibrary" << endl;
			cout << "0.return" << endl;
			cin >> choose;
			fflush(stdin);
		} while (!(choose >= '0'));
		if (choose == '1') {
			system("cls");
			AddFollowerLibrary(FollowerLibrary, FollowerID);
		}
		else if (choose == '2') {
			system("cls");
			DeleteFollowerLibrary(FollowerLibrary);
		}
		else if (choose == '3') {
			system("cls");
			ShowFollowerLibrary(FollowerLibrary);
		}
	}

}
void PlayerLibraryMenu() {
	int PlayerID = 1;
	vector<Player*>PlayerLibrary;
	ReadPlayerLibrary(PlayerLibrary);
	ReadPlayerID(PlayerID);
	char choose = '1';
	while (choose != '0') {

		do {
			cout << "choose:" << endl;
			cout << "1.AddPlayerLibrary" << endl;
			cout << "2.DeletePlayerLibrary" << endl;
			cout << "3.ShowPlayerLibrary" << endl;
			cout << "0.return" << endl;
			cin >> choose;
			fflush(stdin);
		} while (!(choose >= '0'));
		if (choose == '1') {
			system("cls");
			AddPlayerLibrary(PlayerLibrary, PlayerID);
		}
		else if (choose == '2') {
			DeletePlayerLibrary(PlayerLibrary);
			system("cls");
		}
		else if (choose == '3') {
			system("cls");
			ShowPlayerLibrary(PlayerLibrary);
		}
	}
}