//---------------------------------------------------------------------------
//Name: Mayur Sanjay Potdar
//CWID: 50155714
//Title: to implement selection  and  insertion  sorting  algorithm
//---------------------------------------------------------------------------

#include<iostream>
#include<stdlib.h>//Random number generation library

const int nsize = 1000;
using namespace std;
int data[nsize] = {};

class Sorting_tech
{
 public:
    void selectionSort(int data[], int nsize);
    void insertionSort(int data[], int nsize);
    void generateRandomNumbers(int data[],int nsize);
    int displayData(int data[], int nSize);
};

void Sorting_tech::selectionSort(int data[], int nsize)
{
    int npos_val;
    int ntemp;
    cout<<"\n";
    cout<<"OUTPUT:- ";
    for(int ival = 0; ival< nsize - 1; ival++)
    {
        npos_val = ival;
        for(int jval = ival+1; jval<nsize;jval++)
        {
            if(data[jval] < data[npos_val])
                npos_val = jval;
        }
        if(npos_val != ival)
        {
            ntemp = data[ival];
            data[ival] = data[npos_val];
            data[npos_val] = ntemp;
        }
    }
}

void Sorting_tech:: insertionSort(int data[], int nsize)
{
    int ntemp;
    int ival,jval;
    cout<<"\n";
    cout<<"OUTPUT:- ";
    for(ival = 1; ival < nsize; ival++)
    {
        for (jval = ival;jval >=1;jval-- )
        {
            if (data[jval] < data[jval-1])
            {
                ntemp= data[jval];
                data[jval]= data[jval-1];
                data[jval-1] = ntemp;
            }
        }
    }

}

void Sorting_tech::generateRandomNumbers(int data[],int nsize)//Random generation function
{
    srand((unsigned)time(0));

    for (int i = 0; i < nsize; i++)
    {
        data[i] = (rand()%10000) + 1;
        cout<< data[i] <<" ";
    }
    cout<<"\n";
}
int Sorting_tech::displayData(int data[], int nSize)//Displa random generated values
{
    for(int i=0;i<nsize;i++)
    {
        cout<<data[i]<<" ";
    }
}
int main(void)
{
    Sorting_tech s;
    srand(NULL);
            cout<<"Random generation function with Selection Sort:-\n";
            cout<<"INPUT:- ";
            s.generateRandomNumbers(data,nsize);// generate new random numbers
            s.selectionSort(data,nsize);//sort data using selection sorting
            s.displayData(data,nsize);


            cout<<"\n\nRandom generation function with Insertion Sort:-\n";
            cout<<"INPUT:- ";
            s.generateRandomNumbers(data,nsize);// generate new random numbers
            s.insertionSort(data,nsize);// sort data using insertion sort
            s.displayData(data,nsize);

            cout<<"\n\n";
return 0;
}
