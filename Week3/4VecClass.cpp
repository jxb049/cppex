#include "3VecClass.hpp"
#include "4VecClass.hpp"

#include <cmath>
#include <iostream>

FourVec::FourVec(ThreeVector& Momentum,const double t)
  :m_x(Momentum),m_t(t)
{
  //  m_interval = interval();
}

FourVec::FourVec(FourVec& other)
  :m_x(other.getThreeVector()),m_t(other.getT())
{
}

/*FourVec* FourVector::Boost_z( double v) const
{
  double Gamma = 1/sqrt(1-v*v);

  FourVector* BoostedFourVec = new FourVector(m_x, m_y, Gamma*((m_z) - v*(m_t)),Gamma*((m_t) - v*(m_z)));
  
    // BoostedFourVec->m_y = m_y;
    //BoostedFourVec->m_z = Gamma*((m_z) - v*(m_t));
    //BoostedFourVec->m_t = Gamma*((m_t) - v*(m_z));
  return BoostedFourVec;
  }*/

double FourVec::getT()
{
  return m_t;
}

ThreeVector FourVec::getThreeVector()
{
  return m_x;
}

double FourVec::getX()
{
  return m_x.getX();
}

double FourVec::getY()
{
  return m_x.getY();
}

double FourVec::getZ()
{
  return m_x.getZ();
}

void FourVec::setT(double t)
{
  m_t = t;
}

ThreeVector& FourVec::setThreeVector(ThreeVector& Momentum)
{
  m_x = Momentum;
  return m_x;
}

void FourVec::setX(double x)
{
  m_x.setX(x);
}

void FourVec::setY(double y)
{
  m_x.setY(y);
}

void FourVec::setZ(double z)
{
  m_x.setZ(z);
}
