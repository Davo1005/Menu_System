#include "Menu.h"

Menu :: Menu (const Menu& other) {
    for (Dish* dish : other.dishes) {
        dishes.push_back(new Dish(*dish));
    }
}

Menu& Menu :: operator=(const Menu& other){
    if(this!=&other)
    {
        for(Dish* dish : dishes)
        {
            delete dish;
        }
        dishes.clear();
        for(Dish* dish : other.dishes)
        {
            dishes.push_back(new Dish(*dish));
        }
    }
    return *this;
}

Menu :: Menu (Menu&& other) noexcept {
    dishes = move(other.dishes);
    other.dishes.clear();
}

Menu& Menu :: operator=(Menu&& other) noexcept {
    if(this != &other)
    {
        for(Dish* dish : dishes)
        {
            delete dish;
        }
        dishes.clear();
        dishes = move(other.dishes);
        other.dishes.clear();
    }
    return *this;
}

Menu :: ~Menu()
{
    for(Dish* dish : dishes)
    {
        delete dish;
    }
    dishes.clear();
}

void Menu :: addDish(Dish* dish)
{
    dishes.push_back(dish);
}

void Menu :: displayMenu()const
{
    for(Dish* dish : dishes)
    {
        dish->display();
    }
}

Dish* Menu :: getDishByName(const string& dishName)const{
    for(Dish* dish : dishes)
    {
        if(dish->getName() == dishName)
        {
            return dish;
        }
    }
    return nullptr;
}