/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program gives the member function definitions for the
CupCake class, including the constructor method, the CupCake
ToString and DiscountedPrice methods and the sprinkle flavor
accessor method.
*/

#include "CupCake.h"
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;



CupCake::CupCake(string prodFlavor, string frostFlavor, string sprinkFlavor){
	productName = "Cupcake";
	productFlavor = prodFlavor;
	frostingFlavor = frostFlavor;
	sprinkleFlavor = sprinkFlavor;
	if (frostFlavor == "cream-cheese") {
		price = 2.15;
	}
	else {
		price = 1.95;
	}

}

CupCake::CupCake() {
	productName = "none";
	productFlavor = "none";
	frostingFlavor = "none";
	sprinkleFlavor = "none";
	price = 0.00;
}

string CupCake::ToString() const {
	ostringstream osStream;
	const int DIGITS = 2;
	osStream << productFlavor << " cupcake with " << frostingFlavor << " frosting and " <<
		sprinkleFlavor << " sprinkles" << BakedGood::ToString();
	return osStream.str();
}

double CupCake::DiscountedPrice(int quantity) const {
	const double FOUR_DISCOUNT = 0.40;
	const double TWO_DISCOUNT = 0.30;
	const int DISCOUNT_CHECK1 = 4;
	const int DISCOUNT_CHECK2 = 2;
	double discount = 0.00;
	double originalPrice = price * quantity;
	

	if (quantity >= DISCOUNT_CHECK1) {
		discount = quantity * FOUR_DISCOUNT;
		return originalPrice - discount;
	}

	if (quantity >= DISCOUNT_CHECK2) {
		discount = quantity * TWO_DISCOUNT;
		return originalPrice - discount;
	}

	return originalPrice;
}

string CupCake::GetSprinkleFlavor() const {
	return sprinkleFlavor;
}