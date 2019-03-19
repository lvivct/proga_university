#pragma once
#include "monster.h"

class CDRED : public monster
{
public:
	friend std::istream& operator>>(std::istream& in, CDRED* a)
	{
		getline(in, a->name, ' ');
		in >> a->HP >> a->num_hands >> a->strength >> a->coor.x >> a->coor.y;
		return in;
	}
	CDRED();
	CDRED(int num_hands, int strength, double HP, float coor_x, float coor_y, std::string name);
	CDRED(CDRED& a);

	virtual float range_fall();
	virtual void special_f(creature* a, bool help) override;
	virtual void move(int time, direction were) override;
};

class BeTomorrow : public monster
{
	bool resurrection = true;
public:
	friend std::istream& operator>>(std::istream& in, BeTomorrow* a)
	{
		getline(in, a->name, ' ');
		in >> a->HP >> a->num_hands >> a->strength >> a->coor.x >> a->coor.y;
		return in;
	}

	BeTomorrow();
	BeTomorrow(int num_hands, int strength, double HP, float coor_x, float coor_y, std::string name);
	BeTomorrow(BeTomorrow& a);

	void death();
	virtual float range_fall();
	virtual void special_f(creature* a, bool help) override;
	virtual void move(int time, direction were) override;
};
