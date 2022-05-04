#pragma once

#include <iostream>
#include <string>
#include <vector>

inline void add_team(vector<Team>& teams)
{
	cout << endl << endl;
	cout << " ---- ADD TEAM ---- " << endl;
	Team temp;
	cout << "Enter the name of the team: ";
	string name;
	getline(cin, name);
	temp.setName(name);
	cout << "Enter the year of foundation: ";
	int year = 0;
	cin >> year;
	cin.ignore();
	temp.setYear(year);
	cout << "Enter the country: ";
	string country;
	getline(cin, country);
	temp.setCountry(country);
	cout << "Enter the stadium: ";
	string stadium;
	getline(cin, stadium);
	temp.setStadium(stadium);
	cout << "Enter the championships: ";
	int championships = 0;
	cin >> championships;
	cin.ignore();
	temp.setChampionships(championships);
	cout << "Enter the balance: ";
	float balance = 0.0f;
	cin >> balance;
	cin.ignore();
	temp.setBalance(balance);

	teams.push_back(temp);
}

inline void edit_team(vector<Team>& teams)
{
	cout << endl << endl;
	cout << " ---- EDIT TEAM ---- " << endl;
	cout << "TEAMS:" << endl;
	if (teams.empty())cout << "No teams found!" << endl;
	else
	{
		string name;
		bool found = false;
		for (auto& team : teams) cout << team.getName() << endl;
		cout << "Enter team name to edit: ";
		getline(cin, name);
		for (auto& team : teams)
		{
			if (name == team.getName())
			{
				found = true;
				cout << "Enter the year of foundation: ";
				int year = 0;
				cin >> year;
				cin.ignore();
				team.setYear(year);
				cout << "Enter the country: ";
				string country;
				getline(cin, country);
				team.setCountry(country);
				cout << "Enter the stadium: ";
				string stadium;
				getline(cin, stadium);
				team.setStadium(stadium);
				cout << "Enter the championships: ";
				int championships = 0;
				cin >> championships;
				cin.ignore();
				team.setChampionships(championships);
				cout << "Enter the balance: ";
				float balance = 0.0f;
				cin >> balance;
				cin.ignore();
				team.setBalance(balance);
				cout << "Team updated successfully!" << endl;
			}
		}
		if (!found) cout << "Team not found!" << endl;
	}
}

inline void delete_team(vector<Team>& teams)
{
	cout << endl << endl;
	cout << " ---- DELETE TEAM ---- " << endl;
	cout << "TEAMS:" << endl;
	if (teams.empty())cout << "No teams found!" << endl;
	else
	{
		string name;
		bool found = false;
		for (auto& team : teams) cout << team.getName() << endl;
		cout << "Enter team name to delete: ";
		cin >> name;
		cin.ignore();
		for (int i = 0; i < teams.size(); i++)
		{
			if (name == teams[i].getName())
			{
				found = true;
				teams.erase(teams.begin() + i);
				cout << "Team deleted successfully!" << endl;
			}
		}
		if (!found)
		{
			cout << "Team not found!" << endl;
		}
	}
}

inline void show_all_teams(vector<Team> teams)
{
	cout << endl << endl;
	cout << " ---- SHOW ALL TEAMS ---- " << endl;
	cout << "TEAMS:" << endl;
	cout << "Name\tYear\tCountry\tStadium\tChampionships\tBalance" << endl;
	if (teams.empty())cout << "No teams found!" << endl;
	else
	{
		for (auto& team : teams)
		{
			cout << team.getName() << "\t";
			cout << team.getYear() << "\t";
			cout << team.getCountry() << "\t";
			cout << team.getStadium() << "\t";
			cout << team.getChampionships() << "\t\t";
			cout << team.getBalance() << endl;
		}
	}
}

inline void show_team_by_name(vector<Team> teams)
{
	cout << endl << endl;
	cout << " ---- SHOW TEAM BY NAME ---- " << endl;
	cout << "TEAMS:" << endl;
	if (teams.empty())cout << "No teams found!" << endl;
	else
	{
		string name;
		bool found = false;
		for (auto& team : teams) cout << team.getName() << endl;
		cout << "Enter team name: ";
		cin >> name;
		cin.ignore();
		for (auto& team : teams)
		{
			if (name == team.getName())
			{
				found = true;
				cout << "Team found!" << endl;
				cout << "Name\tYear\tCountry\tStadium\tChampionships\tBalance" << endl;
				cout << team.getName() << "\t";
				cout << team.getYear() << "\t";
				cout << team.getCountry() << "\t";
				cout << team.getStadium() << "\t";
				cout << team.getChampionships() << "\t\t";
				cout << team.getBalance() << endl;
			}
		}
		if (!found)
		{
			cout << "Team not found!" << endl;
		}
	}
}

inline void show_teams_by_country(vector<Team> teams)
{
	cout << endl << endl;
	cout << " ---- SHOW TEAMS BY COUNTRY ---- " << endl;
	if (teams.empty())cout << "No teams found!" << endl;
	else
	{
		string country;
		bool found = false;
		cout << "TEAMS:" << endl;
		for (auto& team : teams)
		{
			cout << team.getCountry() << endl;
		}

		cout << "Enter team country: ";
		cin >> country;
		cin.ignore();
		for (auto& team : teams)
		{
			if (country == team.getCountry())
			{
				found = true;
				cout << "Team found!" << endl;
				cout << "Name\tYear\tCountry\tStadium\tChampionships\tBalance" << endl;
				cout << team.getName() << "\t";
				cout << team.getYear() << "\t";
				cout << team.getCountry() << "\t";
				cout << team.getStadium() << "\t";
				cout << team.getChampionships() << "\t\t";
				cout << team.getBalance() << endl;
			}
		}
		if (!found)
		{
			cout << "Team not found!" << endl;
		}
	}
}

