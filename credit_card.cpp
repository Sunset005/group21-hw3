//implementation code for credit_card struct here
#include <iostream>
#include "credit_card.h"

using namespace std;

// print credit card information
string credit_card::credit_card_info()
{
    string info = "Credit Card: \n" + "Credit card number: " + cc_number + "\nCredit Card Limit: " + to_string(limit) + "\nCurrent Balance: " + to_string(current_balance);
    return info;
}

bool credit_card::make_purchase(double purchase_amount)
{
    if (limit - current_balance >= purchase_amount)
    {
        current_balance += purchase_amount;
        return true;
    }
    else
    {
        return false;
    }
}
bool credit_card::make_payment(double payment_amount)
{
    if(payment_amount <= current_balance)
    {
        current_balance -= payment_amount;
        return true;
    }
    else
    {
        return false;
    }
}