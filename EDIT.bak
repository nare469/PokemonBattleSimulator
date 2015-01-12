#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pokdecl.h"

void NewAtk()
{
	attack temp;
	temp.EnterData();
	ofstream ofile("attacks.dat",ios::binary|ios::app);
	if(!ofile)
	{
		cout<<"File open error!"<<endl;
		exit(0);
	}
	ofile.write((char*)&temp, sizeof(temp));
}

void ListAll()
{
	attack A;
	int i = 1;
	ifstream ifile("attacks.dat",ios::binary);
	if(!ifile)
	{
		cout<<"File open error!"<<endl;
		exit(0);
	}
	while (ifile.read((char*)&A, sizeof(A)))
	{
		cout<<i<<". "<<A.GetName()<<endl;
		i++;
	}
}



void EditAtk()
{
	int flag = 0;
	char search[20];
	cout<<"Enter the name of the attack you want to edit"<<endl;
	gets(search);
	attack A;
	ofstream ofile("temp.dat",ios::binary);
	if(!ofile)
	{
		cout<<"File open error!"<<endl;
		exit(0);
	}
	ifstream ifile("attacks.dat",ios::binary);
	if(!ifile)
	{
		cout<<"File open error!"<<endl;
		exit(0);
	}
	while (ifile.read((char*)&A, sizeof(A)))
	{
		if(strcmpi(search,A.GetName()) == 0)
		{
			flag = 1;
			cout<<"Attack found. Please enter the new details"<<endl;
			A.EnterData();
		}
		ofile.write((char*)&A, sizeof(A));
	}
	if (flag == 0)
	{
		cout<<"Attack not found!"<<endl;
	}
	ifile.close();
	ofile.close();
	remove("attacks.dat");
	rename("temp.dat","attacks.dat");
}
void ListAtk()
{
	int flag = 0;
	char search[20];
	cout<<"Enter the name of the attack whose details you want to see"<<endl;
	gets(search);
	attack A;
	ifstream ifile("attacks.dat",ios::binary);
	if(!ifile)
	{
		cout<<"File open error!"<<endl;
		exit(0);
	}
	while (ifile.read((char*)&A, sizeof(A)))
	{
		if(strcmpi(search,A.GetName()) == 0)
		{
			flag = 1;
			cout<<"Attack found."<<endl;
			A.ListDetails();
			break;
		}
	}
	if (flag == 0)
	{
		cout<<"Attack not found!"<<endl;
	}
	ifile.close();
}

int main()
{
	int choice;
	char ch;
	do
	{
		cout<<"1. Enter a new attack"<<endl;
		cout<<"2. List all attacks"<<endl;
		cout<<"3. Edit an attack"<<endl;
		cout<<"4. List details of an attack"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		clrscr();
		switch(choice)
		{
			case 1:
				NewAtk();
				break;
			case 2:
				ListAll();
				break;
			case 3:
				EditAtk();
				break;
			case 4:
				ListAtk();
				break;
		}
		cout<<"Do you want to continue? (Y/N)"<<endl;
		cin>>ch;
		clrscr();
	} while (ch == 'y' || ch == 'Y');
}
