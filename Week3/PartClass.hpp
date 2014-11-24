#ifndef PARTCLASS_HPP
#define PARTCLASS_HPP


#include "3VecClass.hpp"
#include "4VecClass.hpp"

class PartClass
{
public:
  FourVec m_momentum;
  //Constructors
  PartClass() {m_mass=0; m_pdg_code=0;}
  PartClass(PartClass& other);
  PartClass(const int pdgcode, const double Mass);
  PartClass(FourVec& Momentum, const int pdgcode, const double Mass);
  PartClass(const int pdgcode, const double Mass, const double Px, const double Py, const double Pz);
 
  //Public functions Functions
  double getEnergy();
  FourVec& getFourMomentum();
  double getMagMomentum();
  double getMassGeV();
  int getPDGCode();
  ThreeVector getThreeMomentum();
  
  //  void operator=(const PartClass& rhs);

  void setMass(double& mass);
  void setPDGCode(int& pdg_code);
  void setThreeMomentum(ThreeVector& v);
  void setThreeMomentum(double Px, double Py, double Pz);

private:
  int m_pdg_code;
  double m_mass;
};

#endif
// PARTCLASS_HPP
