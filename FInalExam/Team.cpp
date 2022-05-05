#include "Team.h"

#include <utility>

Team::Team()
{
	this->_name = " ";
	this->_year = 0;
	this->_country = " ";
	this->_stadium = " ";
	this->_championships = 0;
	this->_balance = 0.0f;
}

Team::~Team()
= default;

Team::Team(string name_, int year_, string country_, string stadium_, int championships_, float balance_)
{
	this->_name = move(name_);
	this->_year = year_;
	this->_country = move(country_);
	this->_stadium = move(stadium_);
	this->_championships = championships_;
	this->_balance = balance_;
}

string Team::getName()
{
	return this->_name;
}

void Team::setName(string name_)
{
	this->_name = name_;
}

int Team::getYear() const
{
	return this->_year;
}

void Team::setYear(const int year_)
{
	this->_year = year_;
}

string Team::getCountry()
{
	return this->_country;
}

void Team::setCountry(string country_)
{
	this->_country = move(country_);
}

string Team::getStadium()
{
	return this->_stadium;
}

void Team::setStadium(string stadium_)
{
	this->_stadium = move(stadium_);
}

int Team::getChampionships() const
{
	return this->_championships;
}

void Team::setChampionships(const int championships_)
{
	this->_championships = championships_;
}

float Team::getBalance() const
{
	return this->_balance;
}

void Team::setBalance(float balance_)
{
	this->_balance = balance_;
}
