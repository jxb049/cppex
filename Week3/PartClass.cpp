#include "PartClass.hpp"
#include "4VecClass.hpp"
#include "3VecClass.hpp"
#include "PP6Math.hpp"
#include <cmath>
#include <iostream>

PartClass::PartClass(PartClass& other)
  :m_momentum(other.m_momentum),m_pdg_code(other.m_pdg_code),m_mass(other.m_mass)
{
}

PartClass::PartClass(const int pdgcode, const double Mass) 
  :m_pdg_code(pdgcode),m_mass(Mass)
{
}

PartClass::PartClass(FourVec& Momentum, const int pdgcode, const double Mass)
  :m_momentum(Momentum),m_pdg_code(pdgcode),m_mass(Mass)
{
  /* m_momentum.setX(Momentum.getX);
  m_momentum.setY(Momentum.getY);
  m_momentum.setZ(Momentum.getZ);*/
}

PartClass::PartClass(const int pdgcode, const double Mass, const double Px, const double Py, const double Pz)
  :m_pdg_code(pdgcode),m_mass(Mass)
{
  m_momentum.setX(Px);
  m_momentum.setY(Py);
  m_momentum.setZ(Pz);
}

double PartClass::getEnergy()
{
  return vectormag(m_mass,m_momentum.getX(),m_momentum.getY(),m_momentum.getZ());
}

FourVec& PartClass::getFourMomentum()
{
  return m_momentum;
}

double PartClass::getMagMomentum()
{
  return vectormag(0,m_momentum.getX(),m_momentum.getY(),m_momentum.getZ());
}

double PartClass::getMassGeV()
{
  return m_mass;
}

int PartClass::getPDGCode()
{
  return m_pdg_code;
}

ThreeVector PartClass::getThreeMomentum()
{
  return m_momentum.getThreeVector();
} 

/*void PartClass::operator=(const PartClass& rhs)
{
  if(&rhs != this)
    {
      m_mass = rhs.m_mass;
      m_momentum = rhs.m_momentum;
      m_pdg_code = rhs.m_pdg_code;
    }
  else return *this;
  }*/

void PartClass::setMass(double& mass)
{
  m_mass = mass;
}

void PartClass::setPDGCode(int& pdg_code)
{
  m_pdg_code = pdg_code;
}

void PartClass::setThreeMomentum(ThreeVector& ThreeMom)
{
  m_momentum.setX(ThreeMom.getX());
  m_momentum.setY(ThreeMom.getY());
  m_momentum.setZ(ThreeMom.getZ());
}

void PartClass::setThreeMomentum(double Px, double Py, double Pz)
{
  m_momentum.setX(Px);
  m_momentum.setY(Py);
  m_momentum.setZ(Pz);
}
