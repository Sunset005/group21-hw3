//implementation code for address struct here
#include "address.h"

string address::address_info()
{
    string info = "Address:\n" + address_line1 + "\n" + address_line2;
    info += "\n" + city + "\n" + state + "\n" + zip;
    return info;
}