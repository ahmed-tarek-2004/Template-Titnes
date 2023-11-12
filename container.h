#ifndef container_H
#define container_H
#include<algorithm>
#include<iostream>
#include "node.h"
using namespace std;
template<class T>
class container
{
private:
	size_t size;
	node<T>* head;
	node<T>* End;
	void setindex();
	void underline();
public: 
	void Edit(T,int);
	container();
	container(T);
	~container();
	void insertfront(T);
	void insertend(T);
	void insertpos(int pos,T);
	void deletepos(int pos);
	void deletevalue(T);
	void deleteEnd();
	void deletefront();
	void display();
	T at(int pos);
	int find(T);
	void sorting();
	void Swaping(node<T> *,node<T>*);
	void merging(container);
	void reverse();
	int Know_size();
	//void merging2(container);
	//void setdata(T);
	T operator[](int i);
	node<T>*beginning()
	{
		return head;
	}
	node<T>*ending()
	{
		return End;
	}

};
template<typename T>
void container<T>::Edit(T x,int in)
{
	if (in > size || in < 0)
	{
		cout<<"Invalid Input\n";
	}
	node<T>* p = head;
	for (int i = 0; i < in; i++)
	{
		p = p->next;
	}
	p->data = x;
}
/// defalut constructor
template<typename T>
container<T>::container()
{
	End = head = NULL;
	size = 0;
}

/// Under line Function
template<typename T>
void container<T>::underline()
{
	for (int i = 0; i < 100; ++i)
	{
		cout << '-';
	}
	cout << "\n";
}

///Swaping Function
template<typename T>
void container<T>::Swaping(node<T>*x,node<T>*y)
{
	T temp;
	temp = x->data;
	x->data = y->data;
	y->data = temp;
	//swap(x->data, y->data);
}

///insert front  
template<typename T>
void container<T>::insertfront(T value)
{
	if (head == NULL)
	{
		head = new node<T>;
		head->next = head;
		End = head;
		head->pre = End;
		///data
		head->data = value;
		head->index = size;
	}
	else
	{
		node<T>* t = new node<T>;
		t->next = head;
		///data t
		t->data = value;
		t->index = size;
		head->pre = t;
		t->pre = End;
		head = t;
		End->next = head;
	}
	size++;
}

///insert end
template<typename T>
void container<T>::insertend(T value)
{
	if (head == NULL)
	{
		head = new node<T>;
		head->next = head;
		End = head;
		head->pre = End;
		///data
		head->data = value;
		head->index = size;
	}
	else
	{
		node<T>* t = new node<T>;
		End->next = t;
		t->pre = End;
		t->next = head;
		End = t;
		///End->data = c++;
		End->data = value;
		End->index = size;
	}
	size++;
}

///insert position
template<typename T>
void container<T>::insertpos(int pos, T value)
{
	node<T>* p = head;
	node<T>* t;
	if (pos <= size && pos > 0)
	{
		for (int i = 0; i < pos - 1; i++)
		{
			p = p->next;
		}
		t = new node<T>;
		///t->setdata();
		t->data = value;
		t->index = size;
		t->next = p->next;
		p->next->pre = t;
		t->pre = p;
		p->next = t;
		if (pos == size)
		{
			End = t;
		}
		size++;
	}
	else if (pos == 0)
	{
		t = new node<T>;
		t->data = value;
		t->next = p;
		p->pre = t;
		t->pre = End;
		End->next = t;
		head = t;
		size++;
		setindex();
	}
	else
	{
		underline();
		cout << "\n\t\t## Out Of Range ## \n";
		underline();
	}
}

///delete End
template<typename T>
void container<T>::deleteEnd()
{
	if (head == NULL)
	{
		underline();
		cout << "\n\t\t## Out Of Range ## \n";
		underline();
	}
	else
	{
		node<T>* p = End;
		End = End->pre;
		End->next = head;
		head->pre = End;
		delete p;
		p = NULL;
		size--;
		setindex();
	}
}

///delete Front
template<typename T>
void container<T>::deletefront()
{
	if (head == NULL)
	{
		underline();
		cout << "\n\t\t## Out Of Range ## \n";
		underline();
	}
	else
	{
		node<T>* p = head;
		head = head->next;
		head->pre = End;
		End->next = head;
		delete p;
		p = NULL;
		size--;
		setindex();
	}
}

