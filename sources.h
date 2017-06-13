#ifndef SOURCES
#define SOURCES

class sources
{
public:
  sources();
  sources(std::string description =""); 
private:
  std::string fDescription ="";
  double fEnergy = 0;
  double fActivity = 0;
};



#endif //SOURCES