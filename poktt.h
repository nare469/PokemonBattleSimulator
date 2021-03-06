//Version 1.9.1 - Last edited 7/2/2013 by Nikhil Amarnath
//1.1 - Acid fixed
//1.2 - several bugs fixed -
/*
	1. Category 2 type moves had no prompt when they missed.
	2. Flamethrower "fails" because of ApplyCond() prompts.
*/
//1.3 -  Ancientpower, Toxic created.

//1.4 - getch replaced with waitFor

//1.7 - Smokescreen created, bug fixes made

//1.8 - Glitches removed, Rest added and fixed, Splash added

//1.9 - Update for critical hit

//1.9.1 - Bug fixes
#include "pokdecl.h"
#include "pokdb.h"
#include "tutorial.h"
#ifndef POKTT_H
#define POKTT_H
short int charge;
short int charge2;

void pokemon::UsrTurn(pokemon &y)
{  int sf;			//Final
	static short int i;
	short int chk;
	static short int choice;
	float hit;
	srand((int)time(NULL));
	clrscr();
		if (charge != 1)
		{
			do
			{	chk = 0;
				y.FoeShow();
				UsrShow();
				cin>>choice;
				if (att[choice-1].GetPP() <= 0)
				{	clrscr();
					cout<< "There's no PP left for this move!";
					waitFor(2);
					clrscr();
					chk = 1;
				}
			}while (chk !=0);

			if (cond != norm)
			{	if (cond == slp)
				{
					cout<<SleepWait<<endl;
					if (SleepWait == 0)
					{
						cond = norm;
						chk = 0;
						clrscr();
						cout<<GetName()<<" woke up!\n";
						waitFor(2);
					}
					else
					{	chk = 1;
						SleepWait--;
					}
				}
				else if (cond == par)
				{	if ((rand()%100+1) > 25)
					{
						chk = 0;
					}
					else
					{
						chk = 1;
					}
				}
			}
			else
				chk = 0;
			if (chk == 0)
			{	if (att[choice-1].cat == 1)
				{	wait = 1;
					clrscr();
					cout<<GetName()<<" used "<<att[choice-1].GetName()<<" which did damage of "<<attack1(*this, y, att[choice-1])<<"!\n";
					att[choice-1].ReducePP();
					waitFor(1);
					sf = y.supereffect(att[choice-1]) * 100;
					if (miss !=0)
					{
						if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
						switch (sf)
						{	case 0:
								waitFor(1);
								cout<<"It has no effect...\n";
								waitFor(1);
								break;
							case 25:
							case 50:
								waitFor(1);
								cout <<"Not very effective...\n";
								waitFor(1);
								break;
							case 100:
								break;
							case 200:
							case 400:
								waitFor(1);
								cout <<"It's super effective!!!\n";
								waitFor(1);
								break;
						}
					}
					else
					{	cout <<GetName()<<"'s attack missed!\n";
						wait--;
						waitFor(2);
					}
					cout<<"Foe "<<y.GetName()<<"'s health is "<<y.hp<<"\n";
				}
				else if (att[choice-1].cat == 0)
				{	clrscr();
					cout<<GetName()<<" used "<<att[choice-1].GetName()<<" which did damage of "<<attack1(*this, y, att[choice-1])<<"!\n";
					att[choice-1].ReducePP();
					sf = y.supereffect(att[choice-1])* 100;
					waitFor(1);
					if (miss !=0)
					{
						if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
						switch (sf)
						{	case 0:
								waitFor(1);
								cout<<"It has no effect...\n";
								waitFor(1);
								break;
							case 25:
							case 50:
								waitFor(1);
								cout <<"Not very effective...\n";
								waitFor(1);
								break;
							case 100:
								break;
							case 200:
							case 400:
								waitFor(1);
								cout <<"It's super effective!!!\n";
								waitFor(1);
								break;
						}
					}
					else
					{	cout <<GetName()<<"'s attack missed!\n";
						waitFor(2);
					}
					cout<<"Foe "<<y.GetName()<<"'s health is "<<y.hp<<"\n";
				}
				else if (att[choice-1].cat == 2)
				{  clrscr();
					cout <<GetName()<<" used "<<att[choice-1].GetName()<<"!\n";
					att[choice-1].ReducePP();
					if (strcmp(att[choice-1].GetName(), "Rest ") !=0)
					{
					hit = (acc/y.evs *att[choice-1].accuracy);
					if (hit >= (rand()%100+1))
						ApplyCond(y, att[choice-1]);
					else
						cout<<GetName()<<"'s attack missed!";
					}
					else
					{
						if (hp < maxhp)
						{
							cout<<GetName()<<" went to sleep!\n";
							waitFor(1);
							cond = slp;
							SleepWait = 2;
							cout<<GetName()<<"'s HP was restored!\n";
							hp = maxhp;
						}
						else
						{
							cout<<"But it failed!";
						}
					}
				}
				else if (att[choice-1].cat == 3)
				{
					clrscr();
					charge = 1;
					if (strcmpi(att[choice-1].GetName(),"Solarbeam") == 0)
					{
						cout<<GetName()<<" took in sunlight!"<<endl;
					}
					else if (strcmpi(att[choice-1].GetName(),"Sky Attack") == 0)
					{
						cout<<GetName()<<" is glowing!"<<endl;
					}
				}
				else if (att[choice-1].cat == 4)
				{
					clrscr();
					cout <<GetName()<<" used "<<att[choice-1].GetName()<<"!\n";
					att[choice-1].ReducePP();
					waitFor(2);
					if(hp == maxhp)
					{
						cout<<"But "<<GetName()<<"'s hp is full!"<<endl;
						waitFor(2);
					}
					else
					{
						hit = (acc/y.evs *att[choice-1].accuracy);
						if (hit >= (rand()%100+1))
						{
							cout <<GetName()<<" regained health!"<<endl;
							waitFor(2);
							hp = hp + (maxhp/4) + (rand()%(maxhp/4)+1);
							if(hp>maxhp)
							{
								hp = maxhp;
							}
						}
						else
						{
							cout<<"But it failed!"<<endl;
						}
					}
					cout<<GetName()<<"'s health is "<<hp<<"\n";
				}
				else if (att[choice-1].cat == 5)
				{
					clrscr();
					cout <<GetName()<<" used "<<att[choice-1].GetName()<<"!\n";
					att[choice-1].ReducePP();
					waitFor(2);
					hit = (acc/y.evs *att[choice-1].accuracy);
						if (hit >= (rand()%100+1))
						{
							if ( strcmpi(att[choice-1].GetName(), "growl") == 0)
							{
								cout<<"Foe "<<y.GetName()<<"'s attack fell!"<<endl;
								y.atk = y.atk - (y.atk/4);
							}
							else if (strcmpi(att[choice-1].GetName(), "swords dance") == 0)
							{
								cout<<GetName()<<"'s attack sharply rose!"<<endl;
								atk = atk + (atk/3);
							}
							else if (strcmpi(att[choice-1].GetName(), "Smokescreen") == 0)
							{
								cout<<"Foe "<<y.GetName()<<"'s accuracy fell!"<<endl;
								y.acc = y.acc - (y.acc/3);
							}
						}
						else
						{
							cout<<"But it failed!"<<endl;
						}
				}
				else if (att[choice-1].cat == 6)
				{
					clrscr();
					cout <<GetName()<<" used "<<att[choice-1].GetName()<<"!\n";
					att[choice-1].ReducePP();
					waitFor(2);
					if (y.supereffect(att[choice-1]) == 0)
					{
						cout<<"It doesn't effect foe "<<y.GetName()<<" ...\n";
					}
					else
					{
						hit = (acc/y.evs *att[choice-1].accuracy);
						if (hit >= (rand()%100+1))
						{
							cout<<"It's a one-hit KO!!!"<<endl;
							y.hp = 0;
							cout<<"Foe "<<y.GetName()<<"'s health is "<<y.hp<<"\n";
						}
						else
						{
							cout<<GetName()<<"'s attack missed!"<<endl;
						}
					}
				}
				else if (att[choice-1].cat == 7)
				{	clrscr();
					cout<<GetName()<<" used "<<att[choice-1].GetName()<<" which did damage of "<<attack1(*this, y, att[choice-1])<<"!\n";
					att[choice-1].ReducePP();
					sf = y.supereffect(att[choice-1])* 100;

					if (miss !=0)
					{
						if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
						switch (sf)
						{	case 0:
								waitFor(1);
								cout<<"It has no effect...\n";
								waitFor(1);
								break;
							case 25:
							case 50:
								waitFor(1);
								cout <<"Not very effective...\n";
								waitFor(1);
								break;
							case 100:
								break;
							case 200:
							case 400:
								waitFor(1);
								cout <<"It's super effective!!!\n";
								waitFor(1);
								break;
						}
					}
					else
					{	cout <<GetName()<<"'s attack missed!\n";
						waitFor(2);
					}
					cout<<"Foe "<<y.GetName()<<"'s health is "<<y.hp<<"\n";
					if (y.cond == norm)
					{
						if(att[choice-1].condperc > rand()%100+1)
						{  if (sf != 0)
							{
								ApplyCond(y,att[choice-1]);
							}
						}
					}
				}
				else if (att[choice-1].cat == 8)
				{  int Health;
					Health = attack1(*this, y, att[choice-1]);
					clrscr();
					cout<<GetName()<<" used "<<att[choice-1].GetName()<<" which did damage of "<<Health<<"!\n";
					att[choice-1].ReducePP();
					sf = y.supereffect(att[choice-1])* 100;

					if (miss !=0)
					{  if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
						switch (sf)
						{	case 0:
								waitFor(1);
								cout<<"It has no effect...\n";
								waitFor(1);
								break;
							case 25:
							case 50:
								waitFor(1);
								cout <<"Not very effective...\n";
								waitFor(1);
								break;
							case 100:
								break;
							case 200:
							case 400:
								waitFor(1);
								cout <<"It's super effective!!!\n";
								waitFor(1);
								break;
						}
					}
					else
					{	cout <<GetName()<<"'s attack missed!\n";
						waitFor(2);
					}
					cout<<"Foe "<<y.GetName()<<"'s health is "<<y.hp<<"\n";
					waitFor(2);
					clrscr();
					if (miss !=0)
					{	cout<<GetName()<<" lost "<<(attack1(*this, y, att[choice-1])/4)<<" HP due to recoil"<<endl;
						hp = hp - (Health/4);
					}
				}
				else if (att[choice-1].cat == 9)
				{
					clrscr();
					cout<<GetName()<<" used Transform!"<<endl;
					att[choice-1].ReducePP();
					waitFor(2);
					cout<<GetName()<<" transformed into "<<y.GetName()<<"!"<<endl;
					for (int q = 0; q<4; q++)
					{
						att[q] = y.att[q];
						att[q].ReducePP();
					}
					type1 = y.type1;
					type2 = y.type2;

				}
				else if (att[choice-1].cat == 10)
				{
					clrscr();
					cout<<GetName()<<" used "<<att[choice-1].GetName()<<" which did damage of "<<attack1(*this, y, att[choice-1])<<"!\n";
					waitFor(2);
					att[choice-1].ReducePP();
					sf = y.supereffect(att[choice-1])* 100;

					if (miss !=0)
					{  if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
						switch (sf)
						{	case 0:
								waitFor(1);
								cout<<"It has no effect...\n";
								waitFor(1);
								break;
							case 25:
							case 50:
								waitFor(1);
								cout <<"Not very effective...\n";
								waitFor(1);
								break;
							case 100:
								break;
							case 200:
							case 400:
								waitFor(1);
								cout <<"It's super effective!!!\n";
								waitFor(1);
								break;
						}
						if (strcmp(att[choice-1].GetName(), "Acid ") == 0)
						{	if (rand()%100+1 < 10)
							{
								cout<<y.GetName()<<"'s defence was lowered!\n";
								waitFor(2);
								y.def -= (25/100 * y.def);
							}
						}
						if (strcmpi(att[choice-1].GetName(), "Overheat")== 0)
						{
							clrscr();
							atk = atk - (1/3 * atk);
							waitFor(1);
							cout<<GetName()<<"'s sp. attack sharply fell!\n";
							waitFor(1);
						}
						if (strcmpi(att[choice-1].GetName(), "Shadow Ball")== 0)
						{
							if (rand()%100+1 < 10)
							{clrscr();
							y.def = y.def - (1/4 * y.def);
							waitFor(1);
							cout<<y.GetName()<<"'s sp. defence fell!\n";
							waitFor(1);
							}
						}
						if (strcmp(att[choice-1].GetName(), "Ancientpower") == 0)
						{	if (rand()%100+1 < 10)
							{
								clrscr();
								atk = atk + (1/4 * atk);
								def = def + (1/4 * def);
								spd = spd + (1/4 * spd);
								cout<<GetName()<<"'s attack increased!\n";
								waitFor(1);
								cout<<GetName()<<"'s defence increased!\n";
								waitFor(1);
								cout<<GetName()<<"'s sp. attack increased!\n";
								waitFor(1);
								cout<<GetName()<<"'s sp. defence increased!\n";
								waitFor(1);
								cout<<GetName()<<"'s speed increased!\n";
								waitFor(2);
							}
						}
					}
					else
					{	cout <<GetName()<<"'s attack missed!\n";
						waitFor(2);
					}
					cout<<"Foe "<<y.GetName()<<"'s health is "<<y.hp<<"\n";
				}
				else if (att[choice-1].cat == 11)
				{
					int health = attack1(*this, y, att[choice-1]);

					cout<<GetName()<<" used "<<att[choice-1].GetName()<<" which did damage of "<<health<<"!\n";
					waitFor(2);
					att[choice-1].ReducePP();
					sf = y.supereffect(att[choice-1])* 100;

					if (miss !=0)
					{
						if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
						switch (sf)
						{	case 0:
								waitFor(1);
								cout<<"It has no effect...\n";
								waitFor(1);
								break;
							case 25:
							case 50:
								waitFor(1);
								cout <<"Not very effective...\n";
								waitFor(1);
								break;
							case 100:
								break;
							case 200:
							case 400:
								waitFor(1);
								cout <<"It's super effective!!!\n";
								waitFor(1);
								break;
						}
						cout<<GetName()<<" gained "<<(health/4)<<" HP!\n";
						hp += (1/4 * health);
						if (hp > maxhp)
							hp = maxhp;
						waitFor(1);
					}
					cout<<"Foe "<<y.GetName()<<"'s health is "<<y.hp<<"\n";
				}
				else if (att[choice-1].cat == 12)
				{	clrscr();
					att[choice-1].ReducePP();
					cout<<GetName()<<" used "<<att[choice-1].GetName()<<"!\n";
					waitFor(2);
					cout<<"But nothing happened!\n";
				}
				waitFor(2);
				clrscr();
			}
			else
			{  if (cond == slp)
				{	clrscr();
					cout<<GetName()<<" is fast asleep.";
					waitFor(2);
				}
				else if (cond == par)
				{	clrscr();
					cout<<GetName()<<" is paralysed! It can't move!";
					waitFor(2);
				}
			}
		}
		else if (charge == 1)
		{
			charge = 0;
			clrscr();
			cout<<GetName()<<" used "<<att[choice-1].GetName()<<" which did damage of "<<attack1(*this, y, att[choice-1])<<"!\n";
			att[choice-1].ReducePP();
			sf = y.supereffect(att[choice-1])* 100;
			if (miss !=0)
			{
				if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
				switch (sf)
				{

					case 0:
						waitFor(1);
						cout<<"It has no effect...\n";
						waitFor(1);
						break;
					case 25:
					case 50:
						waitFor(1);
						cout <<"Not very effective...\n";
						waitFor(1);
						break;
					case 100:
						break;
					case 200:
					case 400:
						waitFor(1);
						cout <<"It's super effective!!!\n";
						waitFor(1);
						break;
					}
				}
				else
				{
					cout <<GetName()<<"'s attack missed!!!\n";
					waitFor(2);
				}
				cout<<"Foe "<<y.GetName()<<"'s health is "<<y.hp<<"\n";
				waitFor(2);
			}
}

