#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include "forward_list.h"
#include <iostream>

template <typename T>
Node<T>::Node(T data)
	: m_data{data}
	, m_next {nullptr}
{}

template <typename T>
forward_list<T>::forward_list()
	: m_head {nullptr}
{}

template <typename T>
forward_list<T>::forward_list(T data)
	: m_head {new Node(data)}
{}

template <typename T>
forward_list<T>::~forward_list()
{
	clear();
}

template <typename T>
void forward_list<T>::push_front(T data) 
{
	Node<T>* tmp = new Node(data);
	tmp->m_next = m_head;
	m_head = tmp;
}

template <typename T>
void forward_list<T>::pop_front()
{
	if(is_empty()) {
		throw std::out_of_range("list is empty");
	}
	Node<T>* tmp = m_head;
	m_head = m_head->m_next;
	delete tmp;
}

template <typename T>
void forward_list<T>::insert_after(Node<T>* prev_Node, T data)
{
	if(prev_Node != nullptr) {
		Node<T>* new_Node = new Node<T>(data);
		new_Node->m_next = prev_Node->m_next;
		prev_Node->m_next = new_Node;
	}
}

template <typename T>
void forward_list<T>::erase_after(Node<T>* prev_Node)
{
	if(prev_Node != nullptr) {
		Node<T>* tmp = prev_Node->m_next;
		prev_Node->m_next = tmp->m_next;
		delete tmp;
	}
}

template <typename T>
void forward_list<T>::clear()
{
	Node<T>* tmp = m_head;
	while(m_head != nullptr) {
		m_head = m_head->m_next;
		delete tmp;
		tmp = m_head;
	}
}

template <typename T>
bool forward_list<T>::is_empty()
{
	return m_head == nullptr;
}

template <typename T>
T& forward_list<T>::front()
{
	if(m_head == nullptr) {
		throw std::out_of_range("list is empty");
	}
	return m_head->m_data;
}

template <typename T>
void forward_list<T>::reverse()
{
	Node<T>* current = m_head;
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;

	while(current != nullptr) {
		next = current->m_next;
		current->m_next = prev;
		prev = current;
		current = next;
	}
	m_head = prev;
}

template <typename T>
void forward_list<T>::merge(forward_list<T>& other_list)
{
	if(m_head == nullptr) {
		m_head = other_list.m_head;
	} else {
		Node<T>* current = m_head;
		while(current->m_next != nullptr) {
			current = current->m_next;
		}
		current->m_next = other_list.m_head;
	} 
	other_list.m_head = nullptr;

}

template <typename T>
void forward_list<T>::print_list()
{
	Node<T>* current = m_head;
	while(current != nullptr) {
		std::cout << current->m_data << " ";
		current = current->m_next;
	}
	std::cout << "None" << std::endl;
}

template <typename T>
void forward_list<T>::sort()
{
	if(!m_head || !m_head->m_next) {
		return;
	}
	bool swapped = false;
    Node<T>* ptr1 = nullptr;
    Node<T>* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = m_head;

        while (ptr1->m_next != lptr) {
            if (ptr1->m_data > ptr1->m_next->m_data) {
                std::swap(ptr1->m_data, ptr1->m_next->m_data);
                swapped = true;
            }
            ptr1 = ptr1->m_next;
        }
        lptr = ptr1;
    } while (swapped);
}

template <typename T>
void forward_list<T>::unique()
{
	if (!m_head || !m_head->m_next) {
        return;
    }
    Node<T>* current = m_head;
    while (current->m_next != nullptr) {
        if (current->m_data == current->m_next->m_data) {
            Node<T>* duplicate = current->m_next;
            current->m_next = current->m_next->m_next;
            delete duplicate;
        } else {
            current = current->m_next;
        }
    }
}

#endif // FORWARD_LIST_HPP
