#include "Log.hpp"
#include <iostream>
#include <fstream>

int main(void)
{
	dh::Log<int> logger("test2.dat");
	/*int a = 1;
	int b = 2;
	int d[2] = { 3, 4 };
	logger.log(a);
	logger.log(b);
	logger.log(d[0], 2);*/
	char x = 65;
	logger.log(x);
	logger.~Log();
	std::ifstream inp("test2.dat", std::ifstream::in | std::ifstream::binary);
	while (1)
	{
	char c;
	inp.read((char*)& c, sizeof(c));
	if (inp.eof()) break;
	std::cout << c;
	}
	std::cout << std::endl;
	return 0;
}