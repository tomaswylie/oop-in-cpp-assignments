// RadioactiveNucleus.h

// Header file of the RadioactiveNucleus object

// Student ID: 10831050, last updated: 05/04/25

#ifndef RADIOACTIVENUCLEUS_H
#define RADIOACTIVENUCLEUS_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<memory>

#include "Nucleus.h"

class RadioactiveNucleus: public Nucleus
{
  protected:
  double half_life; // In years

  public: 

  // Default constructor
  RadioactiveNucleus();

  // Parameterised constructor
  RadioactiveNucleus(std::string nucleus_type_in, int atomic_mass_in, int atomic_number_in, double half_life_in);

  // Destructor
  ~RadioactiveNucleus();

  void print_data();

  std::vector<std::unique_ptr<Photon>> decay();
};

#endif