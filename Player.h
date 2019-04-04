#pragma once
#include "CDBE.h"
enum characters
{
	BeTomorrows, CDREDs, witchers, knights
};

class Player
{
	creature *ptr;
	int coins = 10;
public:
	class ex {};
	Player();
	Player(creature *ptr);

	bool get_life();
	int get_coins();
	void shop();
	int find(creature *a[], int size);
	void duel(creature *a[],int i);
};
