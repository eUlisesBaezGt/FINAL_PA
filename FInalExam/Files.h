#pragma once

#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include<sstream>

#include "Team.h"
#include "Player.h"

using namespace std;

inline void make_file()
{
	string filename = "Teams.csv";
	ifstream ifile;
	ifile.open(filename);
	if (!ifile)
	{
		ofstream myFileOutput(filename);
		myFileOutput << "NAME" << "," << "YEAR" << "," << "COUNTRY" << ","
			<< "STADIUM" << "," << "CHAMPIONSHIPS" << "," << "BALANCE" << "\n";
		myFileOutput.close();
	}

	string filename2 = "Players.csv";
	ifstream ifile2;
	ifile2.open(filename2);
	if (!ifile2)
	{
		ofstream myFileOutput2(filename2);
		myFileOutput2 << "NAME" << "," << "PRICE" << "," << "TEAM" << "\n";
		myFileOutput2.close();
	}
}


inline void read_file(vector<Team>& teams, vector<Player>& players)
{
	string line, colname;
	vector<string> headers;
	string value;

	ifstream myFileInput("Teams.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ','))
		{
			headers.push_back(colname);
		}
	}

	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0, _year = 0, _championships = 0;
		float _balance = 0.0f;
		string _name, _country, _stadium;

		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_name = value;
				break;
			case 1:
				_year = stoi(value);
				break;
			case 2:
				_country = value;
				break;
			case 3:
				_stadium = value;
				break;
			case 4:
				_championships = stoi(value);
				break;
			case 5:
				_balance = stof(value);
				break;
			default:
				break;
			}

			// If ',' as next character, skip it
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}

		Team temp = {
			_name,
			_year,
			_country,
			_stadium,
			_championships,
			_balance
		};

		teams.push_back(temp);
	}
	myFileInput.close();


	string line2, colname2;
	vector<string> headers2;
	string value2;

	ifstream myFileInput2("Players.csv");
	if (!myFileInput2.is_open()) throw runtime_error("Could not open file");
	if (myFileInput2.good())
	{
		// Extract the first line in the file
		getline(myFileInput2, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ','))
		{
			headers.push_back(colname);
		}
	}

	while (getline(myFileInput2, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		float price = 0.0f;
		string name, team;

		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				name = value;
				break;
			case 1:
				price = stof(value);
				break;
			case 2:
				team = value;
				break;
			default:
				break;
			}

			// If ',' as next character, skip it
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}

		Player temp = {
			name,
			price,
			team
		};

		players.push_back(temp);
	}
	myFileInput2.close();
}

inline void write_file(vector<Team> teams, vector<Player> players)
{
	ofstream myFileOutput("Teams.csv");
	myFileOutput << "NAME" << "," << "YEAR" << "," << "COUNTRY" << ","
		<< "STADIUM" << "," << "CHAMPIONSHIPS" << "," << "BALANCE" << "\n";

	for (auto& team : teams)
	{
		myFileOutput << team.getName() << "," << team.getYear() << "," << team.getCountry() << ","
			<< team.getStadium() << "," << team.getChampionships() << "," << team.getBalance() << "\n";
	}
	myFileOutput.close();


	ofstream myFileOutput2("Players.csv");
	myFileOutput2 << "NAME" << "," << "PRICE" << "," << "TEAM" << "\n";

	for (auto& player : players)
	{
		myFileOutput2 << player.name << "," << player.price << "," << player.team << "\n";
	}
	myFileOutput2.close();
}
