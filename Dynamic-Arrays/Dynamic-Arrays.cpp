/* CPP Lab-8. Data processing in dynamic arrays.
   This file contains menu for demonstrating the work of the program
   and the entry point. 
   Press 1 to create a vector consisting of a thousand elements and 
   another vector that is made up of elements of the first one but in reverse order.
   After that, program will calculate the total purchase sum.
   Press 2 to add 500 elements to the middle of the first vector,
   calculate the total purchase sum, display it on the screen, clear that vector and
   demonstrate that it is empty.
   Press 3 to quit the program */

#include <iostream>
#include <vector>
#include "Product.h"
#include "Tableware.h"
#include "Foodstuff.h"

using namespace std;

// Check if the entered value is appropriate
void validateInput() {
    int ignoreValue = 1024;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(ignoreValue, '\n');
    }
}

// Create two vectors both containing thousand elements
float fillArray(vector<Foodstuff>& f1, vector<Foodstuff>& f2) {
    float sum = 0;
    // Fill the first vector with objects
    for (int i = 0; i < 1000; i++) {
        f1.push_back(Foodstuff(i));
        // Give a random price to the Foodstuff object (from 100 to 1000)
        f1[i].setPrice((float)(100 + (rand() % 1000)));
        // Calculate the total purchase sum
        sum += f1[i].getPrice();
    }
    int firstVectorSize = (int)f1.size() - 1;
    // Fill the second vector (reversed first one)
    for (int i = 0; i <= firstVectorSize; i++) {
        f2.push_back(f1[firstVectorSize--]);
    }
    return sum;
}

// Add 500 elements to a vector
float addElements(vector<Foodstuff>& f1) {
    float sum = 0;
    int index, size;
    std::vector<Foodstuff>::const_iterator iter;
    size = f1.size();
    index = (int)size / 2;
    for (int i = index; i < size; i++) {
        iter = f1.cbegin();
        // Add a new element to the first vector
        f1.emplace(iter + index, Foodstuff(i));
        //Give a random price to the Foodstuff object (from 100 to 1000)
        f1[index].setPrice((float)(100 + (rand() % 1000)));
        // Calculate the total purchase sum
        sum += f1[index].getPrice();
    }
    return sum;
}

int main() {
    // Boolean variable to check if the user wants to quit the program or is continuing the interaction with it
    bool loop = true;
    // This is a variable for the switch statement. Variable's value is modified by the user in the loop
    int input;
    // Purchase sum
    float sum;
    cout << "What do you want to do? Enter a number (1-3): ";
    while (loop) {
        sum = 0;
        cin >> input;
        validateInput();
        // Declaration of vectors
        vector<Foodstuff> foodstuffs;
        vector<Foodstuff> foodstuffsReversed;
        switch (input) {
            // Fill two vectors and calculate the total purchase sum
            case 1:
                sum = fillArray(foodstuffs, foodstuffsReversed);
                cout << "The total purchase sum: " << sum << endl;
                cout << "What do you want to do next? Enter a number (1-3): ";
            break;
            /* Add elements to the middle of the first vector, calculate the total purchase sum,
               clear that vector and demonstrate that it is empty */ 
            case 2:
                // Fill two vectors
                sum = fillArray(foodstuffs, foodstuffsReversed);
                cout << "Current purchase sum: " << sum << endl;
                // Add 500 elements to the first array
                sum += addElements(foodstuffs);
                cout << "The total purchase sum: " << sum << endl;
                // Clear the first vector
                foodstuffs.clear();
                // Demostrate that it is empty
                if (foodstuffs.empty()) {
                    cout << "Vector has been cleared successfully." << endl;
                }
                else {
                    cout << "Vector has " << foodstuffs.size() << " elements." << endl;
                }
                cout << "What do you want to do next? Enter a number (1-3): ";
            break;
            // Exit the program
            case 3:
                loop = false;
            break;
            default:
                cout << "Invalid input. Enter only numbers from 1 to 3: ";
            break;
        }
    }
}
