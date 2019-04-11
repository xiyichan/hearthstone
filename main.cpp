#include"All.h"
int main() {

	char choose = '1';
	while (choose != '0') {

		do {
			cout<<"1.随从列表"<<endl;
			cout<<"2.玩家列表"<<endl;
			cout<<"3.玩家牌库"<<endl;
			cout << "choose:" << endl;
			cin >> choose;
			fflush(stdin);
		} while (!(choose >= '0'));
		if (choose == '1') {
			FollowerLibraryMenu();
		}
		else if (choose == '2') {
			PlayerLibraryMenu();
		}
		else if(choose=='3'){
			PlayerCardLibraryMenu();
		}
	}


	return 0;
}
/*
	vector<Follower *> RoleCard;//角色手牌随从,上限十个
	vector<Follower *> RoleCardLibrary;//角色牌库随从，上限30
	vector<Follower *> RoleThrowCardLibrary;//角色弃牌牌库，上限30
	list<Follower *> RoleFollwer;//当前场上随从，上限7个	
	*/