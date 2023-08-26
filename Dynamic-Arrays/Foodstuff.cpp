// Second derived class (public)
#include <iostream>
#include "Product.h"
#include "Foodstuff.h"
#include "Tableware.h"

using namespace std;

// Default constructor
Foodstuff::Foodstuff() {
	foodId = 0;
}

// Functions for accessing the private variable
void Foodstuff::setFoodId(int foodId) {
	this->foodId = foodId;
}
int Foodstuff::getFoodId() {
	return foodId;
}

// Destructor
Foodstuff::~Foodstuff() {}
