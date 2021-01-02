/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program contains the member function declarations for
the CupCake Class including the CupCake constructor class,
the CupCake ToString and DiscountedPrice method, and the accessor
method for the private data member sprinkle flavor.
*/
#pragma once
#include "BakedGood.h"
#include "Cake.h"
#include<string>
using namespace std;
class CupCake : public Cake
{
public:
	CupCake(string prodFlavor, string frostFlavor, string sprinkFlavor);
	CupCake();
	string ToString() const;
	double DiscountedPrice(int quantity) const;
	string GetSprinkleFlavor() const;
private:
	string sprinkleFlavor;
};

#ifndef CUPCAKE_H
#define CUPCAKE_H

string ToString();
double DiscountedPrice();
string GetSprinkleFlavor();

#endif