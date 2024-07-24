#include "../headers/list.hpp"

#include <iostream>

int main() {
	list<int> mylist;
	mylist.push_front(11);
	mylist.push_front(11);
	mylist.push_front(11);
	mylist.push_front(22);
	mylist.push_front(22);
	mylist.push_front(22);
	mylist.push_front(33);
	mylist.print_list();
	mylist.sort();
	mylist.unique();
	mylist.print_list();

	list<int> my2list(44);
	my2list.push_front(55);
	my2list.push_front(66);
	mylist.merge(my2list);
	mylist.print_list();
	mylist.reverse();
	mylist.print_list();
	mylist.pop_front();
	mylist.print_list();
	mylist.push_back(99);
	mylist.print_list();
	mylist.pop_back();
	mylist.print_list();
	std::cout << mylist.front() <<std::endl;
}
