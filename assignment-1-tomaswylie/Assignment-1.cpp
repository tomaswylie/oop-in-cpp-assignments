// Assignment 1

// Program to calculate transition energy using simple Bohr formula

//Tomas Wylie - 10831050, 06/02/2025

#include<iostream>
#include<iomanip>
#include<limits>
#include<cmath>

const double elementary_charge{1.602e-19};
const double rydberg_energy{13.6};

bool flag{false};
bool& valid{flag}; // Declares global variable valid used to keep track of the validity of each input.

void check_input(int value)
{
  // Checks whether value is positive and if stream is in a good state to handle non-int inputs.
  if(value > 0 && !std::cin.fail())
  {
    valid = true;
  }
  else
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Value inputted is invalid. Please enter a positive integer."<<std::endl;
  }
}

bool check_quantum_number(int initial, int final)
{
  // Checks that the quantum numbers are physcial.
  if(initial > final)
  {
    return true;
  }
  else
  {
    return false;
  }
}

double output_transition_energy(int atomic_number, int initial_quantum_number, int final_quantum_number)
{
  // Asks user which units they require then calculates and prints out the transition energy.
  std::string units;
  double transition_energy;

  while(units != "eV" || units != "J")
  {
    std::cout<<"Would you prefer transition energy in eV or J? ";
    std::cin>>units;
    std::cout<<std::endl;

    if(units == "eV" || units == "J")
    {
      break;
    }
    else
    {
      std::cout<<"Invalid units. Please enter your option as follows \"eV\" or \"J\""<<std::endl;
    }
  }

  transition_energy = rydberg_energy*std::pow(atomic_number,2)*((1/std::pow(final_quantum_number, 2))-(1/std::pow(initial_quantum_number, 2))); // Transition energy calculated in eV.

  if(units == "eV")
  {
    std::cout<<"The energy of this transition is "<<std::setprecision(3)<<transition_energy<<" eV"<<std::endl<<std::endl;
  }
  else
  {
    if(units == "J")
    {
      transition_energy *= elementary_charge;
    }
    std::cout<<"The energy of this transition is "<<std::setprecision(3)<<transition_energy<<" J"<<std::endl;
  }

  return transition_energy;
}

int main()
{
  char run{'y'};
  bool decision{true};
  int input_atomic_number;
  int input_initial_quantum_number;
  int input_final_quantum_number;

  while(decision == true) 
  {
    while(valid == false) 
    {
      // Asks user to input the atomic number and checks the value.
      std::cout<<"Please enter an atomic number: ";
      std::cin>>input_atomic_number;
      std::cout<<std::endl;
      check_input(input_atomic_number);
    }

    valid = false;

    while(valid == false)
    {
      while(valid == false)
      {
        // Asks user to input the initial quantum number and checks the value.
        std::cout<<"Please enter the initial quantum number: ";
        std::cin>>input_initial_quantum_number;
        std::cout<<std::endl;
        check_input(input_initial_quantum_number);
      }

      valid = false;

      while(valid == false)
      {
        // Asks user to input the final quantum number and checks the value.
        std::cout<<"Please enter the final quantum number: ";
        std::cin>>input_final_quantum_number;
        std::cout<<std::endl;
        check_input(input_final_quantum_number);
      }

      valid = false;
      valid = check_quantum_number(input_initial_quantum_number, input_final_quantum_number);
      if(valid == false) {std::cout<<"The initial quantum number n_i must be greater than the final quantum number n_j. Please try again."<<std::endl;}
    }
    
    output_transition_energy(input_atomic_number, input_initial_quantum_number, input_final_quantum_number);

    std::cout<<"Would you like to continue? (y/n)"<<std::endl;
    std::cin>>run;
    std::cout<<std::endl;

    if(run == 'y')
    {
      decision = true;
      valid = false;
    }
    else
    {
      if(run == 'n')
      {
        std::cout<<"Program terminated."<<std::endl;
        decision = false;
        continue;
      }

      std::cout<<"Invalid input. Program terminated."<<std::endl;
      decision = false;
    }
  }
  return 0;
}