void pokemon::CPUTurn(pokemon &x)
{
	int sf;			//Final
	static short int i;
	short int chk;
	static short int choice;
	float hit;
	srand((int)time(NULL));
	clrscr();
		if (charge2 == 0)
		{
			i = AIatk(x);
			chk = 0;
			if (cond != norm)
			{
				if (cond == slp)
				{
					if (SleepWait == 0)
					{
						cond = norm;
						chk = 0;
						clrscr();
						cout<<"Foe "<<GetName()<<" woke up!\n";
					}
					else
					{
						chk = 1;
						SleepWait--;
					}
				}
				else if (cond == par)
				{	if ((rand()%100+1) > 25)
					{
						chk = 0;
					}
					else
					{
						chk = 1;
					}
				}
			}
			if (chk == 0)
			{  if (att[i].cat == 1 || att[i].cat == 0)
				{	cout<<"Foe "<<GetName()<<" used "<< att[i].GetName()<<" which did damage of "<<attack1(*this,x,att[i])<<"!\n";
					waitFor(2);
					if (att[i].cat == 1)
					{
						wait = 1;
					}
					att[i].ReducePP();
					sf = supereffect(att[i]) * 100;
					if (miss !=0)
					{
						if (critdamage == 1.5)
							{  waitFor(1);
								cout<<"A critical hit!\n";
								waitFor(1);
							}
						switch (sf)
						{
							case 0:
								cout<<"It has no effect...\n";
								break;
							case 25:
							case 50:
								cout <<"Not very effective...\n";
								break;
							case 100:
								break;
							case 200:
							case 400:
								cout <<"It's super effective!!!\n";
								break;
						}
						cout<<x.GetName()<<"'s health is "<<x.hp<<"\n";
					}
					else
					{	cout <<GetName()<<"'s attack missed!\n";
					}
				}
				else if (att[i].cat == 2)
				{	clrscr();
					cout <<"Foe "<<GetName()<<" used "<<att[i].GetName()<<"!\n";
					att[i].ReducePP();
					if (strcmp(att[i].GetName(), "Rest ") !=0)
					{
						hit = (acc/x.evs *att[i].accuracy);
						if (hit >= (rand()%100+1))
							ApplyCond(x,att[i]);
						else
							cout<<GetName()<<"'s attack missed!"<<endl;
					}
					else
					{
						if (hp < maxhp)
						{
							cout<<GetName()<<" went to sleep!\n";
							waitFor(1);
							cond = slp;
							SleepWait = 2;
							cout<<GetName()<<"'s HP was restored!\n";
							hp = maxhp;
						}
						else
						{
							cout<<"But it failed!";
						}
					}
				}
				else if (att[i].cat == 3)
				{
					clrscr();
					charge2 = 1;
					if (strcmpi(att[i].GetName(),"Solarbeam") == 0)
					{
						cout<<"Foe "<<GetName()<<" took in sunlight!"<<endl;
						waitFor(2);
					}
					else if (strcmpi(att[i].GetName(),"Sky Attack") == 0)
					{
						cout<<"Foe "<<GetName()<<" is glowing!"<<endl;
						waitFor(2);
					}

				}
				else if (att[i].cat == 4)
				{
					clrscr();
					cout <<"Foe "<<GetName()<<" used "<<att[i].GetName()<<"!\n";
					att[i].ReducePP();
					waitFor(2);
					if(hp == maxhp)
					{
						cout<<"But "<<"Foe "<<GetName()<<"'s hp is full!"<<endl;
						waitFor(2);
					}
					else
					{
						hit = (acc/x.evs *att[i].accuracy);
						if (hit >= (rand()%100+1))
						{
							cout <<"Foe "<<GetName()<<" regained health!"<<endl;
							waitFor(2);
							hp = hp + (maxhp/4)+ (rand()% (hp/4) +1);
							if(hp>maxhp)
							{
								hp = maxhp;
							}
						}
						else
							cout<<"But it failed!"<<endl;
					}
					cout<<"Foe "<<GetName()<<"'s health is "<<hp<<"\n";
				}
				else if (att[i].cat == 5)
				{
					clrscr();
					cout <<"Foe "<<GetName()<<" used "<<att[i].GetName()<<"!\n";
					att[i].ReducePP();
					waitFor(1);
					hit = (acc/x.evs *att[i].accuracy);
					if (hit >= (rand()%100+1))
					{
						if (strcmpi(att[i].GetName(), "growl") == 0)
						{
							cout<<x.GetName()<<"'s attack fell!"<<endl;
							x.atk = x.atk - (x.atk/4);
						}
						else if (strcmpi(att[i].GetName(), "swords dance") == 0)
						{
							cout<<GetName()<<"'s attack sharply rose!"<<endl;
							atk = atk + (atk/3);
						}
						else if (strcmpi(att[i].GetName(), "Smokescreen") == 0)
						{
							cout<<"Foe "<<x.GetName()<<"'s accuracy sharply fell!"<<endl;
							x.acc = x.acc - (x.acc/3);
						}
					}
					else
					{
						cout<<GetName()<<"'s attack missed!"<<endl;
						waitFor(1);
					}
				}
				else if (att[i].cat == 6)
				{
					clrscr();
					cout <<"Foe "<<GetName()<<" used "<<att[i].GetName()<<"!\n";
					att[i].ReducePP();
					waitFor(1);
					if (x.supereffect(att[i]) == 0)
					{
						cout<<"It has no effect...\n";
					}
					else
					{
						hit = (acc/x.evs *att[i].accuracy);
						if (hit >= (rand()%100+1))
						{
							cout<<"It's a one-hit KO!!!"<<endl;
							x.hp = 0;
							cout<<"Foe "<<x.GetName()<<"'s health is "<<x.hp<<"\n";
						}
						else
						{
							cout<<"Attack missed!!!"<<endl;
						}
					}
				}
				else if (att[i].cat == 7)
				{	clrscr();
					cout<<GetName()<<" used "<<att[i].GetName()<<" which did damage of "<<attack1(*this, x, att[i])<<"!\n";
					att[i].ReducePP();
					sf = x.supereffect(att[i])* 100;

					if (miss !=0)
					{  if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
						switch (sf)
						{	case 0:
								waitFor(1);
								cout<<"It has no effect...\n";
								waitFor(1);
								break;
							case 25:
							case 50:
								waitFor(1);
								cout <<"Not very effective...\n";
								waitFor(1);
								break;
							case 100:
								break;
							case 200:
							case 400:
								waitFor(1);
								cout <<"It's super effective!!!\n";
								waitFor(1);
								break;
						}
					}
					else
					{	cout <<GetName()<<"'s attack missed!\n";
						waitFor(1);
					}
					cout<<"Foe "<<x.GetName()<<"'s health is "<<x.hp<<"\n";
					if (x.cond == norm)
					{
						if(att[i].condperc > rand()%100+1)
						{  if (sf != 0)
							{
								ApplyCond(x,att[i]);
							}
						}
					}
				}
				else if (att[i].cat == 8)
				{  int Health = attack1(*this, x, att[i]);
					clrscr();
					cout<<GetName()<<" used "<<att[i].GetName()<<" which did damage of "<<Health<<"!\n";
					att[choice-1].ReducePP();
					sf = x.supereffect(att[i])* 100;

					if (miss !=0)
					{  if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
						switch (sf)
						{	case 0:
								waitFor(1);
								cout<<"It has no effect...\n";
								waitFor(1);
								break;
							case 25:
							case 50:
								waitFor(1);
								cout <<"Not very effective...\n";
								waitFor(1);
								break;
							case 100:
								break;
							case 200:
							case 400:
								waitFor(1);
								cout <<"It's super effective!!!\n";
								waitFor(1);
								break;
						}
					}
					else
					{	cout <<GetName()<<"'s attack missed!\n";
						waitFor(1);
					}
					cout<<"Foe "<<x.GetName()<<"'s health is "<<x.hp<<"\n";
					waitFor(2);
					clrscr();
					if (miss != 0)
					{
						cout<<GetName()<<" lost "<<(Health/4)<<" HP due to recoil!"<<endl;
						hp = hp - (Health/4);
					}
				}
				else if (att[i].cat == 9)
				{
					clrscr();
					cout<<GetName()<<" used Transform!"<<endl;
					att[i].ReducePP();
					waitFor(1);
					cout<<GetName()<<" transformed into "<<x.GetName()<<"!"<<endl;
					for (int r = 0; r<4; r++)
					{
						att[r] = x.att[r];
						att[r].ReducePP();
					}
					type1 = x.type1;
					type2 = x.type2;

				}
				else if (att[i].cat == 10)
				{	cout<<GetName()<<" used "<<att[i].GetName()<<" which did damage of "<<attack1(*this, x, att[i])<<"!\n";
					att[i].ReducePP();
					sf = x.supereffect(att[i])* 100;
					waitFor(1);
					if (miss !=0)
					{
               	if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
						switch (sf)
						{	case 0:
								cout<<"It has no effect...\n";
								waitFor(1);
								break;
							case 25:
							case 50:
								cout <<"Not very effective...\n";
								waitFor(1);
								break;
							case 100:
								break;
							case 200:
							case 400:
								cout <<"It's super effective!!!\n";
								waitFor(1);
								break;
						}
						if (strcmp(att[i].GetName(), "Acid ") == 0)
						{	if (rand()%100+1 < 10)
							{
								cout<<x.GetName()<<"'s defence was lowered!\n";
								waitFor(1);
								x.atk -= (25/100 * x.atk);
							}
						}
						if (strcmp(att[i].GetName(), "Ancientpower") == 0)
						{	if (rand()%100+1 < 10)
							{
								clrscr();
								atk = atk + (1/4 * atk);
								def = def + (1/4 * def);
								spd = spd + (1/4 * spd);
								cout<<GetName()<<"'s attack increased!\n";
								waitFor(1);
								cout<<GetName()<<"'s defence increased!\n";
								waitFor(1);
								cout<<GetName()<<"'s sp. attack increased!\n";
								waitFor(1);
								cout<<GetName()<<"'s sp. defence increased!\n";
								waitFor(1);
								cout<<GetName()<<"'s speed increased!\n";
								waitFor(1);
							}
						}
						if (strcmpi(att[i].GetName(), "Overheat")== 0)
						{
							clrscr();
							atk = atk - (1/3 * atk);
							waitFor(1);
							cout<<GetName()<<"'s sp. attack fell!\n";
							waitFor(1);
						}
						if (strcmpi(att[i].GetName(), "Shadow Ball")== 0)
						{  if (rand()%100+1 < 10)
							{
								clrscr();
								def = def - (1/4 * def);
								waitFor(1);
								cout<<GetName()<<"'s sp. defence fell!\n";
								waitFor(1);
							}
						}

					}
					cout<<"Foe "<<x.GetName()<<"'s health is "<<x.hp<<"\n";
					waitFor(2);
				}
				else if (att[i].cat == 11)
				{
					int health = attack1(*this, x, att[i]);

					cout<<GetName()<<" used "<<att[i].GetName()<<" which did damage of "<<health<<"!\n";
					waitFor(2);
					att[i].ReducePP();
					sf = x.supereffect(att[i])* 100;

					if (miss !=0)
					{  if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
						switch (sf)
						{	case 0:
								waitFor(1);
								cout<<"It has no effect...\n";
								waitFor(1);
								break;
							case 25:
							case 50:
								waitFor(1);
								cout <<"Not very effective...\n";
								waitFor(1);
								break;
							case 100:
								break;
							case 200:
							case 400:
								waitFor(1);
								cout <<"It's super effective!!!\n";
								waitFor(1);
								break;
						}
						cout<<GetName()<<" gained "<<(health/2)<<" HP!\n";
						hp += (1/2 * health);
						if (hp > maxhp)
							hp = maxhp;
						waitFor(1);
					}
					cout<<"Foe "<<x.GetName()<<"'s health is "<<x.hp<<"\n";
				}
				else if (att[i].cat == 12)
				{	clrscr();
					cout<<GetName()<<" used "<<att[i].GetName()<<"!\n";
					waitFor(2);
					cout<<"But nothing happened!\n";
					waitFor(1);
				}
				waitFor(1);
				clrscr();
			}

			else
			{  if (cond == slp)
				{	clrscr();
					cout<<"Foe "<<GetName()<<" is fast asleep.";
					waitFor(1);
				}
				else if (cond == par)
				{	clrscr();
					cout<<"Foe "<<GetName()<<" is paralysed! It can't move!";
					waitFor(1);
				}
			}
		}
		else if (charge2 == 1)
		{
			charge2 = 0;
			cout<<"Foe "<<GetName()<<" used "<< att[i].GetName()<<" which did damage of "<<attack1(*this,x,att[i])<<"\n";
			att[i].ReducePP();
			sf = x.supereffect(att[i]) * 100;
			if (miss !=0)
			{  if (critdamage == 1.5)
						{  waitFor(1);
							cout<<"A critical hit!\n";
							waitFor(1);
						}
				switch (sf)
				{
					case 0:
						waitFor(1);
						cout<<"It has no effect...\n";
						waitFor(1);
						break;
					case 25:
					case 50:
						waitFor(1);
						cout <<"Not very effective...\n";
						waitFor(1);
						break;
					case 100:
						break;
					case 200:
					case 400:
						waitFor(1);
						cout <<"It's super effective!!!\n";
						waitFor(1);
						break;
				}
				cout<<x.GetName()<<"'s health is "<<x.hp<<"\n";
			}
			else
			{
				cout <<GetName()<<"'s attack missed!\n";
			}
			waitFor(2);
		}
	}
#endif