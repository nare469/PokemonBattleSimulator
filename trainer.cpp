//POKEMON GAME 1.5.3(beta), running with Trainer System.
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <fstream.h>
#include <iomanip.h>
#include "pokrand.h"
#include "pokbat.h"
#include "poktt.h"
#include "tutorial.h"
#include "poksf.h"
#include "pokdecl.h"
#include "pokset.h"
#include "pokdb.h"

//VERSION FEATURES:
//1. AI SYSTEM: Defines AI Pokemon's potential damage inflicted on user by running equation
//              with no effect
//	  ALGORITHM:
//		a)Returns these values into an array and sorts by descending order
//		b)runs a random function onto the sorted array such that it picks random(1-100)
//		  and if>50 attack, else move to next attack, pick(1-100) and if>50 attack, else pick random
//		  between last two attacks. This way most probable attack is most damage dealing, but won't always
//  	  be used. 50% chance of most powerful, 25% chance of next powerful, and 12.5% chance between last two.
//
//2. PP: Usage of Pokemon attacks is now limited to its PP or Power Points.
//3. RECHARGE: Makes the Pokemon recharge for one turn after using extra powerful moves.
//   		NOTE: AI Pokemon also recharges after using powerful moves.
//4. ATTACK CATEGORIES: This version separates moves into categories.

//***NEW FEATURES to version 1.2.5***
//1. Stat changes now affect a Pokemon: Pokemon fall asleep for random 2-5 turns when
//their status is affected, or can be poisoned and burnt. Pokemon may be frozen or
//paralysed as well.
//***As of 14/1/13, only Sleep and Paralysis has been implemented.

//**11/1/2013 - Super effect equation modified and improved
//**14/1/2013 - Paralysis working
//				  - Stat change attacks can now be used by AI pokemon
	//type matchups

//15/1/2013 - Poison working
//Synthesis working
//Easter egg 'shivam' added - Pokemon #64

//Version updated to 1.2.6
//18/1/2013 - Pokemon can now get 'burnt'. One attack that causes burn has been added. (Will-o-wisp)
//18/1/2013 - Stat reducing attacks work too. Attack 'Growl' created. Reduces attack by 1/4

//1.3.1 - Version updated
/*
	Category 3 moves like solarbeam now work
	Many bugs fixed including missing getch() prompts. Still certain bugs remain
	Category 5 moves work for opponents too
	category 3 moves also work for opponents
1.3.2 - Update!
	Category 6 moves like sheer cold now work for allies as well as opponents
*/
 //most extra getch() prompts have been removed. Extra testing is required.



/*Category List:
0 - Normal Attacking move
1 - Move that require recharging
2 - Move that changes condition
3 - Attacks that require charging before
4 - Attacks that heal
5 - Stat changing attacks
6 - One-hit KO's
7 - Attacks which damage as well as change condition
8 - Attacks that have recoil damage
9 - Transform
10- Attacks that damage and change stats as well
11- Attacks that restore health to the user after damage
12- Splash
 (as of 2/2/13)
*/



//VERSION 1.4
/*TRAINERS NOW ADDED, YOU CAN MAKE YOUR OWN TRAINER!!!!!!!
	Flamethrower modified to burn
	Two opponent trainers added: Red and Blue
*/

//1.4.1; bug fixes
//Green added, more Pokemon added including Ditto.
//Transform created, and battle prompt bug fixes have been made. *some still remain*

//1.4.2
//headers created;
/*
pokdecl.h 	- Basic Declarations
						Declarations:
							-Type and Condition enums
							- int miss(global variable reqd for battle damage and trainerturn)
							-Attack, pokemon, Pokemon and Trainer classes
						Functions:
							-"pokemonchoose"
		CURRENT VERSION 1.3
pokdb.h 		- Pokemon Database
						Declarations:
							-All Pokemon and Attacks
		CURRENT VERSION 1.6
poksf.h		- Attack Effect Calculation
						Functions:
							-"supereffect"
		CURRENT VERSION 1.1
pokbat.h		- Pokemon Battle-Specific Data
						Functions:
							-"ApplyCond"
							-"attack1" (Battle Damage Equation)
							-"AIatk"
		CURRENT VERSION 1.3
poktt.h		- Pokemon Trainer Turns
						Declarations:
							-charge, charge2 (reqd for category 3 attacks)
						Functions:
							-"trainerturn"
		CURRENT VERSION 1.9
tutorial.h	- Pokemon Tutorial
						Functions:
							-"tutorial"
		CURRENT VERSION 1.2
pokset.h 	- Setting Pokemon
						Functions:
							-"starterset"
							-"legendset"
							-"pokemonset"
							-"trainerdefn"
		CURRENT VERSION 1.4
pokrand.h 	- Time delay function
						Functions:
							"waitFor"
		CURRENT VERSION 1.0
*/
//Updates made for 1.4.3:
//menu updates, more trainers
//new Tutorial feature[IMPLEMENTED(30/1/13), to be improved], and better menu integrity and prompts.
//
//31/1/13: Brock, Misty added. Many new Pokemon added. Documentation for header files started.
// 2/2/13 - Category 10 type moves integrated.

