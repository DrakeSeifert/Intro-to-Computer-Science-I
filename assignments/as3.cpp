/********************************************************
 * Program: as3.cpp
 * Author: Drake Seifert
 * Date: 2/4/15
 * Description:
 * Input:
 * Output:
 * *******************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/**************************************
 * Function: get_user_string
 * Description: Prompts user for a string
 * Parameters: sen
 * Pre-Conditions: None
 * Post-Conditions: Gets user input
 * ************************************/
void get_user_string(string &sen) {
	cout << endl << "Enter a string: ";
	getline(cin, sen);
	cout << endl;
}

/**************************************
 * Function: ascii_to_bin
 * Description: Converts ascii to decimal to binary
 * Parameters: sen
 * Pre-Conditions: sen must have a value
 * Post-Conditions: Binary value
 * ************************************/
void ascii_to_bin(string &sen) {
	int x, num, asdf, y;
	for (x = 0; x < sen.length(); x++) {
		num = int(sen[x]);
		for (y = 7; y >= 0; y--) {
			asdf = num/pow(2,y);
			num -= asdf*pow(2,y);
			cout << asdf;
		}
	}
	cout << endl << endl;
}

/**************************************
 * Function: get_user_bin
 * Description:	Prompts user for binary value
 * Parameters: sen
 * Pre-Conditions: None
 * Post-Conditions: Gets user input
 * ************************************/
void get_user_bin(string &sen) {
	cout << "Enter an 8-bit binary value: ";
	getline(cin, sen);
	cout << endl;
}

/**************************************
 * Function: check_ascii_value
 * Description: Checks that value is between 0 and 127 on ASCII table
 * Parameters: sen
 * Pre-Conditions: sen must have a value
 * Post-Conditions: Won't advance until errors are cleared
 * ************************************/
void check_ascii_value(string &sen) {
	int z;
	for (z = 1; z <= sen.length()/8; z++) {
		int check = int(sen.at(0 + 8*(z-1)));
		while (check != 48) {
			cout << "Only enter an ASCII value between 0 and 127: ";
			cin >> sen;
			check = int(sen.at(0 + 8*(z-1)));
		}
	}
}
/**************************************
 * Function: check_bin_number
 * Description: Checks that value is only 1's and 0's
 * Parameters: sen
 * Pre-Conditions: sen must have a value
 * Post-Conditions: Won't advance until errors are cleared
 * ************************************/
void check_bin_number(string &sen) {
	int x, y;
	for (x = 0; x < sen.length(); x++) {
		y = sen[x] - 48;
		if (y == 0 || y == 1) {
		}
		else {
			cout << "Please enter only 1's or 0's: ";
			cin >> sen;
			x = -1;
		}
	}
	check_ascii_value(sen);
}

/**************************************
 * Function: check_bin_number2
 * Description: Checks that value is divisible by 8
 * Parameters: sen
 * Pre-Conditions: sen must have a value
 * Post-Conditions: Won't advance until errors are cleared
 * ************************************/
void check_bin_number2(string &sen) {
	while((sen.length() % 8) != 0) {
		cout << "Please enter only an 8-bit value: ";
		cin >> sen;
		check_bin_number2(sen);
	}
	check_bin_number(sen);
}

/**************************************
 * Function: bin_to_ascii
 * Description: Converts binary to ASCII value
 * Parameters: sen
 * Pre-Conditions: Sen must have a value
 * Post-Conditions: Displays ASCII Value
 * ************************************/
void bin_to_ascii(string &sen) {
	int x, y, z, num;
	num = z = 0;
	for (x = 0; x < sen.length(); x++) {
		y = sen[x] - 48;
		num += y*pow(2, (7 - (x - (8 * z))));
		if (((x + 1) % 8 == 0) && (x != (0 || z))) {
			char ascii = static_cast<char>(num);
			cout << ascii;
			z = z + 1;
			num = 0;
		}
	}	
}

/************************************
 * Funtion: error_checking
 * Description: Organizing and ordering error checking
 * Parameters: sen
 * Pre-Conditions: Sen must have a value
 * Post-Conditions: Won't continue until errors are clear
 * **********************************/
void error_checking(string &sen) {
	check_ascii_value(sen);
	check_bin_number(sen);
	check_bin_number2(sen);
}

int main(){
	
	string sen;

	get_user_string(sen);
	ascii_to_bin(sen);

	get_user_bin(sen);
	error_checking(sen);
	bin_to_ascii(sen);

	cout << endl << endl;

	return 0;
}
