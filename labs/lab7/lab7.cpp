#include<iostream>
#include<cmath>
using namespace std;

int get_user_method(int &method) {
   cout << "Choose a method (1- rectangles, 2- trapezoids, 3- both): ";
   cin >> method;
   return method;
}

void get_user_input1(int &n) {
   cout << "How many rectangles: ";
   cin >> n;
}

void get_user_input2(int &n) {
   cout << "How many trapezoids?: ";
   cin >> n;
}

void get_user_bounds(double &a, double &b) {
   cout << "Enter lower bound: ";
   cin >> a;
   cout << "Enter upper bound: ";
   cin >> b;
}

float find_rectangle() {
   int n;
   double a, b, value, x, i;
   value = x = i = 0;
   get_user_input1(n);
   get_user_bounds(a, b);
   x = (b-a)/n;
   for (i = a; i <= b; i+=x) {
      value += (pow(i, 5)+10);
   }
   value = value*x;
   return value;
}

float find_trapezoid() {
   int n;
   double a, b, value, x, i;
   value = x = i = 0;
   get_user_input2(n);
   get_user_bounds(a, b);
   x = (b-a)/n;
   for (i = a; i <= b; i+=x) {
      value += x*(((pow(i, 5)+10)+(pow((i+x), 5)+10))/2);
   }
   //value = value*x;
   return value;
}

int main() {

   int method, n;
   double value1, value2;
 
   method = get_user_method(method);
  
   if (method == 1) {
      value1 = find_rectangle();
      cout << "Area: " << value1 << endl;
   }
   else if (method == 2) {
      value2 = find_trapezoid();
      cout << "Area: " << value2 << endl;
   }
   else if (method == 3) {
      value1 = find_rectangle();
      cout << "Rectangle area: " << value1 << endl;
      value2 = find_trapezoid();
      cout << "Trapezoid area: " << value2 << endl;
   }
   else {
      cout << "ERRRRRROOOORRRRR!!!!!!!!!!!!!!!" << endl;
   }
   return 0;
}
