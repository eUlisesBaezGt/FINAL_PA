#pragma once

#include <string>

using namespace std;

class Team
{
private:
	string _name;
	int _year;
	string _country;
	string _stadium;
	int _championships;
	float _balance;

public:
	Team();
	~Team();
	Team(string, int, string, string, int, float);

	string getName();
	void setName(string name_);

	int getYear() const;
	void setYear(int year_);

	string getCountry();
	void setCountry(string country_);

	string getStadium();
	void setStadium(string stadium_);

	int getChampionships() const;
	void setChampionships(int championships_);

	float getBalance() const;
	void setBalance(float balance_);
};
