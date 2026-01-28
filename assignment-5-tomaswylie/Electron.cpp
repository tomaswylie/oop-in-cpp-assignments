// Electron.cpp

// Implementation of the Electron object

// Student ID: 10831050, last updated: 05/04/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "Electron.h"
#include "Photon.h"

// Default constructor
Electron::Electron() :
  Particle(0,electron_rest_mass)
{};

// Parameterised constructor
Electron::Electron(double energy_in) :
  Particle(energy_in,electron_rest_mass)
{};

// Destructor
Electron::~Electron() {std::cout<<"Electron destructor called"<<std::endl;};

// Function to print Electron data
void Electron::print_data()
{
  std::cout<<"ELECTRON"<<std::endl;
  std::cout<<std::setw(40)<<std::setfill('-')<<""<<std::endl;
  std::cout<<"Energy: "<<energy<<" MeV"<<std::endl;
  std::cout<<"Rest mass: "<<rest_mass<<" MeV"<<std::endl;
  std::cout<<std::setw(40)<<std::setfill('-')<<""<<std::endl;
}

std::unique_ptr<Photon> radiate(const Electron& electron_in)
{
  if(electron_in.energy > electron_rest_mass)
  {
    std::cout<<"Radiation emitted"<<std::endl;
    return std::make_unique<Photon>(electron_in.energy-electron_rest_mass);
  }
  else
  {
    std::cerr<<"Error: Electron does not have enough energy to radiate."<<std::endl;
    return nullptr;
  }
}