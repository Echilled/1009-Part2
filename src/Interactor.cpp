#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "Interactor.h"

Interactor::Interactor() {
	this->conversation = this->randomise_conversation();
}

string Interactor::randomise_conversation() {
	return "hello world";
}



string Interactor::get_conversation() {
	return this->conversation;
}
void Interactor::set_conversation(string conversation) {
	this->conversation = conversation;
}
