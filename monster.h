#pragma once
#include <iomanip>
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
	monster* creature_ptr;
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
	double HP;
	int buff_num = 0, armor;
	bool life = true;
	Point coor;
	buff_debuff *buff_ptr;
	std::string name;

	creature();
	creature(double HP, float coor_x, float coor_y, std::string name);
	creature(creature& a);
public:
	class ex {};

	bool get_life();
	double get_HP();
	Point get_coor();

	void set_life(bool a);
	void set_HP(double a);
	void set_armor(int a);

	void add_buff(monster* ptr);
	void delete_buff();
	void time_G(creature * b, int size);
	void time();
	int get_armor();
	virtual bool action(creature * b) = 0;
	virtual std::istream& in(std::istream& in)=0;
	friend std::ostream& operator<<(std::ostream& out, creature* a)
	{
		out << "Iмя" << a->name << "\tкiлькiсть житiв " << a->HP << "\tрозатшування (х y) " << a->coor.x << " " << a->coor.y << '\n';
		return out;
	}

	virtual void move(direction were);
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
	class many_h {};
	class no_h {};

	virtual std::istream& in(std::istream& in);

	int get_strength();
	void set_strength(int a);
	virtual void special_f(creature * a, bool help) = 0;
	virtual ~monster() = 0;	
};
