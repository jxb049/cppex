#include "PP6Math.hpp"
#include "Week2.hpp"
#include "Week1.hpp"
#include "LBoost.hpp"

#include <iostream>
#include <climits>
#include <math.h>

struct FourVector;

void Week3Functions(int Week);
void LorentzBoost(double& z2, double& t2, double v);

int main()
{
  int Week = 0;

  //Behaves as an infinite loop until conditions within end the loop
  while(std::cin)
  {
    std::cout << "What week's work would you like to access?" << std::endl << "(1)- Basic operations" << std::endl << "(2) - More complicated functions using pointers and arrays" << std::endl << "(3) - Lorentz Boosting 4-vectors using structs" << std::endl;
    std::cin >> Week;
    if(cincheck(std::cin))	    continue;

    //Depending on the value chosen apply the function of the week
    if(Week == 1)  Week1Functions(Week);
    else if(Week == 2) Week2Functions(Week);
    else if(Week == 3) Week3Functions(Week);

    break;
  }
  return 0;
}

void Week3Functions(int Week)
{
  while(std::cin)
    {
       char W3Choice=0;

       std::cout << "Would you like to: " << std::endl << "(a) - Boost a 4-Vector Along z" << std::endl << "(b) - Calculate 4-Vector Length " << std::endl << "(q) - Quit" << std::endl;
      std::cin >> W3Choice;

      double x=0, y=0, z=0, t=0, v=0;

      std::cout << "Please enter the components of your 4-vector." << std::endl << "x: ";
      std::cin >> x;
      std::cout << "y: ";
      std::cin >> y;
      std::cout << "z: ";
      std::cin >> z;
      std::cout << "t: ";
      std::cin >> t;

      FourVector *q = new FourVector(x,y,z,t);

      if(W3Choice == 'q') break; //Allow user to quit 
      else if(W3Choice == 'a')
	{
	  std::cout << "Please enter the z-component of the velocity in terms of beta factor v/c: ";
	  std::cin >> v;
	  if(v<0 || v>1) break;

	  FourVector *r = q->applyLBoost(v);

	  r->PrintFourVec();
	}
      else if(W3Choice == 'b')
	{
	  double VectorLength = q->VecLength();
	  std::cout << "Length of four vector: " << VectorLength << std::endl;
	}
 
      break;
    }
}

void LorentzBoost(double& z2, double& t2, double v)
{
  double z1 = z2;
  double t1 = t2;
  double Gamma = 1/sqrt(1-v*v);

  t2 = Gamma*(t1-v*z1);
  z2 = Gamma*(z1-v*t1);
}
