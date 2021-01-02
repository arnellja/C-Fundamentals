/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This class gives the member function definitions for the 
BakedGood class, including the virtual ToString method, as well
as the protected data member accessor methods, with a method to increase
quantity of any one product.
*/

#include "BakedGood.h"
#include<sstream>
#include<iomanip>


string BakedGood::ToString() const {
	ostringstream osStream;
	const int DIGITS = 2;
	osStream << " ($" << fixed << setprecision(DIGITS) << price << ")";
	return osStream.str();
}



double BakedGood::GetPrice() const {
	return price;
}

string BakedGood::GetProductName() const {
	return productName;
}

string BakedGood::GetProductFlavor() const {
	return productFlavor;
}
