#include "Customer.h"
#include "Order.h"

Customer::Customer(string customerName, string contact) : name(customerName), contactInfo(contact) {}

Customer::Customer(const Customer& other) : name(other.name), contactInfo(other.contactInfo), orderHistory(other.orderHistory) {}

Customer& Customer :: operator=(const Customer& other) {
    if(this != &other) {
        name = other.name;
        contactInfo = other.contactInfo;
        orderHistory = other.orderHistory;
        return *this;
    }
    return *this;
}

Customer::Customer(Customer&& other)noexcept : name(move(other.name)), contactInfo(move(other.contactInfo)), orderHistory(move(other.orderHistory)) {}

Customer& Customer::operator=(Customer&& other) noexcept
{
    if(this != &other)
    {
        name = move(other.name);
        contactInfo = move(other.contactInfo);
        orderHistory = move(other.orderHistory);
    }
    return *this;
}



void Customer::placeOrder(Order order) {
    orderHistory.push_back(order);
}

void Customer::viewOrderHistory() const {
    for(Order order : orderHistory) {
        order.displayOrder();
    }
}

string Customer::getName() const {
    return name;
}
