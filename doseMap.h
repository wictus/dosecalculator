#ifndef DOSEMAP
#define DOSEMAP

#include <cmath>
#include "TH2F.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "doseCalculator.h"


class doseMap
{
public:
  doseMap();
  doseMap(const double width, const double height);
  void setSourcePosition(const double X, const double Y);
  void setCalculator(const doseCalculator calculator);
  void createADoseMap();
private:
  double calculateDistanceFromSource(const double X, const double Y);
  double fWidth, fHeight, fX, fY; 
  doseCalculator fCalculator;
};

#endif // DOSEMAP