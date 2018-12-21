#ifndef _BANK_H
#define _BANK_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

using namespace std;
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


#endif
