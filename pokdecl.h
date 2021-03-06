//Version 1.4 - Last edited 12/10/2013 by Narendran Srinivasan
//1.4 - added methods to "attack" for the editor
//1.3 - class "attack" now has critlvl
//1.2 - class Pokemon now has "toxiclvl" and "toxictrue"
#include "pokrand.h"
#ifndef POKDECL_H
#define POKDECL_H

enum type {grass,
	fire,
	water,
	electr,
	ground,
	rock,
	psychic,
	dark,
	normal,
	fight,
	flying,
	dragon,
	poison,
	bug,
	ice,
	steel,
	ghost,
	none};

	enum cond {norm,
	psn,
	slp,
	brn,
	par,
	frz
	};

int miss;
float critdamage;

class attack
	{
		private:
			short int PP;
		public:
			short int power;
			float accuracy;
		private:
			type type;
			char atkname[15];
		public:
			short int cat;
			cond effecttype;
			int condperc;
			int critlvl;
			attack()
			{}
			void EnterData()
			{
				cout<<"Enter the attack name"<<endl;
				gets(atkname);
				cout<<"Enter the PP of the attack"<<endl;
				cin>>PP;
				cout<<"Enter the power of the attack"<<endl;
				cin>>power;
				cout<<"Enter the accuracy of the attack"<<endl;
				cin>>accuracy;
				cout<<"Enter the type of the attack"<<endl;
				char temp[10];
				gets(temp);

				if (strcmpi(temp, "grass") == 0)
				{
					type = grass;
				}
				else if (strcmpi(temp, "fire") == 0)
				{
					type = fire;
				}
				else if (strcmpi(temp, "water") == 0)
				{
					type = water;
				}
				else if (strcmpi(temp, "electr") == 0)
				{
					type = electr;
				}
				else if (strcmpi(temp, "ground") == 0)
				{
					type = ground;
				}
				else if (strcmpi(temp, "rock") == 0)
				{
					type = rock;
				}
				else if (strcmpi(temp, "psychic") == 0)
				{
					type = psychic;
				}
				else if (strcmpi(temp, "dark") == 0)
				{
					type = dark;
				}
				else if (strcmpi(temp, "normal") == 0)
				{
					type = normal;
				}
				else if (strcmpi(temp, "fight") == 0)
				{
					type = fight;
				}
				else if (strcmpi(temp, "flying") == 0)
				{
					type = flying;
				}
				else if (strcmpi(temp, "dragon") == 0)
				{
					type = dragon;
				}
				else if (strcmpi(temp, "poison") == 0)
				{
					type = poison;
				}
				else if (strcmpi(temp, "bug") == 0)
				{
					type = bug;
				}
				else if (strcmpi(temp, "ice") == 0)
				{
					type = ice;
				}
				else if (strcmpi(temp, "steel") == 0)
				{
					type = steel;
				}
				else if (strcmpi(temp, "ghost") == 0)
				{
					type = ghost;
				}
				else if (strcmpi(temp, "none") == 0)
				{
					type = none;
				}
				else
				{
					type = none;
				}
				cout<<"Enter the attack category"<<endl;
				cin>>cat;
				cout<<"Enter the effect (if any) that the attack has"<<endl;
				gets(temp);
				if (strcmpi(temp, "norm") == 0)
				{
					effecttype = norm;
				}
				else if (strcmpi(temp, "psn") == 0)
				{
					effecttype = psn;
				}
				else if (strcmpi(temp, "slp") == 0)
				{
					effecttype = slp;
				}
				else if (strcmpi(temp, "brn") == 0)
				{
					effecttype = brn;
				}
				else if (strcmpi(temp, "par") == 0)
				{
					effecttype = par;
				}
				else if (strcmpi(temp, "frz") == 0)
				{
					effecttype = frz;
				}
				else
				{
					effecttype = norm;
				}
				cout<<"Enter the probability of the effect occurring"<<endl;
				cin>>condperc;
				cout<<"Enter the probability for a critical hit"<<endl;
				cin>>critlvl;
			}
			char*GetName()
			{
				return atkname;
			}
			int GetPP()
			{
				return PP;
			}
			int GetType()
			{
				return type;
			}
			void ListDetails()
			{
				cout<<"Name:      "<<setw(20)<<atkname<<endl;
				cout<<"PP:        "<<setw(20)<<PP<<endl;
				cout<<"Power:     "<<setw(20)<<power<<endl;
				cout<<"Accuracy:  "<<setw(20)<<accuracy<<endl;
				cout<<"Type:      "<<setw(20)<<type<<endl;
				cout<<"EffectType:"<<setw(20)<<effecttype<<endl;
				cout<<"EffectPerc:"<<setw(20)<<condperc<<endl;
				cout<<"CritLevel: "<<setw(20)<<critlvl<<endl;
			}
			void ReducePP()
			{
				--PP;
				if (strcmpi(atkname, "Transform") == 0)
					PP = 5;
			}
	};


	//defining a datatype for pokemon
	class pokemon
	{
		private:
			char pokename[15];
		public:
			short int atk;
			short int def;
			short int spd;
		private:
			short int maxhp;
			type type1;
			type type2;
			attack att[4];
		public:
			float acc;
			float evs;
			short int wait;
			short int SleepWait;
			short int hp;
		private:
			cond cond;
			short int toxiclvl;
			short int toxictrue;
		public:
			pokemon()
			{
				acc = 100;
				evs = 100;
				wait = 0;
				SleepWait = 0;
				hp = 0;
				cond = norm;
				toxiclvl = 0;
				toxictrue = 0;
			}
			float supereffect(attack b);
			void EnterData()
			{
				cout<<"Enter the name of the pokemon"<<endl;
				gets(pokename);
				cout<<"Enter its attack stat"<<endl;
				cin>>atk;
				cout<<"Enter its defense stat"<<endl;
				cin>>def;
				cout<<"Enter its speed stat"<<endl;
				cin>>spd;
				cout<<"Enter its maximum HP"<<endl;
				cin>>maxhp;
				hp = maxhp;
				cout<<"Enter the primary type of the pokemon"<<endl;
				char temp[10];
				gets(temp);

				if (strcmpi(temp, "grass") == 0)
				{
					type1 = grass;
				}
				else if (strcmpi(temp, "fire") == 0)
				{
					type1 = fire;
				}
				else if (strcmpi(temp, "water") == 0)
				{
					type1 = water;
				}
				else if (strcmpi(temp, "electr") == 0)
				{
					type1 = electr;
				}
				else if (strcmpi(temp, "ground") == 0)
				{
					type1 = ground;
				}
				else if (strcmpi(temp, "rock") == 0)
				{
					type1 = rock;
				}
				else if (strcmpi(temp, "psychic") == 0)
				{
					type1 = psychic;
				}
				else if (strcmpi(temp, "dark") == 0)
				{
					type1 = dark;
				}
				else if (strcmpi(temp, "normal") == 0)
				{
					type1 = normal;
				}
				else if (strcmpi(temp, "fight") == 0)
				{
					type1 = fight;
				}
				else if (strcmpi(temp, "flying") == 0)
				{
					type1 = flying;
				}
				else if (strcmpi(temp, "dragon") == 0)
				{
					type1 = dragon;
				}
				else if (strcmpi(temp, "poison") == 0)
				{
					type1 = poison;
				}
				else if (strcmpi(temp, "bug") == 0)
				{
					type1 = bug;
				}
				else if (strcmpi(temp, "ice") == 0)
				{
					type1 = ice;
				}
				else if (strcmpi(temp, "steel") == 0)
				{
					type1 = steel;
				}
				else if (strcmpi(temp, "ghost") == 0)
				{
					type1 = ghost;
				}
				else if (strcmpi(temp, "none") == 0)
				{
					type1 = none;
				}
				else
				{
					type1 = none;
				}
				cout<<"Enter the secondary type of the pokemon"<<endl;
				gets(temp);
				if (strcmpi(temp, "grass") == 0)
				{
					type2 = grass;
				}
				else if (strcmpi(temp, "fire") == 0)
				{
					type2 = fire;
				}
				else if (strcmpi(temp, "water") == 0)
				{
					type2 = water;
				}
				else if (strcmpi(temp, "electr") == 0)
				{
					type2 = electr;
				}
				else if (strcmpi(temp, "ground") == 0)
				{
					type2 = ground;
				}
				else if (strcmpi(temp, "rock") == 0)
				{
					type2 = rock;
				}
				else if (strcmpi(temp, "psychic") == 0)
				{
					type2 = psychic;
				}
				else if (strcmpi(temp, "dark") == 0)
				{
					type2 = dark;
				}
				else if (strcmpi(temp, "normal") == 0)
				{
					type2 = normal;
				}
				else if (strcmpi(temp, "fight") == 0)
				{
					type2 = fight;
				}
				else if (strcmpi(temp, "flying") == 0)
				{
					type2 = flying;
				}
				else if (strcmpi(temp, "dragon") == 0)
				{
					type2 = dragon;
				}
				else if (strcmpi(temp, "poison") == 0)
				{
					type2 = poison;
				}
				else if (strcmpi(temp, "bug") == 0)
				{
					type2 = bug;
				}
				else if (strcmpi(temp, "ice") == 0)
				{
					type2 = ice;
				}
				else if (strcmpi(temp, "steel") == 0)
				{
					type2 = steel;
				}
				else if (strcmpi(temp, "ghost") == 0)
				{
					type2 = ghost;
				}
				else if (strcmpi(temp, "none") == 0)
				{
					type2 = none;
				}
				else
				{
					type2 = none;
				}
				for (int i = 0; i<4; i++)
				{
					cout<<"Enter the name of attack "<<(i+1)<<endl;
					int flag = 0;
					char search[20];
					do
					{
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
								att[i] = A;
								break;
							}
						}
						if (flag == 0)
						{
							cout<<"Attack not found! Try again"<<endl;
						}
						ifile.close();
					} while (flag == 0);
				}
			}
			char*GetName()
			{
				return pokename;
			}
			void ListDetails()
			{
				cout<<"Name:     "<<setw(20)<<pokename<<endl;
				cout<<"Attack:   "<<setw(20)<<atk<<endl;
				cout<<"Defense:  "<<setw(20)<<def<<endl;
				cout<<"Speed:    "<<setw(20)<<spd<<endl;
				cout<<"Max HP:   "<<setw(20)<<maxhp<<endl;
				cout<<"Type 1:   "<<setw(20)<<type1<<endl;
				cout<<"Type 2:   "<<setw(20)<<type2<<endl;
				cout<<"Attack 1: "<<setw(20)<<att[0].GetName()<<endl;
				cout<<"Attack 2: "<<setw(20)<<att[1].GetName()<<endl;
				cout<<"Attack 3: "<<setw(20)<<att[2].GetName()<<endl;
				cout<<"Attack 4: "<<setw(20)<<att[3].GetName()<<endl;
			}
			void init()
			{
				hp = maxhp;
			}
			void FoeShow()
			{
				cout<<"\t\t\t\tFoe "<<pokename<<":\tHP:"<<hp<<"/"<<maxhp<<"\n\n\n\n\n";
			}
			void UsrShow()
			{
				cout<<pokename<<":\t\tHP: "<<hp<<"/"<<maxhp<<endl;
				cout<<"Player 1, your turn!\t\tPP"<<endl;
				cout<<"1. "<<att[0].GetName()<<"\t\t\t"<<att[0].GetPP()<<endl;
				cout<<"2. "<<att[1].GetName()<<"\t\t\t"<<att[1].GetPP()<<endl;
				cout<<"3. "<<att[2].GetName()<<"\t\t\t"<<att[2].GetPP()<<endl;
				cout<<"4. "<<att[3].GetName()<<"\t\t\t"<<att[3].GetPP()<<endl;
			}
			void UsrTurn(pokemon &y);
			void CPUTurn(pokemon &x);
			void CheckConds()
			{
				if (cond == psn)
				{  if (toxictrue == 1)
					{
						toxiclvl++;
					}
					cout<<pokename<<" lost "<<(maxhp/16)*toxiclvl<<" hp due to poison!"<<endl;
					waitFor(2);
					hp = hp - ((maxhp/16)*toxiclvl);
				}
				if (cond == brn)
				{
					cout<<pokename<<" lost "<<(maxhp/16)<<" hp due to burn!"<<endl;
					waitFor(2);
					hp = hp - ((maxhp/16));
				}
			}
			int Faint()
			{
				if (hp == 0)
					return 0;
				else
					return 1;
			}
			void CondSlp()
			{
				cout<<"\n"<<pokename<<" fell asleep!\n";
				cond = slp;
				SleepWait = (rand()%3)+2;
			}
			void CondPar()
			{
				cout<<"\n"<<pokename<<" is paralysed!\n";
				cond = par;
				spd = (75/100) * spd;
			}
			void CondTox()
			{
				waitFor(1);
				toxiclvl =1;
				cout<<"\n"<<pokename<<" is badly poisoned!\n";
				cond = psn;
				toxictrue = 1;
			}
			void CondPsn()
			{
				waitFor(1);
				toxiclvl =2;
				cout<<"\n"<<pokename<<" is poisoned!\n";
				cond = psn;
			}
			void CondBrn()
			{
				waitFor(1);
				cout<<"\n"<<pokename<<" is burnt!\n";
				cond = brn;
				atk = atk/2;
			}
			int STAB(attack y)
			{
				if(((int)type1 == y.GetType()) || (int)type2 == y.GetType())
					return 1.5;
				else
					return 1;
			}
			int ChkPoison()
			{
				if ((type1 == poison) || (type2 == poison))
					return 1;
				else
					return 0;
			}
			int AIatk(pokemon USER);
			int Okay()
			{
				if (cond == norm)
					return 1;
				else
					return 0;
			}
	};


class trainer
{
	private:
		char name[20];
	public:
		pokemon pok[3];
		trainer()
		{
			strcpy(name,"");
		}
		trainer(char A[])
		{
			strcpy(name,A);
		}
		void SetPkmn(int x, pokemon A)
		{
			pok[x] = A;
		}
		void SetPkmn(int x, char search[])
		{
			int flag = 0;
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
					pok[x] = A;
					break;
				}
			}
			if (flag == 0)
			{
				cout<<"Pokemon not found!"<<endl;
			}
			ifile.close();
		}
		void trainerdefn();
		void ready()
		{
			for(int i = 0; i<3; i++)
			{
				pok[i].init();
			}
		}
		char*GetName()
		{
			return name;
		}

};




#endif