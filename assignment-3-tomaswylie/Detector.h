// Detector.h

// Header file for the object Detector

// Student ID: 10831050, last modified: 07/03/25

#ifndef DETECTOR_H
#define DETECTOR_H

#include<iostream> // For std::cout, std::cin
#include<iomanip> // For std::setprecision
#include<cmath> // For std::sqrt
#include<string> // For std::string
#include<vector> // For std::vector
#include<stdexcept> // For std::invalid_argument
#include "Lepton.h"

class Detector
{
private:
  std::string type;
  bool status;

public:

  Detector();

  Detector(std::string Detector_type);

  ~Detector();

  void print_detector();

  void turn_on();

  void turn_off();

  int tracker_detector(Lepton const particle);

  int calorimeter_detector(Lepton const particle);

  int muon_chamber_detector(Lepton const particle);
};

#endif
