#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"

using namespace std;

Player::Player(string name) {
	this->previous_decision = 1;
	this->name = name;
	this->points = 0;
}
int Player::get_points() {
	return this->points;
}
void Player::set_points(int points) {
	this->points = points;
}
string Player::get_name() {
	cout << "AAAAAAA   " << this->name << "   AAAAAAA"; //test
	return this->name;
}
void Player::set_name(string name) {
	this->name = name;
}
int Player::get_decision() {
	return this->previous_decision;
}
void Player::set_decision(int decision) {
	this->previous_decision = decision;
}

int Player::make_decision() {
	return 0;
}

Player::~Player() {}

