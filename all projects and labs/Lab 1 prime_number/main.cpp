//Mayur Sanjay Potdar
//Lab 1
//Title:- Print prime integer between 2 to 1000 by using array index value.
//Date:- 01/28/2016
//------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
 static const int N=1000; 	//constant variable declaration throught the program
 int number=1,i,prime;	// Initilization of veriable as per requirement
 int arr[N];	//array initilization with constant value

 while(number <= N)
 	{
  		prime = 0;
  		i=2;
  		while(i <= number)	//To check module of prime number
		{
		    if(number % i == 0)	// To check prime number condition
		  	{
		    	prime++; //Increment the value of prime variable to 1
		   	}
		   i++;	//Increment i for next iteration
		}
	   if (prime == 1)
	    {
		     arr[number]=1;	//Assing index value to one if number is prime
		}
        else
  		{
      		arr[number]=0;//Assing index value to one if number is prime
  		}
  number++;	//Increment the number for next prime comparision
 }
  int j=2;
  while(j<=N)	//To print the prime number
  {
     if(arr[j]==1)	//To check the prime number from index value
     {
      cout<<"prime no "<< j <<"\t\t";	//Print all prime number
     }
      j++;
  }
 return 0;
 }
