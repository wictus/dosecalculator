#include <iostream>
#include "sources.h"
#include "shieldings.h"
#include "doseCalculator.h"

int main(int argc, char **argv) 
{  
  sources neutronBeam("neutron source of 14 MeV monochromatic neutrons, isotropic", 1E9, 14);
  
  shieldings paraffinBox("parrafin box with set 40 cm thicnkess and escape ratio of 5.5%", sarcophagus, 27.54, 0.02); 
  paraffinBox.setSource(neutronBeam);
  
  doseCalculator calculator;
  calculator.setShielding(paraffinBox);
  calculator.setDistance(100);
  std::cout << calculator.getDose() << std::endl;
  
  return 0;
}
