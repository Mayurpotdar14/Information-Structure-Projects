/*-----------------------------------------------------------------------------------
  Name: Mayur Sanjay Potdar
  CWID: 50155714
  Project 3
  Title: Sorting algorithm with reversing logic

------------------------------------------------------------------------------------*/

#include<iostream>
#include<algorithm>//For reversing function
#include<stdlib.h>//For ganrating random number using standard library
#include<wait.h>


const int nsize = 100000;
using namespace std;
int array_data[nsize] = {};

class Sorting_tech
{
public:

void selection_Sort(int array_data[], int nsize)// Selection sort algorithm
{
    int npos_val;
    int ntemp;
    cout<<"\n";
    cout<<"OUTPUT:- ";
    for(int ival = 0; ival< nsize - 1; ival++)//outer loop
    {
        npos_val = ival;
        for(int jval = ival+1; jval<nsize;jval++)//inner loop
        {
            if(array_data[jval] < array_data[npos_val])
                npos_val = jval;
        }
        if(npos_val != ival)
        {
            ntemp = array_data[ival];
            array_data[ival] = array_data[npos_val];
            array_data[npos_val] = ntemp;
        }
    }

}

void insertion_Sort(int array_data[], int nsize)//Insertion sort algorithm
{
    int ntemp;
    int ival,jval;
    cout<<endl;
    cout<<"OUTPUT:- ";
    for(ival = 1; ival < nsize; ival++)//outer loop
    {
        for (jval = ival;jval >=1;jval-- )//inner loop
        {
            if (array_data[jval] < array_data[jval-1])
            {
                ntemp= array_data[jval];
                array_data[jval]= array_data[jval-1];
                array_data[jval-1] = ntemp;
            }
        }
    }
}

void bubble_sort(int array_data[], int nsize)//bubble sort algorithm
{
    int ival,jval;
    cout<<"\n";
    cout<<"OUTPUT:- ";
    for(ival = 0; ival < nsize; ival++)//outer loop
    {
        for(jval = 0;jval < nsize - ival - 1; jval++)//inner loop
        {
            if(array_data[jval] > array_data[jval + 1])
            {
                swap(array_data[jval],array_data[jval + 1]);
            }
        }
    }

}

void generateRandomNumbers(int data[],int nsize)
{
    srand((unsigned)time(0));//to generate random number

    for (int i = 0; i < nsize; i++)
    {
        array_data[i] = (rand()%100) + 1;
        cout<< array_data[i] <<" ";
    }
    cout<<"\n";
}
void reverse_random_order(int array_data[], int nsize)
{
    int ntemp;
    int ival;
    cout<<"OUTPUT:- ";
    for(ival = 0; ival< nsize/2; ival++)
    {
        reverse(array_data, array_data+nsize);
        cout<<array_data[ival]<<" ";

    }
}
void displayData(int array_data[], int nSize)
{
    for(int ival = 0; ival < nsize; ival++)
    {
        cout<<array_data[ival]<<" ";
    }
}
};
int main(void)
{
    Sorting_tech s;
    clock_t start_val,end_val;
    double nval1,nval2,nval3;//clock time comparision values
    srand(NULL);
            start_val = clock();//begin clock
            cout<<"Random Generation Function algorithm - Selection Sort:-\n";
            cout<<"INPUT:- ";
            s.generateRandomNumbers(array_data,nsize);// generate new random numbers
            s.selection_Sort(array_data,nsize);//sort data using selection sorting algorithm
            s.displayData(array_data,nsize);
            end_val = clock();//End the clock
            cout<<"\nSelection sort time :- [ "<<double(start_val-end_val)/CLOCKS_PER_SEC<<" ] Sec";
            nval1 = double(start_val-end_val)/CLOCKS_PER_SEC;

            start_val = clock();
            cout<<"\n\nRandom generation function algorithm - Insertion Sort:-\n";
            cout<<"INPUT:- ";
            s.generateRandomNumbers(array_data,nsize);// generate new random numbers
            s.insertion_Sort(array_data,nsize);// sort data using Insertion sorting algorithm
            s.displayData(array_data,nsize);
            end_val = clock();
            cout<<"\nInsertion sort time :- [ "<<double(start_val-end_val)/CLOCKS_PER_SEC<<" ] Sec\n";
            nval2 = double(start_val-end_val)/CLOCKS_PER_SEC;

            start_val = clock();//begin clock
            cout<<"\n\nRandom generation function algorithm - Bubble Sort:-\n";
            cout<<"INPUT:- ";
            s.generateRandomNumbers(array_data,nsize);// generate new random numbers
            s.bubble_sort(array_data,nsize);// sort data using bubble sorting algorithm
            s.displayData(array_data,nsize);
            end_val = clock();
            cout<<"\nBubble Sort time :- [ "<<double(start_val-end_val)/CLOCKS_PER_SEC<<" ] Sec\n";
            nval3 = double(start_val-end_val)/CLOCKS_PER_SEC;

            start_val = clock();
            cout<<"\n\nReverse number generation :- ";
            cout<<"\nINPUT:- ";
            s.generateRandomNumbers(array_data,nsize);// generate new random numbers to show the initial result
            s.reverse_random_order(array_data,nsize);// Reverse result
            end_val = clock();
            cout<<"\nReverse number generation time :- [ "<<double(start_val-end_val)/CLOCKS_PER_SEC<<" ] Sec\n\n";

            if(nval1 > nval2 && nval1 > nval3)
                cout<<"\nSelection  sort takes less time :-  "<< nval1;
            if(nval2 > nval1 && nval2 > nval3)
                cout<<"\ Insertion sort takes less time :-  "<< nval2;
            else
                cout<<"\nBubble sort takes less time :-  "<< nval3;
            cout<<"\n\n";
return 0;
}
