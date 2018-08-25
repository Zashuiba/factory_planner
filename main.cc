#include "Factory.h"
#include "Input.h"
#include <vector>
#include <cmath>

static const float DELTA = 0.001;

void print_results(const vector<Input>& inputs, const Factory& factory)
  {
    cout << "The smallest factory capable of mantaining the ratio has ";
    for (unsigned int i = 0; i < inputs.size(); i++)
        cout << inputs[i].getInstances() << " " << inputs[i].getName() << " factories , ";
    cout << "and " << factory.getInstances() << " " << factory.getName() << " factories." << endl;
    cout << "This will produce " << factory.getOutputRate() * factory.getInstances() << " "
    << factory.getName() << " every second" << endl;
    cout << "You can now scale this values by the same number and the ratio will still be kept." << endl;
    cout << "Take into account that in order for the ratio to be mantained, all the assembly machines have to be of the same rank." << endl;
  }

bool is_balanced(const vector<Input>& inputs, const Factory& factory)
  {
    for (unsigned int i = 0; i < inputs.size(); i++)
      {
        if (abs((inputs[i].getRate() * inputs[i].getInstances()) -
           (factory.getInstances() * inputs[i].getRequired() / factory.getCraftingTime())) > DELTA)
          return false;
      }
    return true;
  }

int main()
  {
    //data input
    cout << "Welcome, to factorio factory planner ! " << endl;
    cout << "You can only design a complex item at a time (a green circuit design will give you ratios" << endl;
    cout << "for green to copper coil, but won't tell you how many drills/furnaces you need)" << endl;
    Factory final_product;
    cout << endl;
    vector<Input> inputs;
    cout << "Now input the (non elemmental) materials required for production : " << endl;
    char sel;
    do
      {
        inputs.push_back(Input());
        cout << "Is there any other material left ? (y / n) : ";
        cin >> sel;
        cin.ignore();
      } while (sel == 'y');
    //instances calculation
    while (!is_balanced(inputs, final_product))
      {
        for (unsigned int i = 0; i < inputs.size(); i++)
          {
            if ((inputs[i].getInstances() * inputs[i].getRate()) -
               (final_product.getInstances() * inputs[i].getRequired() / final_product.getCraftingTime())
               < (float) ((-1) * DELTA))
                  inputs[i].add_instance();
            else if ((inputs[i].getInstances() * inputs[i].getRate()) -
                    (final_product.getInstances() * inputs[i].getRequired() / final_product.getCraftingTime())
                    > DELTA)
                        final_product.add_instance();
          }
      }
    print_results(inputs, final_product);
    return 0;
  }
