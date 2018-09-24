/***************************************************************************
 * Program Filename: as2.cpp
 * Author: Drake Seifert
 * Date: 1/26/2015
 * Description: Convert a string of characters into binary and vice versa
 * Input: Binary and ASCII values
 * Output: Binary and ASCII values
 ***************************************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	
	string sen;
	cout << endl;
	cout << "Enter a word or string: ";
	getline(cin, sen);
	cout << endl;
	
	int x, num, asdf, y;

	cout << "Binary Value: ";

	for( x = 0; x < sen.length(); x++) {

		num = int(sen[x]); //converts char at place x to decimal value
		
		asdf = num/pow(2,7);
		cout << asdf;
		num -= asdf*pow(2,7);
                asdf = num/pow(2,6);
                cout << asdf;
                num -= asdf*pow(2,6);
                asdf = num/pow(2,5);
                cout << asdf;
                num -= asdf*pow(2,5);
                asdf = num/pow(2,4);
                cout << asdf;
                num -= asdf*pow(2,4);
                asdf = num/pow(2,3);
                cout << asdf;
                num -= asdf*pow(2,3);
                asdf = num/pow(2,2);
                cout << asdf;
                num -= asdf*pow(2,2);
                asdf = num/pow(2,1);
                cout << asdf;
                num -= asdf*pow(2,1);
                asdf = num/pow(2,0);
                cout << asdf;
		num -= asdf*pow(2,0);
	}

	cout << endl;
	cout << endl;

	cout << "Enter an 8-bit binary value: ";
	getline(cin, sen);
	cout << endl;

	for( x = 0; x < sen.length(); x++) {
		y = sen[x] - 48; //0 and 1 is 48 and 49 on ASCII table
		if (y == 0 || y == 1) {
		}
		else {
			cout << "Please enter only 1's or 0's: ";
			cin >> sen;
			x = -1; //to account for x++
		}
	}

	while((sen.length()%8) != 0) {
		cout << "Please enter only an 8-bit value: ";
		cin >> sen;
	}
	int z = 0;
	char ascii;
	for( x = 0; x < sen.length(); x++) {
		y = sen[x] - 48;
		num += y*pow(2, (7-(x-(8*z))));
		if (((x + 1) % 8 == 0) && (x != (0 || z))) {
			ascii = static_cast<char>(num);
			cout << ascii;
			z = z + 1;
			num = 0;
		}
		else {
		}
	}
	cout << endl;

	return 0;
}
