#include "ComponentList.h"

template<typename T>
inline ComponentList<T>::ComponentList()
{
	root = nullptr;
	top = root;
}

template<typename T>
inline ComponentList<T>::~ComponentList()
{
	this->deleteList();
}

template<typename T>
inline void ComponentList<T>::push(T & t)
{
	if (root == nullptr)
	{
		root = new tNode();
		root->t = t;
		root->nextNode = nullptr;
		root->prevNode = nullptr;
		top = root;
	}
	else
	{
		tNode* temp = new tNode();
		temp->t = t;
		temp->nextNode = nullptr;
		temp->prevNode = top;
		top = temp;
	}
}

template<typename T>
inline T ComponentList<T>::pop()
{
	if (top == root)
	{
		T temp = root->t;
		delete(root);
		return temp;
	}
	T temp = top->t;
	tNode* last = top;
	top = top->prevNode;
	delete(last);
	return temp;
}

template<typename T>
inline T ComponentList<T>::begin () const
{
	return root->t;
}

template<typename T>
inline T ComponentList<T>::end() const
{
	return top->t;
}

template<typename T>
inline void ComponentList<T>::deleteList()
{
	tNode* temp;
	while (top->prev != nullptr)
	{
		temp = top;
		top = top->prev;
		delete(temp);
	}
	delete(top);
}


