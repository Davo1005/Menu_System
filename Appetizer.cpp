


Appetizer :: Appetizer ( string dishName, double dishPrice, bool spicy) : Dish(dishName, dishPrice), isSpicy(spicy) {}

void Appetizer :: display() const {
    cout << name << " $" << price << " Spicy: " << isSpicy << endl;
}