// Nucleus.h

// Header file of the abstract base class Nucleus

// Student ID: 10831050, last updated: 05/04/25

#ifndef NUCLEUS_H
#define NUCLEUS_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "Photon.h"

class Nucleus
{
protected: 
  int atomic_mass, atomic_number;
  std::string nucleus_type;
  bool decay_status;
  std::unique_ptr<Photon> photon_ptr;

  // Protected constructor only accessible by derived classes.
  Nucleus(std::string nucleus_type_in, int atomic_mass_in, int atomic_number_in, bool decay_status_in);

public:

  // Virtual destructor
  virtual ~Nucleus() = default;

  // Virtual print data function
  virtual void print_data()=0;

  // Virtual decay function
  virtual std::vector<std::unique_ptr<Photon>> decay()=0;

  // Nucleus getter functions
  std::string get_nucleus_type() const;
  int get_atomic_mass() const;
  int get_atomic_number() const;
  bool get_decay_status() const;
};

#endif