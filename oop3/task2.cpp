#include<iostream>
#include <string>

using namespace std ;

struct Account {


    string name ; 
    string address ; 
    string city , state; 
    int zip ; 
    int telNumber ;
    int accountBalance ; 
    string accountLastpayment ; 
}; 

int main ()
{

    const int n = 3; 
  Account info [n] ; 
  
  for (int i = 1; i <= n; i++)
  {
    cout << "enter the account name="; 
    getline(cin, info[i].name);
    cout << "enter the account addresss=";
    getline(cin, info[i].address);
    cout << "enter the account city=";
    getline(cin, info[i].city);
    cout << "enter the account state=";
    getline(cin, info[i].state);

    
    cout << "enter the account zip=";
    cin >> info[i].zip;
    cout << "enter the account tel=";
    cin >> info[i].telNumber;
    cout << "enter the account balance=";
    cin >> info[i].accountBalance;
    cout << "enter the account lastday=";
    cin >> info[i].accountLastpayment;
    cin.ignore();    
  }
  
  for (int  i = 1; i <= n; i++)
{
    cout << "the account name is " << " " << info[i].name << endl ;
    cout << "the account address is " << " " << info[i].address << endl ;
    cout << "the account city is " << " " << info[i].city << endl ; 
    cout << "the account  state is " << " " << info[i].state << endl ;
    cout << "the account zip is " << " " << info[i].zip << endl ;
    cout << "the account telnumber is " << " " << info[i].telNumber << endl ;  
    cout << "the account balance is " << " " << info[i].accountBalance << endl ;
    cout << "the account last date payment is " << " " << info[i].accountLastpayment << endl ;

}

   cout << "enter the thing you want to edit" << endl ; 
   cout << "1.name" << endl ; 
    cout << "2.address" << endl ; 
    cout << "3.city" << endl ; 
    cout << "4.state" << endl ; 
    cout << "5.zip " << endl ; 
    cout << "6.telNumber" << endl ; 
    cout << "7.accountBalance" << endl ; 
    cout << "8.accountLastpayment" << endl ; 


    // char choice ; 
    // cin >> choice ; 
    
    // switch (choice)
    // {
    // case 1 :

        
    // break;
    
    // default:
    //     break;
    // }

    
   


  


return 0 ; 

  

}