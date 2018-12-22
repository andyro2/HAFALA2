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

using namespace std;
using std::vector;

#define SIZE_PASSWORD 4
#define NUM_OF_ATM 1

class Account
{
public:
	Account();
	~Account();
	Account(int num, int password,int balance);
	bool check_if_vip();
	void upgrade_to_vip(int password);
    void deposit_balance(int money, int password, int* balance);
	void witdraw_balance(int money, int password, int* balance);
	int get_num();
	int get_password();
	int get_balance();

private:
	int num_;
	int password_;
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
	void transfer(Account& acc, int pass, Account& acc_tar, int ammount)
private:
	int ser_num_;
};

class Bank {
	Bank();
	~Bank();
	void add_account(int ac_num, int pass, int in_ammount);
private:
	vector<Account> accounts;
};


#endif

