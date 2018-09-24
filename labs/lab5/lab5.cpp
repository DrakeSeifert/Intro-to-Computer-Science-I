#include <iostream>
#include <string>

using namespace std;

void error_check(string &);
void letter_check_2(string &);

void letter_check_1(string &roman) {
	int a = 0;
	if (roman.length() >= 4) {
		for (a = 0; a < roman.length()-3; a++) {
			while (roman[a] == roman[a + 1] &&
			       roman[a + 1] == roman[a + 2] &&
		               roman[a + 2] == roman[a + 3]) {
				cout << "ERROR: INVALID INPUT" << endl << "Try again: ";
				cin >> roman;
				letter_check_2(roman);
			}	
		}
	}
}

void letter_check_2(string &roman) {
	int a;
	for (a = 0; a < roman.length(); a++) {
		if (roman[a] != 'M' &&
		    roman[a] != 'D' &&
		    roman[a] != 'C' &&
		    roman[a] != 'L' &&
		    roman[a] != 'X' &&
	 	    roman[a] != 'V' &&
		    roman[a] != 'I') {
			cout << "ERROR: INVALID CHARACTER" << endl << "Try again: ";
			cin >> roman;
			letter_check_1(roman);
		}
	}
}

void error_check(string &roman) {
	letter_check_1(roman);
	letter_check_2(roman);
}

int letter_convert_1(char x) {
		if      (x == 'M') {
			return 1000;
		}
		else if (x == 'D') {
			return 500;
		}
		else if (x == 'C') {
			return 100;
		}
		else if (x == 'L') {
			return 50;
		}
		else if (x == 'X') {
			return 10;
		}
		else if (x == 'V') {
			return 5;
		}
		else if (x == 'I') {
			return 1;
		}
}

int letter_convert_2(string &roman) {
	int a, num = 0;
	for (a = 0; a <= roman.length()-1; a++) {

		if (letter_convert_1(roman[a]) >= letter_convert_1(roman[a+1])) {
			num += letter_convert_1(roman[a]);
		}

		else {
			num -= letter_convert_1(roman[a]);
		}
	}
	return num;
}

int main() {
	
	string roman;

	cout << endl;
	cout << "Enter your Roman numeral: ";
	cin >> roman;
	cout << endl;

	error_check(roman);
	int a = letter_convert_2(roman);
	cout << "Your Roman numeral equals " << a << endl << endl;	

	return 0;
}
