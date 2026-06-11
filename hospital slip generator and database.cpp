// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include<cstdlib>
using namespace std;

class account_query
{
private:
    char account_number[20];
    char firstName[10];
    char lastName[10];
    float total_Balance;
public:
    void read_data();
    void show_data();
    void write_rec();
    void read_rec();
    void search_rec();
    void edit_rec();
    void delete_rec();
};
void account_query::read_data()
{
    cout<<"\nEnter Account Number: ";
    cin>>account_number;
    cout<<"Enter First Name: ";
    cin>>firstName;
    cout<<"Enter Last Name: ";
    cin>>lastName;
    cout<<"Enter Balance: ";
    cin>>total_Balance;
    cout<<endl;
}
void account_query::show_data()
{
    cout<<"Account Number: "<<account_number<<endl;
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Current Balance: Rs.  "<<total_Balance<<endl;
    cout<<"-------------------------------"<<endl;
}
void account_query::write_rec()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}
void account_query::read_rec()
{
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    cout<<"\n****Data from file****"<<endl;
    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
        {
            show_data();
        }
    }
    infile.close();
}
void account_query::search_rec()
{
    int n;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));
    show_data();
}
void account_query::edit_rec()
{
    int n;
    fstream iofile;
    iofile.open("record.bank", ios::in|ios::binary);
    if(!iofile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to edit: ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
    show_data();
    iofile.close();
    iofile.open("record.bank", ios::out|ios::in|ios::binary);
    iofile.seekp((n-1)*sizeof(*this));
    cout<<"\nEnter data to Modify "<<endl;
    read_data();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void account_query::delete_rec()
{
    int n;
    ifstream infile;
    infile.open("record.bank", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n Enter Record Number to Delete: ";
    cin>>n;
    fstream tmpfile;
    tmpfile.open("tmpfile.bank", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("record.bank");
    rename("tmpfile.bank", "record.bank");
}
struct patient
{
    char name[50];
    char lastname[50];
    int age;
    char Gender[50];
    long long int contactnbr;
    int hospitalnbr;
    
} s[1000] ;
void laboratory();
void Patient();
void printslip();
void emergency();
void ward_data_main_function();
int main () 
{
	//timestamp start--------
	time_t now = time(0);
    char* dt = ctime(&now);
    //timestamp code ends--------
	int option;
  
  string line;
  int i=1;
  long int j;
  long int pass=252825;
  for(i=1;i<=3;i++) 
  {
  system ("color 3F");
  	system("cls");
    //below this to open front page code is used-----------------------------
     ifstream myfile ("frontpage.txt");
              if (myfile.is_open())
              {
              while ( getline (myfile,line) )
                {
                  cout << line << '\n';
                }
               myfile.close();
              }
              else 
                cout << "Unable to open file"; 
         //front page end -----------------------------
		
		//option code
		      
              cout<<"ENTER THE OPTION NBR YOU WANT TO CHOOSE : ";
              cin>> option;
     if(option==1)
      {
  	    system("cls");
		  //patientoptions 
             ifstream myfile ("patientoption.txt");
             //below this to open second page code for patients option-----------------------------
             if (myfile.is_open())
             {
             while ( getline (myfile,line) )
                {
                  cout << line << '\n';
                }
                  myfile.close();
             }
              else cout << "Unable to open file";    //patienoption
              
              //patien options code end here------------------------------
              
              //***********************************************************************************************
              //*                         PATIENT OPTIONS                                                     *
              //***********************************************************************************************
      int optionpo;
	  cout<<"Enter an option nbr to Enter respective Option :";
      cin>>optionpo;
      switch(optionpo)
        {
      	case 1:
      	   system("cls");
		   emergency();   //defining the function related to emergency
	     cin.get();
	     break;
		case 2:
	     
	       {
	       	int k;
			   system("cls");
	       	   Patient();
               
			     
			cout<<"Press Enter to continue :";
			cin.get();
			cin.get();
			
			
			
			break;
		  }
         	    
		case 3:
	     cout<<"Blood bank :";   //blood bank
	    break;
		case 4:
	    cout<<"Doctor's avaiablitiy :"; //doctors timetable
	    break;
		case 5:
	    cout<<"Pharmacy :";
	    break;
		case 6:
	    system("cls");
		laboratory();
	   
	    break;
		case 7:
		cout<<"Donations :";  //donations
		break;
		case 8:
		cout<<"map :"; // map
		break;
		case 9:
		exit(0); 
		  
	    }
    
   }
     //***********************************************************************************************************
     //                             option for database of employess,doctors below                               *
     //***********************************************************************************************************
     
  if(option==2)   //option of database for doctors
    {
  	system("cls");
  	//------------------------------------------------PASSWORD THINGS---------------------------------------------------------------
        cout<<"**************************************************************************************************************"<<endl;
        cout<<"*                               Enter Password to Gain access to database                                    *"<<endl;
        cout<<"**************************************************************************************************************"<<endl;
    cout<<endl;
    cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"                           Please Enter Password :";
	cin>>j;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"*********************************************************************************************************************"; 
           switch(j){
		   
           case 252825:
            {
	         system("cls");
  	         ifstream myfile ("doctordatabase.txt");
              //below this is code of doctors options-----------------------------
               if (myfile.is_open())
              {
               while ( getline (myfile,line) )
                {
                  cout << line << '\n';
                }
                  myfile.close();
              }
               else cout << "Unable to open file";
     
              int optiondd;
              cout<<endl<<"choose nbr to Enter following option :";
              cin>>optiondd;
              switch(optiondd)
                    {
     	             case 1:
     	             cout<<"doctors database :";
     	             break;
		             case 2:
     	             cout<<"Awards Detail ";
     	             break;
		             case 3:
     	             ward_data_main_function();
     	             cin.get();
     	             break;
		             case 4:
     	             exit(0);
	
                    } 
             }
	
           default: 
                     {
                     cout<<endl;	
	                 cout<<"incorrect password !!!!!!!!!"<<endl;
	                 cout<<"if you want to quit Enter 4!!!"<<endl;
	                 cout<<"If you want to continue Enter 1!!! "<<endl;
	                 cout<<"Your choice :";
	                 cin>>i;
					    switch(i)
					    {
					 
					     case 1:
					 	 i++;
					 	 
					 	cout<<"Starting from beginning press enter ";
					 	cin.get();
					     break;
						 case 2:
					 	 i=2;
				        }
					 
	                 }
					 }
    }
	
	
  }

  
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  cin.get();
  return 0;
}



//-----------------------------------------functions declarlartion below---------------------------------------
//*
//-------------------------------------------------------------------------------------------------------------

void Patient()
{
	cout<<"*******************************************************************************************************************"<<endl;
	cout<<"---------------------------------- Please Enter Data carefully! ---------------------------------------------------"<<endl;
	cout<<"*******************************************************************************************************************"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	int i=1;
	ofstream Patientfile("patientdata.txt");
	while(i==1)
		{
	
	    int k;
	    time_t now = time(0);
        char* dt = ctime(&now);
	    
	    cout<<"Enter your Patient nbr :";
	    cin>>k;
		cout << "For Patient nbr " << k << ":" << endl;
        Patientfile<<"Patient nbr "<< k <<": "<<endl ;
        cout << "Enter First name: ";
        Patientfile << "Enter First name: ";
        cin>>s[k].name;
        Patientfile<<s[k].name<<endl;
        cout << "Enter Last name: ";
        Patientfile << "Enter Last name: ";
        cin>>s[k].lastname;
		Patientfile<<s[k].lastname<<endl;
        cout << "Enter age: ";
        Patientfile<< "Enter age: ";
		cin>>s[k].age;
		Patientfile << s[k].age<<endl;
        cout << "Enter gender: ";
        Patientfile<< "Enter Gender name: ";
		cin>>s[k].Gender;
		Patientfile << s[k].Gender<<endl; 
        cout << "Enter contact nbr : ";
        Patientfile<< "Enter contact nbr: ";
		cin>>s[k].contactnbr;
		Patientfile << s[k].contactnbr<<endl;
    	cout << endl;
        Patientfile<<endl;
        Patientfile<<"This slip is generated at :"<<dt;
        Patientfile<<"-----------------------------------------------------------------------------------------------";
        Patientfile<<endl;
		cout<<"Menu"<<endl;        
        cout<<"1. To Make new slip :"<<endl;
        cout<<"2. To print this slip :"<<endl;
        cout<<"3. To go back to main menu :"<<endl;
	    cout<<"Enter choice :";
		cin>>i;
	    switch(i)
	    {
		case 1:
	    	i=1;
	    	break;
	    case 2:
	    	printslip();
	    	cout<<"Your data store successfully !"<<endl;
	    	cout<<"This slip is generated at :"<<dt;   
  cout<<"*******************************************************************************************************************"<<endl;
	    	break;
	    case 3:
	    	i=2;
	    	break;}
	}
	
} 
void patientdisplay()
{
	int i;
    cout<<"Which Patient you want to see data :";
    cin>>i;
    cout<<"******************************************************************************************************************"<<endl;
    cout<<"----------------------------- SLIP Generated successfully --------------------------------------------------------"<<endl;
    cout<<"******************************************************************************************************************"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
    

        cout << "\nPatient number : " << i << endl;
        cout << "Name: " << s[i].name <<"                       "<<"Last Name: "<<s[i].lastname<<endl;
        cout <<endl;
        cout <<endl;
		cout << "Age: " << s[i].age <<"                         "<<"Gender: "<<s[i].Gender<<endl;
		cout << "Contact nbr: " << s[i].contactnbr << endl;        
		cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Doctor's Advice below :";
		cout <<endl;
        cout <<endl;
        cout <<endl;
        cout <<endl;
        cout <<endl;
        cout <<endl;
        cout <<endl;
        cout <<endl;
        cout <<endl;
		
		
    cout<<"********************************************************************************************************************";    

}
void printslip()
{
	
	int i;
	cout<<"To print slip Enter your hospital nbr :";
	cin>>i;
	system("cls");
    cout<<"******************************************************************************************************************"<<endl;
    cout<<"----------------------------- SLIP Generated successfully --------------------------------------------------------"<<endl;
    cout<<"******************************************************************************************************************"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
        
		
		
		
		cout << "\nPatient number : " << i << endl;
        cout << "Name: " << s[i].name <<"                       "<<"Last Name: "<<s[i].lastname<<endl;
        cout <<endl;
        cout <<endl;
		cout << "Age:  " << s[i].age  <<"                          "<<"Gender: "<<s[i].Gender<<endl;
		cout << "Contact nbr: " << s[i].contactnbr << endl;        
		cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Doctor's Advice below :";
		cout <<endl;
        cout <<endl;
        cout <<endl;
        cout <<endl;
        cout <<endl;
        cout <<endl;
    
}
void departmentselect()
{
	cout<<"Enter your department";
}

//-----------------------------------------------------------------------------------------------------------------------------
//										Emergency function
//-----------------------------------------------------------------------------------------------------------------------------
void emergency()
{
    system ("color 4F");
	cout<<"*******************************************************************************************************************"<<endl;
	cout<<"------------------------------ We pray for your Disease May Allah help you ----------------------------------------"<<endl;
	cout<<"*******************************************************************************************************************"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	string nbr;
	char name[100];
	cout<<"Enter name :";
	cin>>name;
	cout<<"Contact nbr :";
	cin>>nbr;
    cout<<endl;
    cout<<endl;
    cout<<"following are the contact nbrs of the doctors :"<<endl;
    cout<<"Doctor MUBEEN (MEDICAL SPECIALIST) : 03125256235"<<endl;
    cout<<"Doctor HAMZA KHAN (PSYCOLOGIST) : 03306760320"<<endl;
    cout<<"Doctor AZAN UMER (orthopaedic) : 03053471328"<<endl;
    cout<<"Doctor HASSAN (Surgeon) : 03415634423 "<<endl;
    cout<<"Ambulance : 1515 "<<endl;
    cin.get();
}
void laboratory()
{
	system ("color 6F");
	int x;
	cout<<"*******************************************************************************************************************"<<endl;
	cout<<"------------- Welcome to laboratory please don't touch anything and keep laboratory clean -------------------------"<<endl;
	cout<<"*******************************************************************************************************************"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"              Select the menu:"<<endl;
    cout<<"        -----> 1. Test"<<endl;
    cout<<"        -----> 2. Results"<<endl;
	cout<<endl;
    cout<<"Option choice :";
    cin>>x;
    cout<<endl;
    cout<<endl;
    cout<<"*******************************************************************************************************************"<<endl;
    switch(x)
	{
	
    case 1:
    	{
    		int y;
    		cout<<"Please select type of The lab test you want to take  :"<<endl;
    		cout<<"1.Complete Blood Count"<<endl;
    		cout<<"2.Prothrombin Time"<<endl;
    		cout<<"3.ANA (autoimmune diseases)"<<endl;
    		cout<<"4.PTT (Partial Thromboplastin Time)"<<endl;
    		cout<<"5.ESR (Sedimentation Rate)"<<endl;
    		cout<<endl;
    		cout<<endl;
    		cout<<"Enter choice: ";
			cin>>y;
			cout<<endl;
			cout<<endl;
			cout<<"Sorry for less details we will try to update our software so that your laboratry slip will print online ";
    		cin.get();
    		switch(y){
			
    		case 1:
    			cout<<"contact counter nbr 1 :"<<endl;
    			break;
    		case 2:
    			cout<<"contact counter nbr 2 :"<<endl;
    			break;
		    case 3:
    			cout<<"contact counter nbr 3 :"<<endl;
    			break;
    		case 4:
    			cout<<"contact counter nbr 4 :"<<endl;
    			break;
		    case 5:
    			cout<<"contact counter nbr 5 :"<<endl;
    			break;
		   }
		}
		case 2:
			cout<<"All reports result are available in Counter nbr 10 please bring your slip with you thanks!!!!!!!!!";
			cin.get();
			cin.get();
			
    }


}
void ward_data_main_function()
{
	account_query A;
    int choice;
    cout<<"***Employee Information System***"<<endl;
    while(true)
    {
        cout<<"Select one option below ";
        cout<<"\n\t1-->Add record to file";
        cout<<"\n\t2-->Show record from file";
        cout<<"\n\t3-->Search Record from file";
        cout<<"\n\t4-->Update Record";
        cout<<"\n\t5-->Delete Record";
        cout<<"\n\t6-->Quit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            A.write_rec();
            break;
        case 2:
            A.read_rec();
            break;
        case 3:
            A.search_rec();
            break;
        case 4:
            A.edit_rec();
            break;
        case 5:
            A.delete_rec();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\nEnter corret choice";
            exit(0);
        }
    }
}

