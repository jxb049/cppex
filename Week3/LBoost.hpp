#ifndef LBOOST_HPP
#define LBOOST_HPP

class FourVector
{
public:
  //ctors
  FourVector() { m_x = 0; m_y = 0; m_z = 0; m_t = 0;m_interval = interval();}
  FourVector(const double x, const double y, const double z, const double t);
  FourVector(const FourVector& other);

  //Member Functions
  FourVector* applyLBoost(double v) const;//Takes old FourVector and creates new boosted one - retains old.
  FourVector* operator+=(const FourVector* rhs);
  FourVector* operator-=(const FourVector* rhs);
  // FourVector* operator=(const FourVector rhs);
  void PrintFourVec(); //Outputs the four vectors
  double VecLength() const;
  double interval() const;
private:
  //Member variables
  double m_x;
  double m_y;
  double m_z;
  double m_t;
  double m_interval;
};
#endif
// LBOOST_HPP
