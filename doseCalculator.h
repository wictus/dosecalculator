#ifndef DOSECALCULATOR
#define DOSECALCULATOR

#include "shieldings.h"
#include "sources.h"
#include <iostream>

class doseCalculator
{
public:
  doseCalculator();
  void setShielding(const shieldings shield);
  shieldings getShielding()const;
  double getDose();
  void setDistance(const double distance);
  double getDistance() const;
  void setConversionCoefficient(const double conversion);
  double getConversionCoefficient() const;
  
private:
  void calculateDose();
  double fDose;
  shieldings fShield;
  double fDistance;
  double fConversionCoefficient; // in pSvcm2
};

#endif //DOSECALCULATOR