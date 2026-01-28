// assignment-4.cpp

// A program to construct particle objects with basic four-momentum calculus functionality; and to
// implement copy/move constructors and assignment/move assignment operators, to correctly copy/move
// these particle objects into new or existing objects.

// Student ID: 10831050, last updated 22/02/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stdexcept>

#include "particle.cpp"

int main()
{
  try
  {
    std::vector<particle> particle_list;

    // Declares 6 particle objects: 2 of type "electron", 2 of type "muon", and 2 of type "tau"
    particle electron1("electron",10,2,3,4);
    particle electron2("electron",8,6,1,2);
    
    particle muon1("muon",150,44,23,14);
    particle muon2("muon",123,13,17,14);
    
    particle tau1("tau",1777,343,189,56);
    particle tau2("tau",1963,18,698,278);
    
    // Pushes back all particles into particle list
    particle_list.push_back(electron1); // 0
    particle_list.push_back(electron2); // 1
    particle_list.push_back(muon1); // 2
    particle_list.push_back(muon2); // 3
    particle_list.push_back(tau1); // 4
    particle_list.push_back(tau2); // 5

    // Prints the data of all of the particles in the list
    for(const particle& i : particle_list)
    {
      i.print_data();
    }
    
    // Sum the momenta of the two electrons
    particle electron3;
    electron3 = particle_list[0] + particle_list[1];
    std::cout<<"electron3"<<std::endl;
    electron3.print_data();
    
    // Dot product of the two muons
    double muon_dot_product;
    muon_dot_product = particle_list[2].dotProduct(particle_list[3]);
    std::cout<<"muon_dot_product = "<<muon_dot_product<<std::endl;
    
    // Assignment operator of the first electron to a new electron
    particle new_electron;
    new_electron = particle_list[0];
    std::cout<<"new_electron"<<std::endl;
    new_electron.print_data();
    
    // Copy constructor of the first muon to a new muon
    particle new_muon(particle_list[2]);
    std::cout<<"new_muon"<<std::endl;
    new_muon.print_data();
    
    // Assignment of the first tau to a different tau using the move assignment
    particle different_tau("tau",3578,1689,356,24);
    different_tau = std::move(particle_list[4]);
    std::cout<<"different_tau"<<std::endl;
    different_tau.print_data();
    
    // Moving the second tau into the first tau using the move constructor
    particle moved_tau{std::move(particle_list[5])};
    std::cout<<"moved_tau"<<std::endl;
    moved_tau.print_data();
  }
  catch(const std::invalid_argument& error)
  {
    std::cout<<"Error: "<<error.what()<<std::endl;
    return 1;
  }
  return 0;
}
