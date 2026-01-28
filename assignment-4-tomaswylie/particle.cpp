// particle.cpp

// Implementation of the particle class

// Student ID: 10831050, last updated: 22/03/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stdexcept>
#include<utility>

#include "particle.h"

// Default constructor
particle::particle() :
  particle_name{""}, four_momentum(new std::vector<double>(4,0.0))
{};

// Parameterised constructor
particle::particle(std::string particle_name_in, double E, double px, double py, double pz)
{
  if(E<0)
  {
    throw std::invalid_argument("Energy cannot be negative.");
  }
  else
  {
    if(particle_name_in == "electron" || particle_name_in == "muon" || particle_name_in == "tau" ||
       particle_name_in == "positron" || particle_name_in == "anti-electron" ||
       particle_name_in == "anti-muon" || particle_name_in == "anti-tau")
    {
      particle_name = particle_name_in;
      four_momentum = new std::vector<double>{E,px,py,pz};
    }
    else
    {
      throw std::invalid_argument("Invalid particle name inputted.");
    }
  }
};

// Destructor
particle::~particle()
{
  delete four_momentum; // Clears dynamically allocated memory
  std::cout<<"Calling destructor for "<<particle_name<<std::endl;
}

// Setter functions
void particle::set_name(const std::string particle_name_in) {particle_name = particle_name_in;}
void particle::set_E(const double E_in)
{
  if(E_in<0)
  {
    throw std::invalid_argument("Energy cannot be negative.");
  }
  else
  {
  (*four_momentum)[0] = E_in;
  }
}
void particle::set_px(const double px_in) {(*four_momentum)[1] = px_in;}
void particle::set_py(const double py_in) {(*four_momentum)[2] = py_in;}
void particle::set_pz(const double pz_in) {(*four_momentum)[3] = pz_in;}

// Getter functions
std::string particle::get_name() const {return particle_name;}
double particle::get_E() const {return (*four_momentum)[0];}
double particle::get_px() const {return (*four_momentum)[1];}
double particle::get_py() const {return (*four_momentum)[2];}
double particle::get_pz() const {return (*four_momentum)[3];}
std::vector<double> particle::get_four_momentum() const {return (*four_momentum);}

// Assigment operator
particle particle::operator=(const particle& p)
{
  std::cout<<"Assignment operator called"<<std::endl;

  if(&p == this){return *this;} // Checks self-assignment

  delete four_momentum; // Deletes dynamically allocated memory

  particle_name = p.get_name();
  four_momentum = new std::vector<double>(p.get_four_momentum());

  return *this;
}

// Copy constructor
particle::particle(const particle& q)
{
  std::cout<<"Copy constructor called"<<std::endl;
  particle_name = q.get_name();
  four_momentum = new std::vector<double>(q.get_four_momentum());
}

// Move assignment operator
particle& particle::operator=(particle&& input_particle) noexcept
{
  std::cout<<"Move assignment operator called"<<std::endl;

  if(this == &input_particle) {return *this;} // Checks self-assignment

  delete four_momentum; // Deletes dynamically allocated memory
  particle_name=std::move(input_particle.particle_name);
  four_momentum = input_particle.four_momentum;
  input_particle.four_momentum = nullptr;
  return *this;
}

// Move constructor
particle::particle(particle&& input_particle) noexcept :
  particle_name{std::move(input_particle.particle_name)}, four_momentum{input_particle.four_momentum}
{
  std::cout<<"Move constructor called"<<std::endl;
  input_particle.four_momentum = nullptr;
}

// Four-vector addition operator
particle particle::operator+(const particle& a) const
{
  particle temp;
  if(a.get_four_momentum().size() != 4)
  {
    throw std::invalid_argument("You are trying to add a vector that is not a four-vector");
  }
  else
  {
    temp.set_name(particle_name);
    temp.set_E((*four_momentum)[0]+a.get_E());
    temp.set_px((*four_momentum)[1]+a.get_px());
    temp.set_py((*four_momentum)[2]+a.get_py());
    temp.set_pz((*four_momentum)[3]+a.get_pz());
  }
  return temp;
}

// Function to perform a dot product between two four-vectors
double particle::dotProduct(const particle& p)
{
  return ((*four_momentum)[0]*p.get_E()) - ((*four_momentum)[1]*p.get_px())
           - ((*four_momentum)[2]*p.get_py()) - ((*four_momentum)[3]*p.get_pz());
}

// Function to print the formatted name, four-momentum, and memory address of a particle
void particle::print_data() const
{
  std::cout<<"Particle: [\033[1;90mType\033[0m,(E/c,p_x,p_y,p_z)] = "<<"[\033[1;90m"<<particle_name<<"\033[0m,("<<(*four_momentum)[0]<<","
           <<(*four_momentum)[1]<<","<<(*four_momentum)[2]<<","<<(*four_momentum)[3]<<")]"
           <<" || Memory Address: \033[1;33m"<<this<<"\033[0m"<<std::endl;
}