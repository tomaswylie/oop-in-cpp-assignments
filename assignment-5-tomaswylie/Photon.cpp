// Photon.cpp

// Implementation of the Photon object

// Student ID: 10831050, last updated: 05/04/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<memory>

#include "Photon.h"
#include "Electron.h"


// Default constructor
Photon::Photon() :
  Particle(0,0)
{};

// Parameterised constructor for photon with zero mass
Photon::Photon(double energy_in) :
  Particle(energy_in,0)
{};

// Destructor
Photon::~Photon() {std::cout<<"Photon destructor called"<<std::endl;};

// Function to print Photon data
void Photon::print_data()
{
  std::cout<<"PHOTON"<<std::endl;
  std::cout<<std::setw(40)<<std::setfill('-')<<""<<std::endl;
  std::cout<<"Energy: "<<energy<<" MeV"<<std::endl;
  std::cout<<std::setw(40)<<std::setfill('-')<<""<<std::endl;
}

void Photon::set_energy(double energy_in) {energy=energy_in;}

double photoelectric_effect(const Photon& photon_in) {return photon_in.energy;}

void compton_effect(Photon& photon_in, double angle)
{
  photon_in.set_energy((photon_in.get_energy())/(1+(photon_in.get_energy()/electron_rest_mass)*(1-cos(angle))));

  std::cout<<"Photon underwent Compton scattering."<<std::endl;
}

std::vector<std::unique_ptr<Electron>> pair_production(const Photon& photon_in)
{
  std::vector<std::unique_ptr<Electron>> electron_pair{};

  if(photon_in.energy < 2*electron_rest_mass)
  {
    std::cerr<<"Error: Photon does not have sufficient energy to pair-produce."<<std::endl;
    
    return electron_pair;
  }

  double split_energy = (photon_in.energy - 2*electron_rest_mass)/2;
  electron_pair.push_back(std::make_unique<Electron>(split_energy + electron_rest_mass));
  electron_pair.push_back(std::make_unique<Electron>(split_energy + electron_rest_mass));

  std::cout<<"Electron-positron pair produced."<<std::endl;

  return electron_pair;
}
