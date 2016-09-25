#include "ComponentList.h"


template <class T>
ComponentList<T>::ComponentList()
{
	root = nullptr;
	top = root;
}

template <class T>
ComponentList<T>::~ComponentList()
{
	
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


