#include "Player.h"
#include <fstream>
#include <ctime>
#include <array>
int creature::count = 0;
int main()
{
	srand(time(0));
	setlocale(LC_CTYPE,"ukr");
	std::cout << "hand_state-  NONE=0  heal=1  attack=2  special=3\n";
	std::cout << "matirial-  silever=0  iron=1\n"; 
	std::fstream file("Text.txt");

	creature **a=new creature *[16];
	int i = 0;
	for (; i < 4; ++i)
	{
		try
		{
			a[i] = new CDRED;
			a[i]->in(file);
		}
		catch(creature::ex)
		{
			std::cout << "wrong HP " << i << '\n';
			--i;
		}
		catch (monster::no_h)
		{
			std::cout << "he has no hands " << i << '\n';
			--i;
		}
		catch (monster::many_h)
		{
			std::cout << "to many hands " << i << '\n';
			--i;
		}
	}
	for (; i < 8; ++i)
	{
		try
		{
			a[i] = new BeTomorrow;
			a[i]->in(file);
		}
		catch (...)
		{
			std::cout << "something is wrong "<< i << '\n';
			--i;
		}
	}
	for (; i < 12; ++i)
	{
		try
		{
			a[i] = new knight;
			a[i]->in(file);
		}
		catch (...)
		{
			std::cout << "something is wrong " << i << '\n';
			--i;
		}
	}
	for (; i < 16; ++i)
	{
		try
		{
			a[i] = new witcher;
			a[i]->in(file);
		}
		catch (...)
		{
			std::cout << "wrong\n";
			--i;
		}
	}
	creature *temp= new CDRED;

	char ch;
	std::cin >> ch;
	if (ch >= 'A' && ch <= 'Z') ch += 'z' - 'Z';
	switch(ch)
	{
	case 'c':
	{
		temp = new CDRED;
		std::cout << "input, HP, num_hands, strength, coor.x, coor.y\n";
		break;
	}
	case 'b':
	{
		 temp = new BeTomorrow;
		std::cout << "input, HP, num_hands, strength, coor.x, coor.y\n";
		break;
	}
	case 'w':
	{
		temp = new witcher;
		std::cout << "input, HP, material, one.Power,  material, too.Power, coor.x, coor.y\n";
		break;
	}
	case 'k':
	{
		temp = new knight;
		std::cout << "input, HP, material, one.Power, coor.x, coor.y\n";
		break;
	}
	}
	temp->in(std::cin);
	Player one(temp);

	bool exit=true;
	while (exit)
	{
		std::cin >> ch;
		if (ch >= 'A' && ch <= 'Z') ch += 'z' - 'Z';
		switch (ch)
		{
		case 'd': 
			system("cls");
			one.duel(a, one.find(a, i));
			if (!(one.get_life()))	exit = false;
			break;
		case 'm':
			system("cls");
			std::cout << "you went to the store\n";
			one.shop();
			break;
		case 's':
			exit = false;
			std::cout << "you stop your travel\n";
			break;
		}
	}
}
