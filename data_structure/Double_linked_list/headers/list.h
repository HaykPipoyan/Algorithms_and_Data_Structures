#ifndef LIST_H
#define LIST_H

template <typename T>
class Node {
	public:
		Node(T data);
		T m_data;
		Node* m_next;
		Node* m_prev;
};

template <typename T>
class list {
	public:
		list();
		list(T data);
		~list();

		void push_front(T data);
		void pop_front(); 
		void push_back(T data); 
		void pop_back();
		void insert_after(Node<T>* prev_node, T data); 
		void erase_after(Node<T>* prev_node); 
		void clear(); 
		bool is_empty(); 
		T& front(); 
		void reverse(); 
		void merge(list<T>& other_list); 
		void print_list(); 
		void sort(); 
		void unique(); 
	
	private:
		Node<T>* m_head;
		Node<T>* m_tail;
};

#include "list.hpp"

#endif // LIST_H
