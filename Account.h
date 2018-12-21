#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <string>
#include <vector>


using std::string;
using std::vector;

#define SIZE_PASSWORD 4
#define NUM_OF_ATM 1

class Account
{
public:
	Account();
	~Account();
	Account(int num, char* password,int balance);
	bool check_if_vip();
	int get_password();
	int get_num();
	int get_balance();
	void add_to_balance(int ammount);
//	void upgrade_to_vip(char* password);
//	void update_balance(int money, char* password, int* balance);

private:
	int num_;
	char* password_;
	int balance_;
	bool vip_;

};

#define NUM_OF_ATM 1

class ATM {
public:
	ATM(int ser_num);
	~ATM();
	void open_account(int ac_num, int pass, int in_ammount);
	void make_vip(Account& acc, int pass);
	void deposit(Account& acc, int pass, int ammount);
	void withdraw(Account& acc, int pass, int ammount);
	void check_balance(Account& acc, int pass);
	void transfer(Account& acc, int pass, Account& acc_tar, int ammount);

private:
	int ser_num_;
};

class Bank {
private:
	vector<Account> accounts;
};


#endif



#endif
