#include "shieldings.h"

#include <iostream>

shieldings::shieldings(const std::string description, const shieldType type, const double thickness, const double escapeRatio)
{
  fType = type;
  fThickness = thickness;
  fDescription = description;
  fEscapeRatio = escapeRatio;
}

shieldings::shieldings(const shieldings& shield)
{
  fThickness = shield.getThickness();
  fDescription = shield.getDescription();
  fEscapeRatio = shield.getEscapeRatio();
  fSourceInside = shield.getSource();
  fType = shield.getType();
}


shieldings::shieldings()
{
}

std::string shieldings::getDescription() const
{
  return fDescription;
}

double shieldings::getEscapeRatio()const
{
  return fEscapeRatio;
}

double shieldings::getThickness()const
{
  return fThickness;
}

shieldType shieldings::getType()const
{
  return fType;
}



void shieldings::setSource(const sources& source)
{
  fSourceInside = source;
  std::cout << source.getActivity() << " " << fSourceInside.getActivity() << std::endl;
}

sources shieldings::getSource() const
{
  return fSourceInside;
}