//		Random feature: "pokrand.h" included for function "waitFor(time_t <seconds>)" to
//							 make "Loading..." cool.
//Additional moves added, toxic fixed. Category 2 and Category 6 moves now can't affect certain types as required.

//updated to ver 1.4.5:
//GETCH() replaced by "waitFor()";

//Version 1.5 created
//Several bug fixes and patches
//OBJECTIVES: Switch out Pokemon
//				  Make user battle all trainers in one go

int main()
{
	char ch;
	short int nads = 1;
	dec();

	charge = 0;
	charge2 = 0;
	int choice;
	pokemon x,y;
	char tut;
	cout<<"Initializing databases";
	waitFor(1);
	cout<<".";
	waitFor(1);
	cout<<".";
	waitFor(1);
	cout<<".\n";
	waitFor(1);
	cout<<"Welcome to the Pokemon Battle Simulator ver 1.5.3!";
	waitFor(2);
	cout<<"\n\n\n\n\n\n\nWARNING: Please wait for a flashing cursor to appear before pressing enter";
	cout<<" at\nany point during this game. Failure to do so may cause fatal errors in your \n";
	cout<<"computer. We thank you for your cooperation.\n";
	waitFor(2);
	getch();
	clrscr();
	cout<<"Before the game begins, would you like to see a tutorial? (Y/N)\n";
	cin>>tut;
	clrscr();
	do
	{
		if (tut == 'y' || tut == 'Y')
		{
			tutorial();
			cout<<"Would you like to see that again? (Y/N)\n";
			cin>>tut;
			clrscr();
		}
	}while(tut == 'y' || tut == 'Y');
	cout<<"Ok! The game will begin shortly. :)\n\n";
	waitFor(2);
	clrscr();
	cout<<"Loading";
	waitFor(1);
	cout<<".";
	waitFor(1);
	cout<<".";
	waitFor(1);
	cout<<".";
	waitFor(1);
	clrscr();
	trainer t1, t2;
	t1.trainerdefn();
	do
	{
	clrscr();
	cout<<"Choose your opponent!"<<endl;
	waitFor(2);
	cout<<"1. Red"<<endl;
	cout<<"2. Blue"<<endl;
	cout<<"3. Green"<<endl;
	cout<<"4. Ash"<<endl;
	waitFor(1);
	cout<<"\nGym Leaders:"<<endl;
	waitFor(1);
	cout<<"5. Brock"<<endl;
	cout<<"6. Misty"<<endl;
	cout<<"7. Lt. Surge"<<endl;
	cout<<"8. Erika"<<endl;
	cout<<"9. Sabrina"<<endl;
	cout<<"10. Koga"<<endl;
	cout<<"11. Blaine"<<endl;
	cout<<"12. Giovanni"<<endl;
	waitFor(1);
	cout<<"\nElite Four:\n";
	waitFor(1);
	cout<<"13. Lorelei\n";
	cout<<"14. Bruno\n";
	cout<<"15. Agatha\n";
	cout<<"16. Lance\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			t2 = red;
			break;
		case 2:
			t2 = blue;
			break;
		case 3:
			t2 = green;
			break;
		case 4:
			t2 = ash;
			break;
		case 5:
			t2 = brock;
			break;
		case 6:
			t2 = misty;
			break;
		case 7:
			t2 = ltsurge;
			break;
		case 8:
			t2 = erika;
			break;
		case 9:
			t2 = sabrina;
			break;
		case 10:
			t2 = koga;
			break;
		case 11:
			t2 = blaine;
			break;
		case 12:
			t2 = giovanni;
			break;
		case 13:
			t2 = lorelei;
			break;
		case 14:
			t2 = bruno;
			break;
		case 15:
			t2 = agatha;
			break;
		case 16:
			t2 = lance;
			break;
	}
	cout<<"You have chosen to battle "<<t2.GetName()<<"!"<<endl;
	t2.ready();
	waitFor(2);
	int poknum1 = 0, poknum2 = 0;
clrscr();
x = t1.pok[poknum1];
y = t2.pok[poknum2];

cout<<t2.GetName()<<" sent out "<<t2.pok[0].GetName()<<"!\n";
waitFor(2);
cout<<"Go, "<<t1.pok[0].GetName()<<"!\n";
waitFor(2);
while(poknum1<3 && poknum2<3)
{

while (x.Faint()!=0 && y.Faint() != 0)
{  clrscr();
	if (x.spd>y.spd)
	{	if (x.wait ==0)
		{
			x.UsrTurn(y);
		}
		else
		{	--x.wait;
			cout<<x.GetName()<<" must recharge!";
			waitFor(2);
			clrscr();
		}
		x.CheckConds();
		if (x.Faint() == 0 || y.Faint() == 0)
			break;

		if (y.wait == 0)
			{
				y.CPUTurn(x);
			}
			else
			{	--y.wait;
				cout<<"Foe "<<y.GetName()<<" must recharge!\n";
				waitFor(2);
				clrscr();
			}
		y.CheckConds();
	}
	else if (y.spd>x.spd)
	{  if (y.wait == 0)
			{
				y.CPUTurn(x);
			}
			else
			{	--y.wait;
				cout<<"Foe "<<y.GetName()<<" must recharge!";
				waitFor(2);
				clrscr();
			}
			y.CheckConds();
		if (x.Faint() == 0 || y.Faint() == 0)
			break;

		if (x.wait == 0)
		{
			x.UsrTurn(y);
		}
		else
		{	--x.wait;
			cout<<x.GetName()<<" must recharge!";
			waitFor(2);
			clrscr();
		}
		x.CheckConds();
		clrscr();
	}
	else
	{	if (rand()%100+1 > 50)
		{  if (y.wait == 0)
			{
				y.CPUTurn(x);
			}
			else
			{	--y.wait;
				cout<<"Foe "<<y.GetName()<<" must recharge!";
				waitFor(2);
				clrscr();
			}
			y.CheckConds();
			if (x.Faint() == 0 || y.Faint() == 0)
			break;

			if (x.wait == 0)
			{
				x.UsrTurn(y);
			}
			else
			{	--x.wait;
				cout<<x.GetName()<<" must recharge!";
				waitFor(2);
				clrscr();
			}
			clrscr();
			x.CheckConds();
		}
		else
		{	if (x.wait == 0)
			{
				x.UsrTurn(y);
			}
			else
			{	--x.wait;
				cout<<x.GetName()<<" must recharge!";
				waitFor(2);
				clrscr();
			}
			x.CheckConds();
			if (x.Faint() == 0 || y.Faint() == 0)
			break;
			if (y.wait == 0)
			{
				y.CPUTurn(x);
			}
			else
			{	--y.wait;
				cout<<"Foe "<<y.GetName()<<" must recharge!";
				waitFor(2);
				clrscr();
			}
			clrscr();
			y.CheckConds();
		}
	}
}
if (x.Faint() == 0)
{	cout<<x.GetName()<<" has fainted!"<<endl;
	waitFor(2);
	charge = 0;
	poknum1++;

	x = t1.pok[poknum1];
	if(poknum1<3)
		cout<<"Go, "<<x.GetName()<<"!"<<endl;
	else
	{
		cout<<t1.GetName()<<" is out of usable pokemon!\n";
		waitFor(2);
		cout<<t1.GetName()<<", you were defeated!"<<endl;
		waitFor(2);
	}
}
else
{	cout<<"Foe "<<y.GetName()<<" has fainted!"<<endl;
	charge2 = 0;
	waitFor(2);
	poknum2++;
	y = t2.pok[poknum2];
	if(poknum2<3)
		cout<<t2.GetName()<<" sent out "<<y.GetName()<<"!"<<endl;
	else
	{  clrscr();
		cout<<t2.GetName()<<" is out of usable pokemon!\n";
		waitFor(2);
		cout<<t2.GetName()<<" has been defeated!\n";
		waitFor(2);
		cout<<"Congratulations, "<<t1.GetName()<<", you have won this battle!"<<endl;
	}

}
waitFor(2);
clrscr();
}
cout <<"Do you want to continue? Press Y or N.\n";
cin >> ch;
if (ch == 'n' || ch == 'N')
{
		 nads = 3;
}
else if (ch == 'y' || ch == 'Y')
		 {
					nads = 1;
		 }
clrscr();
}while (nads != 3);
clrscr();
cout<<"Credits: Nikhil A.    - The right half of the work";
cout<<"\n\t Narendran S. - The left half\n\n\n\n";
waitFor(2);
cout<<"(c)2013 The Pokemon Battle Simulator ver 1.5.3";
waitFor(5);
clrscr();
return 0;
}
