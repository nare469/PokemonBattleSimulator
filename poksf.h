//Version 1.1 - Last edited 6/2/2013 by Nikhil Amarnath
//tx = 0 fixes added
#include "pokdecl.h"
#ifndef SUPEREFFECT_H
#define SUPEREFFECT_H
float pokemon::supereffect(attack b)
{  float tx = 1;
	type x = b.GetType();
	if (x == grass)
	{
		switch (type1)
		{
			case fire:
			case grass:
			case flying:
			case poison:
			case steel:
			case dragon:
			case bug:
				tx = tx/2;
				break;
			case water:
			case rock:
			case ground:
				tx *= 2;
				break;
		}
		switch (type2)
		{
			case fire:
			case grass:
			case flying:
			case poison:
			case steel:
			case dragon:
			case bug:
				tx /= 2;
				break;
			case water:
			case rock:
			case ground:
				tx *= 2;
				break;
		}
	}
	else if (x == fire)
	{
		switch (type1)
		{
			case fire:
			case water:
			case rock:
			case dragon:
				tx/=2;
				break;
			case grass:
			case bug:
			case steel:
			case ice:
				tx*=2;
		}
		switch (type2)
		{
			case fire:
			case water:
			case rock:
			case dragon:
				tx/=2;
				break;
			case grass:
			case bug:
			case steel:
			case ice:
				tx*=2;
		}
	}
	else if (x == water)
	{
		switch (type1)
		{
			case water:
			case grass:
			case dragon:
				tx/=2;
				break;
			case fire:
			case ground:
			case rock:
				tx*=2;
				break;
		}
		switch (type2)
		{
			case water:
			case grass:
			case dragon:
				tx/=2;
				break;
			case fire:
			case ground:
			case rock:
				tx*=2;
				break;
		}
	}
	else if (x == electr)
	{
		switch (type1)
		{
			case grass:
			case dragon:
			case electr:
				tx/=2;
				break;
			case water:
			case flying:
				tx*=2;
				break;
			case ground:
				tx=0;
				break;
		}
		switch (type2)
		{
			case grass:
			case dragon:
			case electr:
				tx/=2;
				break;
			case water:
			case flying:
				tx*=2;
				break;
			case ground:
				tx=0;
				break;
		}
	}
	else if (x == ground)
	{
		switch (type1)
		{
			case fire:
			case poison:
			case rock:
			case electr:
			case steel:
				tx*=2;
				break;
			case bug:
			case grass:
				tx/=2;
				break;
			case flying:
				tx=0;
				break;
		}
		switch (type2)
		{
			case fire:
			case poison:
			case rock:
			case electr:
				tx*=2;
				break;
			case bug:
			case grass:
				tx/=2;
				break;
			case flying:
				tx=0;
				break;
		}
	}
	else if (x == rock)
	{
		switch (type1)
		{
			case fight:
			case ground:
			case steel:
				tx/=2;
				break;
			case flying:
			case bug:
			case fire:
			case ice:
				tx*=2;
				break;
		}
		switch (type2)
		{
			case fight:
			case ground:
			case steel:
				tx/=2;
				break;
			case flying:
			case bug:
			case ice:
			case fire:
				tx*=2;
				break;
		}
	}
	else if (x == psychic)
	{
		switch (type1)
		{
			case psychic:
			case steel:
				tx/=2;
				break;
			case fight:
			case poison:
				tx*=2;
				break;
			case dark:
				tx=0;
				break;
		}
		switch (type2)
		{
			case psychic:
			case steel:
				tx/=2;
				break;
			case fight:
			case poison:
				tx*=2;
				break;
			case dark:
				tx=0;
				break;
		}
	}
	else if (x == dark)
	{
		switch (type1)
		{
			case fight:
			case steel:
			case dark:
				tx/=2;
				break;
			case ghost:
			case psychic:
				tx*=2;
				break;
		}
		switch (type2)
		{
			case fight:
			case steel:
			case dark:
				tx/=2;
				break;
			case ghost:
			case psychic:
				tx*=2;
				break;
		}
	}
	else if (x == normal)
	{
		switch (type1)
		{
			case rock:
			case steel:
				tx/=2;
				break;
			case ghost:
				tx=0;
		}
		switch (type2)
		{
			case rock:
			case steel:
				tx/=2;
				break;
			case ghost:
				tx=0;
		}
	}
	else if (x == fight)
	{
		switch (type1)
		{
			case poison:
			case flying:
			case bug:
			case psychic:
				tx/=2;
				break;
			case normal:
			case rock:
			case steel:
			case ice:
			case dark:
				tx*=2;
				break;
			case ghost:
				tx=0;
		}
		switch (type2)
		{
			case poison:
			case flying:
			case bug:
			case psychic:
				tx/=2;
				break;
			case normal:
			case rock:
			case steel:
			case ice:
			case dark:
				tx*=2;
				break;
			case ghost:
				tx=0;
		}
	}
	else if (x == flying)
	{
		switch (type1)
		{
			case steel:
			case rock:
			case electr:
				tx/=2;
				break;
			case bug:
			case fight:
			case grass:
				tx*=2;
				break;
		}
		switch (type2)
		{
			case steel:
			case rock:
			case electr:
				tx/=2;
				break;
			case bug:
			case fight:
			case grass:
				tx*=2;
				break;
		}
	}
	else if (x == dragon)
	{
		switch (type1)
		{
			case dragon:
				tx*=2;
				break;
			case steel:
				tx/=2;
				break;
		}
		switch (type2)
		{
			case dragon:
				tx*=2;
				break;
			case steel:
				tx/=2;
				break;
		}
	}
	else if (x == poison)
	{
		switch (type1)
		{
			case bug:
			case grass:
				tx*=2;
				break;
			case ghost:
			case ground:
			case rock:
			case poison:
				tx/=2;
				break;
			case steel:
				tx = 0;
				break;
		}
		switch (type2)
		{
			case bug:
			case grass:
				tx*=2;
				break;
			case ghost:
			case ground:
			case rock:
			case poison:
				tx/=2;
				break;
			case steel:
				tx = 0;
				break;
		}
	}
	else if (x == bug)
	{
		switch (type1)
		{
			case dragon:
			case flying:
			case grass:
			case ground:
				tx*=2;
				break;
			case ice:
			case fire:
			case water:
			case steel:
				tx/=2;
				break;
		}
		switch (type2)
		{
			case dragon:
			case flying:
			case grass:
			case ground:
				tx*=2;
				break;
			case ice:
			case fire:
			case water:
			case steel:
				tx/=2;
				break;
		}
	}
	else if (x == steel)
	{
		switch (type1)
		{
			case ice:
			case rock:
				tx*=2;
				break;
			case electr:
			case fire:
			case water:
			case steel:
				tx/=2;
				break;
		}
		switch (type2)
		{
			case ice:
			case rock:
				tx*=2;
				break;
			case electr:
			case fire:
			case water:
			case steel:
				tx/=2;
				break;
		}
	}
	else if (x == ghost)
	{
		switch (type1)
		{
			case ghost:
			case psychic:
				tx*=2;
				break;
			case dark:
				tx/=2;
				break;
			case normal:
				tx = 0;
				break;
		}
		switch (type2)
		{
			case ghost:
			case psychic:
				tx*=2;
				break;
			case dark:
				tx/=2;
				break;
      	case normal:
				tx = 0;
				break;
		}
	}
	else if (x == ice)
	{
		switch (type1)
		{
			case dragon:
			case flying:
			case grass:
			case ground:
				tx*=2;
				break;
			case ice:
			case water:
			case fire:
				tx/=2;
				break;
		}
		switch (type2)
		{
			case dragon:
			case flying:
			case grass:
			case ground:
				tx*=2;
				break;
			case ice:
			case water:
				tx/=2;
				break;
		}
	}
	return tx;
}
#endif