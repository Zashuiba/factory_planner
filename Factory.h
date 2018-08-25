#ifndef  _FACTORY_
#define _FACTORY_
#include <cstring>
#include <string>

using namespace std;

class Factory
  {
    private:
      string name;
      double output_rate;
      int instances;
      float crafting_time;
    public:
      Factory(); //.cc
      ~Factory(){};
      double getOutputRate() const {return output_rate;}
      int getInstances() const {return instances;}
      void add_instance() {instances++;}
      float getCraftingTime() const {return crafting_time;}
      string getName() const {return name;}
  };
#endif
