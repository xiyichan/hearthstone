#include"All.h"
int main() {

	char choose = '1';
	while (choose != '0') {

		do {
			cout<<"1.����б�"<<endl;
			cout<<"2.����б�"<<endl;
			cout<<"3.����ƿ�"<<endl;
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
	vector<Follower *> RoleCard;//��ɫ�������,����ʮ��
	vector<Follower *> RoleCardLibrary;//��ɫ�ƿ���ӣ�����30
	vector<Follower *> RoleThrowCardLibrary;//��ɫ�����ƿ⣬����30
	list<Follower *> RoleFollwer;//��ǰ������ӣ�����7��	
	*/