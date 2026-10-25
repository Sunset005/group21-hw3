#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::getline;

static void read_line(istream& in, string& line)
{
	getline(in, line);
	if (!line.empty() && line[line.size() -1] == '\r')
	{
		line.erase(line.size() - 1);
	}
}

static void skip_rest_of_line(istream& in)
{
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	Store store1;
	//import from text files
	ifstream product_file("products.txt");
	if (product_file.is_open())
	{
		int product_count = 0;
		product_file >> product_count;
		skip_rest_of_line(product_file);

		for (int i = 0; i < product_count; ++i)
		{
			string name, description;
			double price = 0.0;

			read_line(product_file, name);
			read_line(product_file, description);
			product_file >> price;
			skip_rest_of_line(product_file);

			product p;
			p.name = name;
			p.description = description;
			p.price = price;
			store1.add_product(p);
		}
		product_file.close();
	}

	string cc_names[100];
	credit_card cc_list[100];
	int cc_count = 0;

	ifstream credit_card_file("credit_card.txt");
	if (credit_card_file.is_open())
	{
		credit_card_file >> cc_count;
		skip_rest_of_line(credit_card_file);
		if (cc_count > 100) cc_count = 100;

		for (int i = 0; i < cc_count; ++i)
		{
			read_line(credit_card_file, cc_names[i]);
			credit_card_file >> cc_list[i].cc_number >> cc_list[i].limit >> cc_list[i].current_balance;
			skip_rest_of_line(credit_card_file);
		}
		credit_card_file.close();
	}

	ifstream people_file("people.txt");
	if (people_file.is_open())
	{
		int people_count = 0;
		people_file >> people_count;
		skip_rest_of_line(people_file);

		for (int i = 0; i < people_count; ++i)
		{
			string name, phone, line1, line2, city, state, zip;
			read_line(people_file, name);
			read_line(people_file, phone);
			read_line(people_file, line1);
			read_line(people_file, line2);
			read_line(people_file, city);
			read_line(people_file, state);
			read_line(people_file, zip);

			address addr;
			addr.address_line1 = line1;
			addr.address_line2 = line2;
			addr.city = city;
			addr.state = state;
			addr.zip = zip;

			//find person's card by name
			credit_card cc;
			cc.cc_number = 0;
			cc.limit = 0.0;
			cc.current_balance = 0.0;
			for (int j = 0; j < cc_count; ++j)
			{
				if (cc_names[j] == name)
				{
					cc = cc_list[j];
					break;
				}
			}
			Person p(name, phone, addr, cc);
			store1.add_customer(p);
		}
		people_file.close();
	}

	cout << "Store info: \n\n";
	cout << store1.store_info() << endl;
	cout << "Customers: \n";
	cout << store1.customer_info() << endl;
	cout << "Products: \n";
	cout << store1.product_info() << endl;
	cout << "All Transactions: \n\n";
	cout << store1.transaction_info() << endl;


	//random transaction time
	if (store1.num_customers() > 0 && store1.num_products() > 0)
	{
		srand(static_cast<unsigned int>(time(0)));
		int num_transactions = (rand() % 89) + 11;

		for (int t = 0; t < num_transactions; ++t)
		{
			int customer_index = rand() % store1.num_customers();
			int product_index = rand() % store1.num_products();
			int quantity = (rand() % 3) + 1;

			Person customer = store1.get_customer(customer_index);
			product item = store1.get_product(product_index);
			double total_cost = item.price * quantity;

			credit_card cc = customer.person_credit_card();
			if (cc.make_purchase(total_cost))
			{
				customer.person_credit_card(cc);
				store1.update_customer(customer_index, customer);
				store1.make_purchase(customer, item, quantity);

				cout << "Successfull transaction!\nTransaction Details:\n";
				cout << store1.get_transaction(store1.num_transactions() -1).transaction_info() << "\n";
			}
			else
			{
				cout << "Unsuccessfull transaction!\nTransaction Details:\n";
				cout << "Person:\n" << customer.person_info() << "\nProduct:\n" << item.product_info() << "Purchase Quantity: " << quantity << "\n\n";
			}
		}
	}

	cout << "Store info: \n\n";
	cout << store1.store_info() << endl;
	cout << "Customers: \n";
	cout << store1.customer_info() << endl;
	cout << "Products: \n";
	cout << store1.product_info() << endl;
	cout << "All Transactions: \n\n";
	cout << store1.transaction_info() << endl;
 
	return 0;
}
