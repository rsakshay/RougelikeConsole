#pragma once
#include <typeinfo>

template <typename T>
class MyList
{

private:
	/*struct tNode
	{
		T t;
		tNode* nextNode;
		tNode* prevNode;
	};

	tNode* root;
	tNode* top;*/
	
public:
	T* objects;
	int size;
	int top;

	MyList();
	~MyList();

	void push(T& t);
	T pop();
	T begin() const;
	T end() const;
	//void deleteList();
	void remove(T* t);
	int& listEnd();
};

template<typename T>
inline MyList<T>::MyList()
{
	/*root = nullptr;
	top = root;*/
	size = 10;
	objects = new T[size];
	top = 0;
}

template<typename T>
inline MyList<T>::~MyList()
{
	delete[] objects;
}

template<typename T>
inline void MyList<T>::push(T & t)
{
	if (top == size - 1)
		abort();
	objects[top++] = t;

	//if (root == nullptr)
	//{
	//	root = new tNode();
	//	root->t = t;
	//	root->nextNode = nullptr;
	//	root->prevNode = nullptr;
	//	top = root;
	//}
	//else
	//{
	//	tNode* temp = new tNode();
	//	temp->t = t;
	//	temp->nextNode = nullptr;
	//	temp->prevNode = top;
	//	top = temp;
	//}
}

template<typename T>
inline T MyList<T>::pop()
{
	if (top <= 0)
		abort();
	return objects[--top];
	//if (top == root)
	//{
	//	T temp = root->t;
	//	delete(root);
	//	return temp;
	//}
	//T temp = top->t;
	//tNode* last = top;
	//top = top->prevNode;
	//delete(last);
	//return temp;
}

template<typename T>
inline T MyList<T>::begin() const
{
	
	return objects[0];
}

template<typename T>
inline T MyList<T>::end() const
{
	return objects[top];
}

//template<typename T>
//inline void MyList<T>::deleteList()
//{
//	tNode* temp;
//	if (top == nullptr)
//		return;
//	while (top->prevNode != nullptr)
//	{
//		temp = top;
//		top = top->prevNode;
//		delete(temp);
//	}
//	delete(top);
//}

template<typename T>
inline void MyList<T>::remove(T* t)
{
	for (int iterator = 0; iterator <= top; iterator++)
	{
		if (&objects[iterator] == t)
		{
			int jterator = iterator;
			while (jterator <= top)
			{
				objects[jterator] = objects[++jterator];
			}
			--top;
		}

	}
	//tNode* iterator;
	//iterator = root;
	//while (&(iterator->t) != t || iterator->nextNode != nullptr)
	//{
	//	iterator = iterator->nextNode;
	//}
	//if (&(iterator->t) == t)
	//{
	//	tNode* temp;
	//	temp = iterator;
	//	iterator = iterator->nextNode;
	//	temp->prevNode->nextNode = iterator;
	//	iterator->prevNode = temp->prevNode;
	//	delete(temp);
	//}
}

template<typename T>
inline int & MyList<T>::listEnd()
{
	// TODO: insert return statement here
	return top;
}

