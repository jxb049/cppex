#include "3VecClass.hpp"

#include <cmath>
#include <iostream>


ThreeVector::ThreeVector(const ThreeVector& Momentum)
{
  m_x = Momentum.m_x;
  m_y = Momentum.m_y;
  m_z = Momentum.m_z;
}

double ThreeVector::getX()
{
  return m_x;
}

double ThreeVector::getY()
{
  return m_y;
}

double ThreeVector::getZ()
{
  return m_z;
}

void ThreeVector::setX(double x)
{
  m_x = x;
}

void ThreeVector::setY(double y)
{
  m_y = y;
}

void ThreeVector::setZ(double z)
{
  m_z = z;
}
