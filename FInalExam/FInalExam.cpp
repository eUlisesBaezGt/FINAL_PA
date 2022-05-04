#include <iostream>

#include "Files.h"
#include "MainMenu.h"

int main()
{
	make_file();
	vector<Team> teams;
	vector<Player> players;
	read_file(teams, players);
	main_menu(teams, players);
	return 0;
}
