#include "container.h"
#include <algorithm>
#include <string>
#include <iostream>
#include "library.h"
#include "book.h"
using namespace std;
void library:: addBook_front()
{
	book b;
	cin >> b;
	ob.insertfront(b);
}
void library:: addBook_End()
{
	book b;
	cin >> b;
	ob.insertend(b);
}
void library::addBook_pos(int index)
{
	book b;
	cin >> b;
	ob.insertpos(index,b);
}
void library::removeBook_front()
{
	ob.deletefront();
}
void library:: removeBook_End()
{
	ob.deleteEnd();
}
void library:: removeBook_pos(int index)
{
	ob.deletepos(index);
}
void library:: removeBook_val()
{
	book b;
	cin >> b;
	ob.deletevalue(b);
}
book library::operator[](int i)
{
	return ob[i];
}
void library:: sortlibrary()
{
	if (ob.Know_size()>0)
	{
		cout<< "Which Element Do You Compare By : \n"
			<< "[1]-Title\n"
			<< "[2]-Author\n"
			<< "[3]-Gener\n"
			<< "[4]-ISBN\n"
			<< "Enter Your Choice  : ";
		int c;
		do
		{
			cin >> c;
			if (c < 0 || c>6)
			{
				cout << "Enter Right Enter : ";
				cin >> c;
			}
		} while (c < 0 || c>6);
		switch (c)
		{
		case 1:
			sortBYtitle();
			break;
		case 2:
			sortBYauthor();
			break;
		case 3:
			sortBYgener();
			break;
		case 4:
			sortBYisbn();
			break;
		}
		cout << "\n\t\t## Sorted Sucessfully ##\n";
	}
	else
	{
		underline();
		cout << "\n\n\t\t## Empty Container ## \n";
		underline();
	}
}
void library::reverselibrary()
{
	ob.reverse();
}
/*void library::mergelibrary()
{
	ob.merging(b);
}*/
int library:: find_Book()
{
	if (ob.Know_size()>0)
	{
		book b;
		string s;
		cout << "Search BY : \n"
			<< "[1]-Title .\n"
			<< "[2]-Author .\n"
			<< "[3]-ISBN .\n"
			<< "[4]-Gener .\n";
		cout << "Enter Your Choice : ";
		int n;
		cin >> n;
		int f = 0;
		int i;
		switch (n)
		{
		case 1:
			f = 0;
			cout << "Enter Book Title To Research : ";
			cin >> s;
			for ( i = 0; i < ob.Know_size(); i++)
			{
				if (s == ob[i].Title())
				{

					cout << "\n\t\t\t\t## Found ##\n";
					book b = ob[i];
					cout << b << endl;
					f = 1;
					break;
				}
			}
			if (!f)
			{
				underline();
				cout << "\n\t\t## Sorry Book Not Found ##\n";
				underline();
			}
			else
				return i;
			break;
		case 2:
			f = 0;
			cout << "Enter Book Author To Research : ";
			cin >> s;
			for ( i = 0; i < ob.Know_size(); i++)
			{
				if (s == ob[i].Author())
				{
					cout << "\t\t\t\t## Found ##\n";
					book b = ob[i];
					underline();
					cout << "Book index is : " << i<<endl;
					underline();
					cout << b << endl;
					f = 1;
					break;
				}
			}
			if (!f)
			{
				underline();
				cout << "\n\t\t## Sorry Book Not Found ##\n";
				underline();
			}
			else
				return i;
			break;
		case 3:
			f = 0;
			cout << "Enter Book ISBN To Research : ";
			cin >> s;
			for ( i = 0; i < ob.Know_size(); i++)
			{
				if (s == ob[i].Isbn())
				{
					cout << "\t\t\t\t## Found ##\n";
					book b = ob[i];
					cout << b << endl;
					f = 1;
					break;
				}
			}
			if (!f)
			{
				underline();
				cout << "\n\t\t## Sorry Book Not Found ##\n";
				underline();
			}
			else
				return i;
			break;
		case 4:
			f = 0;
			cout << "Enter Book Gener To Research : ";
			cin >> s;
			for (i = 0; i < ob.Know_size(); i++)
			{
				if (s == ob[i].Gener())
				{
					cout << "\n\t\t## Found ## \n";
					book b = ob[i];
					cout << b << endl;
					f = 1;
					break;
				}
			}
			if (!f)
			{
				underline();
				cout << "\n\t\t## Sorry Book Not Found ##\n";
				underline();
			}
			else
				return i;
			break;
		}
	}
	else
	{
		underline();
		cout << "\n\t\t## Empty Container ## \n";
		underline();
	}
}
void library:: at_Book(int index)
{
	ob.at(index);
}

