#include "ComponentList.h"

template<class T>
ComponentList<T>::ComponentList()
{
	root = nullptr;
	top = root;
}

template<class T>
ComponentList<T>::~ComponentList()
{
	this->deleteList();
}

template<class T>
void ComponentList<T>::push(T & t)
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

template<class T>
T ComponentList<T>::pop()
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

template<class T>
T ComponentList<T>::begin () const
{
	return root->t;
}

template<class T>
T ComponentList<T>::end() const
{
	return top->t;
}

template<class T>
void ComponentList<T>::deleteList()
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


