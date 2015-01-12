//Version 2.0 - Last edited 14/10/13 by Narendran Srinivasan

//2.0 No more of the menu. Now optimised with file handling
//getch() replaced with waitFor

//1.4 - default parameters set to prevent error
//Starters, Legendaries separated from menu

//1.5 - Hoenn legendaries added
#include <ctype.h>
#include <fstream.h>
#include "pokdecl.h"
#include "pokdb.h"

#ifndef POKSET_H
#define POKSET_H
/*
void starterset(int choice, trainer &t1)
{
	switch (choice)
	{
	case 1:
		t1.pok[0] = venusaur;
		break;
	case 2:
		t1.pok[0] = charizard;
		break;
	case 3:
		t1.pok[0] = blastoise;
		break;
	case 4:
		t1.pok[0] = meganium;
		break;
	case 5:
		t1.pok[0] = typhlosion;
		break;
	case 6:
		t1.pok[0] = feraligatr;
		break;
	case 7:
		t1.pok[0] = sceptile;
		break;
	case 8:
		t1.pok[0] = blaziken;
		break;
	case 9:
		t1.pok[0] = swampert;
		break;
	default:
		t1.pok[0] = magikarp;
		break;
	}
}

void legendset(int choice, trainer &t1)
{
	switch (choice)
	{
	case 1:
		t1.pok[1] = articuno;
		break;
	case 2:
		t1.pok[1] = zapdos;
		break;
	case 3:
		t1.pok[1] = moltres;
		break;
	case 4:
		t1.pok[1] = mewtwo;
		break;
	case 5:
		t1.pok[1] = raikou;
		break;
	case 6:
		t1.pok[1] = entei;
		break;
	case 7:
		t1.pok[1] = suicune;
		break;
	case 8:
		t1.pok[1] = hooh;
		break;
	case 9:
		t1.pok[1] = lugia;
		break;
  case 10:
		t1.pok[1] = latias;
		break;
  case 11:
		t1.pok[1] = latios;
		break;
	case 12:
		t1.pok[1] = kyogre;
		break;
	case 13:
		t1.pok[1] = groudon;
		break;
	case 14:
		t1.pok[1] = rayquaza;
		break;
	case 15:
		t1.pok[1] = jirachi;
		break;
	default:
		t1.pok[1] = magikarp;
		break;
	}
}

void pokemonset(int choice, trainer &t1)
{
	switch (choice)
	{
	case 1:
		t1.pok[2] = aerodactyl;
		break;
	case 2:
		t1.pok[2] = arbok;
		break;
	case 3:
		t1.pok[2] = tyranitar;
		break;
	case 4:
		t1.pok[2] = gyarados;
		break;
	case 5:
		t1.pok[2] = steelix;
		break;
	case 6:
		t1.pok[2] = electabuzz;
		break;
	case 7:
		t1.pok[2] = dragonite;
		break;
	case 8:
		t1.pok[2] = raichu;
		break;
	case 9:
		t1.pok[2] = starmie;
		break;
	case 10:
		t1.pok[2] = ninetales;
		break;
	case 11:
		t1.pok[2] = gengar;
		break;
	case 12:
		t1.pok[2] = crobat;
		break;
	case 13:
		t1.pok[2] = vileplume;
		break;
	case 14:
		t1.pok[2] = hitmonchan;
		break;
	case 15:
		t1.pok[2] = lanturn;
		break;
	case 16:
		t1.pok[2] = arcanine;
		break;
	case 17:
		t1.pok[2] = magneton;
		break;
	case 18:
		t1.pok[2] = rhydon;
		break;
	default:
		t1.pok[2] = magikarp;
		break;

	}
}
*/
void trainer::trainerdefn()
{	cout<<"Hello there, user. May I know your name?"<<endl;
	gets(name);
	name[0] = toupper(name[0]);
	clrscr();
	int choice;
	int randomcrappyhiddenfeature(1);
	while(strcmp(name,"") ==0)
	{	cout<<"Please enter a name, user. You cannot be nameless.\n";
		randomcrappyhiddenfeature++;
		gets(name);
		if (randomcrappyhiddenfeature == 5)
		{	cout<<"Due to your inability to provide a name, we have determined that you are\n";
			cout<<"a n00b. Hence, we shall now address you by the name \"n00b\". :)";
			strcpy(name, "n00b");
			waitFor(3);
		}
		clrscr();
	}
	cout<<"Welcome "<<name<<"!"<<endl;
	int flag = 0;
	char search[20], ch = 'n';
	for(int i = 0; i<3; i++)
	{
		ch = 'n';
		do
		{
			flag = 0;
			cout<<"Enter the name of pokemon "<<(i+1)<<endl;
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
					cout<<"Confirm? (Y/N)"<<endl;
					cin>>ch;
					if (ch == 'y' || ch == 'Y')
						SetPkmn(i,A);
					break;
				}
			}
			clrscr();
			if (flag == 0)
			{
				cout<<"Pokemon not found! Try a new one."<<endl;
			}
			ifile.close();

		} while (ch == 'n' || ch == 'N');
		clrscr();
	}
}
#endif