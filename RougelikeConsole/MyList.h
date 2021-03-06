#pragma once
#include <typeinfo>
//Macro definition for max size of the list
#define MAX_SIZE 10
//Macro function definition that return the larger value of the two
#define GET_MAX(a,b) (a > b) ? a : b

//MyList is a generic data structure list.

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
	//array of objects
	T* objects;
	//size of the list
	int size;
	//Top index of list
	int top;

	//Constructors
	MyList(int s);
	MyList();

	//Destructors
	~MyList();

	//Copy constructor
	MyList(const MyList& other);

	//Copy assignment operator overload
	MyList& operator=(const MyList& other)
	{
		if (this != &other)
		{
			this->size = other.size;
			this->top = other.top;

			if (this->objects == nullptr)
			{
				this->objects = new T[size];
			}

			for (int i = 0; i < size; i++)
				this->objects[i] = other.objects[i];
		}
		// TODO: insert return statement here
		return *this;
	}

	//Member functions
	void push(T& t);			//push Template object to top
	T pop();					//pop Template object from top
	T begin() const;			//return the first object
	T end() const;				//return the last object
	//void deleteList();
	void remove(const T& t);	//remove a specific T object that exists in the list
	int& listEnd();				//return the a refeernce to top
};

template<typename T>
inline MyList<T>::MyList() : MyList<T>::MyList(20)
{
}

template<typename T>
inline MyList<T>::MyList(int s)
{
	/*root = nullptr;
	top = root;*/
	try
	{
		if (GET_MAX(s, MAX_SIZE) > MAX_SIZE)
			throw -1;
		size = s;
	}
	catch (int exception)
	{
		size = MAX_SIZE;
	}
	
	objects = new T[size];
	top = 0;
}

template<typename T>
inline MyList<T>::~MyList()
{
	delete[] objects;
}

template<typename T>
inline MyList<T>::MyList(const MyList & other)
{
	this->size = other.size;
	this->top = other.top;

	if (this->objects == nullptr)
	{
		this->objects = new T[size];
	}
	
	for (int i = 0; i < size; i++)
		this->objects[i] = other.objects[i];
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
inline void MyList<T>::remove(const T& t)
{
	for (int iterator = 0; iterator <= top; iterator++)
	{
		if (objects[iterator] == t)
		{
			int jterator = iterator;
			while (jterator <= top)
			{
				objects[jterator] = objects[++jterator];
			}
			top--;
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

