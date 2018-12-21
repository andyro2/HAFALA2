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
	Account(int num, int password,int balance);
	bool check_if_vip();
	void upgrade_to_vip(int password);
    void deposit_balance(int money, int password, int* balance);
	void witdraw_balance(int money, int password, int* balance);

private:
	int num_;
	int password_;
	int balance_;
	bool vip_;

};

#define NUM_OF_ATM 1

class ATM {
public:
	void open_account(int ac_num, int pass, int in_ammount);
	void make_vip(int ac_num, int pass);
	void deposit(int ac_num, int pass, int ammount);
	void withdraw(int ac_num, int pass, int ammount);
	void transfer(int ac_num, int pass, int target, int ammount);
private:
	int ser_num;
};

class Bank {
private:
	vector<Account> accounts;
};


#endif

