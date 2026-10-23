//code for transaction struct here
#include <iostream>
#include <string>
#include "transaction.h"

using namespace std;

string transaction::transaction_info()
{
    string info = "All Transactions: \nTransaction #: " + std::to_string(transaction_number) + "\n";
    info += "Customer: \nName: " + customer.name() + "\nPhone: " + customer.phone() + "\n" + customer.person_address().address_info() + "\n";
    info += "Credit Card: \nCredit card number: " + customer.person_credit_card().cc_number + std::string("\nCredit Card Limit: ") + std::to_string(customer.person_credit_card().limit) + "\nCurrent Balance: " + std::to_string(customer.person_credit_card().current_balance) + "\n";
    info += "Product: \nName: " + purchased_item.name + "\nDescription: " + purchased_item.description + "\nPrice: " + std::to_string(purchased_item.price) + "\n Quantity: " + std::to_string(quantity) + "\n";
    return info;
}