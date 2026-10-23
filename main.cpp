#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;

int main()
{
	Store store1;
	//import from text files
	ifstream credit_card_file("credit_card.txt");
	ifstream people_file("people.txt");
	ifstream product_file("products.txt");
	//add to store and other variables
	if (product_file.is_open()) 
	{
		product_file.close();
	}

	if (people_file.is_open()) 
	{
		people_file.close();
	}

	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
	cout << store1.customer_info() << endl << endl;
	cout << store1.product_info() << endl << endl;
	cout << store1.transaction_info() << endl << endl;
	//make random number of random transactions
	if (store1.num_customers() > 0 && store1.num_products() > 0)
	{
		srand(static_cast<unsigned int>(time(0)));
		int num_random_purchases = rand() % 100 + 1; //random number of purchases between 1 and 100
		for (int i = 0; i < num_random_purchases; ++i)
		{
			int random_customer_index = rand() % store1.num_customers();
			int random_product_index = rand() % store1.num_products();
			int random_quantity = (rand() % 3) + 1; //random quantity between 1 and 3
			

			store1.make_purchase(store1.get_customer(random_customer_index), store1.get_product(random_product_index), random_quantity);
		}
	}
	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
	cout << store1.customer_info() << endl << endl;
	cout << store1.product_info() << endl << endl;
	cout << store1.transaction_info() << endl << endl;

	return 0;
}
