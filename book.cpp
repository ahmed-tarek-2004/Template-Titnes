#include "book.h"
#include "container.h"
#include<iomanip>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int book::c = 0;
book::book()
{
	author = ISBN = gener = title = "";
	price = statue = 0;
}
void book::underline()
{
	for (int i = 0; i < 100; ++i) 
	{
		cout << '-';
	}
	cout << "\n";
}
bool book:: operator==(const book& other)
{
	if (other.author == author && other.ISBN == ISBN && gener == other.gener && title == other.title && other.statue == statue && other.price == price)
	{
		return 1;
	}
	else
		return 0;
}
void book::operator=(const book& other)
{
	author = other.author;
	ISBN = other.ISBN;
	gener = other.gener;
	title = other.title;
	price = other.price;
	statue = other.statue;
}
void book::setstatue(int value)
{
	statue = value;
}
bool book::Statue()
{
	return statue;
}
bool book::operator>(const book& ob)
{
	cout << "Which Element Do You Compare By : \n"
		<< "[1]-Title\n"
		<< "[2]-Author\n"
		<< "[3]-Gener\n"
		<< "[4]-ISBN\n"
		<< "[5]-Price\n"
		<< "[6]-Statue\n"
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
			return title > ob.title;
			break;
		case 2:
			return author > ob.author;
			break;
		case 3:
			return gener > ob.gener;
			break;
		case 4:
			return ISBN > ob.ISBN;
			break;
		case 5:
			return price > ob.price;
			break;
		case 6:
			return statue > ob.statue;
			break;
		}
}
bool book::operator<(const book& ob)
{
		cout << "Which Element Do You Compare By : \n"
			<< "[1]-Title\n"
			<< "[2]-Author\n"
			<< "[3]-Gener\n"
			<< "[4]-ISBN\n"
			<< "[5]-Price\n"
			<< "[6]-Statue\n"
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
			return title < ob.title;
			break;
		case 2:
			return author < ob.author;
			break;
		case 3:
			return gener < ob.gener;
			break;
		case 4:
			return ISBN < ob.ISBN;
			break;
		case 5:
			return price < ob.price;
			break;
		case 6:
			return statue < ob.statue;
			break;
		}

}
void book::set()
{
	cin >> author >> gener >> ISBN >> title >> statue >> price;
}
istream& operator>>(istream& in, book& ob)
{
	cout << "Enter Book Title : ";
	in >> ob.title;
	cout << "Enter Book Gener : ";
	in >> ob.gener;
	cout << "Enter Book ISBN : ";
	in >> ob.ISBN;
	cout << "Enter Book Author : ";
	in >> ob.author;
	cout << "Book Statue :\n"
		<< "[0]-Available\n"
		<< "[1]-Borrowed\n"
		<< "Enter Your Choice : ";
	in >> ob.statue;
	cout << "Enter Book Price : ";
	cin >> ob.price;
	return in;
}
ostream& operator<<(ostream& out, book& ob)
{
	ob.underline();
	out << "\t\t\t\t"<< "The Title Of The Book IS : " << ob.title << " \n";
	ob.underline();
	out << "\t\t\t\t" << "The Author Of  " << "\"" << ob.title << "\"" << " IS : " << ob.author << "\n";
	ob.underline();
	out << "\t\t\t\t" << "The ISBN : " << ob.ISBN << "\n";
	ob.underline();
	out<<"\t\t\t\t" << "The Gener IS : " << ob.gener << " \n";
	ob.underline();
	out << "\t\t\t\t" << "Book Price IS : " << ob.price <<" L.E"<< "\n";
	ob.underline();
	out << "\t\t\t\tStatue : ";
	if (ob.statue == 0)
		out << "Available .";
	else
	{
		out << "Borrowed .";
	}
	out << setw(20) <<"\n";
	ob.underline();
	return out;
}