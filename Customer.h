#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Order.h"
#include "Menu.h"
#include "Dish.h"
#include <iostream>

using namespace std;

class Order;
class Customer {
    private:
        string name;
        string contactInfo;
        vector<Order> orderHistory;
    public:
        Customer(string customerName, string contact);
        Customer(const Customer& other);
        Customer& operator=(const Customer& other);
        Customer(Customer&& other) noexcept;
        Customer& operator=(Customer&& other) noexcept;
        ~Customer() = default;
        void placeOrder(Order order);
        void viewOrderHistory() const;
        string getName() const;
};

#endif