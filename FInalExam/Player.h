#pragma once

#include <string>

using namespace std;

class Player
{
public:
	string name;
	float price;
	string team;

	Player();
	~Player();
	Player(string, float, string);
};
