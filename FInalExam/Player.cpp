#include "Player.h"

Player::Player()
{
	this->name = " ";
	this->price = 0.0f;
	this->team = " ";
}

Player::~Player()
= default;

Player::Player(string name, float price, string team)
{
	this->name = move(name);
	this->price = price;
	this->team = move(team);
}