inline void add_player(vector<Team>& teams, vector<Player>& players)
{
	cout << " ---- ADD PLAYER ---- " << endl;
	cout << "NO FREE AGENTS ALLOWED" << endl;
	if (teams.empty())
	{
		cout << "No teams found!" << endl;
		cout << "Consider creating teams first!" << endl;
	}

	else
	{
		bool created = false;
		cout << endl << endl;
		Player temp;
		cout << "Name: ";
		string name;
		getline(cin, name);
		cout << "Price: ";
		float price = 0.0f;
		cin >> price;
		cin.ignore();
		cout << "Team: ";
		string teamn;
		getline(cin, teamn);

		for (auto& team : teams)
		{
			if (team.getName() == teamn)
			{
				players.emplace_back(name, price, teamn);
				created = true;
				cout << "Player created successfully!" << endl;
				break;
			}
		}
		if (!created)
		{
			cout << "Team not found!" << endl;
			cout << "Player not created!" << endl;
			cout << "Player try again creating a player with a valid team!" << endl;
		}
	}
}

inline void sell_player(vector<Team>& teams, vector<Player>& players)
{
	cout << endl << endl;
	cout << " ---- SELL PLAYER ---- " << endl;
	cout << "PLAYERS:" << endl;
	if (players.empty())cout << "No players found!" << endl;
	else
	{
		for (auto& player : players) cout << player.name << endl;
		string name;
		bool found = false, found2 = false;
		cout << "Enter player name: ";
		cin >> name;
		cin.ignore();
		for (auto& player : players)
		{
			if (name == player.name)
			{
				cout << "Player found!" << endl;
				found = true;
				cout << "Name\tPrice\tTeam" << endl;
				cout << player.name << "\t";
				cout << player.price << "\t";
				cout << player.team << endl;
				cout << "Are you sure you want to sell this player? (Y/N): ";
				string answer;
				cin >> answer;
				cin.ignore();
				if (answer == "Y" || answer == "y")
				{
					string old_team = player.team;
					string new_team;
					cout << "Enter new team: ";
					getline(cin, new_team);
					for (auto& team : teams)
					{
						if (team.getName() == new_team)
						{
							player.team = new_team;
							found2 = true;
							cout << "Do you want to change the price? (Y/N): ";
							string answer2;
							cin >> answer2;
							cin.ignore();
							if (answer2 == "Y" || answer2 == "y")
							{
								cout << "Enter new price: ";
								float new_price;
								cin >> new_price;
								cin.ignore();
								player.price = new_price;
							}
							team.setBalance(team.getBalance() - player.price);
							cout << "Successful operation" << endl;
							for (auto& team2 : teams)
							{
								if (team2.getName() == old_team)
									team2.setBalance(team2.getBalance() + player.price);
							}
							break;
						}
					}
					if (!found2) cout << "Team not found!" << endl;
				}
				else cout << "Unsold player!" << endl;
			}
		}
		if (!found) cout << "Player not found!" << endl;
	}
}


inline void buy_player(vector<Team>& teams, vector<Player>& players)
{
	cout << endl << endl;
	cout << " ---- BUY PLAYER ---- " << endl;
	cout << "PLAYERS:" << endl;
	if (players.empty())cout << "No players found!" << endl;
	else
	{
		for (auto& player : players) cout << player.name << endl;
		string name;
		bool found = false, found2 = false;
		cout << "Enter player name: ";
		cin >> name;
		cin.ignore();
		for (auto& player : players)
		{
			if (name == player.name)
			{
				cout << "Player found!" << endl;
				found = true;
				cout << "Name\tPrice\tTeam" << endl;
				cout << player.name << "\t";
				cout << player.price << "\t";
				cout << player.team << endl;
				cout << "Are you sure you want to buy this player? (Y/N): ";
				string answer;
				cin >> answer;
				cin.ignore();
				if (answer == "Y" || answer == "y")
				{
					string old_team = player.team;
					found2 = true;
					string new_team;
					cout << "Enter new team: ";
					getline(cin, new_team);
					for (auto& team : teams)
					{
						if (team.getName() == new_team)
						{
							player.team = new_team;
							team.setBalance(team.getBalance() - player.price);
							cout << "Successful operation" << endl;
							for (auto& team2 : teams)
							{
								if (team2.getName() == old_team)
									team2.setBalance(team2.getBalance() + player.price);
							}
							break;
						}
					}
					if (!found2) cout << "Team not found!" << endl;
				}

				else cout << "Unbought player!" << endl;
			}
		}
		if (!found) cout << "Player not found!" << endl;
	}
}

inline void show_all_players(vector<Player> players)
{
	cout << endl << endl;
	cout << " ---- SHOW ALL PLAYERS ---- " << endl;
	cout << "PLAYERS:" << endl;
	cout << "Name\tSalary\tTeam" << endl;
	if (players.empty())cout << "No players found!" << endl;
	for (auto& player : players)
	{
		cout << player.name << "\t";
		cout << player.price << "\t";
		cout << player.team << endl;
	}
}
