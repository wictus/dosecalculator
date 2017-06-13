#include "doseCalculator.h"

doseCalculator::doseCalculator()
{
  fDistance = fDose = 0;
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
  int buildUpFactor = 5;
  int fromHoursToWeek = 40;
  double conversionCoefficient = 433.56; // in pSvcm2
  double rescaleFromPtoNS = 1E-9;
  
  double escapedFluxPerSecondPerSteradian = fShield.getSource().getActivity() ;
  escapedFluxPerSecondPerSteradian*= fShield.getEscapeRatio()*0.01 ; // after shield
  escapedFluxPerSecondPerSteradian*=0.25 /3.14 ; // into steradian
  escapedFluxPerSecondPerSteradian/=fDistance* fDistance;
  escapedFluxPerSecondPerSteradian*=buildUpFactor;
  
  fDose =  escapedFluxPerSecondPerSteradian * conversionCoefficient *rescaleFromPtoNS ;

  fDose*=  fromSecondsToHour *fromHoursToWeek ;
}

double doseCalculator::getDose()
{
  if(fDose == 0)    
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
