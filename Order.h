#ifndef ORDER_H
#define ORDER_H
#include "Customer.h"
#include "Menu.h"
#include "Dish.h"
#include <vector>
#include <iostream>
using namespace std;
class Customer;

class Order {
    private:
        Customer* customer;
        vector<Dish*> orderedDishes;
        double totalPrice;
    public:
        Order(Customer* customer);
        Order(const Order& other);
        Order& operator=(const Order& other);
        Order(Order&& other) noexcept;
        Order& operator=(Order&& other) noexcept;
        ~Order() = default;
        void addDish(Dish* dish);
        Customer* getCustomer() const;
        void calculateTotal();
        void displayOrder() const;
    };
#endif