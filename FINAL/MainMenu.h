#pragma once

#include "Methods.h"

inline void main_menu(vector<Team>& teams)
{
	int opt = 0;
	do
	{
		do
		{
			cout << " ---- MAIN MENU ---- " << endl;
			cout << "1) Add new team" << endl;
			cout << "2) Edit/Update team" << endl;
			cout << "3) Delete team" << endl;
			cout << "4) Show all teams" << endl;
			cout << "5) Show team by name" << endl;
			cout << "6) Show teams by country" << endl;
			cout << "0) Exit" << endl;
			cout << "Enter your choice: ";
			cin >> opt;

			if (opt < 0 || opt > 6) cout << "Invalid option" << endl;
		}
		while (opt < 0 || opt > 6);

		switch (opt)
		{
		case 1:
			{
				add_team(teams);
				break;
			}
		case 2:
			{
				edit_team(teams);
				break;
			}
		case 3:
			{
				delete_team(teams);
				break;
			}
		case 4:
			{
				show_all_teams(teams);
				break;
			}
		case 5:
			{
				show_team_by_name(teams);
				break;
			}
		case 6:
			{
				show_teams_by_country(teams);
				break;
			}
		default:
			break;
		}
	}
	while (opt != 0);
	cout << "Goodbye!" << endl;
}
