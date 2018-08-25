#ifndef _INPUT_
#define _INPUT_
#include <string>
#include <iostream>

using namespace std;

class Input{
  private:
    string name;
    double rate;
    int instances;
    float crafting_time;
    int required;
  public:
    Input();
    int getRequired() const {return required;}
    int getInstances() const {return instances;}
    void setInstances(const int& instances) {this->instances = instances;}
    double getRate() const {return rate;}
    float getCraftingTime() const {return crafting_time;}
    void add_instance() {instances++;}
    string getName() const {return name;}
};
#endif
