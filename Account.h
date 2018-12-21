#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <string>


using std::string;

#define SIZE_PASSWORD 4

class Account
{
public:
	Account();
	~Account();
	Account(int num, char* password,int balance);
	bool check_if_vip();
	void upgrade_to_vip(char* password);
	void update_balance(int money, char* password, int* balance);

private:
	int num_;
	char* password_;
	int balance_;
	bool vip_;

};


#endif
