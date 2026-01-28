// particle.h

// Header file for the particle object

// Student ID: 10831050, last updated: 22/03/25

#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

class particle
{
private:
  std::string particle_name;
  std::vector<double>* four_momentum;
public:
  // Default constructor
  particle();

  // Parameterised constructor
  particle(std::string particle_name_in, double E, double px, double py, double pz);

  // Destructor
  ~particle();

  // Declaration of setters
  void set_name(const std::string particle_name_in);
  void set_E(const double E_in);
  void set_px(const double px_in);
  void set_py(const double py_in);
  void set_pz(const double pz_in);

  // Declaration of getters
  std::string get_name() const;
  double get_E() const;
  double get_px() const;
  double get_py() const;
  double get_pz() const;
  std::vector<double> get_four_momentum() const;

  // Declaration of assignment operator
  particle operator=(const particle& p);

  // Copy constructor
  particle(const particle& q);

  // Declaration of move assignment operator
  particle& operator=(particle&& input_particle) noexcept;

  // Move constructor
  particle(particle&& input_particle) noexcept;

  // Declaration of the overloaded + operator for four-vector addition
  particle operator+(const particle& a) const;

  // Declaration of the dotProduct function
  double dotProduct(const particle& p);

  // Declaration of function to print particle data
  void print_data() const;
};

#endif