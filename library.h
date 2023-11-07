#ifndef LIBRARY_H
#define LIBRARY_H
#include "container.h"
#include <iostream>
#include "book.h"
using namespace std;
class library
{
private:
	int size;
	container<book>ob;
	void setstatue(int);
	void underline();
	void sortBYauthor();
	void sortBYtitle();
	void sortBYisbn();
	void sortBYgener();
public:
	void addBook_front();
	void addBook_End();
	void addBook_pos(int);
	void removeBook_front();
	void removeBook_End();
	void removeBook_pos(int);
	void removeBook_val();
	void sortlibrary();
	void reverselibrary();
	void mergelibrary(library);// add library and every library books
	int find_Book();
	void at_Book(int);
	void borrow();
	void buy();
	void statistics();
	void display_Books();
	book operator[](int i);
};
#endif