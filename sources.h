#ifndef SOURCES
#define SOURCES

#include <string>

class sources
{
public:
  sources(const std::string description, const double activity, const double energy); 
  sources( const sources& source);
  sources();
  double getEnergy() const;
  double getActivity() const;
  std::string getDescription() const;
  double setEnergy(const double energy);
  double setActivity(const double activity);
  std::string setDescription(const std::string description);
private:
  std::string fDescription ="";
  double fEnergy = 0;
  double fActivity = 0;
};



#endif //SOURCES