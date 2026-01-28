// Detector.cpp

// Implementation of the Detector class

// Student ID: 10831050, last modified: 07/03/25

#include<iostream> // For std::cout, std::cin
#include<iomanip> // For std::setprecision
#include<cmath> // For std::sqrt
#include<string> // For std::string
#include<vector> // For std::vector
#include<stdexcept> // For std::invalid_argument
#include "Detector.h"

// Default constructor
Detector::Detector() = default;

// Parameterised constructor
Detector::Detector(std::string Detector_type) :
type{Detector_type}
{};

// Destructor
Detector::~Detector(){std::cout<<"Destroying "<<type<<std::endl;}

// Function to turn on detector
void Detector::turn_on()
{
status = true;
std::cout<<type<<" status: \033[1;32mON\033[0m"<<std::endl;
}

// Function to turn off detector
void Detector::turn_off()
{
status = false;
std::cout<<type<<" status: \033[1;31mOFF\033[0m"<<std::endl;
}

// Function of tracker detector (electrons, positrons, muons, and anti-muons)
int Detector::tracker_detector(Lepton const particle)
{
if(status==true && (particle.get_type()=="electron" || particle.get_type()=="anti-electron" || particle.get_type()=="muon" || particle.get_type()=="anti-muon"))
{
  std::cout<<particle.get_type()<<" was detected in the tracker"<<std::endl;
  return 1;
}
else
{
  return 0;
}
}

// Function of calorimeter detector (electrons and positrons)
int Detector::calorimeter_detector(Lepton const particle)
{
if(status==true && (particle.get_type()=="electron" || particle.get_type()=="anti-electron"))
{
  std::cout<<particle.get_type()<<" was detected in the calorimeter"<<std::endl;
  return 1;
}
else
{
  return 0;
}
}
// Function of muon chamber (muons and anti-muons)
int Detector::muon_chamber_detector(Lepton const particle)
{
if(status==true && (particle.get_type()=="muon" || particle.get_type()=="anti-muon"))
{
  std::cout<<particle.get_type()<<" was detected in the muon chamber"<<std::endl;
  return 1;
}
else
{
  return 0;
}
}

void Detector::print_detector()
{
  std::cout<<"Detector: [type, status]= ["<<type<<","<<(status? "ON":"OFF")<<"]"<<std::endl;
}