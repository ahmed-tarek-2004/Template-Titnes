#include <iostream>
#include <stdexcept>
#include <iomanip>  
#include <windows.h>
#include <algorithm>
#include "library.h"
using namespace std;
library l;
void underline() 
{
	for (int i = 0; i < 100; ++i) {
		cout << '-';
	}
	cout << "\n";
}

/// OPTION FUNCTION
void options()
{
	cout
		<< "|\t\t[1]-Book Insertion ." << setw(66) << " | \n"
		<< "|\t\t[2]-Book Deletion ." << setw(67) << " | \n"
		<< "|\t\t[3]-Book Search ." << setw(69) << " | \n"
		<< "|\t\t[4]-Books Sorting ." << setw(67) << " | \n"
		<< "|\t\t[5]-Books Statictics ." << setw(64) << " | \n"
		<< "|\t\t[6]-Show All Books ." << setw(66) << " | \n"
		<< "|\t\t[7]-Borrowing Book ." << setw(66) << " | \n"
		<< "|\t\t[8]-Selling A Book ."<<setw(66)<<"| \n"
		<< "|\t\t[0]-Exit ." << setw(75) << " |\n";
	underline();
}
int welcome()
{
	underline();
	cout <<setw(35)<< "|\t\t\t  ## Welcome To Library System (*^_^*) ##" << setw(37) << " | \n";
	underline();
	cout <<"| \tMain Menu :" << setw(83) << " | \n";
	options();
	cout << "Enter Your Choice : ";
	int n;
	cin >> n;
	return n;
}

/// ADDING FUNCTION
void add(int pos)
{
	pos--;
	if (pos == 0)
	{
		l.addBook_front();
	}
	else if (pos == 1)
	{
		l.addBook_End();
	}
	else if (pos == 2)
	{
		int n;
		cout << "Enter Position : ";
		cin >> n;
		l.addBook_pos(n);
	}
	cout << "\n\t\t## Added Sucessfully ##\n";
	underline();
}

/// REMOVE FUNCTION
void remove(int pos)
{
	pos--;
	if (pos == 0)
	{
		l.removeBook_front();
	}
	else if (pos == 1)
	{
		l.removeBook_End();
	}
	else if (pos == 2)
	{
		cout << "Enter The Position To Delete : ";
		int p;
		cin >> p;
		l.removeBook_pos(p);
	}
	else if (pos == 3)
	{
		l.removeBook_val();
	}
	cout << "\n\t\t## Removed Sucessfully ##\n";
	underline();
}


/// MAIN FUNCTION
int main()
{
	int pos=-1;
	while (pos)
	{
		int h;
		system("cls");
		switch (welcome())
		{
		case 1:
		underline();
			cout << "[1]-Front\n"
				<< "[2]-End\n"
				<< "[3]-Any Place\n";
			do
			{
			    underline();
				cout << "Enter Your Choice : ";
				cin >> pos;
			} while (pos <1 || pos > 3);
			add(pos);
			break;
		case 2:
			underline();
			cout << "[1]-Front\n"
				<< "[2]-End\n"
				<< "[3]-Any Place\n"
				<< "[4]-By Book Contents \n";
			do
			{
				underline();
				cout << "Enter Your Choice : ";
				//int pos;
				cin >> pos;
			} while (pos < 0 || pos > 4);
			remove(pos);
			break;
		case 3:
			h = l.find_Book();
			//underline();
			cout << "\t\t\t\t<< Book Index IS : " << h <<" . >>"<< endl;
			underline();
			cout << endl;
			break;
		case 4:
			l.sortlibrary();
			break;
		case 5:
			l.statistics();
			break;
		case 6:
			l.display_Books();
			break;
		case 7:
			l.borrow();
			break;
		case 8:
			l.buy();
			break;
		case 0:
			pos = 0;
		break;
		default:
			throw out_of_range("INVALID SYNTAX\n");
			break;
		}
		cout << "Continue ? [(1)-YES / (0)-NO] : ";
		cin >> pos;
	}
	underline();
	cout << "|\t\t\t\t## Thank You (*^_^*) ##"<<setw(46)<<"|\n";
	underline();
	return 0;
}