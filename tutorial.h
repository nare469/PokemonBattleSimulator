//Version 1.2- Last edited 5/2/2013 by Nads
//1.1 - getch() changed to wait.
//1.2 - waitFor changed to getch() LOL xD
#include <iostream.h>
#include "pokdecl.h"
#include "pokdb.h"
#include <conio.h>
#ifndef TUTORIAL_H
#define TUTORIAL_H

void tutorial()
{  clrscr();
	cout<<"Welcome to the wonderful world of Pokemon. This is a world like\n";
	cout<<"no other. It is a world where magical beasts befriend humans and\n";
	cout<<"live together. There are many mysterious Pokemon, and they all\n";
	cout<<"are special in different ways; there are Pokemon of various types.\n";
	cout<<"Each type gives them certain abilities...\n";
	cout<<"These abilities prove to be useful when Pokemon Trainers indulge in\n";
	cout<<"their greatest passion. Battling.";
	waitFor(3);
	cout<<"\nPress any key to continue..."<<endl;
	getch();
	clrscr();
	cout<<"Trainer Battles are one on one battles in which you pit 3 of your Pokemon\n";
	cout<<"against 3 of your opponent's pokemon in order, one by one. The objective of\n";
	cout<<"a Pokemon battle is to reduce your opponent's vitality. This vitality is in\n";
	cout<<"the form of HP, or Hit Points. Once a Pokemon's HP reaches zero, it faints.\n";
	waitFor(3);
	cout<<"Press any key to continue..."<<endl;
	getch();
	clrscr();
	cout<<"First you must choose your Pokemon.\n";
	cout<<"This choice will be a major factor in deciding the outcome of battle.\n";
	cout<<"The trainers you will face mostly specialise in a certain type of \n";
	cout<<"Pokemon. This has its advantages and disadvantages. Each type has a\n";
	cout<<"weakness and a strength; Fire is strong against Grass but weak to\n";
	cout<<"water. Type Matchup plays a key role. This Type Matchup will also\n";
	cout<<"matter when you are actually in battle; select your moves wisely.\n";
	waitFor(3);
	cout<<"Press any key to continue..."<<endl;
	getch();
	clrscr();
	cout<<"Pokemon battles aren't all about attacking. Some Pokemon moves do not damage\n";
	cout<<"the opponent but inflict an ailment upon it; these are called condition moves.\n";
	cout<<"Condition moves, used well, can prove to be essential to victory. For example,\n";
	cout<<"using 'Stun Spore' paralyses the opponent, which means the opponent's speed \n";
	cout<<"lowers, and it will sometimes not be able to attack.";
	waitFor(3);
	cout<<"\nPress any key to continue..."<<endl;
	getch();
	clrscr();
}
#endif

