#pragma once
template <typename T>
struct node
{
	T data ;
	int index;
	node* next;
	node* pre;
	void operator=(node<T> x)
	{
		data = x.data;
	}
};
