#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

template <typename T>
class Node {
	public:
		Node(T data);
		T m_data;
		Node* m_next;
};

template <typename T>
class forward_list {
	public:
		forward_list();
		forward_list(T data);
		~forward_list();

		void push_front(T data);
		void pop_front();
		void insert_after(Node<T>* prev_Node, T data); 
		void erase_after(Node<T>* prev_Node);		
		void clear(); 
		bool is_empty();
		T& front();
		void reverse();
		void merge(forward_list<T>& other_list); 
		void print_list();
		void sort(); 
		void unique();

	private:
		Node<T>* m_head;
};


#include "forward_list.hpp"

#endif // FORWARD_LIST_H
