#include <iostream>
#include <fstream>
#include<string>
#include <iomanip>
#include <vector>


void ShowMainMenue();
void PerfromNormalWithdrawOption();
void ShowQuickWithdrawScreen();
void Login();


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


vector<string> SplitString(string s1, string Delim)
{
	vector<string> vString;
	string word = "";
	short pos = 0;

	while ((pos = s1.find(Delim)) != std::string::npos)
	{
		word = s1.substr(0, pos);

		if (word != "")
		{
			vString.push_back(word);
		}


		s1.erase(0, pos + Delim.length());
	}

	if (s1 != "")
	{
		vString.push_back(s1);
	}

	return vString;

}

stClients ConvertLineToRecord(string line, string Seperator = "#//#")
{
	stClients Client;
	vector<string> vClients = SplitString(line, Seperator);

	Client.AccountNumber = vClients[0];
	Client.PinCode = vClients[1];
	Client.Name = vClients[2];
	Client.Phone = vClients[3];
	Client.Balance = stod(vClients[4]);

	return Client;
}

vector<stClients> LoadClientsDataFrom(string fileName)
{
	vector<stClients> vClients;
	fstream file;

	file.open(fileName, ios::in);

	if (file.is_open())
	{
		string Line;
		stClients Client;


		while (getline(file, Line))
		{
			Client = ConvertLineToRecord(Line);

			vClients.push_back(Client);
		}


		file.close();
	}

	return vClients;

}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClients &Client)
{
	vector<stClients> vClients = LoadClientsDataFrom(CLIENT_FILE_NAME);

	for (stClients C : vClients) 
	{
		if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
		{

			Client = C;

			return true;
		}
	}

	return false;
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
	return FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient);
}

short ReadMainMenueOption()
{

	cout << "Choose what do you want to do? [1 to 5]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
	
}


int ReadWithDrawAmont()
{
	int Amount;
	cout << "\nEnter an amount multiple of 5's ? ";
	cin >> Amount;

	while (Amount % 5 != 0)
	{
		cout << "\nEnter an amount multiple of 5's ? ";
		cin >> Amount;

	}

	return Amount;
}

void ShowCheckBalanceScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tCheck Balance Screen\n";
	cout << "===========================================\n";
	cout << "Your Balance is " << CurrentClient.Balance << "\n";
}


void ShowNormalWithDrawScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tNormal Withdraw Screen\n";
	cout << "===========================================\n";
	PerfromNormalWithdrawOption();
}



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


double ReadDepositAmount()
{
	double Amount;

	do
	{
		cout << "\nEnter a positive Deposit Amount? ";
		cin >> Amount;
	} while (Amount <= 0);

	return Amount;
}

string ConvertRecordToLine(stClients Clients, string Seperator = "#//#")
{
	string stClienitRecord = "";

	stClienitRecord += Clients.AccountNumber + Seperator;
	stClienitRecord += Clients.PinCode + Seperator;
	stClienitRecord += Clients.Name + Seperator;
	stClienitRecord += Clients.Phone + Seperator;
	stClienitRecord += to_string(Clients.Balance);

	return stClienitRecord;



}

vector <stClients> SaveCleintsDataToFile(string fileName, vector<stClients> vClients)
{
	fstream file;
	file.open(fileName, ios::out);

	string Line;

	if (file.is_open())
	{

		for (stClients C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				Line = ConvertRecordToLine(C);
				file << Line << endl;
			}
		}


		file.close();
	}

	return vClients;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<stClients> &vClients)
{
	char Answer = 'n';


	cout << "\n\nAre you sure you want perfrom this transaction? Y/N ? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		for (stClients &C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.Balance += Amount;
				SaveCleintsDataToFile(CLIENT_FILE_NAME, vClients);
				cout << "\n\nDone Successfully.New balance is : " << C.Balance;
				return true;
			}
		}
		return false;
	}

}

short getQuickWithDrawAmount(short QuickWithDrawOption)
{
	switch (QuickWithDrawOption) 
	{
	case 1:
		return 20;
	case 2:
		return 50;
	case 3:
		return 100;
	case 4: 
		return 200;
	case 5:
		return 400;
	case 6:
		return 600;
	case 7 :
		return 800;
	case 8: 
		return 1000;
	default:
		return 0;


	}
}



void PerfromQuickWithdrawOption(short QuickWithDrawOption)
{
	if (QuickWithDrawOption == 9)
		return;


	short WithDrowBalance = getQuickWithDrawAmount(QuickWithDrawOption);

	if (WithDrowBalance > CurrentClient.Balance)
	{
		cout << "\nThe amount exceeds your balance, make another choice.\n";
			cout << "Press Anykey to continue...";
		system("pause>0");
		ShowQuickWithdrawScreen();
		return;
	}

	vector<stClients> vClients = LoadClientsDataFrom(CLIENT_FILE_NAME);

	DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithDrowBalance * -1, vClients);

	CurrentClient.Balance -= WithDrowBalance;
}

void PerfromNormalWithdrawOption()
{
	int WithDrawBalance = ReadWithDrawAmont();
	if (WithDrawBalance > CurrentClient.Balance)
	{
		cout << "\nThe amount exceeds your balance, make another choice.\n";
		cout << "Press Anykey to continue...";
		system("pause>0");
		ShowNormalWithDrawScreen();
		return;
	}
	vector <stClients> vClients = LoadClientsDataFrom(CLIENT_FILE_NAME);
	DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithDrawBalance * -1, vClients);


	CurrentClient.Balance -= WithDrawBalance;
}
void PerfromDepositOption()
{
	double DepositAmount = ReadDepositAmount();

	vector<stClients> vClients = LoadClientsDataFrom(CLIENT_FILE_NAME);


	DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, DepositAmount, vClients);
	CurrentClient.Balance += DepositAmount;

}

void ShowQuickWithdrawScreen()
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

	PerfromQuickWithdrawOption(ReadQuickWithdrawOption());

	

}

void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenue();
}

void ShowDepositScreen()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tDeposit Screen\n";
	cout << "===========================================\n";
	PerfromDepositOption();
}

void PerfromMainMenueOption(enMainMuneOptios MainMuneOption)
{	
	switch (MainMuneOption)
	{
	case enMainMuneOptios::eQucikWithdraw:
	{
		system("cls");
		ShowQuickWithdrawScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMuneOptios::eNormalWithDraw: 
	{
		system("cls");
		ShowNormalWithDrawScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMuneOptios::eDeposit: 
	{
		system("cls");
		ShowDepositScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMuneOptios::eCheckBalance:
	{
		system("cls");
		ShowCheckBalanceScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMuneOptios::eExit: 
	{
		system("cls");
		Login();


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


	PerfromMainMenueOption((enMainMuneOptios)ReadMainMenueOption());

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


		loginFaild = !LoadClientInfo(AccountNumber, PinCode);



	} while (loginFaild);

	ShowMainMenue();

}

int main()
{
	Login();
	//ShowMainMenue();


	system("pause>0");

	return 0;
}


