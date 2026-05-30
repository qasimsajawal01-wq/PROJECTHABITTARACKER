#include<iostream>
#include <string.h>

using namespace std ;

struct  Account 
{
    string accountNumber; 
    double balance; 
    double interestRate; 
    double averageMonthlybalance; 
};


int main ()
{

  Account det1 ; 

  det1.accountNumber = "acz3352-422112"; 
  det1.averageMonthlybalance = 4217.55; 
  det1.interestRate = 0.04 ; 
  det1.balance = 4521.774; 


   cout << "the account number is =" << det1.accountNumber  << endl; 
   cout << "the avergae balance =" << det1.averageMonthlybalance << endl; 
   cout <<  "the interest is ="<< det1.interestRate << endl ; 
   cout <<  "balance is =" << det1.balance << endl ; 

  return 0 ; 



}