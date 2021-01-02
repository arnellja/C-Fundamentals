/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program simulates ordering from a bakery.  It
creates class objects of CupCakes, Breads, and LayerCakes
and places them into a BakedGood Vector.  Once the vector is 
filled with orders, the program will return a order confirmation
of each individual pastry, followed by an invoice detailing total
price and various discounts.
Late Days: N/A

*/

#include"BakedGood.h"
#include"Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"

#include<string>
#include<vector>
#include<iostream>
#include<iomanip>
using namespace std;

void GetBread(vector<BakedGood*>& bakery, vector<BakedGood*>& temp, vector<int>& quantities) {
	const int LAST_GOOD = 1;
	string productFlavor;
	int quantity = 0;
	cin >> productFlavor;
	cin >> quantity;
	for (int counter = 0; counter < quantity; ++counter) {
		bakery.push_back(new Bread(productFlavor));
	}
	if (!temp.empty()) {
		for (unsigned int counter = 0; counter < temp.size(); ++counter) {
			if (bakery.at(bakery.size() - LAST_GOOD)->ToString() == temp.at(counter)->ToString()) {
				quantities.at(counter) += quantity;
				return;
			}
		}
	}
	temp.push_back(bakery.at(bakery.size() - LAST_GOOD));
	quantities.push_back(quantity);
}

void GetLayerCake(vector<BakedGood*>& bakery, vector<BakedGood*>& temp, vector<int>& quantities) {
	const int LAST_GOOD = 1;
	string productFlavor;
	string frostingFlavor;
	int numLayers = 0;
	int quantity = 0;
	cin >> productFlavor;
	cin >> frostingFlavor;
	cin >> numLayers;
	cin >> quantity;
	for (int counter = 0; counter < quantity; ++counter) {
		bakery.push_back(new LayerCake(productFlavor, frostingFlavor, numLayers));
	}

	if (!temp.empty()) {
		for (unsigned int counter = 0; counter < temp.size(); ++counter) {
			if (bakery.at(bakery.size() - LAST_GOOD)->ToString() == temp.at(counter)->ToString()) {
				quantities.at(counter) += quantity;
				return;
			}
		}
	}
	temp.push_back(bakery.at(bakery.size() - LAST_GOOD));
	quantities.push_back(quantity);
}

void GetCupCake(vector<BakedGood*>& bakery, vector<BakedGood*>& temp, vector<int>& quantities) {
	const int LAST_GOOD = 1;
	string productFlavor;
	string frostingFlavor;
	string sprinkleFlavor;
	int quantity = 0;
	cin >> productFlavor;
	cin >> frostingFlavor;
	cin >> sprinkleFlavor;
	cin >> quantity;
	for (int counter = 0; counter < quantity; ++counter) {
		bakery.push_back(new CupCake(productFlavor, frostingFlavor, sprinkleFlavor));
	}
	if (!temp.empty()) {
		for (unsigned int counter = 0; counter < temp.size(); ++counter) {
			if (bakery.at(bakery.size() - LAST_GOOD)->ToString() == temp.at(counter)->ToString()) {
				quantities.at(counter) += quantity;
				return;
			}
		}
	}
	temp.push_back(bakery.at(bakery.size() - LAST_GOOD));
	quantities.push_back(quantity);
}

void OrderConfirmation(vector<BakedGood*> bakery) {
	const int SPACING = 75;
	cout << "Order Confirmations:" << endl;
	for (unsigned int counter = 0; counter < bakery.size(); ++counter) {
			cout << left << setw(SPACING) << bakery.at(counter)->ToString() << endl;
	}
}

void PrintInvoice(vector<BakedGood*> temp, vector<int> quantities) {
	const int SPACING = 75;
	const int DIGITS = 2;
	int totalQuantity = 0;
	double totalPrice = 0.00;
	cout << "Invoice:" << endl;
	cout << left << setw(SPACING) << "Baked Good";
	cout << "Quantity\t\tTotal" << endl;
	for (unsigned int counter = 0; counter < temp.size(); ++counter) {
		cout << left << setw(SPACING) << temp.at(counter)->ToString();
		cout << quantities.at(counter) << "\t\t" << fixed << setprecision(DIGITS) << temp.at(counter)->DiscountedPrice(quantities.at(counter)) << endl;
		totalQuantity += quantities.at(counter);
		totalPrice += temp.at(counter)->DiscountedPrice(quantities.at(counter));

	}
	cout << left << setw(SPACING) << "Totals";
	cout << totalQuantity << "\t\t" << fixed << setprecision(DIGITS) << totalPrice << endl;
}



int main() {
	vector<BakedGood*> bakery;
	vector<BakedGood*> temp;
	vector<int> quantities;
	string productName;

	cout << "**Bread and Cakes Bakery**" << endl;
	cout << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;

	while (productName != "done") {
		cout << "Sub-order: " << endl;
		cin >> productName;

		if (productName == "Bread") {
			GetBread(bakery, temp, quantities);
		}
		else if (productName == "Layer-cake") {
			GetLayerCake(bakery, temp, quantities);
		}
		else if (productName == "Cupcake") {
			GetCupCake(bakery, temp, quantities);
		}

	}

	OrderConfirmation(bakery);
	PrintInvoice(temp, quantities);



	cout << "Good Bye" << endl;

	//system("pause");
	return 0;
}