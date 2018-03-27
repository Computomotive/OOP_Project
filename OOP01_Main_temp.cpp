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
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��"<<endl;
	cout<<"3. �� ��"<<endl;
	cout<<"4. �������� ��ü ���"<<endl;	 
	cout<<"5. ���α׷� ����"<<endl;
	cout<<"����: ";
	cin>>ichoice;
	return ichoice;
}

void CreateAccount()
{
	cout<<"[���°���]"<<endl;
	cout<<"����ID: ";
	cin>>aAccountArray[cAccountArrayCount].iAccountID;
//	cout<<endl;
	cout<<"�̸�: ";
	cin>>aAccountArray[cAccountArrayCount].sName;
//	cout<<endl;
	cout<<"�Աݾ�: ";
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
	cout<<"[��    ��]"<<endl;	
	cout<<"����ID: ";
	cin>>iAccountID;
	cout<<"�Աݾ�: ";	
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
	cout<<"[��    ��]"<<endl;	
	cout<<"����ID: ";
	cin>>iAccountID;
	cout<<"�ݾ�: ";	
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
		cout<<"����ID: ";
		cout<<aAccountArray[iAccountArrayIndex].iAccountID<<endl;
		cout<<"�̸�: ";
		cout<<aAccountArray[iAccountArrayIndex].sName<<endl;
		cout<<"�Աݾ�: ";
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
