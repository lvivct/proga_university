#include "witcher.h"
void witcher::attack(monster * a)
{
	if (one.mat == iron) a->set_HP(a->get_HP() - one.Power*0.2);
	else a->set_HP(a->get_HP() - one.Power);
	if (too.mat == iron) a->set_HP(a->get_HP() - too.Power*0.2);
	else a->set_HP(a->get_HP() - too.Power);
	action(a);
}
void witcher::attack(knight * a)
{
	if (one.mat == iron) a->set_HP(a->get_HP() - one.Power);
	else a->set_HP(a->get_HP() - one.Power*0.5);
	if (too.mat == iron) a->set_HP(a->get_HP() - too.Power*0.2);
	else a->set_HP(a->get_HP() - too.Power);
	action(a);
}

void knight::attack(monster * a)
{
	if (one.mat != iron) a->set_HP(a->get_HP() - (one.Power*0.1));
}
void knight::attack(knight * a)
{
	if (one.mat == iron) a->set_HP(a->get_HP() - one.Power);
	else a->set_HP(a->get_HP() - one.Power*0.1);
}

int knight::get_power()
{
	return one.Power;
}
matirial knight::get_material()
{
	return one.mat;
}

