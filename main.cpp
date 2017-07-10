#include <iostream>
#include "sources.h"
#include "shieldings.h"
#include "doseCalculator.h"
#include "doseMap.h"

void exampleOfSingleUse(const double escapeRatio, const double distanceFromSource);

int main(int argc, char **argv) 
{ 
  exampleOfSingleUse(2.5, 1);
  exampleOfSingleUse(2.5, 6);
  
  //doseMap, set dimensions of room
  doseMap map(575, 737);
  //set coordinates of place
  map.setSourcePosition(75, 200);
  //set calculator stuff
  sources neutronBeam("neutron source of 14 MeV monochromatic neutrons, isotropic",
		      7.7E5, 14);
  shieldings paraffinBox("parrafin box", 
			 sarcophagus, 50, 2.5 ); 
  paraffinBox.setSource(neutronBeam);
  doseCalculator calculator;	
  calculator.setShielding(paraffinBox);
  calculator.setDistance( 0 );
  calculator.setConversionCoefficient(384);
  
  map.setCalculator(calculator);
  //create map
  map.createADoseMap();	
    
  return 0;
}

void exampleOfSingleUse(const double escapeRatio, const double distanceFromSource)
{
  if( 0 == escapeRatio && 0 == distanceFromSource )
  {
    std::cout << "Please add input parameters: escape ratio and distance from source\n";
    std::exit(2); 
  }
  
  sources neutronBeam("neutron source of 14 MeV monochromatic neutrons, isotropic", 1E9, 14);
  
  shieldings paraffinBox("parrafin box", 
			 sarcophagus, 0, escapeRatio ); 
  paraffinBox.setSource(neutronBeam);
  
  doseCalculator calculator;
  calculator.setShielding(paraffinBox);
  calculator.setDistance( distanceFromSource);
  calculator.setConversionCoefficient(450);
  std::cout <<"For escape ratio: " << escapeRatio << "% and distance from the source " 
  << distanceFromSource << "cm dose in [mSv/week] amounts to " << calculator.getDose() << std::endl;

}


