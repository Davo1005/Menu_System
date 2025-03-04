#include "Dish.h"

Dish :: Dish  (string dishName, double dishPrice) : name(dishName), price(dishPrice) {}

Dish :: Dish  (const Dish& other) : name(other.name), price(other.price) {}

Dish& Dish :: operator=(const Dish& other) {
    if (this != &other) {
        name = other.name;
        price = other.price;
    }
    return *this;
}

Dish :: Dish (Dish&& other) noexcept : name (move(other.name)), price(other.price) {}

Dish& Dish :: operator=(Dish&& other) noexcept
{
    if(this != &other)
    {
        name = move(other.name);
        price = move(other.price);
    }
    return *this;
}

void Dish :: display() const {
    cout << name << " $" << price << endl;
}

double Dish :: getPrice() const {
    return price;
}

string Dish :: getName() const {
    return name;
}