///delete position 
template<typename T>
void container<T>::deletepos(int pos)
{
	if (pos <= size && pos >= 0)
	{
		node<T>* p = head;
		if (pos == 0)
		{
			head = head->next;
			head->pre = End;
			End->next = head;
			delete p;
		}
		else if (pos == size)
		{
			p = End;
			End = End->pre;
			head->pre = End;
			End->next = head;
			delete p;
		}
		else
		{
			for (int i = 0; i < pos; i++)
			{
				p = p->next;
			}
			node<T>* t = p->next;
			t->pre = p->pre;
			p->pre->next = t;
			delete p;
		}
		p = NULL;
		size--;
		setindex();
	}
	else
	{
		underline();
		cout << "\n\t\t## Out Of Range ## \n";
		underline();
	}
}

///delete value
template<typename T>
void container<T>::deletevalue(T x)
{
	node<T>* p = head;
	int i = -1;
	int f = 0;
	deletepos(find(x));
}

/// at function
template<typename T>
T container<T>::at(int pos)
{
	node<T>* p = head;
	int i;
	if (pos>=0&&pos<=size)
	{
		for (i = 0; i < pos - 1; i++)
		{
			p = p->next;
		}
		return (p->data);
	}
	else
	{
		underline();
		cout << "\n\t\t## Out Of Range ## \n";
		underline();
	}
}

///find function
template<typename T>
int container<T>::find(T value)
{
	node<T>* p = head;
	int i;
	int f = 0;
	for (i = 0; i < size; i++)
	{
		if (p->data==value)
		{
			f = 1;
			break;
		}
		p = p->next;
	}
	if (f)
		return i;
	else
		return -1;
}

///merge function
template<typename T>
void container<T>::merging(container x)
{
	End->next = x.beginning();
	End = x.ending();
	End->next = head;
	head->pre = End;
	setindex();
}

/// sort function
template<typename T>
void container<T>::sorting()
{
	if (head!=NULL)
	{
		T* arr = new T[size];
		node<T>* p = head;
		for (int i = 0; i < size; i++)
		{
			arr[i] = p->data;
			p = p->next;
		}
		sort(arr, arr + size);
		p = head;
		for (int i = 0; i < size; i++)
		{
			p->data = arr[i];
			p = p->next;
		}
		delete[]arr;
		setindex();
	}
	else
	{
		underline();
		cout << "\n\t\t## Out Of Range ## \n";
		underline();
	}
}

///reverse function
template<typename T>
void container<T>::reverse()
{
	if (head!=NULL)
	{
		node<T>* p = head;
		node<T>* t;
		do
		{
			swap(p->next, p->pre);
			p = p->pre;
		} while (p != head);
		swap(head, End);
	}
}
///operator array
template<typename T>
T container<T>::operator[](int index)
{
	if (size>index&&index>=0)
	{
		node<T>* p = head;
		do
		{
			if (index == p->index)
			{
				return p->data;
			}
			p = p->next;
		} while (p != head);
	}
	else
	{
		//throw out_of_range("INVALID SYNTAX\n");
		cout << "\n\t\t## NOT Found ## \n";
		//return NULL;
	}
}

///set index
template<typename T>
void container<T>::setindex()
{
	node<T>* p = head;
	for (int i = 0; i < size; i++)
	{
		p->index= i;
		p = p->next;
	}
}

///Return Size
template<typename T>
int container<T>::Know_size()
{
	return size;
}
///display function
template<typename T>
void container<T>::display()
{
	if (head !=NULL&&size!=0)
	{
		setindex();
		node<T>* p = head;
		do
		{
			cout << endl << endl;
			cout << "Book [" << p->index+1 << "]-" << "\n";
			cout << p->data << " ";
			p = p->next;
		} while (p != head);
	}
	else
	{
		underline();
		cout << "\n\t\t## Empty Container ## \n";
		underline();
		//
		//	throw out_of_range("\n\t\t## Empty Container ## \n");
	}
}
template<typename T>
container<T>::~container()
{
	node<T>*p,*q=NULL;
	p = head;
	for (int i = 0; i < size; i++)
	{
		q = p;
		p = p->next;
		delete q;
	}
}
#endif
