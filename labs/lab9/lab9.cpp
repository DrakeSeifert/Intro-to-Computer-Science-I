#include <iostream>

#define POSTS 3

using namespace std;

int print_arr(int **arr, int);

int create_arr(int rings) {
	int **arr;
	arr = new int*[rings];
	for (int i = 0; i < rings; i++) {
		arr[i] = new int[POSTS];
	}
	for (int x = 0; x < rings; x++)
		arr[x][0] = x+1;
	print_arr(arr, rings);
}

int print_arr(int **arr, int rings) {
	for (int x = 0; x < rings; x++) {
		cout << endl;
		for (int y = 0; y < POSTS; y++) {
			cout << arr[x][y] << " ";
		}
	}
	cout << endl;
}

void hanoi(int rings, char a, char b, char c) {
	if (rings == 0) {
		cout << "ERROR: Invalid number of discs" << endl;
	}
	else if (rings == 1) {
		cout << "Move disc from " << a << " to " << b << endl;
	}
	else {
		hanoi(rings - 1, a, c, b);
		cout << "Move disc from " << a << " to " << b << endl;
		hanoi(rings - 1, c, b, a);
	}
}

int main() {
	int rings;
	cout << "How many discs?: ";
	cin >> rings;
	create_arr(rings);
	hanoi(rings, '1', '2', '3');
	return 0;
}
