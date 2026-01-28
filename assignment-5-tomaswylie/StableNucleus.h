// StableNucleus.h

// Header file of the StableNucleus object

// Student ID: 10831050, last updated: 05/04/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "Nucleus.h"

class StableNucleus: public Nucleus
{
  public:

  // Default constructor
  StableNucleus();

  // Parameterised constructor
  StableNucleus(std::string nucleus_type_in, int atomic_mass_in, int atomic_number_in);

  // Destructor
  ~StableNucleus();

  void print_data();

  std::vector<std::unique_ptr<Photon>> decay();
};