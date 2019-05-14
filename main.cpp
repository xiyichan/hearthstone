#include "All.h"
int main()
{

	char choose = '1';
	while (choose != '0')
	{
		do
		{
			cout << "1.随从列表" << endl;
			cout << "2.玩家列表" << endl;
			cout << "3.英雄列表" << endl;
			cout << "4.玩家牌库" << endl;
			cout << "5.开始比赛" << endl;
			cout << "choose:" << endl;
			cin >> choose;
			fflush(stdin);
		} while (!(choose >= '0'));
		if (choose == '1')
		{
			FollowerLibraryMenu();
		}
		else if (choose == '2')
		{
			PlayerLibraryMenu();
		}
		else if (choose == '3')
		{
			RoleLibraryMenu();
		}
		else if (choose == '4')
		{
			PlayerCardLibraryMenu();
		}
		else if (choose == '5')
		{
			Game();
		}
	}

	return 0;
}
