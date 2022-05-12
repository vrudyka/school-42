#include "AbstractVM.hpp"

int main(int ac, char **av)
{
	try
	{
		AbstractVM vm(ac, av);
	}
	catch(const Error &e)
	{
		std::cerr << e.what() << '\n';
		system("leaks avm");
		return EXIT_FAILURE;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		system("leaks avm");
		return EXIT_FAILURE;
	}
	system("leaks avm");
	return EXIT_SUCCESS;
}
