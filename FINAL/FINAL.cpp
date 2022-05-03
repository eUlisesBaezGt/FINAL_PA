#include <iostream>

#include "Files.h"
#include "MainMenu.h"

int main()
{
	make_file();
	vector<Team> teams;
	read_file(teams);
	main_menu(teams);
	return 0;
}
