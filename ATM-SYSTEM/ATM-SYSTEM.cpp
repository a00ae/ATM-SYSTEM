#include <iostream>
#include<string>
#include <iomanip>


using namespace std;
//global Varble;
const string CLIENT_FILE_NAME = "Client.txt";
//Struct File
struct stClients 
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double Balance;
	bool MarkForDelete = false;
};

enum enMainMuneOptios {
	eQucikWithdraw = 1, eNormalWithDraw = 2, eDeposit = 3,
	eCheckBalance = 4, eExit = 5
};




void ShowMainMenue()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tATM Main Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "===========================================\n";
}


void Login()
{

	bool loginFaild = false;

	string AccountNumber, PinCode;

	do {
		system("cls");
		cout << "\n---------------------------------\n";
		cout << "\tLogin Screen";
		cout << "\n---------------------------------\n";

		if (loginFaild)
		{
			cout << "Invlaid Account Number/PinCode!\n";
		}

		cout << "Enter Account Number? ";
		cin >> AccountNumber;
		cout << "Enter Pin? ";
		cin >> PinCode;

		//






	} while (loginFaild);

	ShowMainMenue();

}

int main()
{
	Login();

	system("pause>0");

	return 0;
}


