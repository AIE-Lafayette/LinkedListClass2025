#pragma once

template<typename AnyType>
struct Node
{
	Node<AnyType>();
	Node<AnyType>(AnyType newData);

	AnyType data;
	Node<AnyType>* previous;
	Node<AnyType>* next;
};

template<typename AnyType>
inline Node<AnyType>::Node()
{
	previous = nullptr;
	next = nullptr;
}

template<typename AnyType>
inline Node<AnyType>::Node(AnyType newData)
{
	previous = nullptr;
	next = nullptr;
	data = newData;
}
