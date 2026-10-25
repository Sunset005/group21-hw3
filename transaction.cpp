//code for transaction struct here
#include <iostream>
#include <string>
#include "transaction.h"

using namespace std;

string transaction::transaction_info()
{
    string info = "Transaction #: " + to_string(transaction_number) + "\n";
    info += "Customer:\n" + customer.person_info() + "\n";
    info += "Product:\n" + purchased_item.product_info();
    info += "Quantity: " + to_string(quantity) + "\n";
    return info;
}