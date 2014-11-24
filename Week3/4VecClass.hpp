#ifndef FOURVECCLASS_HPP
#define FOURVECCLASS_HPP

#include "3VecClass.hpp"

class FourVec
{
public:
  ThreeVector m_x;
  //ctors
  FourVec() {m_t = 0;}
  FourVec(ThreeVector& Momentum, const double t);
  FourVec(FourVec& other);

  //Member Functions
  //  FourVec* Boost_z(double v) const;

  double getT();
  ThreeVector getThreeVector();
  double getX();
  double getY();
  double getZ();
  // double interval();
 
  void setT(double t);
  ThreeVector& setThreeVector(ThreeVector& Momentum);
  void setX(double x);
  void setY(double y);
  void setZ(double z);
  
private:
  // double c;
  //  double c2;

  // double m_s;
  double m_t;
};

#endif
// FOURVECCLASS_HPP
