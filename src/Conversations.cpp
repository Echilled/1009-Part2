#include <string>
#include <stdio.h>
#include <iostream>
#include "Conversations.h"

Conversations::Conversations() {
	this->name = this->randomise_name();
	this->conversation = this->randomise_conversation();
}

Conversations::Conversations(string name) {
	this->name = name;
	this->conversation = this->randomise_conversation();
}

string Conversations::randomise_name() {
	string a[] = {"A1","B2","C3","D4","E5"};
	return a[rand()%5];
}
string Conversations::randomise_conversation() {
	return "hello world";
}

string Conversations::get_name() {
	return this->name;
}
string Conversations::get_conversation() {
	return this->conversation;
}

void Conversations::set_name(string name) {
	this->name = name;
}
void Conversations::set_conversation(string conversation) {
	this->conversation = conversation;
}
