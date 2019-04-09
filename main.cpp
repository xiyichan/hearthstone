#include"All.h"
int main() {

	char choose = '1';
	while (choose != '0') {

		do {
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
	}
	return 0;
}