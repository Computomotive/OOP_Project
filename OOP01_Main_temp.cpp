#include <iostream>
#define MAX_NAME_LEN 20
#define MAX_ACCOUNT_LEN  100 

using namespace std;

int ShowMenu();
void CreateAccount();
void DepositMoney();
void WithdrawMoney();
int CheckAccountIndex(int iAccountID);
void ShowAllAccount();

enum {CREATE=1, DEPOSIT=2, WITHDRAW=3, SHOWALL=4, QUIT=5}; 

typedef struct 
{
	int iAccountID;
	char sName[MAX_NAME_LEN];
	int iMoney;	
} AccountInfo;

AccountInfo aAccountArray[MAX_ACCOUNT_LEN];
int cAccountArrayCount = 0;

int ShowMenu()
{
	int ichoice; 
	cout<<"-----Menu-----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;	 
	cout<<"5. 프로그램 종료"<<endl;
	cout<<"선택: ";
	cin>>ichoice;
	return ichoice;
}

void CreateAccount()
{
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>aAccountArray[cAccountArrayCount].iAccountID;
//	cout<<endl;
	cout<<"이름: ";
	cin>>aAccountArray[cAccountArrayCount].sName;
//	cout<<endl;
	cout<<"입금액: ";
	cin>>aAccountArray[cAccountArrayCount].iMoney;
//	cout<<endl;
	cAccountArrayCount++;
}

int CheckAccountIndex(int iAccountID)
{
	int iAccountArrayIndex = 0;
	for (iAccountArrayIndex=0; iAccountArrayIndex<MAX_ACCOUNT_LEN; iAccountArrayIndex++)
	{
		if(aAccountArray[iAccountArrayIndex].iAccountID == iAccountID)
		{
			return iAccountArrayIndex;
		}	
		else 
		{
			return -1;
		}	
	}
}

void DepositMoney()
{
	int iAccountID;
	int iMoney;
	int iFoundIDIndex;
	cout<<"[입    금]"<<endl;	
	cout<<"계좌ID: ";
	cin>>iAccountID;
	cout<<"입금액: ";	
	cin>>iMoney;	
	iFoundIDIndex = CheckAccountIndex (iAccountID);
	if(iFoundIDIndex!=-1)
	{
		aAccountArray[iFoundIDIndex].iMoney += iMoney;		
	}
	else 
	{
		cout<< "No AccountID Founded"<<endl;
		return;
	}
}

void WithdrawMoney()
{
	int iAccountID;
	int iMoney;
	int iFoundIDIndex;
	cout<<"[출    금]"<<endl;	
	cout<<"계좌ID: ";
	cin>>iAccountID;
	cout<<"금액: ";	
	cin>>iMoney;	
	iFoundIDIndex = CheckAccountIndex (iAccountID);
	if(iFoundIDIndex!=-1)
	{
		aAccountArray[iFoundIDIndex].iMoney -= iMoney;		
	}
	else 
	{
		cout<< "No AccountID Founded"<<endl;
		return;
	}
}


void ShowAllAccount()
{
	int iAccountArrayIndex = 0;
	for (iAccountArrayIndex=0; iAccountArrayIndex<cAccountArrayCount; iAccountArrayIndex++)
	{
		cout<<"계좌ID: ";
		cout<<aAccountArray[iAccountArrayIndex].iAccountID<<endl;
		cout<<"이름: ";
		cout<<aAccountArray[iAccountArrayIndex].sName<<endl;
		cout<<"입금액: ";
		cout<<aAccountArray[iAccountArrayIndex].iMoney<<endl;		
		cout<<endl;
	}
}


int main() 
{
	for(;;)
	{
		int iSelectedValue = ShowMenu();
		switch (iSelectedValue)
		{
			case CREATE: 
			{
				CreateAccount();
				break;
			}
			case DEPOSIT: 
			{
				DepositMoney();
				break;
			}
			case WITHDRAW: 
			{
				WithdrawMoney();
				break;
			}
			case SHOWALL: 
			{
				ShowAllAccount();
				break;
			}
			case QUIT: 
			{
				return 0;
			}
			default: 
			{
				break;
			}
		}		
	}
	return 0;
}
