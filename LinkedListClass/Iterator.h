#pragma once
#include "Node.h"

template<typename AnyType>
class Iterator
{
public:
	Iterator<AnyType>();
	Iterator<AnyType>(Node<AnyType>* node);

	AnyType operator *();

	Iterator<AnyType> operator ++();
	Iterator<AnyType> operator --();

	const bool operator ==(const Iterator<AnyType>& iter);
	const bool operator !=(const Iterator<AnyType>& iter);

private:
	Node<AnyType>* m_current;
};

template<typename AnyType>
inline Iterator<AnyType>::Iterator()
{
	m_current = nullptr;
}

template<typename AnyType>
inline Iterator<AnyType>::Iterator(Node<AnyType>* node)
{
	m_current = node;
}

template<typename AnyType>
inline AnyType Iterator<AnyType>::operator*()
{
	return m_current->data;
}

template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator++()
{
	if (m_current)
	{
		Iterator<AnyType> iter = Iterator<AnyType>(m_current->next);
		m_current = m_current->next;
		return iter;
	}

	Iterator<AnyType> iter = Iterator<AnyType>(nullptr);
	return iter;
}

template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator--()
{
	if (m_current)
	{
		Iterator<AnyType> iter = Iterator<AnyType>(m_current->previous);
		m_current = m_current->previous;
		return iter;
	}

	Iterator<AnyType> iter = Iterator<AnyType>(nullptr);
	return iter;
}

template<typename AnyType>
inline const bool Iterator<AnyType>::operator==(const Iterator<AnyType>& iter)
{
	return m_current == iter.m_current;
}

template<typename AnyType>
inline const bool Iterator<AnyType>::operator!=(const Iterator<AnyType>& iter)
{
	return m_current != iter.m_current;
}
