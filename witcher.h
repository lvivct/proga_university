#pragma once
#include "CDBE.h"
enum matirial
{
	silever,iron
};
struct weapon
{
	matirial mat;
	int Power;
};

class knight : virtual public creature
{
protected:
	weapon one;
public:
	friend std::istream& operator>>(std::istream& in, knight& a)
	{
		getline(in, a.name, ' ');
		int temp;
		in >> a.HP >> temp >> a.one.Power >> a.coor.x >> a.coor.y;
		a.one.mat = static_cast<matirial>(temp);
		return in;
	}
	knight() : creature() {};
	knight(double HP, float coor_x, float coor_y, weapon one, std::string name)
		: creature(HP, coor_x, coor_y, name), one(one) {}
	knight(knight& a) : creature(a) {}

	virtual void attack(monster* a);
	virtual void attack(knight* a);

	int get_power();
	matirial get_material();
};

class witcher : knight,public CDRED
{
	weapon too;
public:

	friend std::istream& operator>>(std::istream& in, witcher* a)
	{
		getline(in, a->name, ' ');
		int temp,temp_2;
		in >> a->HP >> temp >> a->one.Power >> temp_2 >> a->too.Power >> a->coor.x >> a->coor.y;
		a->one.mat = static_cast<matirial>(temp);
		a->too.mat = static_cast<matirial>(temp_2);
		return in;
	}


	witcher() : knight(), CDRED(), too{ iron,10 } {};
	witcher(double HP, float coor_x, float coor_y, weapon one, weapon too, std::string name)
		: knight(HP, coor_x, coor_y, one, name), CDRED(), too(too){};

	witcher(witcher& a) : knight(a),CDRED(), too(a.too) { };

	virtual void attack(monster* a);
	virtual void attack(knight* a);
};
