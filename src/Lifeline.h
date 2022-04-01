#pragma once
#include <string>
#include <stdio.h>
#include <iostream>


using namespace std;

class Lifeline{
protected:
    int lifeline_count;
public:
  Lifeline();	
  int get_lifeline_count();
  void minus_lifeline();
  int lifeline_menu(int);
  void reveal_type();
};