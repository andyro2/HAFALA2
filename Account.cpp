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
		cout << "Error <ATM ID> : Your transaction failed � password for account id <id> is incorrect\n";//I will check later when 
	// i will creat the atm class
}


void Account::update_balance(int money, char* password, int* balance) 
{

	
	if (!strcmp(password_, password))
	{
		if (balance_ + money < 0)
		{
			cout << "Error <ATM ID>: Your transaction failed � account id <id> balance is lower than <amount>";
			return;
		}
		else
		{
			balance_ += money;
			*balance = balance_;
		}

	}
	else
		cout << "Error <ATM ID>: Your transaction failed � password for account id <id> is incorrect";
}
int Account::get_password() {
	return password_;
}
int Account::get_num() {
	return num_;
}
int Account::get_balance() {
	return balance_;
}

void Account::add_to_balance(int ammount) {
	balance_ += ammount;
	return;
}
void ATM::check_balance(Account& acc, int pass)
{
	if (acc.get_password() == pass)
		cout << ser_num_ << ": Account " << acc.get_num() << " balance is " << acc.get_balance() << endl;
	else
		cout << "Error "<< ser_num_ << ": Your transaction failed - password for account id " << acc.get_num() << " is incorrect" << endl;
}

void ATM::transfer(Account& acc, int pass, Account& acc_tar, int ammount)
{
	if (acc.get_password() != pass) {
		cout << "Error " << ser_num_ << ": Your transaction failed - password for account id " << acc.get_num() << " is incorrect" << endl;
		return;
	}
	else if (ammount > acc.get_balance()) {
		cout << "Error " << ser_num_ << ": Your transaction failed - password for account id " << acc_tar.get_num() << " balance is lower than " <<ammount<< endl;
		return;
	}
	else {
		withdraw(&acc, pass, ammount);
		acc_tar.add_to_balance(ammount);
		cout << ser_num_ << ": Transfer " << ammount << " from account " << acc.get_num << " to account " << acc_tar.get_num << " new account balance is " << acc.get_balance() << " new target account balance is " << acc_tar.get_balance() << endl;
	}
}

ATM::ATM(int ser_num) :ser_num_(ser_num);

ATM::~ATM(){};