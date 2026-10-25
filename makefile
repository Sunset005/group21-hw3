CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
 
OBJS = main.o address.o credit_card.o person.o product.o store.o transaction.o
 
store_app: $(OBJS)
	$(CXX) $(CXXFLAGS) -o store_app $(OBJS)
 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
 
clean:
	rm -f *.o store_app
 