#include "doseCalculator.h"

doseCalculator::doseCalculator()
{
  fDistance = fDose = fConversionCoefficient= 0;
}

shieldings doseCalculator::getShielding() const
{
  return fShield;
}

void doseCalculator::setShielding(const shieldings shield)
{
  fShield = shield;
}

void doseCalculator::calculateDose()
{
  double fromSecondsToHour = 60*60;
  int buildUpFactor = 1;
  int fromHoursToWeek = 40;
  double rescaleFromPtoNS = 1E-9;
  
  double escapedFluxPerSecondPerSteradian = fShield.getSource().getActivity() ;
  escapedFluxPerSecondPerSteradian*= fShield.getEscapeRatio()*0.01 ; // after shield
  escapedFluxPerSecondPerSteradian*=0.25 /3.14 ; // into steradian
  escapedFluxPerSecondPerSteradian/=fDistance* fDistance;
  escapedFluxPerSecondPerSteradian*=buildUpFactor;
  
  fDose =  escapedFluxPerSecondPerSteradian * fConversionCoefficient *rescaleFromPtoNS ;

  fDose*=  fromSecondsToHour *fromHoursToWeek ;
}

double doseCalculator::getDose()
{
  calculateDose();
  return fDose;
}

double doseCalculator::getDistance() const
{
  return fDistance;
}

void doseCalculator::setDistance(const double distance)
{
  fDistance = distance;
}

double doseCalculator::getConversionCoefficient() const
{
  return fConversionCoefficient;
}

void doseCalculator::setConversionCoefficient(const double conversion)
{
  fConversionCoefficient = conversion;
}

