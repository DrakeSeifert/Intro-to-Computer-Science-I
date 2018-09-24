/***********************************************************************************
 * Program Filename: as5
 * Author: Drake Seifert
 * Date: 3/4/15
 * Description: Random Matrix multiplication detection
 * Input: rows, columns, optional txt file
 * Output: a matrix and important values
 * ********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

void print_array(int **arr, int &, int &);

int find_vertical(int **arr, int &, int &, int &, int &, int &);
int find_horizontal(int **arr, int &, int &, int &, int &, int &);
int find_dia_top_left(int **arr, int &, int &, int &, int &, int&);
int find_dia_bot_left(int **arr, int &, int &, int &, int &, int &);
int find_box(int **arr, int &, int &, int &, int &, int &);
int find_hor_zig1(int **arr, int &, int &, int &, int &, int &);
int find_hor_zig2(int **arr, int &, int &, int &, int &, int &);
int find_ver_zig1(int **arr, int &, int &, int &, int &, int &);
int find_ver_zig2(int **arr, int &, int &, int &, int &, int &);
int find_L1(int **arr, int &, int &, int &, int &, int &);
int find_L2(int **arr, int &, int &, int &, int &, int &);

/**********************************************************************************
 * Function: input_rows_cols
 * Description: Takes user input for rows and cols
 * Parameters: rows, cols
 * Pre-Conditions: none
 * Post-Conditions: gets input
 * ********************************************************************************/

void input_rows_cols(int &rows, int &cols) {
	cout << "Enter number of cols (x-axis): ";
	cin >> cols;
	while (cols <= 0 || cin.fail()) {
		cout << "ERROR: Enter a valid number: ";
		cin.clear();
		cin.ignore();
		cin >> cols;
	}
	cout << "Enter number of rows (y-axis): ";
	cin >> rows;
	while (rows <= 0 || cin.fail()) {
		cout << "ERROR: Enter a valid number: ";
		cin.clear();
		cin.ignore();
		cin >> rows;
	}
}

/**********************************************************************************
 * Function: greatest
 * Description: finds the greatest product
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: all functions called work
 * Post-Conditions: returns greatest value
 * ********************************************************************************/

int greatest(int **arr, int rows, int cols, int &f, int &g, int &h) {
	int a = find_vertical(arr, rows, cols, f, g, h),
	    b = find_horizontal(arr, rows, cols, f, g, h),
	    c = find_dia_top_left(arr, rows, cols, f, g, h),
	    d = find_dia_bot_left(arr, rows, cols, f, g, h),
	    e = find_box(arr, rows, cols, f, g, h),
	    k = find_hor_zig1(arr, rows, cols, f, g, h),
            l = find_hor_zig2(arr, rows, cols, f, g, h),
	    m = find_ver_zig1(arr, rows, cols, f, g, h),
            n = find_ver_zig2(arr, rows, cols, f, g, h),
	    o = find_L1(arr, rows, cols, f, g, h),
	    p = find_L2(arr, rows, cols, f, g, h);

	if      (a > b && a > c && a > d && a > e && a > k && a > m && a > l && a > n && a > o && a > p) {
		a = find_vertical(arr, rows, cols, f, g, h);
		return a;
	}
	else if (b > a && b > c && b > d && b > e && b > k && b > m && b > l && b > n && b > o && b > p) {
		b = find_horizontal(arr, rows, cols, f, g, h);
		return b;
	}
	else if (c > a && c > b && c > d && c > e && c > k && c > m && c > l && c > n && c > o && c > p) {
		c = find_dia_top_left(arr, rows, cols, f, g, h);
		return c;
	}
	else if (d > a && d > b && d > c && d > e && d > k && d > m && d > l && d > n && d > o && d > p) {
		d = find_dia_bot_left(arr, rows, cols, f, g, h);
		return d;
	}
	else if (e > a && e > b && e > c && e > d && e > k && e > m && e > l && e > n && e > o && e > p) {
		e = find_box(arr, rows, cols, f, g, h);
		return e;
	}
	else if (k > a && k > b && k > c && k > d && k > e && k > m && k > l && k > n && k > o && k > p) {
		k = find_hor_zig1(arr, rows, cols, f, g, h);
		return k;
	}
	else if (m > a && m > b && m > c && m > d && m > e && m > k && m > l && m > n && m > o && m > p) {
		m = find_ver_zig1(arr, rows, cols, f, g, h);
		return m;
	}
	else if (l > a && l > b && l > c && l > d && l > e && l > k && l > m && l > n && l > o && l > p) {
		l = find_hor_zig2(arr, rows, cols, f, g, h);
		return l;
	}
	else if (n > a && n > b && n > c && n > d && n > e && n > k && n > m && n > l && n > o && n > p) {
		n = find_ver_zig2(arr, rows, cols, f, g, h);
		return n;
	}
	else if (o > a && o > b && o > c && o > d && o > e && o > k && o > m && o > l && o > n && o > p) {
		o = find_L1(arr, rows, cols, f, g, h);
		return o;
	}
	else if (p > a && p > b && p > c && p > d && p > e && p > k && p > m && p > l && p > n && p > o) {
		p = find_L2(arr, rows, cols, f, g, h);
		return p;
	}
}

