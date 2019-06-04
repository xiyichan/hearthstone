#include "All.h"
int main()
{

	char choose = '1';
	while (choose != '0')
	{
		do
		{
			cout << "1.FollowerLibrary" << endl;
			cout << "2.PlayerLibrary" << endl;
			cout << "3.RoleLibrary" << endl;
			cout << "4.CardLibrary" << endl;
			cout << "5.Game" << endl;
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
