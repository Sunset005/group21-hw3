//code for product struct here
#include <iostream>
#include "product.h"

using namespace std;

string product::product_info()
{
    string info = "Products:\n";
    info += "Name: " + name + "\nDescription: " + description + "\nPrice: $" + to_string(price) + "\n;";
    return info;
}