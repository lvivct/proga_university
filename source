#include "witcher.h"
#include <fstream>
int creature::count = 0;
int main()
{
	std::cout << "NONE=" << NONE << "\theal=" << heal << "\tattack=" << attack << "\tspecial=" << special << '\n';
	std::fstream file("Text.txt");
	BeTomorrow test[4];
	CDRED	test_2[4];
	witcher test_3[4];
	for (int i = 0; i < 4; i++)	file >> &test[i];
	for (int i = 0; i < 4; i++)	file >> &test_2[i];
	for (int i = 0; i < 4; i++)	file >> &test_3[i];
	for (int i = 0; i < 3; i++)
	{
		std::cout << test_2 << test_3 << '\n';
		test_3[0].attack(&test_2[0]);
		test_2[0].action(&test_3[0]);
	}
}
