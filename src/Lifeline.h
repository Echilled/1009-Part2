#pragma once
#include <string>
#include <stdio.h>
#include <iostream>


using namespace std;

class Lifeline{
protected:
    int lifeline_count;
    int lifeline_selection;
public:
  Lifeline();	
  int get_lifeline_count();
  int get_lifeline_selection();
  void set_lifeline_selection(int);
  void minus_lifeline();
  int lifeline_menu(int);
  void reveal_type();
};
