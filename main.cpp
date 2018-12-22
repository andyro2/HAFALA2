#include "Account.h"

using std::ostream;

bool CheckValidArgs(int argc, char* argv[]);

ofstream logfile("log.txt");
pthread_mutex_t PrintLogMutex;
pthread_mutex_t PrintDisplayMutex;
bool ATMsFinished = false;
Bank* bank;



int main(int argc, char* argv[])
{
	int flagPrintLogLock = pthread_mutex_init(&PrintLogMutex, NULL);
	int flagPrintDisplayMutex = pthread_mutex_init(&PrintDisplayMutex, NULL);
	if (flagPrintLogLock != 0 || flagPrintDisplayMutex != 0)
	{
		perror(NULL);
		exit(1);
	}
	if (!CheckValidArgs(argc, argv))
		exit(0);
	bank = new Bank(argv);
	pthread_t* comissionThread = bank->GetCommission();
	pthread_t* printThread = bank->PrintAccounts();
	bank->CreateAtmsThreads();
	ATMsFinished = true;

	pthread_join(*comissionThread, NULL);
	pthread_join(*printThread, NULL);
	delete[] comissionThread;
	delete[] printThread;
	pthread_mutex_destroy(&PrintDisplayMutex);
	pthread_mutex_destroy(&PrintLogMutex);
	delete[] bank;
}


//**************************************************************************************
// function name: CheckValidArgs
// Description: Check that the arguments for the program Bank are valid
// Parameters: Arguments for the program and the number of them
// Returns: true if valid or false if not
//**************************************************************************************
bool CheckValidArgs(int argc, char* argv[])
{
	int numAtms = atoi(argv[1]);
	if (argc < 3 || argc - 2 != numAtms)
	{
		cerr << "illegal arguments" << endl;
		return false;
	}
	return true;
}
