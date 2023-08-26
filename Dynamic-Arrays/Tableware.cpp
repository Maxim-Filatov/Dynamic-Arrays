// First derived class (private)
#include <iostream>
#include "Product.h"
#include "Tableware.h"
#include "Foodstuff.h"

using namespace std;

// Default constructor
Tableware::Tableware() {
	tablewareId = 1;
}

// Functions for accessing the private variable
void Tableware::setTablewareId(int tablewareId) {
	this->tablewareId = tablewareId;
}
int Tableware::getTablewareId() {
	return tablewareId;
}

// Destructor
Tableware::~Tableware() {}
