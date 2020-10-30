#include <iostream>
#include "list.h"

int main() {
	list list1, list2;
	list1.push_back(3);
	/*list1.push_back(5);
	list1.push_front(1);
	list1.push_back(7);*/
	list1.pop_front();
	//std::cout << list1.at(1);
	list2.push_back(2);
	list2.push_back(4);
	list2.push_back(6);
	list2.push_back(8);
	//list1.push_front(list2);
	list1.print_to_console();
	return 0;
}