// Nucleus.cpp

// Implementation of the Nucleus object

// Student ID: 10831050, last updated: 05/04/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<memory>

#include "Nucleus.h"

// Parameterised constructor
Nucleus::Nucleus(std::string nucleus_type_in, int atomic_mass_in, int atomic_number_in, bool decay_status_in) :
  nucleus_type{nucleus_type_in}, decay_status{decay_status_in}
{
  if(atomic_mass_in >= 0 && atomic_number_in >= 0)
  {
    atomic_mass = atomic_mass_in;
    atomic_number = atomic_number_in;
  }
  else
  {
    if(atomic_number_in < 0)
    {
      throw std::invalid_argument("Atomic number cannot be negative.");
    }
    else
    {
      if(atomic_mass_in < 0)
      {
        throw std::invalid_argument("Atomic mass cannot be negative.");
      }
      else
      {
        throw std::invalid_argument("Please check your atomic mass/atomic number input.");
      }
    }
  }
};

// Getter functions
std::string Nucleus::get_nucleus_type() const {return nucleus_type;}
int Nucleus::get_atomic_mass() const {return atomic_mass;}
int Nucleus::get_atomic_number() const {return atomic_number;}
bool Nucleus::get_decay_status() const {return decay_status;}
