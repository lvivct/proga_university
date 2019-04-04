#include"CDBE.h"
CDRED::CDRED() : monster() {}
CDRED::CDRED(int num_hands, int strength, double HP, float coor_x, float coor_y,std::string name)
	: monster(num_hands, strength, HP, coor_x, coor_y, name) {}
CDRED::CDRED(CDRED & a) : monster(a) {}

void CDRED::special_f(creature * a, bool help)
{
	a->set_armor(a->get_armor() + 1);
	if (help) a->add_buff(this);
}
bool CDRED::action(creature * b)
{
	for (int i = 0; i < num_hands; i++)
		switch ((hand_ptr + i)->qq)
		{
		case NONE:
			std::cout << "hand " << i + 1 << " inactive\n";
			(hand_ptr + i)->NONE_f(this, b);
			break;
		case heal:
			(hand_ptr + i)->heal_f(this, b);
			break;
		case attack:
			(hand_ptr + i)->attack_f(this, b);
			break;
		case special:
			(hand_ptr + i)->special_a(this, b);
			break;
		}
	if (b->get_HP() < 0) return 0;
	return 1;
}


BeTomorrow::BeTomorrow() : monster() {}
BeTomorrow::BeTomorrow(int num_hands, int strength, double HP, float coor_x, float coor_y, std::string name)
	: monster(num_hands, strength, HP, coor_x, coor_y, name) {}
BeTomorrow::BeTomorrow(BeTomorrow & a) : monster(a) {}

bool BeTomorrow::action(creature * b)
{
	for (int i = 0; i < num_hands; i++)
		switch ((hand_ptr + i)->qq)
		{
		case NONE:
			std::cout << "hand " << i + 1 << " inactive\n";
			(hand_ptr + i)->NONE_f(this, b);
			break;
		case heal:
			(hand_ptr + i)->heal_f(this, b);
			break;
		case attack:
			(hand_ptr + i)->attack_f(this, b);
			break;
		case special:
			(hand_ptr + i)->special_a(this, b);
			break;
		}
	if (b->get_HP() < 0) return 0;
	return 1;
}
void BeTomorrow::death()
{
	if (resurrection)
	{
		resurrection = false;
		HP = strength * 50;
	}
	else std::cout << "this monster is dead";
}
void BeTomorrow::special_f(creature * a, bool help)
{
	a->set_HP(a->get_HP() - 10);
	if (help) a->add_buff(this);
}


bool witcher::action(monster * a)
{
	if (one.mat == iron) a->set_HP(a->get_HP() - one.Power*0.2);
	else a->set_HP(a->get_HP() - one.Power);
	if (too.mat == iron) a->set_HP(a->get_HP() - too.Power*0.2);
	else a->set_HP(a->get_HP() - too.Power);
	if (a->get_HP() < 0) return 0;
	return 1;
}
bool witcher::action(creature * a)
{
	if (one.mat == iron) a->set_HP(a->get_HP() - one.Power);
	else a->set_HP(a->get_HP() - one.Power*0.5);
	if (too.mat == iron) a->set_HP(a->get_HP() - too.Power*0.2);
	else a->set_HP(a->get_HP() - too.Power);

	if (a->get_HP() < 0) return 0;
	return 1;
}


bool knight::action(monster * a)
{
	if (one.mat != iron) a->set_HP(a->get_HP() - (one.Power*0.1));
	if (a->get_HP() < 0) return 0;
	return 1;
}
bool knight::action(creature * a)
{
	if (one.mat == iron) a->set_HP(a->get_HP() - one.Power);
	else a->set_HP(a->get_HP() - one.Power*0.1);
	if (a->get_HP() < 0) return 0;
	return 1;
}
int knight::get_power()
{
	return one.Power;
}
matirial knight::get_material()
{
	return one.mat;
}

std::istream& knight::in(std::istream & in)
{
	int temp;
	in >> HP >> temp >> one.Power >> coor.x >> coor.y;
	getline(in, name);
	if(HP<=0)throw ex();
	one.mat = static_cast<matirial>(temp);
	return in;
}
std::istream& witcher::in(std::istream & in)
{
	int temp, temp_2;
	in >> HP >> temp >> one.Power >> temp_2 >> too.Power >> coor.x >> coor.y;
	getline(in, name);
	if (HP <= 0)throw ex();
	one.mat = static_cast<matirial>(temp);
	too.mat = static_cast<matirial>(temp_2);
	return in;
}
