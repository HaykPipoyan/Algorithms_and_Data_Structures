#include "../headers/forward_list.hpp"
#include <iostream>

int main() {
	forward_list<int> list;
	list.push_front(12);
	list.push_front(2);
	list.push_front(2);
	list.push_front(2);
	list.push_front(3);
	list.pop_front();
	list.push_front(123);
	std::cout << list.front() << std::endl;
	list.print_list();
	list.reverse();
	list.print_list();
	forward_list<int> list2(55);
	list.merge(list2);
	list.print_list();
	list.sort();
	list.print_list();
	list.unique();
	list.print_list();
	
}
