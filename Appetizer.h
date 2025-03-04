#ifndef APPRTIZER_H
#define APPRTIZER_H
#include "Dish.h"
#include <string>
#include <iostream>

using namespace std;

class Appetizer : public Dish {
    private:
        bool isSpicy;
    public:
        Appetizer(std::string dishName, double dishPrice, bool spicy);
        void display() const;
    };
    
#endif