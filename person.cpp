//code for person class here
#include <iostream>
#include "person.h"

using namespace std;

Person::Person()
{
    name_ = "";
    phone_ = "";
}

Person::Person(string name, string phone, address person_address, credit_card person_credit_card) 
{
    this->name_ = name;
    this->phone_ = phone;
    this->person_address_ = person_address;
    this->person_credit_card_ = person_credit_card;
    
};

void Person::name(string name) {this->name_ = name; }
string Person::name() { return this-> name_; }

void Person::phone(string phone) { this->phone_ = phone; }
string Person::phone() { return this->phone_; }

void Person::person_address(address addr) { this->person_address_ = addr; }
address Person::person_address() { return this-> person_address_; }

void Person::person_credit_card(credit_card cc) { this->person_credit_card_ = cc; }
credit_card Person::person_credit_card() { return this->person_credit_card_; }


string Person::person_info()
{
    string info = "Name: " + name_ + "\nPhone: " + phone_ + "\nAddress:\n" + person_address_.address_info() + "\nCredit Card:\n" + person_credit_card_.credit_card_info();
    return info;
}