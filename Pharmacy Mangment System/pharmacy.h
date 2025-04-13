#ifndef PHARMACY
#define PHARMACY
#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <string>
#include <cstring>

#include <stdlib.h>
#include <iomanip>
#include <vector>

using namespace std;
string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}




class pharmacy
{
    private :
        struct meds
{


    char drug_id[5];
    double drugid;
    char drug_name [30];
    char Drug_Amount[30] ;
    char Price [30];
    char Type_of_Package [30];
    char Shelf_Number [30];


};
    void validateName(string &name)
    {
        cin.clear();
        cin.sync();
        getline(cin, name);
        while (name.find_first_of("0123456789!@#$%^&*()_+:{}/-+=") != -1)
        {
            cout << "Error ";
            cout << "No digits are allowed in name." << endl;
            cout << "Please re-enter a valid name:" << endl;
            cin.clear();
            cin.sync();
            getline(cin, name);
        }
    }
public :
    void insert()
 {

   meds ph;
   int flag=0;
   ofstream file;
   file.open("meds.txt",std::ios_base::app);
   do{
 	cout<<"   ENTER THE Drug Id :>> ";
	 cin>>ph.drug_id;

	 cout<<"  ENTER THE NAME :>> ";
	 cin>>ph.drug_name;
	 cout<<"  ENTER THE AMOUNT :>> ";
	 cin>>ph.Drug_Amount;
	 cout<<"  ENTER THE PRICE :>> ";
	 cin>>ph.Price;
	 cout<<"  ENTER THE TYPE :>> ";
	 cin>>ph.Type_of_Package;
	 cout<<"  ENTER SHELF NUMBER :>> ";
	 cin>>ph.Shelf_Number;

     file<<ph.drug_id<<"|"<<ph.drug_name<<"|"<<ph.Drug_Amount<<"|"<<ph.Price<<"|"<<ph.Type_of_Package<<"|"<<ph.Shelf_Number<<endl;
	 cout<<"	PRESS (0) TO FINISH INSERT DATA OR PRESS ANY KEY TO COUNTINE \n\n";
     cin>>flag;
     }
     while(flag!=0);

 	file.close();
 }

    void view()
    {   meds mymeds;
        system("cls");
        fstream file;
        file.open("meds.txt", ios::in | ios::out | ios::app);
        cout << "|************|************|************|********|******************|****************|\n";
        cout << "|  DRUG ID   | DRUG NAME  | DRUG AMOUNT| PRICE  | TYPE OF PACKAGE  | Shelf Number   |\n";
        while (!file.eof())
        {
        cout << "|------------|------------|------------|--------|------------------|----------------|\n";

            file.getline(mymeds.drug_id , 100 , '|') ;
            file.getline(mymeds.drug_name, 100 , '|');
            file.getline(mymeds.Drug_Amount , 100 , '|');
            file.getline(mymeds.Price , 100 , '|');
            file.getline(mymeds.Type_of_Package , 100 , '|') ;
            file.getline(mymeds.Shelf_Number , 100 , '\n') ;

            cout <<setw(8)<< mymeds.drug_id <<setw(14) << mymeds.drug_name <<setw(12)<< mymeds.Drug_Amount <<setw(12)<< mymeds.Price<<setw(10)<<mymeds.Type_of_Package <<setw(18)<<mymeds.Shelf_Number<<endl;

        }
        cout << "|***********************************************************************************|\n";
        file.close();
        cin.ignore();
        cin.ignore();

    }

    meds Searchbill (){
        fstream file;
        string name ;
    meds mymeds;
    meds blank = {"",0,"","","","",""} ;
            bool flag = 0;
            validateName( name );
            file.open("meds.txt" , ios::in);
            while (!file.eof())
            {
            file.getline(mymeds.drug_id , 100 , '|') ;
            file.getline(mymeds.drug_name, 100 , '|');
            file.getline(mymeds.Drug_Amount , 100 , '|');
            file.getline(mymeds.Price , 100 , '|');
            file.getline(mymeds.Type_of_Package , 100 , '|') ;
            file.getline(mymeds.Shelf_Number , 100 , '\n') ;
                if (mymeds.drug_name == name )
                {
                    flag = 1;
                    file.close();
                    mymeds.drugid = strtod (mymeds.drug_id,NULL);
                    return mymeds;
                    }
            }
            if (flag == 0){
                    file.close();

                    cout <<"###############- Med is Not found - #############"<<endl;
                    return blank;


            }
        }



