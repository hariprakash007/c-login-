#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void login();
void registration();
void forget();

int main(){
	int c;
	cout<< "\t\t\t___________________________________________________________\n\n\n";
	cout<< "\t\t\t                       Welcome to Login Page                \n\n\n";
	cout<<"\t\t\t_________________________      MENU                           \n\n";
	cout<<"                                                                     \n\n";
	cout<<"\t | Press 1 to LOGIN                           |"<< endl;
	cout<<"\t | Press 2 to REGISTER                        |"<< endl;
	cout<<"\t | Press 3 if you forget your password        |"<< endl;
	cout<<"\n\t\t\t Please enter your choice :   ";
	cin>> c;
	cout<<endl;

    switch(c){
    	case 1:
    		login();
    		break;
    		
    	case 2:
		     registration();
			 break;
		case 3:
		    forget();
			break;
			
		case 4:
		    cout<<"\t\t\t Thank You for Staying \n\n";
			break;
		default:
			system("cls");
		     cout<<"\t\t\t Please Select from the options givrn above \n"<<endl;
		     main();
		    	  			 	
	}
}
    void login()
    {
    	int count;
    	string userId, password, id, pass;
    	system("cls");
    	cout<<"\t\t\t USERNAME ";
    	cin>>userId;
    	cout<<"\t\t\t PASSWORD ";
    	cin>> password;
    	
    	ifstream input("records.txt");
    	
    	while(input>>id>>pass)
    	{
    		if (id==userId && pass==password){
    			count = 1;
    			system("cls");
			}
		}
		input.close();
		
		if (count==1){
			cout<<userId<<"\n your LOGIN is Successfull \n Thanks for Logging in !";
			main();
		}else{
			cout<<"\n LOGIN ERROR \n Please check your username and password\n";
			main();
		}
	}
    
    void registration() {
    	string ruserId, rpassword, rid, rpass;
    	system("cls");
    	cout<<"\t\t\t Enter the username : ";
    	cin>>ruserId;
    	cout<<"\t\t\t Enter the password : ";
    	cin>>rpassword;
    	
    	ofstream f1("records.txt", ios::app);
    	f1<<ruserId<<" "<<rpassword<<endl;
    	system("cls");
    	cout<<"\n\t\t\t Registration is successfull! \n";
    	main();
    	
	}
	void forget()
{
	int option;
	system("cls");
	cout<<"\t\t\t You forget the password? No worries \n";
	cout<< "Press 1 to search your id bu username "<<endl;
	cout<<"Press 2 to go back to the main menu "<< endl;
	cout<<"\t\t\t Enter your choice :";
	cin>> option;
	
	switch(option)
	{
		case 1 :{
			int count = 0;
			string suserId, sId,spass;
			cout<<"\n\t\t Enter the username which you remembered : ";
			
			ifstream f2("records.txt");
			while(f2>>sId>>spass){
				if(sId==suserId){
					count=1;
				}
			}
			f2.close();
			if(count==1){
				cout<<"\n\n Your account is found! \n";
				cout<<"\n\n Your Password is : " <<spass;
				main();
			}else{
				cout<<"\n\t Sorry! your account is not found! \n";
				main();
				 
			}
			break;
		}
		
		case 2:
			{
				main();
			}
			default:
				cout<<"\t\t\t Wrong choice ! Please try again ";
				forget();
	}
}




















