#pragma once

template <typename T>
class ComponentList
{
	struct tNode
	{
		T t;
		tNode* nextNode;
		tNode* prevNode;
	};

	tNode* root;
	tNode* top;
public:
	ComponentList();
	~ComponentList();

	void push(T& t);
	T pop();
	T begin() const;
	T end() const;
	void deleteList();

};
