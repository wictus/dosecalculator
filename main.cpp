#include <iostream>
#include "sources.h"
#include "shieldings.h"
#include "doseCalculator.h"

int main(int argc, char **argv) 
{ 
  if(argc != 3)
  {
    std::cout << "Please add input parameters: escape ratio and distance from source e.g:\n"
    << "./doseCalculator 2.5 40\n";
    std::exit(2); 
  }
  
  sources neutronBeam("neutron source of 14 MeV monochromatic neutrons, isotropic", 1E9, 14);
  
  shieldings paraffinBox("parrafin box", 
			 sarcophagus, 0, atof(argv[1]) ); 
  paraffinBox.setSource(neutronBeam);
  
  doseCalculator calculator;
  calculator.setShielding(paraffinBox);
  calculator.setDistance( atof(argv[2]));
  calculator.setConversionCoefficient(450);
  std::cout <<"For escape ratio: " << atof(argv[1]) << "% and distance from the source " 
  << atof(argv[2]) << "cm dose in [mSv/week] amounts to " << calculator.getDose() << std::endl;
  
  return 0;
}
