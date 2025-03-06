
using namespace std;
#include "Order.h"
Order :: Order(Customer* customer): customer(customer), totalPrice(0) {}

Order :: Order(const Order& other): customer(other.customer), orderedDishes(other.orderedDishes), totalPrice(other.totalPrice) {}

Order& Order :: operator=(const Order& other) {
    if(this != &other) {
        customer = other.customer;
        orderedDishes = other.orderedDishes;
        totalPrice = other.totalPrice;
    }
    return *this;
}

Order :: Order(Order&& other) noexcept: customer(move(other.customer)), orderedDishes(move(other.orderedDishes)), totalPrice(other.totalPrice) {}

Order& Order :: operator=(Order&& other) noexcept {
    if(this != &other) {
        customer = move(other.customer);
        orderedDishes = move(other.orderedDishes);
        totalPrice = move(other.totalPrice);
    }
    return *this;
}

void Order :: addDish(Dish* dish)
{
    orderedDishes.push_back(dish);
}

void Order :: calculateTotal()
{
    for(Dish* dish : orderedDishes)
    {
        totalPrice += dish->getPrice();
    }
}

void Order :: displayOrder() const
{
    cout << "Order for: " << customer->getName() << endl;
    for(Dish* dish : orderedDishes)
    {
        dish->display();
    }
    cout << "Total: $" << totalPrice << endl;
}

Customer* Order ::getCustomer() const 
{ 
    return customer; 
}