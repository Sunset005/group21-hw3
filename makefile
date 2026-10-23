CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

hw3: main.cpp address.cpp credit_card.cpp person.cpp product.cpp store.cpp transaction.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f hw3
