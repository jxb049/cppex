#ifndef THREEVECCLASS_HPP
#define THREEVECCLASS_HPP

class ThreeVector
{
public:
  double m_x;
  double m_y;
  double m_z;
  //ctors
  ThreeVector() {m_x=0; m_y=0; m_z=0;}
  ThreeVector(const ThreeVector& Momentum);

  double getX();
  double getY();
  double getZ();

  void setX(double x);
  void setY(double y);
  void setZ(double z);
private:
  // double m_len;
};

#endif
// THREEVECCLASS_HPP
