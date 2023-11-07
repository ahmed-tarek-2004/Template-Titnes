#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include <string>
using namespace std;
class book
{
	string author;
	string ISBN;
	string gener;
	string title;
	static int c;
	int statue;
	double price;
	void underline();
public:
	book();
	bool Statue();
	void set();
	string Title() { return title; }
	string Author() { return author; }
	string Isbn() { return ISBN; }
	string Gener() { return gener; }
	void setstatue(int);
	bool operator==(const book& other);
	void operator=(const book& other);
	bool operator>(const book& ob);
	bool operator<(const book& ob);
	friend ostream& operator<<(ostream& out, book& ob);
	friend istream& operator >>(istream& in, book& ob);
};
#endif