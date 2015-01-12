//Version 1.7 - Last edited by Narendran Srinivasan 12/10/2013

//Version 1.1.0 - Acid modified, Arbok created.
//Version 1.1.1 - Ancientpower modified, toxic and fissure created.

//Version 1.2 - Koga Sabrina Erika and Surge added

//Version 1.3 - Blaine added

//Version 1.4 - Edits made, Splash and Magikarp added

//Version 1.5 - Elite Four added

//1.6 - Johto legendaries added
//		-update; few pokemon have newer attacks now.

//1.7 - Hoenn legendaries added


#include "pokdecl.h"
#include <string.h>
#ifndef POKDB_H
#define POKDB_H

trainer blaine("Blaine\0");
trainer red("Red\0");
trainer koga("Koga\0");
trainer sabrina("Sabrina\0");
trainer blue("Blue\0");
trainer green("Green\0");
trainer ash("Ash\0");
trainer brock("Brock\0");
trainer misty("Misty\0");
trainer erika("Erika\0");
trainer ltsurge("Lt. Surge\0");
trainer giovanni("Giovanni\0");
trainer lorelei("Lorelei\0");
trainer bruno("Bruno\0");
trainer agatha("Agatha\0");
trainer lance("Lance\0");



void dec()
{
	red.SetPkmn(0,"charizard");
	red.SetPkmn(1,"typhlosion");
	red.SetPkmn(2,"blaziken");

	blue.SetPkmn(0,"blastoise");
	blue.SetPkmn(1,"feraligatr");
	blue.SetPkmn(2,"swampert");

	green.SetPkmn(0,"venusaur");
	green.SetPkmn(1,"meganium");
	green.SetPkmn(2,"sceptile");

	ash.SetPkmn(0,"pikachu");
	ash.SetPkmn(1,"charizard");
	ash.SetPkmn(2,"bulbasaur");

	brock.SetPkmn(0,"kabutops");
	brock.SetPkmn(1,"graveler");
	brock.SetPkmn(2,"steelix");

	misty.SetPkmn(0,"gyarados");
	misty.SetPkmn(1,"lanturn");
	misty.SetPkmn(2,"starmie");

	ltsurge.SetPkmn(0,"magneton");
	ltsurge.SetPkmn(1,"electabuzz");
	ltsurge.SetPkmn(2,"raichu");

	erika.SetPkmn(0,"vileplume");
	erika.SetPkmn(1,"victreebel");
	erika.SetPkmn(2,"venusaur");

	koga.SetPkmn(0,"weezing");
	koga.SetPkmn(1,"muk");
	koga.SetPkmn(2,"crobat");

	sabrina.SetPkmn(0,"alakazam");
	sabrina.SetPkmn(1,"slowking");
	sabrina.SetPkmn(2,"venomoth");

	blaine.SetPkmn(0,"ninetales");
	blaine.SetPkmn(1,"arcanine");
	blaine.SetPkmn(2,"magmar");

	giovanni.SetPkmn(0,"persian");
	giovanni.SetPkmn(1,"rhydon");
	giovanni.SetPkmn(2,"kangaskhan");

	lorelei.SetPkmn(0,"piloswine");
	lorelei.SetPkmn(1,"lapras");
	lorelei.SetPkmn(2,"jynx");

	bruno.SetPkmn(0,"steelix");
	bruno.SetPkmn(1,"hitmonchan");
	bruno.SetPkmn(2,"machamp");

	agatha.SetPkmn(0,"arbok");
	agatha.SetPkmn(1,"crobat");
	agatha.SetPkmn(2,"gengar");

	lance.SetPkmn(0,"gyarados");
	lance.SetPkmn(1,"Aerodactyl");
	lance.SetPkmn(2,"Dragonite");



}


#endif




