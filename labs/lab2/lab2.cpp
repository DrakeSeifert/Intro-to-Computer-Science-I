#include <iostream>

using namespace std;

float cereal_weight;
float expected_lifespan;
float boxes_week;

int main() {
	float cereal_weight;

	cout << "Enter the weight (in ounces) of a box of cereal: ";
	cin >> cereal_weight; //cereal_weight contains input
	
	cout << "Enter your expected lifespan: ";
	cin >> expected_lifespan;

	cout << "Enter number of boxes of ceareal eaten in a week: ";
	cin >> boxes_week;

	cout << "Weight of cereal boxes in metric tons: " <<  cereal_weight/35273.92 << endl;

	cout << "Number of boxes needed to yield one metric ton: " << 35273.92/cereal_weight << endl;

	cout << "Number of boxes eaten by user in a lifetime: " <<  52*expected_lifespan*boxes_week << endl;

	return 0;
}
