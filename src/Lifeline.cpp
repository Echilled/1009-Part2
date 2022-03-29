#include <string>
#include <stdio.h>
#include <iostream>

#include "Lifeline.h"
using namespace std;

Lifeline::Lifeline(){
  this->lifeline_count = 2;
}
int Lifeline::get_lifeline_count(){
  return lifeline_count;
}

void Lifeline::minus_lifeline(){
  if (this->lifeline_count >0){
    this->lifeline_count--;
  }else{
    cout << "No more Lifeline. No lifeline given..." << endl;
  }
}