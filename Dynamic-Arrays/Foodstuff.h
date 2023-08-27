#pragma once
#include <iostream>
#include "Product.h"
#include "Tableware.h"

using namespace std;

class Foodstuff: public Product {
	private:
		int foodId;
	public:
		Foodstuff();
		Foodstuff(int id);
		void setFoodId(int foodId);
		int getFoodId();
		~Foodstuff();
		// Friend function
		friend float computeValue(Tableware tableware, Foodstuff foodstuff);
};