/**********************************************************************************
 * Function: shape_func
 * Description: outputs type of shape of function with greatest value
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: all functions called work
 * Post-Conditions: returns shape
 * ********************************************************************************/

string shape_func(int **arr, int rows, int cols, int f, int g, int h) {
	int a = find_vertical(arr, rows, cols, f, g, h),
	    b = find_horizontal(arr, rows, cols, f, g, h),
	    c = find_dia_top_left(arr, rows, cols, f, g, h),
	    d = find_dia_bot_left(arr, rows, cols, f, g, h),
	    e = find_box(arr, rows, cols, f, g, h),
	    k = find_hor_zig1(arr, rows, cols, f, g, h),
            l = find_hor_zig2(arr, rows, cols, f, g, h),
	    m = find_ver_zig1(arr, rows, cols, f, g, h),
            n = find_ver_zig2(arr, rows, cols, f, g, h),
	    o = find_L1(arr, rows, cols, f, g, h),
	    p = find_L2(arr, rows, cols, f, g, h);

	if      (a > b && a > c && a > d && a > e && a > k && a > m && a > l && a > n && a > o && a > p)
		return "vertical";
	else if (b > a && b > c && b > d && b > e && b > k && b > m && b > l && b > n && b > o && b > p)
		return "horizontal";
	else if (c > a && c > b && c > d && c > e && c > k && c > m && c > l && c > n && c > o && c > p)
		return "negative diagonal";
	else if (d > a && d > b && d > c && d > e && d > k && d > m && d > l && d > n && d > o && d > p)
		return "positive diagonal";
	else if (e > a && e > b && e > c && e > d && e > k && e > m && e > l && e > n && e > o && e > p)
		return "box";
	else if (k > a && k > b && k > c && k > d && k > e && k > m && k > l && k > n && k > o && k > p)
		return "horizontal zigzag";
	else if (m > a && m > b && m > c && m > d && m > e && m > k && m > l && m > n && m > o && m > p)
		return "vertical zigzag";
	else if (l > a && l > b && l > c && l > d && l > e && l > k && l > m && l > n && l > o && l > p)
		return "mirrored horizontal zigzag";
	else if (n > a && n > b && n > c && n > d && n > e && n > k && n > m && n > l && n > o && n > p)
		return "mirrored vertical zigzag";
	else if (o > a && o > b && o > c && o > d && o > e && o > k && o > m && o > l && o > n && o > p)
		return "L";
	else if (p > a && p > b && p > c && p > d && p > e && p > k && p > m && p > l && p > n && p > o)
		return "mirrored L";
}

/**********************************************************************************
 * Function: create_array
 * Description: creates space for an array, calls the array, displays info
 * Parameters: rows, cols
 * Pre-Conditions: rows and cols input
 * Post-Conditions: shows matrix and runs everything
 * ********************************************************************************/

