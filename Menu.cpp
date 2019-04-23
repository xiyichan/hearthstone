#include"Menu.h"
#include"File.h"
#include"Show.h"
#include"Player.h"
#include"All.h"
#include"Menu.h"
void FollowerLibraryMenu() {
	int FollowerID = 1;
	vector<Follower *> FollowerLibrary;
	ReadFollowerLibrary(FollowerLibrary,"FollowerLibrary.txt");
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

void RoleLibraryMenu()
{
	int RoleID=1;
	vector<Role *>RoleLibrary;
	ReadRoleLibrary(RoleLibrary);
	ReadRoleID(RoleID);
	char choose = '1';
	while (choose != '0') {

		do {
			cout << "choose:" << endl;
			cout << "1.AddRoleLibrary" << endl;
			cout << "2.DeleteRoleLibrary" << endl;
			cout << "3.ShowRoleLibrary" << endl;
			cout << "0.return" << endl;
			cin >> choose;
			fflush(stdin);
		} while (!(choose >= '0'));
		if (choose == '1') {
			system("cls");
			AddRoleLibrary(RoleLibrary,RoleID);
		}
		else if (choose == '2') {
			DeleteRoleLibrary(RoleLibrary);
			system("cls");
		}
		else if (choose == '3') {
			system("cls");
			ShowRoleLibrary(RoleLibrary);
			
			
		}
	}
}


void PlayerCardLibraryMenu(){
	int PlayerID = 1;
	vector<Player*>PlayerLibrary;
	ReadPlayerLibrary(PlayerLibrary);
	ReadPlayerID(PlayerID);
	int FollowerID = 1;
	vector<Follower *> FollowerLibrary;
	ReadFollowerLibrary(FollowerLibrary,"FollowerLibrary.txt");
	ReadFollowerID(FollowerID);
	char choose = '1';

	while (choose != '0') {

		do {
			cout << "choose:" << endl;
			cout << "1.玩家牌库" << endl;
			cout<<"2.开始比赛"<<endl;
			cin >> choose;
			fflush(stdin);
		} while (!(choose >= '0'));
		if (choose == '1') {
			//system("cls");
		 PlayerCardLibrary();
		}
		else if (choose == '2') {
				//Game();
		}
		else if (choose == '3') {

		}
	}

}