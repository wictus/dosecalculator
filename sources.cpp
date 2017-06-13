#include "sources.h"

sources::sources()
{

}

sources::sources(const std::string description, const double activity, const double energy)
{
  fDescription = description;
  fActivity =activity;
  fEnergy = energy;
}

sources::sources(const sources& source)
{
  fActivity = source.getActivity();
  fEnergy = source.getEnergy();
  fDescription = source.getDescription();
}


double sources::getActivity() const
{
  return fActivity;
}

std::string sources::getDescription() const
{
  return fDescription;
}

double sources::getEnergy() const
{
  return fEnergy;
}

double sources::setActivity(const double activity) 
{
  fActivity = activity;
}

std::string sources::setDescription(const std::string description) 
{
  fDescription = description;
}

double sources::setEnergy(const double energy) 
{
  fEnergy = energy;
}