void library::buy()
{
	if (ob.Know_size()>0)
	{
		cout << endl;
		ob.display();
		cout << "Which Book You Will Sell ";
		int n;
		do
		{
			cout << ", Enter Book Number : ";
			cin >> n;
		} while (n<0 || n>ob.Know_size());
		ob.deletepos(n);
		underline();
		cout << "\n\t\t\t\t\tBook Selled Sucessfully\n";
		underline();
	}
	else
	{
		underline();
		cout << "\n\t\t## Empty Container ## \n";
		underline();
	}
}
void library::borrow()
{
	if (ob.Know_size()>0)
	{
		int c = 1;
		bool f = 0;
		int index = 0;
		node<book>* p = ob.beginning();
		do
		{
			if (p->data.Statue() == 0)
			{
				cout << "\n[" << c << "]- \n";
				cout << p->data << endl;
				f++;
				underline();
			}
			p = p->next;
			c++;
		} while (p != ob.beginning());

		if (!f)
		{
			cout << "\n\n\t\t>> Sorry No Books Available {{{(>_<)}}} <<\n";
			underline();
			return;
		}
		do
		{
			cout << "Enter Your Choice : ";
			cin >> c;
		} while (c > ob.Know_size() || c < 1);

		book b = ob[c - 1];
		b.setstatue(1);
		ob.Edit(b, c - 1);
		underline();
		cout << "\n\t\t>> Borrowd (*^_^*)<<\n";
		underline();
		cout << endl;
	}
	else
	{
		underline();
		cout << "\n\t\t## Empty Container ## \n";
		underline();
	}
}
void library::statistics()
{
	//underline();
	cout << endl;
	cout << "Number of ALL Books IS " << ob.Know_size() << endl;
	int bb = 0, aa = 0;
	int size = ob.Know_size();
	//* P = new book[size];
	book* b = new book[size];
	book* A = new book[size];
	for (int i = 0; i < size; i++)
	{
		if (ob[i].Statue() == 0)
		{
			A[aa++] = ob[i];
		}
		else if(ob[i].Statue()==1)
		{
			b[bb++] = ob[i];
		}
	}
	underline();
	for (int i = 0; i < aa; i++)
	{
		cout << A[i].Title() << " => Available\n";
	}
	underline();
	for (int i = 0; i < bb; i++)
	{
		cout << b[i].Title() << " => Borrowed\n";
	}
	underline();
	//delete [] P;
	delete [] b;
	delete [] A;

}
void library::sortBYauthor()
{
	node<book>* it = ob.beginning();
	do
	{
		node<book>* it2 = it->next;
		do
		{
			if (it->data.Author() > it2->data.Author())
				ob.Swaping(it, it2);
			it2 = it2->next;
		} while (it2 != ob.beginning());
		it = it->next;
	} while (it != ob.ending());
}
void library::sortBYgener()
{
	node<book>* it = ob.beginning();
	do
	{
		node<book>* it2 = it->next;
		do
		{
			if (it->data.Gener() > it2->data.Gener())
				ob.Swaping(it, it2);
			it2 = it2->next;
		} while (it2 != ob.beginning());
		it = it->next;
	} while (it != ob.ending());
}
void library::sortBYtitle()
{
	node<book>* it = ob.beginning();
	do
	{
		node<book>* it2 = it->next ;
		do
		{
			if (it->data.Title() > it2->data.Title())
				ob.Swaping(it, it2);
			it2 = it2->next;
		} while (it2 != ob.beginning());
		it = it->next;
	} while (it !=ob.ending());
}
void library::sortBYisbn()
{
	node<book>* it = ob.beginning();
	do
	{
		node<book>* it2 = it->next;
		do
		{
			if (it->data.Isbn() > it2->data.Isbn())
				ob.Swaping(it, it2);
			it2 = it2->next;
		} while (it2 != ob.beginning());
		it = it->next;
	} while (it != ob.ending());
}
void library::underline()
{
	for (int i = 0; i < 100; ++i)
	{
		cout << '-';
	}
	cout << "\n";
}
void library::display_Books()
{
	ob.display();
}