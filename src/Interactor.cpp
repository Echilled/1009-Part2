#include <string>
#include <stdio.h>
#include <iostream>
#include "Interactor.h"

Interactor::Interactor() {
	this->name = this->randomise_name();
	this->conversation = this->randomise_conversation();
}

Interactor::Interactor(string name) {
	this->name = name;
	this->conversation = this->randomise_conversation();
}

string Interactor::randomise_name() {
	string a[] = {"A1","B2","C3","D4","E5"};
	return a[rand()%5];
}
string Interactor::randomise_conversation() {
	return "hello world";
}

string Interactor::get_name() {
	return this->name;
}
string Interactor::get_conversation() {
	return this->conversation;
}

void Interactor::set_name(string name) {
	this->name = name;
}
void Interactor::set_conversation(string conversation) {
	this->conversation = conversation;
}
