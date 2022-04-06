#include <string>
#include <stdio.h>
#include <iostream>
#include "Lifeline.h"
using namespace std;

Lifeline::Lifeline() {
    this->lifeline_count = 2;
}
int Lifeline::get_lifeline_count() {
    return lifeline_count;
}
void Lifeline::set_lifeline_selection(int selection) {
	this->lifeline_selection = selection;
}
int Lifeline::get_lifeline_selection() {
	return this->lifeline_selection;
}

void Lifeline::minus_lifeline() {
    if (this->lifeline_count > 0) {
        this->lifeline_count--;
        cout << "Current Lifeline Count: " << lifeline_count << endl;
    }
    else {
        cout << "No more Lifeline. No lifeline used..." << endl;
    }
}

int Lifeline::lifeline_menu(int lifeline_count) {
    int lifeline_decision = -1;
    do {
        cout << "===================================================" << endl;
        cout << "Current Lifeline Count: " << lifeline_count << endl;
        cout << "Choose one of the following Lifeline:" << endl;
        cout << "1) Reveal Bot(AI) Type" << endl;
        cout << "2) Force current Bot(AI) to Cooperate with you." << endl;
        cout << "Lifeline decision required: " << endl;
        cin >> lifeline_decision;
        cout << "---------------------------------------------" << endl;

        if (lifeline_decision > 2 || lifeline_decision < 1) {
            cout << "Invalid Option. Please choose the following options again."
                << endl;
        }
    } while (lifeline_decision != 1 && lifeline_decision != 2);
    return lifeline_decision;
}


