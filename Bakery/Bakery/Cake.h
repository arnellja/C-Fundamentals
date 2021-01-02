/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program gives the class declarations for the Cake class.
It declares the ToString and DiscountedPrice methods to be overridden
in the CupCake and LayerCake classes.  It also declares the accessor method
for the frosting flavor protected data member utitlized by the derived cake 
classes.
*/

#pragma once
#include "BakedGood.h"
#include<string>
using namespace std;
class Cake : public BakedGood
{
public:
	virtual string ToString() const = 0;
	virtual double DiscountedPrice(int quantity) const = 0;
	string GetFrostingFlavor() const;
protected:
	string frostingFlavor;
};


#ifndef CAKE_H
#define CAKE_H

string ToString();
double DiscountedPrice();
string GetFrostingFlavor();

#endif
