#include "Cake.h"

/*
Jeff Arnell, section 001, jman.arnell@yahoo.com
This program defines the accessor method for the frosting flavor
to be used as a private data member in the cup and layer cake classes.
*/

string Cake::GetFrostingFlavor() const {
	return frostingFlavor;
}
