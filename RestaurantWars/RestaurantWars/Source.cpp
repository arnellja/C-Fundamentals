/*
Jeff Arnell, Section 1, jman.arnell@yahoo.com
This program is supposed to take in a list of restaurants
and peform of elimination bracket to get one winning
restaurant based on user input.  The program will also be able to
cut, shuffle, add to, remove from and print out the list of restaruants
at any time.
Late Days: N/A

Test Case 1:
Input: (add, Mcdonalds, add, Pizza Hut, battle, 1, quit)
Output: (Mcdonalds added, Pizza Hut added, Mcdonalds Winner).
Test Passed

Test Case 2:
Input: (-1, 0, quit)
Output: (Invalid selection, printed menu, invalid selection, printed menu, goodbye)
Test Passed

Test Case 3:
Input: (add, Mcdonalds, shuffle, battle, add, pizza hut, shuffle, cut, 1, display, quit)
Expected output: (added mcd's, not enough for shuffle or battle, added pizzahut, shuffle, cut 1 off top, show mcd's on top, goodbye)
Test Passed
*/




#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<cmath>
#include<limits>
using namespace std;

const int EVEN_DIVIDE = 2;
const int NO_REMAINDER = 0;
const int FIRST_RESTAURANT = 0;
const int OPTION_ONE = 1;
const int OPTION_TWO = 2;
const int NEXT_RESTAURANT = 1;


void PrintOptions() {
	cout << "Please select one of the following options:" << endl;
	cout << endl;
	cout << "quit - Quit the program" << endl;
	cout << "display - Display all restaurants" << endl;
	cout << "add - Add a restaurant" << endl;
	cout << "remove - Remove a restaurant" << endl;
	cout << "cut - \"Cut\" the list of restaurants" << endl;
	cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
	cout << "battle - Begin the tournament" << endl;
	cout << "options - Print the options menu" << endl;
	return;
}

bool Find(const vector<string> places, string searchPlace) {
	for (int counter = 0; counter < places.size(); ++counter) {
		if (places.at(counter) == searchPlace) {
			return true;
		}
	}
	return false;
}

void RemoveRestaurant(vector<string>& restaurants) {
	string newEntry;
	cout << "What is the name of the restaurant you want to remove?" << endl;
	getline(cin, newEntry);
	if (Find(restaurants, newEntry) == true) {
		for (int counter = 0; counter < restaurants.size(); ++counter) {
			if (restaurants.at(counter) == newEntry) {
				restaurants.erase(restaurants.begin() + counter);
			}
		}
		cout << newEntry << " has been removed." << endl;
	}
	else {
		cout << "That restaurant is not on the list, you can not remove it." << endl;
	}
	return;
}

void AddRestaurant(vector<string>& restaurants) {
	string newEntry;
	cout << "What is the name of the restaurant you want to add?" << endl;
	getline(cin, newEntry);
	if (Find(restaurants, newEntry) == false) {
		restaurants.push_back(newEntry);
		cout << newEntry << " has been added." << endl;
	}
	else {
		cout << "That restaurant is already on the list, you can not add it again." << endl;
	}
	return;
}

void ShowRestaurants(const vector<string> places) {
	cout << "Here are the current restaurants:" << endl;
	cout << endl;
	for (int counter = 0; counter < places.size(); ++counter) {
		cout << "\t\"" << places.at(counter) << "\"" << endl;
		cout << endl;
	}
	return;
}

void CutList(vector<string>& restaurants) {
	const int LIST_START = 0;
	int cutNum = 0;
	vector<string> tempList;

	while (cutNum <= LIST_START || cutNum >= restaurants.size()) {
		cout << "How many restaurants should be taken from the top and put on the bottom?" << endl;
		cout << endl;
		cin >> cutNum;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "The cut number must be between 0 and " << restaurants.size() << endl;
			cout << "How many restaurants should be taken from the top and put on the bottom?" << endl;
			cout << endl;
			cin >> cutNum;
		}
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		if (cutNum > LIST_START && cutNum < restaurants.size()) {
			for (int counter = 0; counter < cutNum; ++counter) {
				tempList.push_back(restaurants.at(LIST_START));
				restaurants.erase(restaurants.begin() + LIST_START);
			}
			for (int counter = 0; counter < cutNum; ++counter) {
				restaurants.push_back(tempList.at(LIST_START));
				tempList.erase(tempList.begin() + LIST_START);
			}
			break;
		}
		else if (cutNum == LIST_START || cutNum == restaurants.size()) {
			break;
		}
		else if (cutNum < LIST_START || cutNum < restaurants.size()) {
			cout << "The cut number must be between 0 and " << restaurants.size() << endl;
		}
		else {
			return;

		}
	}

	return;
}

