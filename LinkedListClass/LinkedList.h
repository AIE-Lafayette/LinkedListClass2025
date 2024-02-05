#pragma once
#include "Iterator.h"
#include <iostream>

//pushback
//insert 
//remove
//destroy

template<typename AnyType>
class LinkedList
{
public:
	LinkedList();
	void print() const;

	Iterator<AnyType> begin() const;
	Iterator<AnyType> end() const;

	void pushBack(const AnyType& value);
	void pushFront(const AnyType& value);

	bool insert(const AnyType& value, int index);
	bool remove(const AnyType& value);

private:
	Node<AnyType>* m_first;
	Node<AnyType>* m_last;

	int m_nodeCount;
};

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename AnyType>
inline void LinkedList<AnyType>::print() const
{
	for (Iterator<AnyType> iter = begin(); iter != end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::begin() const
{
	return Iterator<AnyType>(m_first);
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::end() const
{
	if (m_last)
		return Iterator<AnyType>(m_last->next);

	return Iterator<AnyType>(nullptr);
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushBack(const AnyType& value)
{
	//Create a new node to put the value in.
	Node<AnyType>* newNode = new Node<AnyType>(value);
	//Update the node count to include the new node.
	m_nodeCount++;
	//If the last node is null that must mean the list is empty...
	if (!m_last)
	{
		//...so set the new node to be the first and last.
		m_last = newNode;
		m_first = newNode;
		return;
	}

	//Set the last node's next to be the new node.
	m_last->next = newNode;
	//Tell the new node to set its previous to the old last node.
	newNode->previous = m_last;
	//Mark the new node as being the last node.
	m_last = newNode;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushFront(const AnyType& value)
{
	//Create a new node to put the value in.
	Node<AnyType>* newNode = new Node<AnyType>(value);
	//Update the node count to include the new node.
	m_nodeCount++;
	//If the last node is null that must mean the list is empty...
	if (!m_last)
	{
		//...so set the new node to be the first and last.
		m_last = newNode;
		m_first = newNode;
		return;
	}

	//Set the first node's previous to be the new node.
	m_first->previous = newNode;
	//Tell the new node to set its next to the old first node.
	newNode->next = m_first;
	//Mark the new node as being the first node.
	m_first = newNode;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	//Check if the index is within the bounds of the list.
	if (index < 0 || index >= m_nodeCount)
		return false;

	//If the list is empty...
	if (m_nodeCount == 0)
	{
		//...use the logic from pushback to add it to the list.
		pushBack(value);
		return true;
	}

	if (index == 0)
	{
		pushFront(value);
		return true;
	}

	Node<AnyType>* newNode = new Node<AnyType>(value);

	Node<AnyType>* iter = m_first;

	for (int i = 0; i < index; i++)
	{
		if (iter->next == nullptr)
			break;

		iter = iter->next;
	}

	newNode->next = iter;
	newNode->previous = iter->previous;

	newNode->previous->next = newNode;
	iter->previous = newNode;

	m_nodeCount++;

	return true;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::remove(const AnyType& value)
{
	Node<AnyType>* iter = m_first;

	for (int i = 0; i < m_nodeCount; i++)
	{
		if (iter == nullptr)
			return false;

		if (iter->data == value)
			break;

		iter = iter->next;
	}

	iter->next->previous = iter->previous;
	iter->previous->next = iter->next;

	delete iter;

	return true;
}
