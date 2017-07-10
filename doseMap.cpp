#include "doseMap.h"


doseMap::doseMap()
:fWidth(0), fHeight(0)
{

}

doseMap::doseMap(const double width, const double height)
:fWidth(width), fHeight(height)
{

}

void doseMap::setSourcePosition(const double X, const double Y)
{
  fX = X;
  fY = Y;
}

void doseMap::setCalculator(const doseCalculator calculator)
{
  fCalculator = calculator;
}

double doseMap::calculateDistanceFromSource(const double X, const double Y)
{
  return sqrt(pow(X - fX,2) + pow(Y - fY,2));
}


void doseMap::createADoseMap()
{
  gStyle->SetOptStat(0);
  TCanvas*c = new TCanvas();
  TH2F* histo = new TH2F("histo","histo",fWidth,0, fWidth, fHeight,0,fHeight);
  histo->SetTitle("Dose in mSv/week");
  for(double X = 0; X < fWidth; X+=1)
  {
    for(double Y = 0; Y< fHeight; Y+=1)
    {
      double distance = calculateDistanceFromSource( X, Y );
      
      if( fX - fCalculator.getShielding().getThickness() < X && X < fX + fCalculator.getShielding().getThickness() && fY - fCalculator.getShielding().getThickness() < Y && Y < fY + fCalculator.getShielding().getThickness() )
	continue;
      
      fCalculator.setDistance(distance);

      histo->Fill(X,Y,fCalculator.getDose()*50);
      
    }
  }
  histo->Draw("colz");
  c->SaveAs("kiko.png");
  
  delete histo;
}


