#include "Convertor.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number arguments!" << std::endl;
		return 1;
	}
	std::cout << Convertor(argv[1]) << std::endl;
}
