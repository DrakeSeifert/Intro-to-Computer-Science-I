#include <iostream>
using namespace std;

int main() {
	
	float sweet_lifetime, sweet_kill_person, sweet_kill_mouse, mouse_weight, diet_weight, life_span, soda_week;
	
	cout << endl;	
	cout << "Enter amount of artificial sweetener needed to kill a mouse (in ounces): ";
	cin >> sweet_kill_mouse;
	cout << endl;

	cout << "Enter the weight of the mouse (in ounces): ";
	cin >> mouse_weight;
	cout << endl;

	cout << "Enter the weight you'll stop dieting (in pounds): ";
	cin >> diet_weight;
	cout << endl;

	cout << "How long will you live? (in years): ";
	cin >> life_span;
	cout << endl;

	cout << "How many diet sodas do you drink a week?: ";
	cin >> soda_week;
	cout << endl;

	sweet_kill_mouse = sweet_kill_mouse/mouse_weight;

	diet_weight = diet_weight*sweet_kill_mouse;

	life_span = (life_span*52)*soda_week;

	sweet_lifetime = life_span*(1.2/16); //1.2 is because a regular 12oz can of soda times the 10% sweetener content is 1.2, and 16 is how many ounces in a pound 

	sweet_kill_person = sweet_lifetime*diet_weight;
	
	cout << "Amount of sweetener needed to kill you: " << sweet_kill_person << " oz" << endl;

	cout << "Amount of sweetener consumed in your lifetime: " << sweet_lifetime << " oz" << endl;

	if (diet_weight > sweet_kill_person) {
	cout << "You will die :(" << endl; 
	}
	else {
	cout << "You will live!" << endl;
	}
	return 0;
}
