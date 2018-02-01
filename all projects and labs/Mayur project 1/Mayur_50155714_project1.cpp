/*-----------------------------------------------------------------------------------------------------------
Name: Mayur Sanjay Potdar
CWID: 50155714
Project 1
Title: Linked list vs Array Performance
--------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>//To perform random number generation function by using library

using namespace std;
const int N = 10000;//Constant variable declaration
int rand (void);//Rand function declaration
int n_arr[N]= {};//Array with empty values:- with constant variabale

class project1 // Class of array and l;inked list
{
private:
    struct Project1//Structure for linked list
	{
		int n_value;// Value to be add to the linked list
		Project1 * pnext;// Linked list next pointer
	};

    int nStop_bit, nStart_bit, nC_time, nIn_time;

public:

void LL_execution()// Linked list function
{
    int ival,jval;
	nStart_bit = clock(); //begin the clock
	Project1 *pList = NULL; // BaSe_Pointer Creation

	for(ival = 1; ival <= N; ival++)
	{
		Project1* nCurr = new Project1;
		nCurr->n_value = rand()%10000;
		nCurr->pnext = pList;
		pList=nCurr;
	}//linked list creation with initialization

	nStop_bit = clock();	//Clock freeze
	nC_time = (nStop_bit - nStart_bit);	//Linked List creation with initialization time
	cout << "Linked List :- \n";//Caluclation of creation, initilization and total time
	cout << "Creation Time:- " << nC_time <<"     ";
    nStart_bit = clock();////begin the clock
    for(jval=ival=0; ival < sizeof(n_arr)/sizeof(n_arr[0]) ; ival++)//It looks for the index till the end of the linked list
	{
		Project1* nCurr = new Project1;
		nCurr->n_value = rand()%10000;	//random values between 0 and 10000 are given to the linked list variable
		nCurr->pnext = NULL;
		Project1 * pPrev=pList;

		if(n_arr[ival]==0)// Insetion values at each head of index value
		{
			nCurr->pnext=pList;
			pList=nCurr;
			continue;
		}
		jval=1;

		while(n_arr[ival]>1 && jval< n_arr[ival])//traversal til end of index position
		{
			pPrev=pPrev->pnext;
			jval++;
		}
		nCurr->pnext=pPrev->pnext;
		pPrev->pnext=nCurr;

	}
	nStop_bit = clock(); //clock Freeze
	nIn_time = (nStop_bit-nStart_bit);	//Linked List insertion time

	cout<<"Insertion Time:- " << nIn_time <<" ";//total time for insrslidon
	cout<<"\nLinked List (Total time = Creation + Insertion ):- "<<nC_time + nIn_time<<"\n\n";
}

void A_execution()//Array function
{
    int ival,jval;
	nStart_bit = clock(); //clock start
	int *n_arr =new int [N + (sizeof(n_arr)/sizeof(n_arr[0]))];	//Array creation with extra size for insertion
	for(ival = 0 ; ival < N ; ival++)
	{
		n_arr[ival] = rand()%10000;	//storing random value between 0 and 10000
	}
	nStop_bit = clock(); //clock freeze
	nC_time = (nStop_bit-nStart_bit); //array creation and initialization time
	cout << "Array :- \n";
	cout<<"Creation time:- " << nC_time <<"     ";
    nStart_bit = clock(); //clock start
	for(ival = 0 ; ival < sizeof(n_arr)/sizeof(n_arr[0]) ; ival++)//Insert array value at specific index position
	{
		for(jval = N + ival; jval > n_arr[ival]; jval--)
		{
			n_arr[jval] = n_arr[jval-1];
		}
		n_arr[n_arr[ival]]=rand()%10000;	//storing random values between 0 and 10000
	}

	nStop_bit = clock();//clock freeze
	nIn_time = (nStop_bit-nStart_bit); //array insertion time in millisecosnds
	cout << "Insertion time:- " << nIn_time <<"\n";//
	cout<<"Array (Total time = Creation + Insertion):- "<<nC_time + nIn_time<<"\n\n";
	delete[] n_arr;	//deletion of array
}
void generateRandomNumbers(int n_arr[],int N)//Random number generation function
{
    srand((unsigned)time(0));//to generate random number

    for (int i = 0; i < N; i++)
    {
        n_arr[i] = (rand()%1000) + 1;
    }
}
};

int main()
{
    project1 p;
	cout<<"1) We are generating data (N = "<< N <<")\n";
	//call random number fuctions
    p.generateRandomNumbers(n_arr,N);
   	cout<<"2) New data are being added\n";
	cout<<"3) Processing time:\n\n";
	p.A_execution();	//arrays using class object
	p.LL_execution();	//function linked listusing class object
 	return 0;
}
