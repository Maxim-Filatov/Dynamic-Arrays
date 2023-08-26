// Base class
#include <iostream>
#include "Product.h"

using namespace std;

// Default constructor
Product::Product() {
	id = 0;
	presence = true;
	price = 0;
}

// Functions for accessing variables
void Product::setId(int id) {
	this->id = id;
}
int Product::getId() {
	return id;
}
void Product::setPresence(bool presence) {
	this->presence = presence;
}
bool Product::getPresence() {
	return presence;
}
void Product::setPrice(float price) {
	this->price = price;
}
float Product::getPrice() {
	return price;
}

// Destructor
Product::~Product() {}
