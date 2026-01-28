// Particle.h

// Header file of the abstract base class Particle

// Student ID: 10831050, last updated: 05/04/25

#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

class Particle
{
protected:
  double energy; // In MeV
  double rest_mass; // In MeV
  std::string particle_type;

  Particle(double energy_in, double rest_mass_in);

public:

  virtual ~Particle() = default;
  virtual void print_data()=0;

  // Getter functions
  double get_energy() const;
  double get_rest_mass() const;
};

#endif