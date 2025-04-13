#include "pharmacy.h"

int main()
{   pharmacy Pharmacy;
    system("cls");

    string pass;
    cout<<"\t\t\t$Welcome to Konoz pharmacy $\t"<<endl;
    cout<<"\t\t\t\t***************\n"<<endl;
    cout<<"\t\t\t$=====Hello my dear user======$\t"<<endl;
    cout<<"\t\t\t        ENTER YOUR PASSWORD "<<endl;
     cout<<"\t\t\t$============Welcome=========$\t"<<endl;
 cin>>pass;
    if(pass=="sec12"){
            while (true){
    system("cls");
    cout<<"\n\n";

    cin.clear();
    int i;


    cout<<" \t\t\t ENTER '1' TO INSERT DRUG .\n \t\t\t ENTER '2' TO VIEW CONTENT.\n \t\t\t ENTER '3' TO SEARCH DRUG. \n \t\t\t ENTER '4' TO BINARY SEARCH. \n \t\t\t ENTER '5' TO DELETE DRUG .\n \t\t\t ENTER '6' TO UPDATE DATA. \n \t\t\t  ENTER '7' TO BILL \n\n OR PRESS '0' TO (EXIT) "<<'\n'<<endl;

     cout<<"YOUR CHOICE IS : ";
     cin>>i;

    switch (i){
    case 1:
            Pharmacy.insert();
break;
case 2:
            Pharmacy.view();

break;
case 3:
            Pharmacy.Search();

break;
case 4:
            Pharmacy.binarySearchForPK();

break;
case 5:
            Pharmacy.deleteing ();

break;
case 6:
            Pharmacy.updating();

break;
case 7:
            Pharmacy.billing();
break;
case 0:
           return 0;
break;
default :
cout<<"enter a valid choice Press Enter to Continue";
cin.ignore();


    }

   } }
    else
        main();

    return 0;
}
