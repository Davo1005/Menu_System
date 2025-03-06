#ifndef MENU_H
#define MENU_H
#include "Dish.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Menu {
    private:
        vector<Dish*> dishes;
    public:
        Menu() = default;
        Menu(const Menu& other);
        Menu& operator=(const Menu& other);
        Menu(Menu&& other) noexcept;
        Menu& operator=(Menu&& other) noexcept;
        ~Menu();
        void addDish(Dish* dish);
        void displayMenu() const;
        Dish* getDishByName(const string& dishName) const;
    };
#endif 