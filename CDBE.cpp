#include"CDBE.h"
CDRED::CDRED() : monster() {}
CDRED::CDRED(int num_hands, int strength, double HP, float coor_x, float coor_y,std::string name)
	: monster(num_hands, strength, HP, coor_x, coor_y, name) {}
CDRED::CDRED(CDRED & a) : monster(a) {}

float CDRED::range_fall()
{
	return 0.25;
}
void CDRED::special_f(creature * a, bool help)
{
	a->set_armor(a->get_armor() + 1);
	if (help) a->add_buff(this);
}
void CDRED::move(int time, direction were)
{
	float speed = time;
	switch (were)
	{
	case North:
		coor.x += speed;
		break;
	case South:
		coor.x -= speed;
		break;
	case West:
		coor.y -= speed;
		break;
	case East:
		coor.y += speed;
		break;
	}
}


BeTomorrow::BeTomorrow() : monster() {}
BeTomorrow::BeTomorrow(int num_hands, int strength, double HP, float coor_x, float coor_y, std::string name)
	: monster(num_hands, strength, HP, coor_x, coor_y, name) {}
BeTomorrow::BeTomorrow(BeTomorrow & a) : monster(a) {}

void BeTomorrow::death()
{
	if (resurrection)
	{
		resurrection = false;
		HP = strength * 50;
	}
	else std::cout << "this monster is dead";
}
float BeTomorrow::range_fall()
{
	return 0.1;
}
void BeTomorrow::special_f(creature * a, bool help)
{
	a->set_HP(a->get_HP() - 10);
	if (help) a->add_buff(this);
}
void BeTomorrow::move(int time, direction were)
{
	float speed = time * 2;
	switch (were)
	{
	case North:
		coor.x += speed;
		break;
	case South:
		coor.x -= speed;
		break;
	case West:
		coor.y -= speed;
		break;
	case East:
		coor.y += speed;
		break;
	}
}
