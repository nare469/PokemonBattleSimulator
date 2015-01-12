//Pokemon Editor v 1.0 Last edit by Narendran Srinivasan on 12/10/2013

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pokdecl.h"

void NewPkmn()
{
	pokemon temp;
	temp.EnterData();
	ofstream ofile("pokemon.dat",ios::binary|ios::app);
	if(!ofile)
	{
		cout<<"File open error!"<<endl;
		exit(0);
	}
	ofile.write((char*)&temp, sizeof(temp));
}

void ListAll()
{
	pokemon A;
	int i = 1;
	ifstream ifile("pokemon.dat",ios::binary);
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

void EditPkmn()
{
	int flag = 0;
	char search[20];
	cout<<"Enter the name of the pokemon you want to edit"<<endl;
	gets(search);
	pokemon A;
	ofstream ofile("temp.dat",ios::binary);
	if(!ofile)
	{
		cout<<"File open error!"<<endl;
		exit(0);
	}
	ifstream ifile("pokemon.dat",ios::binary);
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
			cout<<"Pokemon found. Please enter the new details"<<endl;
			A.EnterData();
		}
		ofile.write((char*)&A, sizeof(A));
	}
	if (flag == 0)
	{
		cout<<"Pokemon not found!"<<endl;
	}
	ifile.close();
	ofile.close();
	remove("pokemon.dat");
	rename("temp.dat","pokemon.dat");
}

void ListPkmn()
{
	int flag = 0;
	char search[20];
	cout<<"Enter the name of the pokemon whose details you want to see"<<endl;
	gets(search);
	pokemon A;
	ifstream ifile("pokemon.dat",ios::binary);
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
			cout<<"Pokemon found."<<endl;
			A.ListDetails();
			break;
		}
	}
	if (flag == 0)
	{
		cout<<"Pokemon not found!"<<endl;
	}
	ifile.close();
}


int main()
{
	int choice;
	char ch;
	do
	{
		cout<<"1. Enter a new pokemon"<<endl;
		cout<<"2. List all pokemon"<<endl;
		cout<<"3. Edit an existing pokemon"<<endl;
		cout<<"4. List details of an existing pokemon"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		clrscr();
		switch(choice)
		{
			case 1:
				NewPkmn();
				break;
			case 2:
				ListAll();
				break;
			case 3:
				EditPkmn();
				break;
			case 4:
				ListPkmn();
				break;
		}
		cout<<"Do you want to continue? (Y/N)"<<endl;
		cin>>ch;
		clrscr();
	} while (ch == 'y' || ch == 'Y');
}