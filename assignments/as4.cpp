/*****************************************************************************************
 * Program: as4.cpp
 * Author: Drake Seifert
 * Date: 2/20/15
 * Description: This program takes assignment 3 and allows the user to input values at the
 * 		same time as running the program.
 * Input: -a, a string, -b, a binary value.
 * Output: a binary value and a string.
 * ***************************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;

/***************************************************
 * Function: get_user_string
 * Description: Prompts user for a string
 * Parameters: sen
 * Pre-Conditions: None
 * Post-Conditions: Gets user input
 * *************************************************/

void get_user_string(string &sen) {
	cout << endl << "Enter a string: ";
	getline(cin, sen);
	cout << endl;
}

/***************************************************
 * Function: ascii_to_bin
 * Description: Converts ascii to decimal to binary
 * Parameters: sen
 * Pre-Conditions: sen must have a value
 * Post-Conditions: Binary value
 * *************************************************/

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
}

/***************************************************
 * Function: get_user_bin
 * Description: Prompts user for binary value
 * Parameters: sen
 * Pre-Conditions: None
 * Post-Conditions: Gets user input
 * *************************************************/

void get_user_bin(string &sen) {
	cout << "Enter an 8-bit binary value: ";
	getline(cin, sen);
	cout << endl;
}

/***************************************************
 * Function: check_ascii_value
 * Description: Checks that value is between 0 and 127 on ASCII table
 * Parameters: sen
 * Pre-Conditions: sen must have a value
 * Post-Conditions: Won't advance until errors are cleared
 * *************************************************/

void check_ascii_value(string &sen) {
	int z;
	for (z = 1; z <= sen.length()/8; z++) {
		int check = int(sen.at(0 + 8*(z-1)));
		while (check != 48) {
			cout << "Only enter an ASCII value between 0 and 127 for your binary value: ";
			cin >> sen;
			check = int(sen.at(0 + 8*(z-1)));
		}
	}
}

/***************************************************
 * Function: check_bin_number
 * Description: Checks that value is only 1's and 0's
 * Parameters: sen
 * Pre-Conditions: sen must have a value
 * Post-Conditions: Won't advance until errors are cleared
 * *************************************************/

void check_bin_number(string &sen) {
	int x, y;
	for (x = 0; x < sen.length(); x++) {
		y = sen[x] - 48;
		if (y == 0 || y == 1) {
		}
		else {
			cout << "Please enter only 1's or 0's for your binary value: ";
			cin >> sen;
			x = -1;
		}
	}
	check_ascii_value(sen);
}

/***************************************************
 * Function: check_bin_number2
 * Description: Checks that value is divisible by 8
 * Parameters: sen
 * Pre-Conditions: sen must have a value
 * Post-Conditions: Won't advance until errors are cleared
 * *************************************************/

void check_bin_number2(string &sen) {
	while ((sen.length() % 8) != 0) {
		cout << "Please enter only an 8-bit value for your binary value: ";
		cin >> sen;
		check_bin_number2(sen);
	}
	check_bin_number(sen);
}

/***************************************************
 * Function: bin_to_ascii
 * Description: Converts binary to ASCII value
 * Parameters: sen
 * Pre-Conditions: Sen must have a value
 * Post-Conditions: Displays ASCII value
 * *************************************************/


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

/***************************************************
 * Function: error_checking
 * Description: Organizing and ordering error checking
 * Parameters: sen
 * Pre-Conditions: Sen must have a value
 * Post-Conditions: Won't continue until errors are clear
 * *************************************************/

void error_checking(string &sen) {
	check_ascii_value(sen);
	check_bin_number(sen);
	check_bin_number2(sen);
}

/***************************************************
 * Function: check_bin_input
 * Description: Allows user to input values before the program is running
 * Parameters: sen, argv, argc
 * Pre-Conditions: user types an input
 * Post-Conditions: outputs a binary value or string
 * *************************************************/

void check_bin_input(string &sen, char** argv, int argc) {
	for (int i = 1; i < argc; i += 2) {
		if (!strcmp(argv[i], "-a")) {
			sen = argv[i + 1];
			cout << "Your string says ";
			ascii_to_bin(sen);
			cout << endl;
		}	
		else if (!strcmp(argv[i], "-b")) {
			sen = argv[i + 1];
			cout << "Your binary value says ";
			bin_to_ascii(sen);
			cout << endl;
		}
		else {
			cout << "Error invalid input, must enter -a or -b" << endl;
			exit(EXIT_FAILURE);
		}
	}
}

int main(int argc, char *argv[]) {
	
	string sen;
	cout << endl;
	check_bin_input(sen, argv, argc);
	cout << endl;

	return 0;
}
