
  
  for (int i = 0; i < n; i++)
  {


    cout << "enter the account name="; 
    getline(cin, info[i].name);
    cout << "enter the account addresss=";
    getline(cin, info[i].address);
    cout << "enter the account city=";
    getline(cin, info[i].city);
    cout << "enter the account state=";
    getline(cin, info[i].state);
    cin.ignore(); 
    
    cout << "enter the account zip=";
    cin >> info[i].zip;
    cout << "enter the account tel=";
    cin >> info[i].telNumber;
    cout << "enter the account balance=";
    cin >> info[i].accountBalance;
    cout << "enter the account lastday=";
    cin >> info[i].accountLastpayment; 
    
    
    
    
  }
  
  for (int  i = 0; i < n; i++)
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

return 0 ; 

  

}