void ShuffleList(vector<string>& restaurants) {
	vector<string> tempList1;
	vector<string> tempList2;
	int halfListSize = restaurants.size() / EVEN_DIVIDE;
	if (restaurants.size() % EVEN_DIVIDE == NO_REMAINDER) {
		for (int counter = 0; counter < halfListSize; ++counter) {
			tempList1.push_back(restaurants.at(FIRST_RESTAURANT));
			restaurants.erase(restaurants.begin() + FIRST_RESTAURANT);
		}
		for (int counter = 0; counter < halfListSize; ++counter) {
			tempList2.push_back(restaurants.at(FIRST_RESTAURANT));
			restaurants.erase(restaurants.begin() + FIRST_RESTAURANT);
		}
		for (int counter = 0; counter < halfListSize; ++counter) {
			restaurants.push_back(tempList2.at(FIRST_RESTAURANT));
			tempList2.erase(tempList2.begin() + FIRST_RESTAURANT);
			restaurants.push_back(tempList1.at(FIRST_RESTAURANT));
			tempList1.erase(tempList1.begin() + FIRST_RESTAURANT);
		}
	}
	else {
		cout << "The current tournament size (" << restaurants.size() << ") is not a power of two " <<
			"(2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
	}
	return;
}

int GetBattleRounds(const vector<string> restaurants) {
	int totalRestaurantNum = restaurants.size();
	int roundNum = 0;
	for (int counter = 0; counter < totalRestaurantNum; ++counter) {
		if (pow(EVEN_DIVIDE, counter) == totalRestaurantNum) {
			roundNum = counter;
			break;
		}
	}
	return roundNum;
}

void Battle(vector<string> restaurantsList) {
	int rounds = 0;
	int restaurantChoice = 0;
	if (restaurantsList.size() % EVEN_DIVIDE == NO_REMAINDER) {
		rounds = GetBattleRounds(restaurantsList);
		for (int counter = 1; counter <= rounds; ++counter) {
			cout << endl;
			cout << "Round: " << counter << endl;
			cout << endl;
			for (int matchUps = 0; matchUps < restaurantsList.size(); ++matchUps) {
				cout << "Type \"1\" if you prefer " << restaurantsList.at(matchUps) << " or" << endl;
				cout << "type \"2\" if you prefer " << restaurantsList.at(matchUps + NEXT_RESTAURANT) << endl;
				cout << "Choice: " << endl;
				cin >> restaurantChoice;
				if (cin.fail() || (restaurantChoice < OPTION_ONE || restaurantChoice > OPTION_TWO)) {
					cin.clear();
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					cout << "Invalid choice" << endl;
					matchUps--;
					continue;
				}
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				if (restaurantChoice == OPTION_ONE) {
					restaurantsList.erase(restaurantsList.begin() + matchUps + NEXT_RESTAURANT);
				}
				else {
					restaurantsList.erase(restaurantsList.begin() + matchUps);
				}
			}
		}
		cout << "The winning restaurant is " << restaurantsList.at(FIRST_RESTAURANT) << "." << endl;
	}
	else {
		cout << "The current tournament size (" << restaurantsList.size() << ") is not a power of two " <<
			"(2, 4, 8...)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl;
	}
	return;
}

int main() {
	vector<string> restaurants;
	string menuChoice = " ";

	cout << "Welcome to the restaurant battle!  Enter \"Options\" to see options." << endl;


	while (menuChoice != "quit") {
		cout << endl;
		cout << "Enter your selection:" << endl;
		cin >> menuChoice;
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;

		if (menuChoice == "options") {
			PrintOptions();
		}
		else if (menuChoice == "battle") {
			Battle(restaurants);
		}
		else if (menuChoice == "shuffle") {
			ShuffleList(restaurants);
		}
		else if (menuChoice == "cut") {
			CutList(restaurants);
		}
		else if (menuChoice == "remove") {
			RemoveRestaurant(restaurants);
		}
		else if (menuChoice == "add") {
			AddRestaurant(restaurants);
		}
		else if (menuChoice == "display") {
			ShowRestaurants(restaurants);
		}
		else if (menuChoice == "quit") {
			break;
		}
		else {
			cout << "Invalid Selection" << endl;
			PrintOptions();
		}
	}

	cout << "Goodbye!" << endl;

	system("pause");
	return 0;
}