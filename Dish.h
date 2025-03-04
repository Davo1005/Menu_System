#ifndef DISH_H
#define DISH_H
#include<iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Dish {
    protected:
        string name;
        double price;
    public:
        Dish(string dishName, double dishPrice);
        Dish(const Dish& other);
        Dish& operator=(const Dish& other);
        Dish(Dish&& other) noexcept;
        Dish& operator=(Dish&& other) noexcept;
    
        void display() const;
        double getPrice() const;
        string getName() const;
    };
#endif