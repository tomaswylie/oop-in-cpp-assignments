// assignment-5.cpp

// Program to simulate the radioactive decay of unstable nuclei, returning photon objects. The various interactions of these
// photons with matter are simulated: the photoelectric effect, Compton scattering and pair production, the latter returning
// electron objects. These electrons are then simulated to radiate photons if they have energy in excess of their rest mass 
// energy.

// Student ID: 10831050, last updated: 05/04/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "Nucleus.h"
#include "StableNucleus.h"
#include "RadioactiveNucleus.h"

#include "Particle.h"
#include "Electron.h"
#include "Photon.h"

// Main program
int main()
{
  try
  {
    // Each Nuclei
    std::vector<std::unique_ptr<Nucleus>> nuclei;
    nuclei.push_back(std::make_unique<StableNucleus>("Fe",56,26));
    nuclei.push_back(std::make_unique<RadioactiveNucleus>("Na",22,11,2.603));
    nuclei.push_back(std::make_unique<RadioactiveNucleus>("Cs",137,55,30.17));
    nuclei.push_back(std::make_unique<RadioactiveNucleus>("Co",60,27,5.272));

    std::vector<std::unique_ptr<Photon>> photons;  // 1.274, 0.661, 1.173, 1.333 
    nuclei[0]->print_data();
    for(size_t i=1;i<nuclei.size();i++)
    {
      nuclei[i]->print_data();
      for(auto& photon : nuclei[i]->decay())
      {
        photons.push_back(std::move(photon));
      }
    }

    for(auto& photon : photons)
    {
      photon->print_data();
    }

    std::vector<std::unique_ptr<Electron>> electron_pair_1{pair_production(*photons[0])};
    std::vector<std::unique_ptr<Electron>> electron_pair_2{pair_production(*photons[1])}; // Cannot pair produce as energy is too small

    photons.push_back(radiate(*electron_pair_1[0]));
    photons[4]->print_data();

    compton_effect(*photons[2],M_PI/4);
    photons[2]->print_data();

    std::cout<<"Photon emitted from decay of Co60 has energy: "<<photoelectric_effect(*photons[3])<<" MeV"<<std::endl;


  }
  catch(const std::invalid_argument& error1)
  {
    std::cout<<"Error: "<<error1.what()<<std::endl;
    return 1;
  }
  catch(const std::logic_error& error2)
  {
    std::cout<<"Error: "<<error2.what()<<std::endl;
    return 1;
  }

  return 0;
}
