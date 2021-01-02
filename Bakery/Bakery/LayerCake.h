/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This class gives the member function declarations for the
LayerCake class, as well as declares the private data member layerQuantity.
The declared methods include ToString, DiscountedPrice and layerQuantity's 
accessor method.
*/
#pragma once
#include "BakedGood.h"
#include "Cake.h"
#include<string>
using namespace std;
class LayerCake : public Cake
{
public:
	LayerCake(string prodFlavor, string frostFlavor, int numLayers);
	LayerCake();
	string ToString() const;
	double DiscountedPrice(int quantity) const;
	int GetLayerQuantity() const;
private:
	int layerQuantity;
	
};

#ifndef LAYERCAKE_H
#define LAYERCAKE_H

string ToString();
double DiscountedPrice();
int GetLayerQuantity();

#endif

