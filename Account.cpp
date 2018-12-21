#include "Account.H"



using namespace std;

Account::Account()
{
	num_ = 0;
	password_ = new char[SIZE_PASSWORD + 1];
	strcpy(password_, "0000");
	balance_ = 0;
	vip_ = false;
}

Account::~Account() 
{
	delete[] password_;

}

Account::Account(int num, char* password, int balance)
{
	num_ = num;
	password_ = password;
	balance_ = balance;
	vip_ = false;
}

bool Account::check_if_vip()
{
	return vip_ ;
}


void Account::upgrade_to_vip(char* password)
{
	if (!strcmp(password_, password))
	{
		vip_ = true;
	}
	else
		cout << "Error <ATM ID> : Your transaction failed – password for account id <id> is incorrect\n";//I will check later when 
	// i will creat the atm class
}


void Account::update_balance(int money, char* password, int* balance) 
{

	
	if (!strcmp(password_, password))
	{
		if (balance_ + money < 0)
		{
			cout << "Error <ATM ID>: Your transaction failed – account id <id> balance is lower than <amount>";
			return;
		}
		else
		{
			balance_ += money;
			*balance = balance_;
		}

	}
	else
		cout << "Error <ATM ID>: Your transaction failed – password for account id <id> is incorrect";
}