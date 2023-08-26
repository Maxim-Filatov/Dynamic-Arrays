#pragma once
#include <iostream>

using namespace std;

class Foodstuff;
class Tableware;

class Product {
	private:
		int id;
		bool presence;
		float price;
	public:
		Product();
		void setId(int id);
		int getId();
		void setPresence(bool presence);
		bool getPresence();
		void setPrice(float price);
		float getPrice();
		~Product();
		// Friend function
		friend float computeValue(Tableware tableware, Foodstuff foodstuff);
};
