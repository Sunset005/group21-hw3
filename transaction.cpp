//code for transaction struct here
#include <iostream>
#include "transaction.h";

using namespace std;

string transaction::transaction_info()
{
    string info = "All Transactions:\n" + "Transaction #: " + to_string(transaction_number) + "\n";
    info += "Customer: \n" + "Name: " + customer.name() + "\nPhone: " + customer.phone() + "\n" + customer.person_address().address_info() + "\n";
    info += "Credit Card: \n" + "Credit card number: " + customer.person_credit_card().credit_card_number() + "\n" + "Credit Card Limit: " + to_string(customer.credit_card().limit()) + "\n" + "Current Balance: " + to_string(customer.credit_card().current_balance()) + "\n";
    info += "Product: \n" + "Name: " + purchased_item.name + "\nDescription: " + purcahsed_item.description + "\nPrice: " + to_string(purchased_item.price) + "\n Quantity: " + to_string(quantity) + "\n";
    return info;
}