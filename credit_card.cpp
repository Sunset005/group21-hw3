//implementation code for credit_card struct here
#include <iostream>
#include <sstream>
#include <iomanip>
#include "credit_card.h"

using namespace std;

// print credit card information
string credit_card::credit_card_info()
{
    ostringstream out;
    out << fixed << setprecision(2);
    out << "Credit card number: " << cc_number << "\n";
    out << "Credit Card Limit: $" << limit << "\n";
    out << "Current Balance: $" << current_balance;
    return out.str(); 
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