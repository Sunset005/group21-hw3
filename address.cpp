//implementation code for address struct here
#include "address.h"

string address::address_info()
{
    string info = address_line1 + "\n" + address_line2 + "\n" + city + "\n" + state + "\n" + zip;
    return info;
}