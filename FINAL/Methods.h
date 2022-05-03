#pragma once

#include <iostream>
#include <string>
#include <vector>

inline void add_team(vector<Team>& teams)
{
}

inline void edit_team(vector<Team>& teams)
{
	string name;
	bool found = false;
	for (auto& team : teams) cout << team.getName() << endl;
	cout << "Enter team name to edit: ";
	cin >> name;
	for (auto& team : teams)
	{
		if (name == team.getName())
		{
			found = true;
			// TODO EDIT TEAM
			cout << "Team updated successfully!" << endl;
		}
	}
	if (!found)
	{
		cout << "Team not found!" << endl;
	}
}

inline void delete_team(vector<Team>& teams)
{
	string name;
	bool found = false;
	for (auto& team : teams) cout << team.getName() << endl;
	cout << "Enter team name to delete: ";
	cin >> name;
	for (auto& team : teams)
	{
		if (name == team.getName())
		{
			found = true;
			// TODO DELETE FROM TEAMS VECTOR
			cout << "Team deleted successfully!" << endl;
		}
	}
	if (!found)
	{
		cout << "Team not found!" << endl;
	}
}

inline void show_all_teams(vector<Team> teams)
{
	if(teams.empty())
	{
		cout << "No teams found!" << endl;
	}
	for (auto& team : teams)
	{
		cout << team.getName() << endl;
		cout << team.getYear() << endl;
		cout << team.getCountry() << endl;
		cout << team.getStadium() << endl;
		cout << team.getChampionships() << endl;
	}
}

inline void show_team_by_name(vector<Team> teams)
{
	string name;
	bool found = false;
	for (auto& team : teams) cout << team.getName() << endl;
	cout << "Enter team name: ";
	cin >> name;
	for (auto& team : teams)
	{
		if (name == team.getName())
		{
			found = true;
			cout << "Team found!" << endl;
			cout << team.getName() << endl;
			cout << team.getYear() << endl;
			cout << team.getCountry() << endl;
			cout << team.getStadium() << endl;
			cout << team.getChampionships() << endl;
		}
	}
	if (!found)
	{
		cout << "Team not found!" << endl;
	}
}

inline void show_teams_by_country(vector<Team> teams)
{
	string country;
	bool found = false;
	for (auto& team : teams) cout << team.getCountry() << endl;
	cout << "Enter team country: ";
	cin >> country;
	for (auto& team : teams)
	{
		if (country == team.getCountry())
		{
			found = true;
			cout << "Team found!" << endl;
			cout << team.getName() << endl;
			cout << team.getYear() << endl;
			cout << team.getCountry() << endl;
			cout << team.getStadium() << endl;
			cout << team.getChampionships() << endl;
		}
	}
	if (!found)
	{
		cout << "Team not found!" << endl;
	}
}
