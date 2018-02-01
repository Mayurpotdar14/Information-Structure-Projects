#include <iostream>
using namespace std;

int setBit_value(unsigned int x, int bitValue, int i);//Function declaration to check prime number
int getBit_value(unsigned int x, int i);//Function declaration to print

int setBit_value(unsigned int x, int bitValue, int i)
{
    x = x | (bitValue << i);//To check the prime value in 32 bit block
    return 0;
}

int getBit_value(unsigned int x, int i)
{
    return (x & (1<<i));// to return the prime bit value to 1
}

int main()
{
 unsigned int x;
 static const int N=35; 	//constant variable declaration through the program
 int number=1,i,prime;	// Initialization of variable as per requirement

 while(number <= N)
 	{
  		prime = 0;
  		i=2;
  		while(i <= number)	//To check module of prime number
		{
		    if(number % i == 0)	// To recheck prime number condition
		  	{
		    	prime++; //Increment the value of prime variable to 1
		   	}
		   i++;	//Increment i for next iteration
		}
	   if (prime == 1)
	    {
		     cout<< "\nPrime:" << number;
		     setBit_value(x, 1, number);
		}
		  else
  		{
      		setBit_value(x, 0, number);
  		}
  number++;	//Increment the number for next prime comparison
 }

for(i=0; i<32; i++)
     {
    	if(getBit_value(x,i)==1)
		 {
    		 cout << i;// To print prime number
		 }
	 }
 return 0;
 }
