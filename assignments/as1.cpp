/*******************************************************************************************
 **Program: Assignment1.cpp
 **Author: Drake Seifert
 **Date: 1/15/2015
 **Description: This program shows the signed and unsigned values of short, int, and long.
		It also converts ASCII characters to decimal, hexadecimal, and binary.
 **Input: Any character
 **Output: Signed and Unsigned values for short, int, and long.
	   Decimal, hexadecimal, and binary for input.
********************************************************************************************/

#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

int main()
{
	char ascii;
	int asdf, num;
	
	cout << "Size of short integer: " << sizeof(short) << " bits" << endl;
	cout << "Signed short integer min value: " << pow(-2,7) << endl;
	cout << "Signed short integer max value: " << pow(2,7)-1  << endl;
	cout << "Unsigned short integer min value: " << 0 << endl;
	cout << "Unsigned short integer max value: " << pow(2,8)-1 << endl;
	cout << endl;

	cout << "Size of integer: " << sizeof(int) << " bits" << endl;
	cout << "Signed integer min value: " << pow(-2,15) << endl;
	cout << "Signed integer max value: " << pow(2,15)-1 << endl;
	cout << "Unsigned integer min value: " << 0 << endl;
	cout << "Unsigned integer max value: " << pow(2,16)-1 << endl;
	cout << endl;

	cout << "Size of long integer: " << sizeof(long) << " bits" << endl;
	cout << "Signed long integer min value: " << pow(2,31) << endl;
	cout << "Signed long integer max value: " << pow(2,31)-1 << endl;
	cout << "Unsigned long integer min value: " << 0  << endl;
	cout << "Unsigned long integer max value: " << pow(2,32)-1 << endl;
	cout << endl;

	cout << "Input ASCII character value: " << endl;
	cin >> ascii;
	cout << "Decimal value: " << int(ascii) << endl;
	cout << "Hexadecimal value: " << hex << int(ascii) << endl;
	
	cout << dec;
	num = int(ascii);

	cout << "Binary value: ";
	asdf = num/pow(2,7);
	num = num - asdf*pow(2,7);
	cout << asdf;
	asdf = num/pow(2,6);
	num = num - asdf*pow(2,6);
	cout << asdf;
	asdf = num/pow(2,5);
	num = num - asdf*pow(2,5);
	cout << asdf;
	asdf = num/pow(2,4);
	num = num - asdf*pow(2,4);
	cout << asdf;
	asdf = num/pow(2,3);
	num = num - asdf*pow(2,3);
	cout << asdf;
	asdf = num/pow(2,2);
	num = num - asdf*pow(2,2);
	cout << asdf;
	asdf = num/pow(2,1);
	num = num - asdf*pow(2,1);
	cout << asdf;
	asdf = num/pow(2,0);
	num = num - asdf*pow(2,0);

	cout << asdf << endl;

	return 0;
}
