#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
const int adminPassword=1106;
class bank
{
	private:
		int accountNumber;
		string accountHolderName;
		int userPassword;
		double accountBalance;
		char accountType;
		int balance=1; 
	public:
		void read();
		void display();
		int account_Number();
		void deposit_money(int d);
		void withdraw_money(int d);
		void balance_Enquiry();
		void modify_Password(int n)
		{
			userPassword=n;
		}
		int user_Password();
		int account_balance();
		int get_balance();
};
int bank:: get_balance()
{
	return balance;
}
// void bank::account_Number()
// {
// 	fstream file;
// 	file.open("userDetails.txt",ios::in|ios::out);
// 	if(accountNumber!=10001)
// 	{
// 		while(!file.eof())
// 		{
// 			if(file.eof())
// 			{
// 				accountNumber++;
// 			}
// 		}
// 	}
// 	else
// 	{
// 		accountNumber++;
// 	}
// }
void bank::read()
{	
	cout<<"\n\nEnter your account number: ";
	cin>>accountNumber;
	cout<<"Account holder name: ";
	cin.ignore();
	getline(cin,accountHolderName);
	cout<<"Enter Your Secure Password: ";
	cin>>userPassword;
	cout<<"Which account you want to open Savings or Current(c/s): ";
	cin>>accountType;
	int amt;
	switch(accountType)
	{
		case 'S':
		case 's':	cout<<"Enter initial amount: "; 
				cin>>amt;
				if(amt>=10000)
				{
					accountBalance=amt;

				}
				else
				{
					balance=false;
					cout<<"Your Account can not be created, minimum amount should be 10000\n";
				}
				break;
		case 'c':
		case 'C':	cout<<"Enter initial amount: "; 
				cin>>amt;
				if(amt>=25000)
				{
				 	accountBalance=amt;

				}
				else
				{
					balance=false;
					cout<<"Your Account can not be created, minimum amount should be 25000\n";
				}
				break;
		default :	cout<<"Enter right input";
		}

}
void bank::display()
{
	cout<<"\nAccount number:\t"<<accountNumber;
	cout<<"\nAccount Holder Name:\t"<<accountHolderName<<"\nAccount Type"<<accountType<<endl;

}
void bank::deposit_money(int d)
{
	accountBalance+=d;
	cout<<"\nAccount balance should be "<<accountBalance;
}
void bank::withdraw_money(int d)
{
	switch(accountType)
	{
		case 's':
		case 'S':	if(accountBalance-d>300)
					{
						accountBalance-=d;
					}
					else
						cout<<"\nMinium Balance should be above 300";
					break;
		case 'c':
		case 'C':	if(accountBalance-d>1000)
					{
						accountBalance-=d;
					}
					else
						cout<<"\nMinium Balance should be above 1000";
	}
}
int bank::account_Number()
{
	return accountNumber;
}
void bank::balance_Enquiry()
{
	cout<<"Balance in your Account is "<<accountBalance;
}
int bank::user_Password()
{
	return userPassword;
}
void createNewAccount()
{
	int checkPassword;
	cout<<"\nEnter admin password: ";
	cin>>checkPassword;
	if(checkPassword==adminPassword)
	{
		cout<<"Admin logged in successfully";
		// b1.account_Number();
		bank b1;
		b1.read();
		fstream file;
		file.open("userDetails.txt",ios::out|ios::app);
		if(b1.get_balance())
		{
			file.write((char*)&b1,sizeof(b1));
			cout<<"Your account successfully created!!!";
		}		
	}
	else
		cout<<"Wrong password entered, Redirecting to main menu";
}
void deposit_Amount()
{
	int dm;
	fstream file,fileout;
	file.open("userDetails.txt",ios::in);
	fileout.open("temp.txt",ios::out|ios::app);
	bank b2;
	int accon;
	bool found=false;
	cout<<"\nEnter account number : ";
	cin>>accon;
	while(!file.eof())
	{
		file.read((char*)&b2,sizeof(b2));
		if(file.eof())
			break;
		if(b2.account_Number()==accon)
		{	int password;
			found=true;
			cout<<"enter your password: ";
			cin>>password;
			if(b2.user_Password()==password)
			{
				cout<<"How Much Money You Want To Deposit: ";
				cin>>dm;
				b2.deposit_money(dm);
				fileout.write((char *)&b2,sizeof(b2));
			}
			else
			{
				cout<<"\nEntered Password is wrong!!!";
				
			}
			
		}
		else
		{
			fileout.write((char *)&b2,sizeof(b2));			
		}

	}
	if(!found)
	{
			cout<<"\nRecord Not Found!!!";
	}
	file.close();
	fileout.close();
	remove("userDetails.txt");
	rename("temp.txt","userDetails.txt");	
}
void withdraw_Amount()
{
	int dm;
	fstream file,fileout;
	file.open("userDetails.txt",ios::in);
	fileout.open("temp.txt",ios::out|ios::app);
	bank b2;
	int accon;
	bool found=false;
	cout<<"\nEnter account number : ";
	cin>>accon;
	while(!file.eof())
	{
		file.read((char*)&b2,sizeof(b2));
		if(file.eof())
			break;
		if(b2.account_Number()==accon)
		{	int password;
			found=true;
			cout<<"enter your password: ";
			cin>>password;
			if(b2.user_Password()==password)
			{
				cout<<"How Much Money You Want To Withdraw: ";
				cin>>dm;
				b2.withdraw_money(dm);
				fileout.write((char *)&b2,sizeof(b2));
			}
			else
			{
				cout<<"\nEntered Password is wrong!!!";
				
			}
			
		}
		else
		{
			fileout.write((char *)&b2,sizeof(b2));			
		}

	}
	if(!found)
	{
			cout<<"\nRecord Not Found!!!";
	}
	file.close();
	fileout.close();
	remove( "userDetails.txt" );
	rename( "temp.txt" , "userDetails.txt" );	
}
void balance_Enquiry()
{
	int password;
	fstream file;
	file.open("userDetails.txt",ios::in);
	bank b2;
	int accon;
	bool found=false;
	cout<<"\nEnter account number : ";
	cin>>accon;
	while(!file.eof())
	{
		file.read((char*)&b2,sizeof(b2));
		if(b2.account_Number()==accon)
		{
			found=true;
			cout<<"enter your password: ";
			cin>>password;
			if(b2.user_Password()==password)
			{
				b2.balance_Enquiry();
				break;
			}
			else
			{
				cout<<"You Entered wrong password!!!";
				break;
			}	
		}
		// if(file.eof())
		// break;

	}
		if(!found)
		{
			cout<<"\nRecord Not Found!!!";
		}
}
void all_Holder_list()
{
	int password;
	cout<<"\nAdmins password: ";
	cin>>password;
	if(password==adminPassword)
	{
		fstream file;
		file.open("userDetails.txt",ios::in);
		bank b1;
		while(file)
		{
			file.read((char *)&b1,sizeof(b1));
			if(file.eof())
				break;
			b1.display();
		}
	}
	else
		cout<<"\nEntered Password is wrong, We can not complete your request!!!";
}
void close_account()
{
	fstream filein,fileout;
	filein.open("userDetails.txt",ios::in);
	fileout.open("temp.txt",ios::out|ios::app);
	bank b2;
	int accon;
	bool found=false;
	char confirm;	
	cout<<"\nEnter account number : ";
	cin>>accon;
	while(!filein.eof())
	{
		filein.read((char*)&b2,sizeof(b2));
		if(filein.eof())
			break;
		if(b2.account_Number()==accon)
		{
			int password;
			cout<<"Confirm your password: ";
			cin>>password;
			if(b2.user_Password()==password)
			{
			b2.display();
			found=true;
			cout<<"\nAre you sure you want to delete this account(y/n):";
			cin>>confirm;
			if(confirm=='n'|| confirm=='N')
			{
				fileout.write((char *)&b2,sizeof(b2));
			}
			}
		}
		else			
		{
			fileout.write((char *)&b2,sizeof(b2));
		}

	}
	if(!found)
	{
		cout<<"\nRecord Not Found!!!";
	}
	else
			cout<<"\nRecord deleted successfully";	
	filein.close();
	fileout.close();
	remove("userDetails.txt");
	rename("temp.txt","userDetails.txt");
}
void modify_password()
{
	int dm;
	fstream file,fileout;
	file.open("userDetails.txt",ios::in);
	fileout.open("temp.txt",ios::out|ios::app);
	bank b2;
	int accon;
	bool found=false;
	cout<<"\nEnter account number : ";
	cin>>accon;
	while(!file.eof())
	{
		file.read((char*)&b2,sizeof(b2));
		if(file.eof())
			break;
		if(b2.account_Number()==accon)
		{	int password;
			found=true;
			cout<<"enter your Old password: ";
			cin>>password;
			if(b2.user_Password()==password)
			{
				cout<<"Type Your New Password ";
				cin>>dm;
				b2.modify_Password(dm);
				fileout.write((char *)&b2,sizeof(b2));
			}
			else
			{
				cout<<"\nEntered Password is wrong!!!";
				
			}
			
		}
		else
		{
			fileout.write((char *)&b2,sizeof(b2));			
		}

	}
	if(!found)
	{
			cout<<"\nRecord Not Found!!!";
	}
	file.close();
	fileout.close();
	remove("userDetails.txt");
	rename("temp.txt","userDetails.txt");	

}
int main()
{
	int optionSelect;
	do
	{
		cout<<"\n\n\t\tMAIN MENU\n";
		cout<<"\n\t01. CREAT A NEW ACCOUNT\n";
		cout<<"\n\t02. DEPOSIT AMOUNT\n";
		cout<<"\n\t03. WITHDRAW AMOUNT\n";
		cout<<"\n\t04. BALANCE ENQUIRY\n";
		cout<<"\n\t05. ALL ACCOUNT HOLDER LIST\n";
		cout<<"\n\t06. CLOSE AN ACCOUNT\n";
		cout<<"\n\t07. MODIFY AN ACCOUNT\n";
		cout<<"\n\t08. EXIT\n";
		cout<<"\n\nSelect Your Option :\t";
		cin>>optionSelect;
		switch(optionSelect)
		{
			case 1 :	createNewAccount();
						break;
			case 2 :	deposit_Amount();
						break;
			case 3 :	withdraw_Amount();
						break;
			case 4 :	balance_Enquiry();
						break;
			case 5 :	all_Holder_list();
						break;
			case 6 :	close_account();
						break;
			case 7 :	modify_password();
		}
	}
	while(optionSelect!=8);	
	cout<<"\nThank You For Chosing our service!!! We are Happy To Help You";
}