       void Search ()
    {   fstream file;
        system("cls");
        cout << "CHOOSE ONE OF THE THREE OPTIONS :"<<endl;
        cout << "1- DRUG ID.\n2- DRUG NAME\n3- back.\n";
        int i;
        cin >>i;
        while (true)
        {
            if (cin.fail() ||  !(i<=7 && i>0))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid choice :" << endl;
                cin >> i ;
            }
            else break;
        }
        switch (i)
        {

        case 1 :
        {

            meds mymeds;
            system("cls");
            file.open("meds.txt" , ios::in | ios::out | ios::app);
            cout << "ENTER DRUG ID :\n";
            double ID ;
            bool flag = 0;
            cin>> ID ;
            while (true)
            {
                if (cin.fail() ||  ID <= 0)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "please Enter a Valid ID :" << endl;
                    cin >> ID ;
                }
                else break;
            }
            while (!file.eof())
            {
            file.getline(mymeds.drug_id , 100 , '|') ;
            file.getline(mymeds.drug_name, 100 , '|');
            file.getline(mymeds.Drug_Amount , 100 , '|');
            file.getline(mymeds.Price , 100 , '|');
            file.getline(mymeds.Type_of_Package , 100 , '|') ;
            file.getline(mymeds.Shelf_Number , 100 , '\n') ;
                if (ID == strtod(mymeds.drug_id , NULL))
                {
                    flag = 1 ;
                    cout <<"=============================================\n";
                    cout <<"DRUG ID : "<< mymeds.drug_id << "\nDRUG NAME : " << mymeds.drug_name << "\nDRUG AMOUNT : "<< mymeds.Drug_Amount <<"\nPRICE : " << mymeds.Price <<"\nTYPE OF PACKAGE : "<<mymeds.Type_of_Package <<"\nShelf Number : "<<mymeds.Shelf_Number<<endl;
                    cout <<"=============================================\n";
                }
            }
            if (flag == 0) cout <<"************** - Not found - ***********"<<endl;
        }

        file.close();
        cin.ignore();
        cin.ignore();
        break;

        case 2 :
        {
             meds mymeds;
            system("cls");
            cout << "ENTER DRUG NAME :\n";
            string name ;
            bool flag2 = 0;
            validateName( name );
            file.open("meds.txt" , ios::in);
            while (!file.eof())
            {
            file.getline(mymeds.drug_id , 100 , '|') ;
            file.getline(mymeds.drug_name, 100 , '|');
            file.getline(mymeds.Drug_Amount , 100 , '|');
            file.getline(mymeds.Price , 100 , '|');
            file.getline(mymeds.Type_of_Package , 100 , '|') ;
            file.getline(mymeds.Shelf_Number , 100 , '\n') ;
                if (mymeds.drug_name == name )
                {
                    flag2 = 1;
                    cout <<"=============================================\n";
                    cout <<"DRUG ID : "<< mymeds.drug_id << "\nDRUG NAME : " << mymeds.drug_name << "\nDRUG AMOUNT : "<< mymeds.Drug_Amount <<"\nPRICE : " << mymeds.Price <<"\nTYPE OF PACKAGE : "<<mymeds.Type_of_Package <<"\nShelf Number : "<<mymeds.Shelf_Number<<endl;
                    cout <<"=============================================\n";
                }
            }
            if (flag2 == 0) cout <<"###############- Not found - #############"<<endl;
        }
        file.close();
        break;


        case 3 :
            return;
        }
