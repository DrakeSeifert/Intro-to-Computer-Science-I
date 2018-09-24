/*********************************************************************************
 * Program Filenam: as6.cpp
 * Author: Drake Seifert
 * Date: 3/13/15
 * Descripton: Takes and displays a struct of movies
 * Input: yes/no, movie title, stars, cast members, rating
 * Output: movie title, stars, cast members, rating
 * *******************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

void user_input();
void print_movie(int, struct netflix movie);

struct netflix {
	string name;
	int stars;
	string *cast;
	string rating;
};

/*********************************************************************************
 * Function: enter_movie
 * Description: asks user if they would like to enter a movie into the database
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: respond to user input
 * *******************************************************************************/

void enter_movie() {
	string answer;
	cout << "Do you want to enter a movie to the database? ";
	cin >> answer;

	if (answer == "yes" || answer == "y" || answer == "no" || answer == "n") {
		if      (answer == "yes" || answer == "y") {
			user_input();
		}
		else if (answer == "no" || answer == "n") {
			cout << "Goodbye!" << endl;
			exit(EXIT_FAILURE);
		}
	}
	else {
		cout << "Invalid input :(" << endl;
		enter_movie();
	}
}

/*********************************************************************************
 * Function: error_check
 * Description: checks the argument is an int
 * Parameters: verify
 * Pre-Conditions: input is entered
 * Post-Conditions: will reprompt user until int is entered
 * *******************************************************************************/

void error_check(int &verify) {
	while (verify < 1 || cin.fail()) {
		cout << "ERROR: Enter a valid input: ";
		cin.clear();
		cin.ignore();
		cin >> verify;
	}
}

/*********************************************************************************
 * Function: user_input
 * Description: takes user input for struct
 * Parameters: none
 * Pre-Conditions: "yes" or "y" was entered for enter_movie function
 * Post-Conditions: collects user input
 * *******************************************************************************/

void user_input() {
	struct netflix movie;
	int num;

	cin.ignore();	
	cout << "Enter the name of your movie: ";
	getline(cin, movie.name);

	cout << "How many stars? ";
	cin >> movie.stars;
	error_check(movie.stars);

	cout << "How many cast members? ";
	cin >> num;
	error_check(num);
	movie.cast = new string[num];
	cin.ignore();
	for (int i = 0; i < num; i++) {
		cout << "Enter cast member " << i + 1 << ": ";
		getline(cin, movie.cast[i]);
	}

	cout << "Enter the movie rating: ";
	getline(cin, movie.rating);

	print_movie(num, movie);
	enter_movie();
}

/*********************************************************************************
 * Function: print_movie
 * Description: prints information from user_input and clears memory
 * Parameters: num, struct netflix movie
 * Pre-Conditions: all other functions have been followed
 * Post-Conditions: prints out info and clears memory
 * *******************************************************************************/

void print_movie(int num, struct netflix movie) {
	cout << endl << "Your movie entry is:" << endl;
	cout << "Title: " << movie.name << endl;
	cout << "Stars: " << movie.stars << endl;
	cout << "Cast: ";
	for (int i = 0; i < num; i++) {
		if (i != num - 1)
			cout << movie.cast[i] << ", ";
		else
			cout << movie.cast[i];
	}
	cout << endl;
	cout << "Rating: " << movie.rating << endl << endl;

	delete [] movie.cast;
}

int main() {
	enter_movie();
	return 0;
}
