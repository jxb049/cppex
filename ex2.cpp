#include "PP6Math.hpp"
#include "Week3.hpp"
#include "Week2.hpp"
#include "Week1.hpp"

#include <iostream>
#include <climits>
#include <math.h>

struct FourVector;

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


