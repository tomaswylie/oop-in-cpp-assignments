// Photon.h

// Header file of the Photon object

// Student ID: 10831050, last updated: 05/04/25

#ifndef PHOTON_H
#define PHOTON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<memory>

#include "Particle.h"

class Electron;

class Photon: public Particle
{
private:
  std::vector<std::unique_ptr<Electron>> electrons;

public:

  // Default constructor
  Photon();

  // Parameterised constructor
  Photon(double energy_in);

  // Destructor
  ~Photon();

  // Function to print Photon data
  void print_data();

  // Energy setter function
  void set_energy(double energy_in);

  // Photoelectric effect
  friend double photoelectric_effect(const Photon& photon_in);

  // Compton scattering
  friend void compton_effect(Photon& photon_in, double angle);

  // Pair production
  friend std::vector<std::unique_ptr<Electron>> pair_production(const Photon& photon_in);
};

#endif