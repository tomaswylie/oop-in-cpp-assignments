// Electron.h

// Header file of the Electron object

// Student ID: 10831050, last updated: 05/04/25

#ifndef ELECTRON_H
#define ELECTRON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "Particle.h"

const double electron_rest_mass{0.511}; // In MeV

class Photon;

class Electron: public Particle
{
private:
  std::vector<std::unique_ptr<Photon>> radiation;

public:

  // Default constructor
  Electron();

  // Parameterised constructor
  Electron(double energy_in);

  // Destructor
  ~Electron();

  // Function to print Electron data
  void print_data();

  // Friend function decleration to produce radiation from electron
  friend std::unique_ptr<Photon> radiate(const Electron& electron_in);
};

#endif