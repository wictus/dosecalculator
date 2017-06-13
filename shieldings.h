#ifndef SHIELDINGS
#define SHIELDINGS

#include <string>
#include "sources.h"
enum shieldType{ unkown, sarcophagus };

class shieldings
{
public:
  shieldings(const std::string description, const shieldType type, const double thickness, const double escapeRatio); 
  shieldings();
  shieldings(const shieldings& shield);
  void setSource(const sources& source);
  sources getSource() const;
  shieldType getType() const;
  double getThickness() const;
  std::string getDescription() const;
  double getEscapeRatio() const;
  
private:
  shieldType fType = unkown ;
  double fThickness = 0;
  std::string fDescription = "";
  double fEscapeRatio = 0;
  sources fSourceInside;
};

#endif //SHIELDINGS