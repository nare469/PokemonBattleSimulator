//Version 1.3 - Last edited 3/2/2013 by Nads

//Version 1.1 - Update package for "attack1" for spatk and spdef stats
//Reverting to Version 1.0
//Version 1.2 - ApplyCond modified to correspond with type matchup protocol

//Version 1.3 - getch removed. waitFor added.

#include "pokdecl.h"
#include "poksf.h"
#include "pokdb.h"
#include <string.h>
#include <iostream.h>
#include <time.h>
#ifndef POKBAT_H
#define POKBAT_H
void ApplyCond(pokemon &X, attack a)
{  if (X.supereffect(a) == 0)
	{  waitFor(2);
		cout<<"It has no effect...\n";
	}
	else
	{
		srand((int)time(NULL));
		if(X.Okay())
		{  if (a.effecttype== slp)
			{
				X.CondSlp();
			}
			else if (a.effecttype == par)
			{
				X.CondPar();
			}
			else if (a.effecttype == psn)
			{  if (X.ChkPoison() == 0)
				{
					if (strcmp(a.GetName(), "Toxic") == 0)
					{
						X.CondTox();
					}
					else
					{
						X.CondPsn();
					}
				}
				else
				{
					cout<<"\nIt doesn't affect foe "<<X.GetName()<<"...\n";
				}
			}
			else if(a.effecttype == brn)
			{
				X.CondBrn();
			}
		}
		else
		{
			cout<<"\n"<<"But it failed!";
		}
	}
}

//battle damage equation
int attack1(pokemon a,pokemon &b,attack y)
{  srand((int)time(NULL));
	float hit;
	hit = (a.acc/b.evs * y.accuracy);
	float x;
	float t = a.STAB(y);
	if ( (rand()%100+1) < (y.critlvl * 6.25))
	{	critdamage = 1.5;
	}
	else
	{	critdamage = 1;}
	x = ((22 * a.atk/b.def * y.power)/50 + 2) * critdamage*t*b.supereffect(y)*((float)(rand()%15 +85)/100);
	if (hit >= (rand()%100+1))
	{miss = 1;
	if (x > b.hp)
	x = b.hp;
	b.hp -= (int)x;
	return (int)x;}
	else
	{miss =0;
	return 0;}
}



int pokemon::AIatk(pokemon USER)
{  srand((int)time(NULL));
	int swp,i,j;
	int AIatks[2][4];

	//THIS ARRAY CONTAINS AMOUNT OF DAMAGE THAT EACH MOVE OF THE AI POKEMON DOES TO A REGULAR POKEMON
	for (i = 0; i <4; i++)
	{	AIatks[1][i] = attack1(*this,USER,att[i]);
		AIatks[0][i] = i;
	}

	//SORTING ATTACKS BY DAMAGE IT DOES
	for (i = 0; i <3; i++)
	{  for (j = i; j < 4; j++)
		{	if (AIatks[1][i] < AIatks[1][j])
			{	swp = AIatks[0][j];
				AIatks[0][j] = AIatks[0][i];
				AIatks[0][i] = swp;
				swp = AIatks[1][j];
				AIatks[1][j] = AIatks[1][i];
				AIatks[1][i] = swp;
			}
		}
	}

	//RANDOMISING ATTACKS
		if (rand()%100+1 > 50)
		{  return AIatks[0][0];
		}
		else if (rand()%100+1 > 50)
		{  return AIatks[0][1];
		}
		else if (rand()%100+1 > 50)
		{  return AIatks[0][2];
		}
		else
		{  return AIatks[0][3];
		}

}

#endif
