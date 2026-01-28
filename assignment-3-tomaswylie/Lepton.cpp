// Lepton.cpp

// Implementation of the Lepton class

// Student ID: 10831050, last modified: 07/03/25

#include<iostream> // For std::cout, std::cin
#include<iomanip> // For std::setprecision
#include<cmath> // For std::sqrt
#include<string> // For std::string
#include<vector> // For std::vector
#include<stdexcept> // For std::invalid_argument
#include "Lepton.h"

// Default constructer
Lepton::Lepton() = default;

// Parameterised constructor
Lepton::Lepton(std::string Lepton_type, double Lepton_rest_mass, int Lepton_charge, double Lepton_velocity) :
  type{Lepton_type}, rest_mass{Lepton_rest_mass}, charge{Lepton_charge}, velocity{check_velocity(Lepton_velocity)},
  beta{velocity/speed_of_light} 
{};

// Destructor
Lepton::~Lepton(){};

// Function to create anti-particle from the existing particle's properties
Lepton Lepton::antiparticle()
{
  return Lepton("anti-" + type, rest_mass, -charge, velocity);
}

// Setter functions for the private data
void Lepton::set_type(const std::string type_in) {type = type_in;}
void Lepton::set_rest_mass(const double rest_mass_in) {rest_mass = rest_mass_in;}
void Lepton::set_charge(const int charge_in) {charge = charge_in;}
void Lepton::set_velocity(const double velocity_in) {velocity = velocity_in;}

// Getter functions for the private data
std::string Lepton::get_type() const {return type;}
double Lepton::get_rest_mass() const {return rest_mass;}
int Lepton::get_charge() const {return charge;}
double Lepton::get_velocity() const {return velocity;}
double Lepton::get_beta() const {return beta;}

// Method to check the inputted velocity is valid
double Lepton::check_velocity(const double& velocity_input)
{
  if(velocity_input<speed_of_light && velocity_input>=0)
  {
    return velocity_input;
  }
  else
  {
    throw std::invalid_argument("Velocity must not be greater than than the speed of light.");
  }
}

void Lepton::print_lepton() 
{
  std::cout<<std::setprecision(3)<<"\033[1;36m Particle:\033[0m [type, rest mass, charge, velocity, beta] = [\033[1;34m"<<type<<"\033[0m, "<<rest_mass<<" MeV, "
           <<std::showpos<<charge<<std::noshowpos<<", "<<velocity<<" m/s, "<<beta<<"]"<<std::endl;
}