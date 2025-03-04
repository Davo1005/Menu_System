#include "Restaurant.h"

Restaurant :: Restaurant() {}

Restaurant :: Restaurant(const Restaurant& other): menu(other.menu), customers(other.customers), orders(other.orders) {}

Restaurant& Restaurant :: operator=(constr Restaurant& other) {
    if(this != &other) {
        menu = other.menu;
        customers = other.customers;
        orders = other.orders;
        return *this;
    }
    return *this;
}


Restaurant :: Restaurant(Restaurant&& other) noexcept: menu(move(other.menu)), customers(move(other.customers)), orders(move(other.orders)) {}  

void Restaurant :: showMenu() const {
    menu.display();
}

Customer* Restaurant :: getCustomerByName(const string& name) {
    for(Customer* customer : customers) {
        if(customer->getName() == name) {
            return customer;
        }
    }
    return nullptr;
}

void Restaurant :: placeNewOrder(const string& customerName) {
    Customer* customer = getCustomerByName(customerName);
    if(customer == nullptr) {
        cout << "Customer not found" << endl;
        return;
    }
    Order order(customer);
    string dishName;
    do {
        cout << "Enter dish name (or 'done' to finish): ";
        cin >> dishName;
        if(dishName != "done") {
            Dish* dish = menu.getDishByName(dishName);
            if(dish == nullptr) {
                cout << "Dish not found" << endl;
            } else {
                order.addDish(dish);
            }
        }
    } while(dishName != "done");
    order.calculateTotal();
    order.displayOrder();
    orders.push_back(order);
}

void Restaurant :: viewCustomerOrderHistory(const string& customerName) const {
    Customer* customer = getCustomerByName(customerName);
    if(customer == nullptr) {
        cout << "Customer not found" << endl;
        return;
    }
    for(Order order : orders) {
        if(order.getCustomer() == customer) {
            order.displayOrder();
        }
    }
}
Restaurant :: ~Restaurant() {
    for(Customer* customer : customers) {
        delete customer;
    }
}