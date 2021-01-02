/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program gives the declarations for the member 
functions of the Bread class.  These
include the Bread constructor method, the bread ToString
method to override the BakedGood ToString and the DiscountedPrice 
method to override the BakedGood class and find the Bread's true 
price taking discounts into account.
*/
#pragma once
#include "BakedGood.h"
#include<string>
using namespace std;
class Bread : public BakedGood
{
public:
	Bread(string flavor);
	Bread();
	string ToString() const;
	double DiscountedPrice(int quantity) const;
};

#ifndef BREAD_H
#define BREAD_H

string ToString();
double DiscountedPrice();

#endif

