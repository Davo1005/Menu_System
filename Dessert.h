#ifndef DESSERT_H
#define DESSERT_H
#include "Dish.h"
#include <string>
#include <iostream>

using namespace std;

    class Dessert : public Dish {
    private:
        bool containsNuts;
    public:
        Dessert(string dishName, double dishPrice, bool nuts);
        void display() const;
    };
#endif