/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program gives the member function declarations for 
the BakedGood class as well as the derived classes of Bread,
Cake, Layercake, and Cupcake, as well as the protected data members those 
classes will share, such as the product flavor, price and quantity. The
functions include accessors for the data members and the virtual member 
functions for the ToString method and the DiscountedPrice method.
*/


#pragma once
#include <string>
using namespace std;
class BakedGood
{
public:
	virtual string ToString() const;
	virtual double DiscountedPrice(int quantity) const = 0;
	string GetProductName() const;
	string GetProductFlavor() const;
	double GetPrice() const;
protected:
	string productName;
	string productFlavor;
	double price;

};

#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H

string ToString();
double DiscountedPrice();
void IncreaseQuantity(int increase);
string GetProductName();
string GetProductFlavor();
double GetPrice();
int GetQuantity();
#endif