#include "monster.h"

creature::creature() : HP(100), coor({ 1,1 })
{
	buff_ptr = new buff_debuff[0];
	count++;
	name += "creature_" + std::to_string(count) + "\t";
}
creature::creature(double HP, float coor_x, float coor_y,std::string name)
	: HP(HP), coor({ coor_x,coor_y }), name(name)
{
	buff_ptr = new buff_debuff[0];
	count++;
}
creature::creature(creature & a)
	: HP(a.HP), coor(a.coor),name(a.name)
{
	buff_ptr = new buff_debuff[0];
	count++;
}

Point creature::get_coor()
{
	return coor;
}

double creature::get_HP()
{
	return HP;
}
bool creature::get_life()
{
	return life;
}
void creature::add_buff(monster* ptr)
{
	buff_debuff b = { ptr ,5 };
	buff_debuff *temp = new buff_debuff[buff_num];
	for (int i = 0; i < buff_num; i++) 
		temp[i] =buff_ptr[i];
	delete[] buff_ptr;
	buff_num++;
	buff_ptr=new buff_debuff[buff_num];
	for (int i = 0; i < buff_num-1; i++) 
		buff_ptr[i] = temp[i];
	buff_ptr[buff_num - 1] = b;
	delete[] temp;
}
void creature::time()
{
	for (int i = 0; i < buff_num; i++)
	{
		buff_ptr[i].creature_ptr->special_f(this,false);
		buff_ptr[i].time--;
	}
	delete_buff();
}
void creature::set_armor(int a)
{
	armor = a;
}
void creature::set_HP(double a)
{
	HP = a;
}
void creature::set_life(bool a)
{
	life = a;
}
int creature::get_armor()
{
	return armor;
}
void creature::time_G(creature * b, int size)
{
	for (int i = 0; i < size; i++) (b + i)->time();
}
void creature::delete_buff()
{
	const int const_size = buff_num;
	for (int i = 0; i < const_size; i++)
		if (buff_ptr[i].time == 0)
		{
			buff_num--;
			buff_ptr[i] = buff_ptr[buff_num];		
		}
	if (const_size != buff_num)
	{
		buff_debuff *temp = new buff_debuff[const_size];
		for (int i = 0; i < buff_num; i++)  temp[i] = buff_ptr[i];
		delete[] buff_ptr;
		buff_ptr = new buff_debuff[buff_num];
		for (int i = 0, j = 0; i < buff_num; j++) if (temp[j].time != 0)
		{
			buff_ptr[j] = temp[i];
			i++;
		}
		delete[] temp;
	}
}
void creature::move(direction were)
{
	switch (were)
	{
	case North:
		++coor.x;
		break;
	case South:
		--coor.x;
		break;
	case West:
		--coor.y;
		break;
	case East:
		++coor.y;
		break;
	}
}

creature::~creature()
{
	delete[] buff_ptr;
}


monster::monster() : num_hands(2), strength(10), creature()
{
	hand_ptr = new hand[num_hands];
}
monster::monster(int num_hands, int strength, double HP, float coor_x, float coor_y,std::string name)
	:creature(HP, coor_x, coor_y,name),  num_hands(num_hands), strength(strength)
{
	hand_ptr = new hand[num_hands];
}
monster::monster(monster & a) : num_hands(a.num_hands), strength(a.strength), creature(a)
{
	hand_ptr = new hand[num_hands];
}

int monster::get_strength()
{
	return strength;
}
void monster::set_strength(int a)
{
	strength = a;
}
std::istream& monster::in(std::istream & in)
{
	in >> HP >> num_hands >> strength >> coor.x >> coor.y;
	getline(in, name);
	if (HP <= 0) throw ex();
	if (num_hands > 10) throw many_h();
	if (num_hands <= 0) throw no_h();
	return in;
}

monster::~monster()
{
	delete[] hand_ptr;
}


double hand::range(Point a, Point b)
{
	return sqrt(pow(a.x-b.x,2)+ pow(a.y - b.y, 2));
}
void hand::special_a(monster * a, creature * b)
{
	a->special_f(b,true);
}
void hand::attack_f(monster * a, creature * b)
{
	if(range(a->get_coor(),b->get_coor())<30)
		b->set_HP(b->get_HP() - (a->get_strength() * 10));
	else 
		b->set_HP(b->get_HP() - (a->get_strength()));
}
void hand::heal_f(monster * a, creature * b)
{
	if (range(a->get_coor(), b->get_coor()) < 30)
		b->set_HP(b->get_HP() + 25);
	else
		b->set_HP(b->get_HP());
}
void hand::NONE_f(monster * a, creature * b)
{
	int z;
	std::cin >> z;
	std::cout << " ";
	switch (static_cast<hand_state>(z))
	{
	case heal:
		qq = heal;
		break;
	case attack:
		qq = attack;
		break;
	case special:
		qq = special;
		break;
	default:
		qq = NONE;	
	}
}
