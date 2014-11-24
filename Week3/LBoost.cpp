#include "LBoost.hpp"

#include <cmath>
#include <iostream>

FourVector::FourVector(const double x,const double y,const double z,const double t)
  :m_x(x),m_y(y),m_z(z),m_t(t)
{
  m_interval = interval();
}

FourVector::FourVector(const FourVector& other)
  :m_x(other.m_x),m_y(other.m_y),m_z(other.m_z),m_t(other.m_t)
{
}

FourVector* FourVector::applyLBoost( double v) const
{
  double Gamma = 1/sqrt(1-v*v);

  FourVector* BoostedFourVec = new FourVector(m_x, m_y, Gamma*((m_z) - v*(m_t)),Gamma*((m_t) - v*(m_z)));
  
    // BoostedFourVec->m_y = m_y;
    //BoostedFourVec->m_z = Gamma*((m_z) - v*(m_t));
    //BoostedFourVec->m_t = Gamma*((m_t) - v*(m_z));
  return BoostedFourVec;
}

FourVector* FourVector::operator+=(const FourVector* rhs)
{
  m_x += rhs->m_x;
  m_y += rhs->m_y;
  m_z += rhs->m_z;
  m_t += rhs->m_t;
  return this;
}

FourVector* FourVector::operator-=(const FourVector* rhs)
{
  m_x -= rhs->m_x;
  m_y -= rhs->m_y;
  m_z -= rhs->m_z;
  m_t -= rhs->m_t;
  return this;
}

/*FourVector* FourVector::operator=(const FourVector rhs)
{
  if (&rhs != this)
    {
      m_x = rhs.m_x;
      m_y = rhs.m_y;
      m_z = rhs.m_z;
      m_t = rhs.m_t;
      return this;
    }
  else
    {
      std::cout << "They are already the same." << std::endl;
      return 0;
    }
    }*/

void FourVector::PrintFourVec()
{
  std::cout << "Your new boosted components are..." << std::endl;
  std::cout << "x: " << m_x << ", y: " << m_y << ", z:" << m_z << ", t:" << m_t << std::endl;
}

double FourVector::interval() const
{
  // Assume natural units
  double s = m_t*m_t - m_x*m_x - m_y*m_y - m_z*m_z;
  return s;
}

double FourVector::VecLength() const
{
  return sqrt(m_interval);
}