cin.ignore();
    }

    void binarySearchForPK ()
    {   fstream file;


        vector <meds> mymeds;
        meds sorttemp;
        meds temp;
        int counter = 0;
        file.open("meds.txt" , ios::in);
        while (true)
        {

            file.getline(temp.drug_id, 100 , '|') ;
            file.getline(temp.drug_name, 100 , '|');
            file.getline(temp.Drug_Amount , 100 , '|');
            file.getline(temp.Price , 100 , '|');
            file.getline(temp.Type_of_Package , 100 , '|') ;
            file.getline(temp.Shelf_Number , 100 , '\n') ;
            temp.drugid = atof(temp.drug_id);
            mymeds.push_back(temp);


            if (file.eof())
                break;
            else
                counter++;
        }
        file.close();
        int w;

        ///////////////////////// Sorting ///////////////
        int i , j ;
        for(i=0; i<counter+1; ++i)
        {
            for(j=0; j <= counter+1 ; ++j)
                if(mymeds[i].drugid <mymeds[j].drugid)
                {
                    sorttemp=mymeds[i];
                    mymeds[i]=mymeds[j];
                    mymeds[j]=sorttemp;

                }
        }
for(w=0; w < mymeds.size(); w++)
        cout<<"-----------"<<mymeds[w].drugid<<"----------\n";
        cout << "Enter the drug ID to search with Binary Search Method :" <<endl;
        double id;
        cin >> id ;
        while (true)
        {
            if (cin.fail() ||  id <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid ID :" << endl;
                cin >> id ;
            }
            else break;
        }
        int posetion = binarySearch( mymeds, 0 , counter , id) ;
        if ( posetion != -1 )
        {

            cout << "##################_Found _###############"<<'\n'<< endl;
            cout <<"DRUG ID : "<< mymeds[posetion].drug_id << endl;
            cout <<"DRUG NAME : "<< mymeds[posetion].drug_name << endl;
            cout <<"DRUG AMOUNT : " << mymeds[posetion].Drug_Amount << endl;
            cout <<"PRICE : " << mymeds[posetion].Price << endl;
            cout <<"TYPE OF PACKAGE : "<< mymeds[posetion].Type_of_Package << endl;
            cout <<"SHELF NUMBER : "<< mymeds[posetion].Shelf_Number << endl;
        }
        else cout << "***************** Not Found ******************"<<endl;
        cin.ignore();
        cin.ignore();
        return;

    }

