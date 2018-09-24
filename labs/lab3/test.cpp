#include <iostream>
using namespace std;
int main() {
	int choice;
	cout << "Do you like vi as an editor????????(1=yes and 0=no): ";
	cin >> choice;
	cout << endl;

	if (choice == 1) {
		cout << "You love vi!" << endl;
	}
	else if (choice == 0) {
		cout << "You hate vi!" << endl;
	}
	else {
		cout << "Enter a 1 or 0 dummy" << endl;
		main();
	}
	return 0;
}
