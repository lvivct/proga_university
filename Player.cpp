#include "Player.h"

Player::Player()
{
	ptr = new witcher();
}
Player::Player(creature *neww)
{
	ptr = neww;
}


void Player::shop()
{
	std::cout << " prees 'h' to heal  's' to exit\n";
	bool exit = true;
	while (exit)
	{
		char ch;
		std::cin >> ch;
		if (ch >= 'A' && ch <= 'Z') ch += 'z' - 'Z';
		switch (ch)
		{
		case 'h':
		{
			if (coins <= 2)
			{
				std::cout << "you do not have enough money\n";
				exit = false;
				break;
			}
			coins -= 2;
			ptr->set_HP(ptr->get_HP() + 100);
			std::cout << "your coins " << coins << "   your HP " << ptr->get_HP() << '\n';
			break;
		}
		case 's':
		{
			exit = false;
			break;
		}
		}
	}
	std::cout << "You came out of the store\n";
}
int Player::find(creature *a[], int size)
{
	Point temp = a[0]->get_coor(),thiss = ptr->get_coor();
	int index = 0;
	float min = sqrt(pow(temp.x - thiss.x, 2) + pow(temp.y - thiss.y, 2));
	for (int i=1;i< size;i++)
	{
		if (a[i]->get_life())
		{
			temp = a[i]->get_coor();
			float range;
			range = sqrt(pow(temp.x - thiss.x, 2) + pow(temp.y - thiss.y, 2));
			if (min > range)
			{
				min = range;
				index = i;
			}
		}
	}
	return index;
}
void Player::duel(creature *a[], int i)
{
	while (1)
	{
		if (!ptr->action(a[i])) break;
		if (!a[i]->action(ptr)) break;
		std::cout << "enemy HP " << a[i]->get_HP() << '\n';
		std::cout << "your HP " << ptr->get_HP() << "\n\n";
		a[i]->time();
		ptr->time();
	}
	if (ptr->get_HP() >= 0)
	{
		a[i]->set_life(false);
		int ern_c = rand() % 20;;
		coins += ern_c;
		std::cout << "you win   you earn  " << ern_c;
	}
	else
	{
		std::cout << "you die end";
		coins /= 2;
	}
	std::cout << '\n';
}

int Player::get_coins()
{
	return coins;
}
bool Player::get_life()
{
	return ptr->get_life();
}