///////////////////////////////////////////////////////////////////////////////////////////////
    int binarySearch(vector<meds> p, int l, int r, double x)
    {
        while (l <= r) {
        int m = l + (r - l) / 2;
         if (p[m].drugid == x)
            return m;
         if (p[m].drugid < x)
            l = m + 1;

        else
            r = m - 1;


    }
    return -1;
    }

    void deleteing ()
    {
        fstream file;
        system("cls");
        fstream file1;
        file.open("meds.txt" , ios::in | ios::out | ios::app);
        file1.open("delete.txt" ,  ios::out);
        int flag = 0;
        int deleted = 0;
        cout << "ENTER DRUG ID YOU WANT TO DELETE :"<<endl;
        double id ;
        cin >> id ;
        while (true)
        {
            if (cin.fail() ||  id <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid ID :" << endl;
                cin >> id ;
            }
            else break;
        }
        meds mymeds;
        while (!file.eof())
        {

            file.getline(mymeds.drug_id , 100 , '|') ;
            file.getline(mymeds.drug_name, 100 , '|');
            file.getline(mymeds.Drug_Amount , 100 , '|');
            file.getline(mymeds.Price , 100 , '|');
            file.getline(mymeds.Type_of_Package , 100 , '|') ;
            file.getline(mymeds.Shelf_Number , 100 , '\n') ;
            file1.seekg(0 , ios::end);
            if (strtod(mymeds.drug_id,NULL) != id)
            {
                if(file1.tellp() == 0)
                    file1  << mymeds.drug_id<< "|" <<mymeds.drug_name<< "|" << mymeds.Drug_Amount << "|" << mymeds.Price << "|" << mymeds.Type_of_Package<<"|"<<mymeds.Shelf_Number;
                else
                    file1 <<"\n"<< mymeds.drug_id<< "|" <<mymeds.drug_name<< "|" << mymeds.Drug_Amount << "|" << mymeds.Price << "|" << mymeds.Type_of_Package<<"|"<<mymeds.Shelf_Number;

            }
            else
            {
                flag = 1;
                deleted = 1;
            }
        }
        file.close();
        file1.close();
        remove("meds.txt");
        rename("delete.txt" , "meds.txt" );
        if (flag)
            cout << "==> Deleted <==" <<endl;
        else cout <<" ==> Not Found <==" <<endl;

    }

    void updating (double id ,int x)
    {
        fstream file;
        system("cls");
        fstream file1;
        file.open("meds.txt" , ios::in | ios::out | ios::app);
        file1.open("Update.txt" ,  ios::out);
        int flag = 0;

        meds mymeds;
        while (!file.eof())
        {
             file.getline(mymeds.drug_id , 100 , '|') ;
            file.getline(mymeds.drug_name, 100 , '|');
            file.getline(mymeds.Drug_Amount , 100 , '|');
            file.getline(mymeds.Price , 100 , '|');
            file.getline(mymeds.Type_of_Package , 100 , '|') ;
            file.getline(mymeds.Shelf_Number , 100 , '\n') ;
            file1.seekg(0 , ios::end);

            if (strtod(mymeds.drug_id,NULL) != id && strlen(mymeds.drug_id)!=0)
            {
                if(file1.tellp() == 0)
                    file1  << mymeds.drug_id<< "|" <<mymeds.drug_name<< "|" << mymeds.Drug_Amount << "|" << mymeds.Price << "|" << mymeds.Type_of_Package<<"|"<<mymeds.Shelf_Number;
                else
                    file1  <<"\n"<< mymeds.drug_id<< "|" <<mymeds.drug_name<< "|" << mymeds.Drug_Amount << "|" << mymeds.Price << "|" << mymeds.Type_of_Package<<"|"<<mymeds.Shelf_Number;

            }
            else if (strlen(mymeds.drug_id)==0){}
            else
            {


                fstream file;
                file.open( "meds.txt" , ios::in | ios::out | ios::app );

                if(file1.tellp() == 0)

                file1  << mymeds.drug_id<< "|" <<mymeds.drug_name<< "|" << stoi(mymeds.Drug_Amount)-x << "|" << mymeds.Price << "|" << mymeds.Type_of_Package<<"|"<<mymeds.Shelf_Number;

                else
                    file1  <<"\n"<< mymeds.drug_id<< "|" <<mymeds.drug_name<< "|" << stoi(mymeds.Drug_Amount)-x << "|" << mymeds.Price << "|" << mymeds.Type_of_Package<<"|"<<mymeds.Shelf_Number;




            }

        }
        file.close();
        file1.close();
        remove("meds.txt");
        rename("Update.txt" , "meds.txt");
cin.ignore();

        }
    void updating ()
    {
        string temp;
        fstream file;
        system("cls");
        fstream file1;
        file.open("meds.txt" , ios::in | ios::out | ios::app);
        file1.open("Update.txt" ,  ios::out);
        int flag = 0;
        cout << "ENTER DRUG ID YOU WANT TO  UPDATE :"<<endl;
        double id ;
        cin >> id ;

        while (true)
        {
            if (cin.fail() ||  id <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid ID :" << endl;
                cin >> id ;
            }
            else break;
        }
        meds mymeds;
        while (!file.eof())
        {
             file.getline(mymeds.drug_id , 100 , '|') ;
            file.getline(mymeds.drug_name, 100 , '|');
            file.getline(mymeds.Drug_Amount , 100 , '|');
            file.getline(mymeds.Price , 100 , '|');
            file.getline(mymeds.Type_of_Package , 100 , '|') ;
            file.getline(mymeds.Shelf_Number , 100 , '\n') ;
            file1.seekg(0 , ios::end);

            if (strtod(mymeds.drug_id,NULL) != id && strlen(mymeds.drug_id)!=0)
            {
                if(file1.tellp() == 0)
                    file1  << mymeds.drug_id<< "|" <<mymeds.drug_name<< "|" << mymeds.Drug_Amount << "|" << mymeds.Price << "|" << mymeds.Type_of_Package<<"|"<<mymeds.Shelf_Number;
                else
                    file1  <<"\n"<< mymeds.drug_id<< "|" <<mymeds.drug_name<< "|" << mymeds.Drug_Amount << "|" << mymeds.Price << "|" << mymeds.Type_of_Package<<"|"<<mymeds.Shelf_Number;

            }
            else if (strlen(mymeds.drug_id)==0){}
            else
            {
                cout << "==> Found <==" << endl;
                cout << "drug id  : " << mymeds.drug_id<<endl;
                cout << "drug name : " << mymeds.drug_name<<endl;
                cout << "drug amount: " << mymeds.Drug_Amount<<endl;
                cout << "price: " << mymeds.Price<<endl;
                cout << "type of package : " << mymeds.Type_of_Package<<endl;
                cout << "shelf number : " << mymeds.Shelf_Number<<endl;
                cout << " Now you will Update this Data"<<endl;
                meds xmeds ;
tt :
                xmeds.drugid = strtod(xmeds.drug_id,NULL);
                fstream file;
                file.open( "meds.txt" , ios::in | ios::out | ios::app );
                int i = 0 ;
                while (true)
                {
                    cout << "ENTER THE NEW DRUG ID :"<<endl;
                    cin >> xmeds.drug_id;
                    while (true)
                    {
                        if (cin.fail() ||  xmeds.drug_id<= 0)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "please Enter a Valid ID :" << endl;
                            cin >> xmeds.drug_id ;
                        }
                        else break;
                    }
                     if (xmeds.drugid == mymeds.drugid){
                    meds mymeds;

                    while (!file.eof())
                    {
            file.getline(mymeds.drug_id , 100 , '|') ;
            file.getline(mymeds.drug_name, 100 , '|');
            file.getline(mymeds.Drug_Amount , 100 , '|');
            file.getline(mymeds.Price , 100 , '|');
            file.getline(mymeds.Type_of_Package , 100 , '|') ;
            file.getline(mymeds.Shelf_Number , 100 , '\n') ;

                        if (xmeds.drugid == mymeds.drugid)
                            i = 1;

                    }

                    }
                    if (i == 1 )
                    {
                        cout <<"THIS DRUG ID IS ALREADY EXIST .... \n";
                        goto tt;
                    }
                    else break;

                }
                cin.ignore();

        cout << "Enter NEW DRUG NAME : ";
        validateName(temp);
        strcpy(xmeds.drug_name, temp.c_str());
        cout << "Enter NEW DRUG AMOUNT : ";
        cin>>xmeds.Drug_Amount;
        fflush(stdin);
        cout << "Enter NEW PRICE : ";
        cin>>xmeds.Price;
        fflush(stdin);
        cout << "Enter NEW TYPE OF PACKAGE : ";
        cin >> xmeds.Type_of_Package;
        cout << "Enter NEW SHELF NUMBER : ";
        cin >> xmeds.Shelf_Number;

                if(file1.tellp() == 0)
                {
                    file1 << xmeds.drug_id<< "|" << xmeds.drug_name << "|" << xmeds.Drug_Amount << "|" << xmeds.Price << "|" << xmeds.Type_of_Package<<"|"<<xmeds.Shelf_Number;
                }
                else
                {
                    file1 << "\n"  << xmeds.drug_id<< "|" << xmeds.drug_name << "|" << xmeds.Drug_Amount << "|" << xmeds.Price << "|" << xmeds.Type_of_Package<<"|"<<xmeds.Shelf_Number;
                }
                system("cls");
                cout << "==> Updated Successfully <=="<<endl;
                flag = 1;
            }
        }
        file.close();
        file1.close();
        remove("meds.txt");
        rename("Update.txt" , "meds.txt");
        if (!flag)
            cout <<" ==> Not Found <== " <<endl;
        cout << "\n \n \n \n \n "<<endl;
        cout << "press (Y/y) if you want to update another drug id \nany thing else if you want to continue.   ";
                char ch;
                fflush(stdin);
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                    updating();

    }

    void billing (){
        system("cls");
   vector <meds> medlist ;
   char flag  = 'y';
    meds temp;
    string temps;
    int amount ;
    view();
    double total = 0  ;
    while (flag == 'y'){
    cout<<"ENTER DRUG NAME:";
    temp = Searchbill();
    cout<<"enter the amount:";
    cin>> amount ;


    updating(temp.drugid,amount);
    temps = to_string(amount);
    strcpy(temp.Drug_Amount,temps.c_str());
    temp.drugid = strtod(temp.drug_id,NULL);
    medlist.push_back(temp);
    total += strtod(temp.Price,NULL) * amount;
    cout << " do you want to continue?? (y/n):";
    cin >> flag ;

    if (flag != 'y')
    break;

        }
    cout<<"PRODUCT NAME \t\t\t\t PRICE \t\t\t\t QUANTITY \n";

    for (int i = 0 ;i<medlist.size();i++){
        cout<<medlist[i].drug_name<<"\t\t\t\t\t"<<medlist[i].Price<<"RM\t\t\t\t\t\t"<<medlist[i].Drug_Amount<<"\n";
    }
    cout<<"\n\n\n"<<"TOTAL:"<<total<<"RM"<<endl;
    cin.ignore();
    cin.ignore();
        }
    };

#endif // PHARMACY
