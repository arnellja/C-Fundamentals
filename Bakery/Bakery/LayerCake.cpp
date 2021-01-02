/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This class gives the member function definitions for the
LayerCake class, including definitions for the LayerCake
constructor, its ToString method, its DiscountedPrice method,
and an accessor method for the layer quantity private data member
called GetLayerQuantity();
*/

#include "LayerCake.h"
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

LayerCake::LayerCake(string prodFlavor, string frostFlavor, int numLayers) {
	productName = "Layercake";
	productFlavor = prodFlavor;
	frostingFlavor = frostFlavor;
	price = 9.00 + 3.00 * (numLayers - 1);
	if (frostFlavor == "cream-cheese") {
		price += numLayers;
	}
	layerQuantity = numLayers;
}

LayerCake::LayerCake() {
	productName = "none";
	productFlavor = "none";
	frostingFlavor = "none";
	price = 0.00;
	layerQuantity = 0;
}


string LayerCake::ToString() const {
	ostringstream osStream;
	const int DIGITS = 2;
	osStream << layerQuantity << "-layer " << productFlavor << " cake with " <<
		frostingFlavor << " frosting" << BakedGood::ToString();
	return osStream.str();
}

double LayerCake::DiscountedPrice(int quantity) const {
	const double CAKE_DISCOUNT = 2.00;
	const int DISCOUNT_CHECK = 3;
	double originalPrice = price * quantity;
	double discount = 0.00;

	if (quantity >= DISCOUNT_CHECK) {
		discount += (quantity * CAKE_DISCOUNT);
	}

	return originalPrice - discount;
}

int LayerCake::GetLayerQuantity() const {
	return layerQuantity;
}