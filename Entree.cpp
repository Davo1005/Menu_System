#include "Entree.h"
Entree :: Entree (string dishName, double dishPrcie, int cal) : Dish(dishName, dishPrcie), calories(cal) {}

void Entree :: display() const {
    cout << name << " $" << price << " Calories: " << calories << endl;
}
