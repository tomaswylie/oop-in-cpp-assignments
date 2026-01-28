// Lepton.h

// Header file of the object Lepton

// Student ID: 10831050, last modified: 07/03/25

#ifndef LEPTON_H
#define LEPTON_H

#include<iostream> // For std::cout, std::cin
#include<iomanip> // For std::setprecision
#include<cmath> // For std::sqrt
#include<string> // For std::string
#include<vector> // For std::vector
#include<stdexcept> // For std::invalid_argument

const double speed_of_light{2.99792458e8};

class Lepton
{
private:
  std::string type;
  double rest_mass; // In terms of MeV
  int charge;
  double velocity;
  double beta;

public:
  // Default constructor
  Lepton();

  // Parameterised constructor
  Lepton(std::string Lepton_type, double Lepton_rest_mass, int Lepton_charge, double Lepton_velocity);

  // Destructor
  ~Lepton();

  double check_velocity(const double& velocity_input);

  Lepton antiparticle();

  // Setter functions
  void set_type(const std::string type_in);
  void set_rest_mass(const double rest_mass_in);
  void set_charge(const int charge_in);
  void set_velocity(const double velocity_in);

  // Getter functions
  std::string get_type() const;
  double get_rest_mass() const;
  int get_charge() const;
  double get_velocity() const;
  double get_beta() const;

  void print_lepton();
};

#endif