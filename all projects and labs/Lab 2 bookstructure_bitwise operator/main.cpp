//Name: Mayur Sanjay Potdar
//CWID: 50155714
//Date: 3/2/2016
//Statement: To create structure array to print book with auther and details.
//-----------------------------------------------------------------------------


#include <iostream>
#include<string>

using namespace std;

struct book //create structure
{
	char book_name[500];
	char author_name[100];
	int ISBN;
	int year;
};

int main()
{
	int	book_counter = 1;// book number only
	book b[4] = {{"\"C++ How to Program (9th Edition),","by Paul J. Deitel, Harvey M. Deitel,Prentice Hall Inc.\"", 9780136117261,  2013},
                 {"\"Algorithms in C++, Parts 1-4, Fundamentals, Data Structures, Sorting,Searching","by Robert Sedgewick, Addison Wesley,",201350882,  2009},
				 {"\"Operating Systems Internals and Design Principles - 8th Edition"," by William Stallings Prentice-Hall Inc.,", 9780133805918,  2014},
				 {"\"Introduction to Algorithms second edition"," by Thomas H. Cormen, CharlesE. Leiserson, Ronald L. Rivest and Clifford Stein, Mc Graw-Hill,", 000000000,  2009}};
				//Value given to structure array at compiletime

	cout<<"The book details are : \n";

	for(int i=0;i<4;i++)//printing the book detalis by using for loop for
	{
		cout <<"\n\nBook "<<book_counter<<" : ";
		cout<<b[i].book_name<<" "<<b[i].author_name<<" "<<b[i].ISBN<<" "<<b[i].year;	//printing the structure value in between the for loop
		book_counter++;// Number of book counter that has been increased by 1
	}

	cout<<"\n\n\n\n";
	return 0;
}