int create_array(int &rows, int &cols) {
	int i, f, g, h;
	int **arr;
	arr = new int*[rows];
	for (i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
	print_array(arr, rows, cols);
	cout << endl << endl << "Greatest product: " << greatest(arr, rows, cols, f, g, h)<< endl;
	cout << endl << "Shape: " << shape_func(arr, rows, cols, f, g, h) << endl;
	cout << endl << "col (x-axis): " << f << endl << "row (y-axis): " << g << endl;
	cout << endl << "initial integer: " << h << endl;
}

/**********************************************************************************
 * Function: print_array
 * Description: prints and displays area
 * Parameters: arr, rows, cols
 * Pre-Conditions: rows and cols input
 * Post-Conditions: prints matrix
 * ********************************************************************************/

void print_array(int **arr, int &rows, int &cols){
	int num, x, y;
	for (x = 0; x < rows; x++) {
		cout << endl;
		for (y = 0; y < cols; y++) {
			arr[x][y] = rand() % 50 + 1;
			
			if (arr[x][y] < 10) {
				cout << "0";
			}
			cout << arr[x][y] << " ";
		}
	}
}

/**********************************************************************************
 * Function: find_vertical
 * Description: finds product of vertical values
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: returns greatest product of vertical values
 * ********************************************************************************/

int find_vertical(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 0; x < cols; x++) {
		for ( int y = 0; y < rows - 3; y++) {
			int product = 1, i;
			for (i = 0; i < 4; i++) {
				product *= arr[y + i][x];
			}
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: find_horizontal
 * Description: finds product of horizontal values
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: returns greatest prduct of horizontal values
 * ********************************************************************************/

int find_horizontal(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 0; x < cols - 3; x++) {
		for (int y = 0; y < rows; y++) {
			int product = 1, i;
			for (i = 0; i < 4; i++) {
				product *= arr[y][x + i];
			}
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: find_dia_top_left
 * Description: finds product of vertical values
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: returns greatest product of forward diagonal values
 * ********************************************************************************/

int find_dia_top_left(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 0; x < cols - 3; x++) {
		for (int y = 0; y < rows - 3; y++) {
			int product = 1, i;
			for (i = 0; i < 4; i++) {
				product *= arr[y + i][x + i];
			}
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: find_dia_bot_left
 * Description: finds product of vertical values
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: returns greatest product of backwards diagonal values
 * ********************************************************************************/

int find_dia_bot_left(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 0; x < cols - 3; x++) {
		for (int y = 3; y < rows; y++) {
			int product = 1, i;
			for (i = 0; i < 4; i++) {
				product *= arr[y - i][x + i];
			}
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: find_box
 * Description: finds product of vertical values
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: returns greatest product of box values
 * ********************************************************************************/

int find_box(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 0; x < cols - 1; x++) {
		for (int y = 0; y < rows - 1; y++) {
			int product = 1;
			product *= arr[y][x] *
			arr[y + 1][x + 1] *
			arr[y][x + 1] *
			arr[y + 1][x];
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: find_hor_zig1
 * Description: finds product of horizontal zig zag shape
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: return greatest product of horizontal zig zag values
 * ********************************************************************************/

int find_hor_zig1(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 0; x < cols - 2; x++) {
		for (int y = 0; y < rows - 1; y++) {
			int product = 1;
			product *= arr[y][x] *
			arr[y][x + 1] *
			arr[y + 1][x + 1] *
			arr[y + 1][x + 2];
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: find_hor_zig2
 * Description: finds product of mirrored horizontal zig zag shape
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: return greatest product of mirrored horizontal zig zag values
 * ********************************************************************************/

int find_hor_zig2(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 0; x < cols - 2; x++) {
		for (int y = 1; y < rows; y++) {
			int product = 1;
			product *= arr[y][x] *
			arr[y][x + 1] *
			arr[y - 1][x + 1] *
			arr[y - 1][x + 2];
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: find_ver_zig1
 * Description: finds product of vertical zig zag shape
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: return greatest product of vertical zig zag values
 * ********************************************************************************/

int find_ver_zig1(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 0; x < cols - 1; x++) {
		for (int y = 0; y < rows - 2; y++) {
			int product = 1;
			product *= arr[y][x] *
			arr[y + 1][x] *
			arr[y + 1][x + 1] *
			arr[y + 2][x + 1];
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: find_ver_zig2
 * Description: finds product of mirrored vertical zig zag shape
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: return greatest product of mirrored vertical zig zag values
 * ********************************************************************************/

int find_ver_zig2(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 0; x < cols - 1; x++) {
		for (int y = 2; y < rows; y++) {
			int product = 1;
			product *= arr[y][x] *
			arr[y - 1][x] *
			arr[y - 1][x + 1] *
			arr[y - 2][x + 1];
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: find_L1
 * Description: finds product of L shape
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: return greatest product of L values
 * ********************************************************************************/

int find_L1(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 0; x < cols - 1; x++) {
		for (int y = 0; y < rows - 2; y++) {
			int product = 1;
			product *= arr[y][x] *
			arr[y + 1][x] *
			arr[y + 2][x] *
			arr[y + 2][x + 1];
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: find_L2
 * Description: finds product of mirrored L shape
 * Parameters: arr, rows, cols, f, g, h
 * Pre-Conditions: rows and cols
 * Post-Conditions: return greatest product of mirrored L values
 * ********************************************************************************/

int find_L2(int **arr, int &rows, int &cols, int &f, int &g, int &h) {
	int greatest = 0;
	for (int x = 1; x < cols; x++) {
		for (int y = 0; y < rows - 2; y++) {
			int product = 1;
			product *= arr[y][x] *
			arr[y + 1][x] *
			arr[y + 2][x] *
			arr[y + 2][x - 1];
			if (product > greatest) {
				greatest = product;
				f = x + 1;
				g = y + 1;
				h = arr[y][x];
			}
		}
	}
	return greatest;
}

/**********************************************************************************
 * Function: create_arr_test
 * Description: creates array for txt file 
 * Parameters: rows, cols
 * Pre-Conditions: txt file input
 * Post-Conditions: creates array
 * ********************************************************************************/

int **create_arr_test(int rows, int cols) {
	int **arr = NULL;
	arr = new int*[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
	return arr;
}

/**********************************************************************************
 * Function: test
 * Description: displays array and other values for txt file
 * Parameters: none
 * Pre-Conditions: txt file input
 * Post-Conditions: creates matrix and displays values
 * ********************************************************************************/

void test() {
	int rows, cols, **arr, f, g, h;
	
	cin >> rows;
	cin >> cols;
	cout << endl;

	arr = create_arr_test(rows, cols);
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			cin >> arr[x][y];
			if (arr[x][y] < 10) {
				cout << "0";
			}
			cout << arr[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl <<  "Greatest product: " << greatest(arr, rows, cols, f, g, h) << endl;
	cout << endl << "Shape: " << shape_func(arr, rows, cols, f, g, h) << endl;
	cout << endl << "col (x-axis): " << f << endl << "row (y-axis): " << g << endl;
	cout << endl << "initial integer: " << h << endl << endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

	int rows, cols, **arr, f, g, h;
	srand(time(NULL));

	if (argc != 1) {
		for (int i = 0; i < argc; i++) {
			if (argc > 2) {
				cout << "ERROR: Too many arguments :(" << endl;
				exit(EXIT_FAILURE);
			}
			else if (!strcmp(argv[i], "-test")){
				test();
			}
			else if (strcmp(argv[1], "-test")) {
				cout << "ERROR: Invalid Input :(" << endl << endl;
				exit(EXIT_FAILURE);
			}
		}
	}
	else  {
		input_rows_cols(rows, cols);
		create_array(rows, cols);
	}

	cout << endl << endl;

	return 0;
}
