#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <vector>
#include <string>
#include "Menu.h"
#include "Customer.h"
#include "Order.h"
#include <iostream>

using namespace std;    

class Restaurant {
    private:
        Menu menu;
        vector<Customer*> customers;
        vector<Order> orders;
    public:
    
        Restaurant();
        Restaurant(const Restaurant& other);
        Restaurant& operator=(const Restaurant& other);
        Restaurant(Restaurant&& other) noexcept;
        Restaurant& operator=(Restaurant&& other) noexcept;
        ~Restaurant();
        void showMenu() const;
        Customer* getCustomerByName(const string& name);
        void placeNewOrder(const string& customerName);
        void viewCustomerOrderHistory(const string& customerName) const;
    }; 
#endif