//Version 1.5 - Last edited 8/2/13 by Nads
//getch() replaced with waitFor

//1.4 - default parameters set to prevent error
//Starters, Legendaries separated from menu

//1.5 - Hoenn legendaries added
#include <ctype.h>

#include "pokdecl.h"
#include "pokdb.h"

#ifndef POKSET_H
#define POKSET_H
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

void trainerdefn(trainer &t1)
{	cout<<"Hello there, user. May I know your name?"<<endl;
	gets(t1.name);
	t1.name[0] = toupper(t1.name[0]);
	int choice;
	int randomcrappyhiddenfeature(1);
	while(strcmp(t1.name,"") ==0)
	{	cout<<"Please enter a name, user. You cannot be nameless.\n";
		randomcrappyhiddenfeature++;
		gets(t1.name);
		if (randomcrappyhiddenfeature == 5)
		{	cout<<"Due to your inability to provide a name, we have determined that you are\n";
			cout<<"a n00b. Hence, we shall now address you by the name \"n00b\". :)";
			strcpy(t1.name, "n00b");
			waitFor(3);
		}
		clrscr();
	}
	clrscr();
	cout<<"Welcome, "<<t1.name<<"!"<<endl;
	waitFor(2);
	cout<<"First, you must choose a starter Pokemon."<<endl;
	waitFor(1);
	cout<<"1. Venusaur"<<"\t4. Meganium\t7. Sceptile"<<endl;
	cout<<"2. Charizard\t5. Typhlosion\t8. Blaziken"<<endl;
	cout<<"3. Blastoise"<<"\t6. Feraligatr\t9. Swampert"<<endl;
	waitFor(2);
	cin>>choice;
	starterset(choice, t1);
	clrscr();
	cout<<"Now, you get to choose a legendary Pokemon."<<endl;
	waitFor(2);
	cout<<"1. Articuno\t\t5. Raikou\t\t10. Latias\n";
	cout<<"2. Zapdos\t\t6. Entei\t\t11. Latios\n";
	cout<<"3. Moltres\t\t5. Suicune\t\t12. Kyogre\n";
	cout<<"4. Mewtwo\t\t7. Lugia\t\t13. Groudon\n";
	cout<<"\t\t\t8. Ho-Oh\t\t14. Rayquaza\n";
	cout<<"\t\t\t\t\t\t15. Jirachi\n";
	cin>>choice;
	legendset(choice, t1);
	clrscr();
	cout<<"Finally, choose your third pokemon."<<endl;
	waitFor(2);
	cout<<"1. Aerodactyl\t\t10. Ninetales"<<endl;
	cout<<"2. Arbok\t\t11. Gengar"<<endl;
	cout<<"3. Tyranitar\t\t12. Crobat"<<endl;
	cout<<"4. Gyarados\t\t13. Vileplume"<<endl;
	cout<<"5. Steelix\t\t14. Hitmonchan"<<endl;
	cout<<"6. Electabuzz\t\t15. Lanturn"<<endl;
	cout<<"7. Dragonite\t\t16. Arcanine\n";
	cout<<"8. Raichu\t\t17. Magneton\n";
	cout<<"9. Starmie\t\t18. Rhydon\n";
	cin>>choice;
	pokemonset(choice, t1);
	clrscr();
}
#endif