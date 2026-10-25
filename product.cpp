//code for product struct here
#include <iostream>
#include <sstream>
#include <iomanip>
#include "product.h"

using namespace std;

string product::product_info()
{
    ostringstream out;
    out << fixed << setprecision(2);
    out << "Name: " << name << "\n" << "Description: " << description << "\n" << "Price: $" << price << "\n";
    return out.str();
}