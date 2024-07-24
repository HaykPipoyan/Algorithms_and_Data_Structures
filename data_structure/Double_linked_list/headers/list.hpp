#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "list.h"

template <typename T>
Node<T>::Node(T data) 
	: m_data {data}
	, m_next {nullptr}
	, m_prev {nullptr}
{}

template <typename T>
list<T>::list()
	: m_head {nullptr}
	, m_tail {nullptr}
{}

template <typename T>
list<T>::list(T data)
	: m_head {new Node(data)}
	, m_tail {m_head}
{}

template <typename T>
list<T>::~list()
{
	clear();
}

template <typename T>
void list<T>::push_front(T data)
{
	Node<T>* tmp = new Node(data);
	if(is_empty()) {
		m_head = tmp;
		m_tail = tmp;
	} else {
	tmp->m_next = m_head;
	m_head->m_prev = tmp;
	m_head = tmp;
	}
}

template <typename T>
void list<T>::pop_front()
{
	if(is_empty()) {
		throw std::out_of_range("list is empty");
	}
	Node<T>* tmp = m_head;
	m_head = m_head->m_next;
	if(m_head != nullptr) {
		m_head->m_prev = nullptr;
	} else {
		m_tail = nullptr;
	}
	delete tmp;
}

template <typename T>
void list<T>::push_back(T data)
{
	Node<T>* tmp = new Node(data);
		if(is_empty()) {
			m_head = tmp;
			m_tail = tmp;
		} else {
			tmp->m_prev = m_tail;
			m_tail->m_next = tmp;
			m_tail = tmp;
		}
} 

template <typename T>
void list<T>::pop_back()
{
	if(is_empty()) {
		throw std::out_of_range("list is empty");
	}
	Node<T>* tmp = m_tail;
	m_tail = m_tail->m_prev;
	if(m_tail != nullptr) {
		m_tail->m_next = nullptr;
	} else {
		m_head = nullptr;
	}
	delete tmp;
}

template <typename T>
void list<T>::insert_after(Node<T>* prev_node, T data)
{
	if(prev_node != nullptr) {
		Node<T>* newNode = new Node<T>(data);
		newNode->m_next = prev_node->m_next;
		newNode->m_prev = prev_node;
		prev_node->m_next = newNode;
		if(newNode->m_next != nullptr) {
			newNode->m_next->m_prev = newNode;
		}
		if(newNode->m_next == nullptr) {
			m_tail = newNode;
		}
	}
}

template <typename T>
void list<T>::erase_after(Node<T>* prev_node)
{
	if(prev_node != nullptr && prev_node->m_next != nullptr) {
		Node<T>* tmp = prev_node->m_next;
		prev_node->m_next = tmp->m_next;
		if(tmp->m_next != nullptr) {
			tmp->m_next->m_prev = prev_node;
		} else {
			m_tail = prev_node;
		}
		delete tmp;
	}
}
	
template <typename T>
void list<T>::clear()
{
	Node<T>* tmp = m_head;
	while(m_head != nullptr) {
		m_head = m_head->m_next;
		delete tmp;
		tmp = m_head;
	}
}

template <typename T>
bool list<T>::is_empty()
{
	return m_head == nullptr;
} 

template <typename T>
T& list<T>::front()
{
	if(m_head != nullptr) {
		return m_head->m_data;
	}
	throw std::out_of_range("list is empty");
} 

template <typename T>
void list<T>::reverse()
{
	if (is_empty()) {
        return; 
    }
	Node<T>* current = m_head;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
	while(current != nullptr) {
		next = current->m_next;
		current->m_next = prev;
		current->m_prev = next;
		prev = current;
		current = next;
	}
	Node<T>* tmp = m_head;
	m_head = m_tail;
	m_tail = tmp;
} 

template <typename T>
void list<T>::merge(list<T>& other_list)
{
	if(other_list.is_empty()) {
		return;
	}
	if(m_head == nullptr) {
		m_head = other_list.m_head;
		m_tail = other_list.m_tail;
	}
	m_tail->m_next = other_list.m_head;
	other_list.m_head->m_prev = m_tail;
	m_tail = other_list.m_tail;
	other_list.m_head = nullptr;
    other_list.m_tail = nullptr;
}

template <typename T>
void list<T>::print_list()
{
	std::cout << "None" << " ";
	Node<T>* tmp = m_head;
	while(tmp != nullptr) {
		std::cout << tmp->m_data << " ";
		tmp = tmp->m_next;
	} 
	std::cout << "None" << std::endl;
} 

template <typename T>
void list<T>::sort()
{
	if(!m_head || !m_head->m_next) {
		return;
	}
	bool swapped = false;
	Node<T>* tmp = nullptr;
	Node<T>* lptr = nullptr;
	do {
		tmp = m_head;
		swapped = false;
		while(tmp->m_next != lptr) {
			if(tmp->m_data > tmp->m_next->m_data) {
				std::swap(tmp->m_data, tmp->m_next->m_data);
				swapped = true;
			}
			tmp = tmp->m_next;
		}
		lptr = tmp;
	} while(swapped);
} 

template <typename T>
void list<T>::unique()
{
	if(!m_head || !m_head->m_next) {
	return;
	}
	Node<T>* tmp = m_head;
	while(tmp->m_next) {
		if(tmp->m_data == tmp->m_next->m_data) {
			Node<T>* dublicat = tmp->m_next;
			tmp->m_next = dublicat->m_next;
			if(tmp->m_next) {
				tmp->m_next->m_prev = tmp;
			} else {
				m_tail = tmp;
			}	
			delete dublicat;
		} else {
			tmp = tmp->m_next;
		}
	}
}


#endif // LIST_HPP
