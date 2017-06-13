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
private:
  void calculateDose();
  double fDose;
  shieldings fShield;
  double fDistance;
};

#endif //DOSECALCULATOR