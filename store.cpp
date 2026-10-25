#include <iostream>
#include <string>
#include "store.h"

using namespace std;

Store::Store()
{
    this->num_customers_ = 0;
    this->num_products_ = 0;
    this->num_transactions_ = 0;
}

void Store::num_products(int product_count) { this->num_products_ = product_count; }
int Store::num_products() { return this->num_products_; }

void Store::num_customers(int customer_count) { this->num_customers_ = customer_count; }
int Store::num_customers() { return this->num_customers_; }

void Store::num_transactions(int transaction_count) { this->num_transactions_ = transaction_count; }
int Store::num_transactions() { return this->num_transactions_; }

bool Store::add_product(product item)
{
    if (this->num_products_ >= 100) return false; // array is full
    this->products_[this->num_products_] = item;
    this->num_products_++;
    return true;
}

product Store::get_product(int index)
{
    return this->products_[index];
}

bool Store::add_customer(Person customer)
{
    if (this->num_customers_ >= 100) return false; // array is full
    this->customers_[this->num_customers_] = customer;
    this->num_customers_++;
    return true;
}

bool Store::update_customer(int index, Person customer)
{
    if (index < 0 || index >= this->num_customers_)
    {
        return false;
    }
    this->customers_[index] = customer;
    return true;
}

Person Store::get_customer(int index)
{
    return this->customers_[index];
}

bool Store::add_transaction(transaction transaction)
{
    if (this->num_transactions_ >= 100) return false;
    this->transactions_[this->num_transactions_] = transaction;
    this->num_transactions_++;
    return true;
}

transaction Store::get_transaction(int index)
{
    return this->transactions_[index];
}

bool Store::make_purchase(Person customer, product item, int amount)
{
    transaction new_transaction;
    new_transaction.transaction_number = this->num_transactions_ + 1;
    new_transaction.customer = customer;
    new_transaction.purchased_item = item;
    new_transaction.quantity = amount;

    return this->add_transaction(new_transaction);
}

string Store::product_info()
{
    string info = "";
    for (int i = 0; i < this->num_products_; i++)
    {
        info += this->products_[i].product_info();
    }
    return info;
}

string Store::transaction_info()
{
    string info = "";
    for (int i = 0; i < this->num_transactions_; i++)
    {
        info += this->transactions_[i].transaction_info();
    }
    return info;
}

string Store::customer_info()
{
    string info = "";
    for (int i = 0; i < this->num_customers_; i++)
    {
        info += this->customers_[i].person_info() + "\n";
    }
    return info;
}

string Store::store_info()
{
    return "";
}

string Store::purchase_history(Person customer)
{
    string info = "Purchase History for " + customer.name() + ":\n";
    for (int i = 0; i < this->num_transactions_; i++)
    {
        if (this->transactions_[i].customer.name() == customer.name()) 
        {
            info += this->transactions_[i].transaction_info() + "\n";
        }
    }
    return info;
}

int Store::find_customer(Person customer)
{
    for (int i = 0; i < this->num_customers_; i++)
    {
        if (this->customers_[i].name() == customer.name())
        {
            return i;
        }
    }
    return -1; // customer not found
}