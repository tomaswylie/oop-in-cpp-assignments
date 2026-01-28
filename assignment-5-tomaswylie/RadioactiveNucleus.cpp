// RadioactiveNucleus.cpp

// Implementation of the RadioactiveNucleus object

// Student ID: 10831050, last updated: 05/04/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "RadioactiveNucleus.h"

// Default constructor
RadioactiveNucleus::RadioactiveNucleus() :
  Nucleus{"",0,0,false}, half_life{0}
{};

// Parameterised constructor
RadioactiveNucleus::RadioactiveNucleus(std::string nucleus_type_in, int atomic_mass_in, int atomic_number_in, double half_life_in) :
  Nucleus{nucleus_type_in,atomic_mass_in,atomic_number_in,false}, half_life{half_life_in}
{
  if(half_life_in <= 0) {throw std::invalid_argument("The half-life cannot be <= 0.");}
};

// Destructor
RadioactiveNucleus::~RadioactiveNucleus() {std::cout<<"RadioactiveNucleus destructor called"<<std::endl;};

void RadioactiveNucleus::print_data()
{
  std::cout<<"RADIOACTIVE NUCLEUS"<<std::endl;
  std::cout<<std::setw(40)<<std::setfill('-')<<""<<std::endl;
  std::cout<<"Type: "<<nucleus_type<<"\nAtomic mass: "<<atomic_mass<<"\nAtomic number: "<<atomic_number<<"\nHalf-life: "<<half_life<<" years\nDecay status: "
           <<(decay_status ? "Decayed" : "Not decayed")<<std::endl;
  std::cout<<std::setw(40)<<std::setfill('-')<<""<<std::endl;
}

std::vector<std::unique_ptr<Photon>> RadioactiveNucleus::decay()
{
  std::vector<std::unique_ptr<Photon>> photons;

  if(decay_status == true) {throw std::logic_error("This nucleus has already decayed.");}

  decay_status = true;

  if(atomic_mass == 22 && atomic_number == 11)
  {
    photons.push_back(std::make_unique<Photon>(1.2745));
  }
  else
  {
    if(atomic_mass == 137 && atomic_number == 55)
    {
      photons.push_back(std::make_unique<Photon>(0.661));
    }
    else
    {
      if(atomic_mass == 60 && atomic_number == 27)
      {
        photons.push_back(std::make_unique<Photon>(1.173));
        photons.push_back(std::make_unique<Photon>(1.333));
      }
      else
      {
        throw std::invalid_argument("No valid radioactive nuclei found.");
      }
    }
  }

  return photons;
}

