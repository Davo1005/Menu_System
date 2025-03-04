Dessert :: Dessert(string dishName, double dishPrice, bool nuts) : Dish(dishName, dishPrice), containsNuts(nuts) {}

void Dessert :: display() const {
    cout << name << " $" << price << " Contains Nuts: " << containsNuts << endl;
}