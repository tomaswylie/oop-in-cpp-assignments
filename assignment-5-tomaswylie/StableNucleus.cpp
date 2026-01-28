// StableNucleus.cpp

// Implementation of the StableNucleus object

// Student ID: 10831050, last updated: 05/04/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<memory>

#include "StableNucleus.h"

// Default constructor
StableNucleus::StableNucleus() :
  Nucleus{"", 0, 0, false}
{};

// Parameterised constructor
StableNucleus::StableNucleus(std::string nucleus_type_in, int atomic_mass_in, int atomic_number_in) :
  Nucleus{nucleus_type_in,atomic_mass_in,atomic_number_in,false}
{};

StableNucleus::~StableNucleus() {std::cout<<"StableNucleus destructor called"<<std::endl;}

void StableNucleus::print_data()
{
  std::cout<<"STABLE NUCLEUS"<<std::endl;
  std::cout<<std::setw(40)<<std::setfill('-')<<""<<std::endl;
  std::cout<<"Type: "<<nucleus_type<<"\nAtomic mass: "<<atomic_mass<<"\nAtomic number: "<<atomic_number<<"\nDecay status: "
           <<(decay_status ? "Decayed" : "Not decayed")<<std::endl;
  std::cout<<std::setw(40)<<std::setfill('-')<<""<<std::endl;
}

std::vector<std::unique_ptr<Photon>> StableNucleus::decay()
{
  throw std::logic_error("A stable nucleus cannot decay");
}