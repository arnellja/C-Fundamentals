/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program defines the constructor method, ToString method
and DiscountedPrice method for the Bread class.
*/

#include "Bread.h"
#include "BakedGood.h"
#include<string>
#include<iomanip>
#include<sstream>

Bread::Bread(string flavor)
{
	productName = "bread";
	productFlavor = flavor;
	price = 4.50;
	

}

Bread::Bread() {
	productName = "none";
	productFlavor = "none";
	price = 0.00;
}

string Bread::ToString() const {
	ostringstream osStream;
	const int DIGITS = 2;
	
	osStream << productFlavor << " bread" << BakedGood::ToString();
	return osStream.str();
}

double Bread::DiscountedPrice(int quantity) const{
	const int DISCOUNT_DIVIDER = 3;
	double originalPrice = quantity * price;
	int freeLoaves = quantity / DISCOUNT_DIVIDER;
	double discount = freeLoaves * price;
	return originalPrice - discount;
}