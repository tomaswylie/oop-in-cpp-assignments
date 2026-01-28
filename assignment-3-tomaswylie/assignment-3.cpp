// assignment-3.cpp

// A program to construct lepton objects for various lepton types, and detector object for a tracker, calorimeter,
// and muon chamber. These particles are passed through each detector type where whether they are detected depends on
// their type and the status of the detector.

// Student ID: 10831050, last modified: 07/03/25

#include<iostream> // For std::cout, std::cin
#include<iomanip> // For std::setprecision
#include<cmath> // For std::sqrt
#include<string> // For std::string
#include<vector> // For std::vector
#include<stdexcept> // For std::invalid_argument
#include "Detector.h"
#include "Lepton.h"

int main()
{
  std::vector<Lepton> particle_list{};
  // Try's to construct the objects for all known Leptons and throws an error if any velocity provided is invalid.
  try
  {
    // Declares two lepton objects for two electrons
    Lepton electron1("electron",0.511,-1,1.8e8);
    Lepton electron2("electron",0.511,-1,2e8);
    particle_list.push_back(electron1);
    particle_list.push_back(electron2);

    // Declares a lepton object positron
    Lepton positron{electron2.antiparticle()};
    particle_list.push_back(positron);

    // Declares four lepton objects for four muons
    Lepton muon1("muon",106,-1,1.9e8);
    Lepton muon2("muon",106,-1,2.5e8);
    Lepton muon3("muon",106,-1,2.3e8);
    Lepton muon4("muon",106,-1,2.4e8);

    particle_list.push_back(muon1);
    particle_list.push_back(muon2);
    particle_list.push_back(muon3);
    particle_list.push_back(muon4);

    // Declares the lepton object anti_muon
    Lepton anti_muon{muon1.antiparticle()};
    particle_list.push_back(anti_muon);

    std::cout<<"\n===Particle Data==="<<std::endl<<std::endl;

    // Iterates through all particles and prints them
    for(Lepton i : particle_list)
    {
      i.print_lepton();
    }

    std::cout<<std::endl; // Inserts space between text blocks

    // Declares the detector object tracker, turns it on, passes the particles through it, and turns it off.
    Detector tracker("tracker");

    tracker.turn_on();

    std::cout<<std::endl; // Inserts space between text blocks

    for(Lepton i : particle_list)
    {
      tracker.tracker_detector(i);
    }

    std::cout<<std::endl; // Inserts space between text blocks

    tracker.turn_off();

    std::cout<<std::endl; // Inserts space between text blocks

    // Declares the detector object calorimeter, turns it on, passes the particles through it, and turns it off
    Detector calorimeter("calorimeter");

    calorimeter.turn_on();

    std::cout<<std::endl; // Inserts space between text blocks

    for(Lepton i : particle_list)
    {
      calorimeter.calorimeter_detector(i);
    }

    std::cout<<std::endl; // Inserts space between text blocks

    calorimeter.turn_off();

    std::cout<<std::endl; // Inserts space between text blocks

    // Declares the detector object muon_chamber, turns it on, passes the particles through it, and turns it off
    Detector muon_chamber("muon chamber");

    muon_chamber.turn_on();

    std::cout<<std::endl; // Inserts space between text blocks

    for(Lepton i : particle_list)
    {
      muon_chamber.muon_chamber_detector(i);
    }

    std::cout<<std::endl; // Inserts space between text blocks

    muon_chamber.turn_off();

    std::cout<<std::endl; // Inserts space between text blocks
  }
  catch(const std::invalid_argument& error)
  {
    std::cout<<"Error: "<<error.what()<<std::endl;
    return 1;
  }

  return 0;
}