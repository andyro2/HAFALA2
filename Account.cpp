#include "Account.H"



using namespace std;

Account::Account()
{
	num_ = 0;
	password_ = 0000;
	balance_ = 0;
	vip_ = false;
}

Account::~Account() 
{
	delete[] password_;

}

Account::Account(int num, int password, int balance)
{
    
	num_ = num;
	password_ = password;
	balance_ = balance;
	vip_ = false;
	cout<<"<ATM ID>: New account id is <id> with password <pass> and initial balance <bal>";
}

bool Account::check_if_vip()
{
	return vip_ ;
}


void Account::upgrade_to_vip(char* password)
{
	if (password_==password)
	{
		vip_ = true;
	}
	else
		cout << "Error <ATM ID> : Your transaction failed – password for account id <id> is incorrect\n";//I will check later when 
	// i will creat the atm class
}


void Account::witdraw_balance(int money, int password, int* balance) 
{

	
	if (password_==password)
	{
		if (balance_ - money < 0)
		{
			cout << "Error <ATM ID>: Your transaction failed – account id <id> balance is lower than <amount>";
			return;
		}
		else
		{
			balance_ -= money;
			*balance = balance_;
			cout<< "<ATM ID>: Account <id> new balance is <bal> after <amount> $ was withdrew";
		}

	}
	else
		cout << "Error <ATM ID>: Your transaction failed – password for account id <id> is incorrect";
}

void Account::deposit_balance(int money, int password, int* balance) 
{

	
	if (password_==password)
	{

		else
		{
			balance_ += money;
			*balance = balance_;
			cout<< "<ATM ID>: Account <id> new balance is <bal> after <amount> $ was deposited";
		}

	}
	else
		cout << "Error <ATM ID>: Your transaction failed – password for account id <id> is incorrect";
}