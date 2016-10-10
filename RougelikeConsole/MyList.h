#pragma once
#include <typeinfo>

template <typename T>
class MyList
{

private:
	struct tNode
	{
		T t;
		tNode* nextNode;
		tNode* prevNode;
	};

	tNode* root;
	tNode* top;

public:
	MyList();
	~MyList();

	void push(T& t);
	T pop();
	T begin() const;
	T end() const;
	void deleteList();
	void remove(T* t);
};

template<typename T>
inline MyList<T>::MyList()
{
	root = nullptr;
	top = root;
}

template<typename T>
inline MyList<T>::~MyList()
{
	this->deleteList();
}

template<typename T>
inline void MyList<T>::push(T & t)
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
inline T MyList<T>::pop()
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
inline T MyList<T>::begin() const
{
	return root->t;
}

template<typename T>
inline T MyList<T>::end() const
{
	return top->t;
}

template<typename T>
inline void MyList<T>::deleteList()
{
	tNode* temp;
	if (top == nullptr)
		return;
	while (top->prevNode != nullptr)
	{
		temp = top;
		top = top->prevNode;
		delete(temp);
	}
	delete(top);
}

template<typename T>
inline void MyList<T>::remove(T* t)
{
	tNode* iterator;
	iterator = root;
	while (&(iterator->t) != t || iterator->nextNode != nullptr)
	{
		iterator = iterator->nextNode;
	}
	if (&(iterator->t) == t)
	{
		tNode* temp;
		temp = iterator;
		iterator = iterator->nextNode;
		temp->prevNode->nextNode = iterator;
		iterator->prevNode = temp->prevNode;
		delete(temp);
	}
}

