#pragma once

#include "Files.h"
#include "Methods.h"

inline void main_menu(vector<Team>& teams, vector<Player>& players)
{
	int opt = 0;
	do
	{
		do
		{
			cout << endl << endl;
			cout << " ---- MAIN MENU ---- " << endl;
			cout << "1) Add new team" << endl;
			cout << "2) Edit/Update team" << endl;
			cout << "3) Delete team" << endl;
			cout << "4) Show all teams" << endl;
			cout << "5) Show team by name" << endl;
			cout << "6) Show teams by country" << endl;

			cout << "7) Add player" << endl;
			cout << "8) Sell player (can change price)" << endl;
			cout << "9) Buy player (as it is)" << endl;
			cout << "10) Show all players" << endl;

			cout << "0) Exit" << endl;
			cout << "Enter your choice: ";
			cin >> opt;
			cin.ignore();

			if (opt < 0 || opt > 10) cout << "Invalid option" << endl;
		}
		while (opt < 0 || opt > 10);

		switch (opt)
		{
		case 1:
			{
				add_team(teams);
				write_file(teams, players);
				break;
			}
		case 2:
			{
				edit_team(teams);
				write_file(teams, players);
				break;
			}
		case 3:
			{
				delete_team(teams, players);
				write_file(teams, players);
				break;
			}
		case 4:
			{
				show_all_teams(teams);
				break;
			}
		case 5:
			{
				show_team_by_name(teams, players);
				break;
			}
		case 6:
			{
				show_teams_by_country(teams);
				break;
			}
		case 7:
			{
				add_player(teams, players);
				write_file(teams, players);
				break;
			}
		case 8:
			{
				sell_player(teams, players);
				write_file(teams, players);
				break;
			}
		case 9:
			{
				buy_player(teams, players);
				write_file(teams, players);
				break;
			}
		case 10:
			{
				show_all_players(players);
				break;
			}
		default:
			break;
		}
	}
	while (opt != 0);
	cout << "Goodbye!" << endl;
}
