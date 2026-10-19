#include <iostream>
#include<string>
#include <iomanip>


void ShowMainMenue();

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

stClients CurrentClient;

enum enMainMuneOptios {
	eQucikWithdraw = 1, eNormalWithDraw = 2, eDeposit = 3,
	eCheckBalance = 4, eExit = 5
};


short ReadQuickWithdrawOption()
{
	short choice = 0;

	while (choice < 1 || choice > 9)
	{
		cout << "\nChoose what to do from [1] to [9] ? ";
		cin >> choice;
	}
	return choice;
}

void ShowQucikWithdrawScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tQucik Withdraw\n";
	cout << "===========================================\n";
	cout << "\t[1] 20\t\t[2] 50\n";
	cout << "\t[3] 100\t\t[4] 200\n";
	cout << "\t[5] 400\t\t[6] 600\n";
	cout << "\t[7] 800\t\t[8] 1000\n";
	cout << "\t[9] Exit\n";
	cout << "===========================================\n";
	cout << "Your Balance is " << CurrentClient.Balance;

	//PerfromMainMenueOption(ReadQuickWithdrawOption());

}

void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenue();
}



void PerfromMainMenueOption(enMainMuneOptios MainMuneOption)
{	
	switch (MainMuneOption)
	{
	case enMainMuneOptios::eQucikWithdraw:
	{
		system("cls");
		ShowQucikWithdrawScreen();
		GoBackToMainMenue();
	}
	}

}


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


