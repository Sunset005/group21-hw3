//code for person class here
#include <iostream>
#include "person.h"

using namespace std;

person::person(string name, string phone, address person_address, credit_card person_credit_card) 
{
    this->name_ = name;
    this->phone_ = phone;
    this->person_address_ = person_address;
    this->person_credit_card_ = person_credit_card;
    
    string info = "Name: " + name_ + "\nPhone: " + phone_ + "\nAddress:\n" + person_address_.address_info() + "\nCredit Card:\n" + person_credit_card_.credit_card_info();

}