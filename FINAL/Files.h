#pragma once

#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include<sstream>

#include "Team.h"

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
			<< "STADIUM" << "," << "CHAMPIONSHIPS" << "\n";
		myFileOutput.close();
	}
}


inline void read_file(vector<Team>& teams)
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

		int colIdx = 0;
		int _year = 0, _championships = 0;
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
			_championships
		};

		teams.push_back(temp);
	}
	myFileInput.close();
}
