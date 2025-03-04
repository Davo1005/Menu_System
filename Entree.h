#ifndef ENTREE_H
#define ENTREE_H
#include "Dish.h"
#include <string>
#include <iostream>

class Entree : public Dish {
    private:
        int calories;
    public:
        Entree(string dishName, double dishPrice, int cal);
        void display() const;
    };

#endif