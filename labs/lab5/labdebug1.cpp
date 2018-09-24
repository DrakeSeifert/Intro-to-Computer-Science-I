#include <iostream>
#include <cmath>
#define WATER_WEIGHT 62.4 //Defines the specific weight of water
using std::cout;
using std::cin;
int main {
 	//Variables needed to calculate buoyancy
 	float radius, bforce, volume, weight;
	const double PI = 3.14159
 	//Prompt user for weight and radius of sphere
 	cout << "Please enter the weight (lbs): ";
 	cin >> weight;
	cout << std::endl;
 	cout << "Please enter the radius: ";
 	cin >> radius;
	cout << std::endl;
 
 	//Calculate the volume and buoyancy force
 	volume = 4.0/3.0 * PI * pow(radius, 3);
 	bforce = volume * WATER_WIEGHT;
 	//Determine if the sphere will sink or float
 	if(bforce >= weight) {
 		cout << "The sphere will float!\n";
 	else
 		cout << "The sphere will sink!\n";
	}
  }
  return;
