#pragma once
#include "monster.h"
enum matirial
{
	silever, iron
};
struct weapon
{
	matirial mat;
	int Power;
};

class CDRED : public monster
{
public:

	CDRED();
	CDRED(int num_hands, int strength, double HP, float coor_x, float coor_y, std::string name);
	CDRED(CDRED& a);

	bool action(creature* a) override;
	void special_f(creature* a, bool help) override;
};

class BeTomorrow : public monster
{
	bool resurrection = true;
public:

	BeTomorrow();
	BeTomorrow(int num_hands, int strength, double HP, float coor_x, float coor_y, std::string name);
	BeTomorrow(BeTomorrow& a);

	bool action(creature* a) override;
	void death();
	void special_f(creature* a, bool help) override;
};

class knight : virtual public creature
{
protected:
	weapon one;
public:
	std::istream& in(std::istream& in) override;

	knight() : creature() {};
	knight(double HP, float coor_x, float coor_y, weapon one, std::string name)
		: creature(HP, coor_x, coor_y, name), one(one) {}
	knight(knight& a) : creature(a) {}
	bool action(monster* a);
	bool action(creature* a) override;

	int get_power();
	matirial get_material();
};

class witcher : public knight, public CDRED
{
	weapon too;
public:
	std::istream& in(std::istream& in) override;

	witcher() : knight(), CDRED(), too{ iron,10 } {};
	witcher(double HP, float coor_x, float coor_y, weapon one, weapon too, std::string name)
		: knight(HP, coor_x, coor_y, one, name), CDRED(), too(too) {};
	witcher(witcher& a) : knight(a), CDRED(), too(a.too) { };

	bool action(monster* a);
	bool action(creature* a) override;
};
