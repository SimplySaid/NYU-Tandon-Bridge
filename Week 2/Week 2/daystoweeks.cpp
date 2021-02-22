#include <iostream>
using namespace std;

const int DAYS_IN_WEEK = 7;

int daysinweek() {
	int traveled;
	
	cout << "Input the amount of days traveled" << endl;
	cin >> traveled;

	cout << "You have traveled " << traveled / DAYS_IN_WEEK << " weeks and " << traveled % DAYS_IN_WEEK << " days";

	return traveled / DAYS_IN_WEEK;
}