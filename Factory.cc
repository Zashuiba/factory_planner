#include "Factory.h"
#include <iostream>

using namespace std;

Factory::Factory()
  {
    cout << "What do you want to produce ? : ";
    string s;
    getline(cin, s);
    this->name = s;
    cout << "How many products does one crafting of this product yield ? : ";
    int num;
    cin >> num;
    cin.ignore();
    cout << "In how much time ? : ";
    float den;
    cin >> den;
    cin.ignore();
    this-> output_rate = num / den;
    this->instances = 1;
    this->crafting_time = den;
  }
