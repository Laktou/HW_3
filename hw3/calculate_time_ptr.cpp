#include <iostream>

using namespace std;

int main(){
	int *secs, *mins, *hours, *days;

	// Retrieve number of seconds from user
	secs = new int;
	cout << "Enter a number of seconds: ";
	cin >> *secs;
	cout << endl;

	// Checks if the seconds are less than that of one hour
	if (*secs < 3600){
		mins = new int;
		*mins = *secs / 60;
		*secs = *secs - (*mins * 60);
		cout << "That's " << *mins << " minute(s) and " << *secs << " second(s)." << endl;
		delete[] mins;
	}
	// Checks if the seconds are less than that of a day
	else if (*secs < 86400){
		mins = new int;
		hours = new int;
		*hours = *secs / 3600;
		*mins = (*secs - (*hours * 3600)) / 60;
		*secs = *secs - ((*hours * 3600) + (*mins * 60));
		cout << "That's " << *hours << " hour(s), " << *mins << " minute(s), and " << *secs << " second(s)." << endl;
		delete[] mins, hours;
	}
	// Takes care of anything equal to or more than a day
	else {
		mins = new int;
		hours = new int;
		days = new int;
		*days = *secs / 86400;
		*hours = (*secs - (*days * 86400)) / 3600;
		*mins = (*secs - ((*days * 86400) + (*hours * 3600))) / 60;
		*secs = *secs - ((*days * 86400) + (*hours * 3600) + (*mins * 60));
		cout << "That's " << *days << " day(s), " << *hours << " hour(s), " << *mins << " minute(s), and " << *secs << " second(s)." << endl;
		delete[] mins, hours, days;
	}
	delete[] secs;

	return 0;
}