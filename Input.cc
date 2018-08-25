#include "Input.h"

Input::Input()
  {
    cout << "What's the name of this intermediate material ? : ";
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
    this->rate = num / den;
    this-> instances = 1;
    cout << "How much " << this->name << " do you need per crafting? :";
    cin >> this->required;
    this->crafting_time = den;
  }
