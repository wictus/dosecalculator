#ifndef SOURCES
#define SOURCES

#include <string>

class sources
{
public:
  sources(const std::string description, const double activity, const double energy); 
private:
  std::string fDescription ="";
  double fEnergy = 0;
  double fActivity = 0;
};



#endif //SOURCES