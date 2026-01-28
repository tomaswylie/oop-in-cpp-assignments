// Particle.cpp

// Implementation file of the Particle object

// Student ID: 10831050, last updated: 05/04/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "Particle.h"

Particle::Particle(double energy_in, double rest_mass_in) :
  energy{energy_in}, rest_mass{rest_mass_in}
{
  if(energy_in < 0 || rest_mass_in < 0)
  {
    throw std::invalid_argument("Energy/rest mass cannot be negative.");
  }
  else
  {
    if(energy_in < rest_mass_in)
    {
      throw std::invalid_argument("Particle is unphysical. Energy cannot be less than the rest mass.");
    }
  }
};

// Getter functions
double Particle::get_energy() const {return energy;}
double Particle::get_rest_mass() const {return rest_mass;}