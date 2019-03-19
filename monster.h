#pragma once
#include <iostream>
#include <string>
class creature;
class monster;
enum direction
{
	North, South, West, East
};
enum hand_state
{
	NONE, heal,attack, special
};
struct Point
{
	float x, y;
};
struct buff_debuff
{
	creature* creature_ptr;
	int time;
};

class hand
{
	double range(Point a, Point b);
public:
	hand_state qq = NONE;
	void special_a(monster* a, creature*b);
	void attack_f(monster* a, creature*b);
	void heal_f(monster* a, creature*b);
	void NONE_f(monster* a, creature*b);
};

class creature
{
	static int count;
protected:
	int HP, buff_num = 0,armor;
	bool life = true;
	Point coor;
	buff_debuff *buff_ptr;
	std::string name;

	creature();
	creature(int HP, float coor_x, float coor_y, std::string name);
	creature(creature& a);
public:
	int get_HP();
	Point get_coor();
	void set_HP(int a);
	void add_buff(creature* ptr);
	void delete_buff();
	void time_G(creature * b, int size);
	void time();
	void set_armor(int a);
	int get_armor();

	friend std::ostream& operator<<(std::ostream& out, creature* a)
	{
		out << a->name << "\tHP= " << a->HP << "\tcoor= " << a->coor.x << ' ' << a->coor.y;
		return out;
	}

	virtual void special_f(creature* a, bool help) = 0;
	virtual void move(int time, direction were) = 0;
	virtual float range_fall() = 0;
	virtual ~creature() = 0;
};

class monster : virtual public creature
{
protected:
	int num_hands, strength;
	hand *hand_ptr;
	
	monster();
	monster(int num_hands,int strength, double HP, float coor_x,float coor_y, std::string name);
	monster(monster& a);
public:
	int get_strength();
	void set_strength(int a);
	void action(creature * b);

	virtual ~monster() = 0;	
};
