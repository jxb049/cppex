#include "Week1.hpp"
#include "Week2.hpp"
#include "PP6Math.hpp"

#include <iostream>
#include <climits>
#include <math.h>

void Week1Functions(double Week)
{ 
  while(std::cin)
    { 
      double V1;
      double V2;
      double Pr; //Result of function on V1 and V2
      char W1Choice;
      char ExtraChoices;

      std::cout << "What operation would you like to perform?" << std::endl << "(a) addition, " << std::endl << "(s) subtraction," << std::endl << "(m) multiplication" << std::endl << "(d) division" << std::endl << "(q) to quit" << std::endl << "or (e) for extra functions" << std::endl;
      std::cin >> W1Choice;

      //Extra functions
      if(W1Choice == 'e')
	{
	  std::cout << "Would you like to: " << std::endl << "(a) Calculate the intercept of a line on the x-axis, " << std::endl << "(b) Solve a quadratic equation, " << std::endl << "(c) Calculate the length of 3 and 4 vectors or " << std::endl << "(d) Calculate the invariant mass of two particles, " << std::endl << "(q) quit?" << std::endl;
	  std::cin >> ExtraChoices; 
	}
      else if(W1Choice == 'a' || W1Choice == 's' || W1Choice == 'm' || W1Choice == 'd') // The basic functions
	{
	  std::cout << "Type in a value for variable 1: ";
	  std::cin >> V1;
	  if(cincheck(std::cin))	    continue;

	  std::cout << std::endl << "Type in a value for variable 2: ";
	  std::cin >> V2;
	  if(cincheck(std::cin))	    continue;
	}

      //Calculating x intercept
      if(ExtraChoices == 'a' && W1Choice !='q')
	{
	  double m=0; //gradient
	  double i=0; //y-intercept
	  std::cout << "Please enter a value of the gradient of your line: " << std::endl;
	  std::cin >> m;
	  if(cincheck(std::cin))	    continue;

	  std::cout << "Please enter a value of the y-intercept of your line: " <<std::endl;
	  std::cin >> i;
	  if(cincheck(std::cin))	    continue;

	  double x_intercept = -division(i,m);

	  std::cout << "You inputted the equation y=" << m << "x+" << i << std::endl;
	  std::cout << "The x-intercept of the line is at: " << x_intercept << std::endl;
	  break;
	}
      else if(ExtraChoices == 'b' && W1Choice != 'q') //Solving quadratic equation
	{
	  double i=0,j=0,k=0;
	  std::cout << "Enter your coefficient of x^2: " << std::endl;
	  std::cin >> i;
	  if(cincheck(std::cin))	    continue;

	  std::cout << "Enter your coefficient of x: " << std::endl;
	  std::cin >> j;
	  if(cincheck(std::cin))	    continue;

	  std::cout << "Enter the constant: " << std::endl;
	  std::cin >> k;
	  if(cincheck(std::cin))	    continue;

	  double* x_pos;
	  double* x_neg;

	  x_pos = new double;
	  x_neg = new double;

	  bool OK = Quadratic(i,j,k,x_pos,x_neg);

	  if(OK)
	    {
	      std::cout << "You inputted the equation 0=" << i << "x^2+" << j << "x+"<< k << std::endl;
	      std::cout << "The solutions to this are x=" << *x_pos << " and x=" << *x_neg << std::endl;
	    }
	  else
	    {
	      std::cout << "The solutions to this quadratic are either imaginary or the input was incorrect." << std::endl;
	      continue;
	    }
	}
      else if(ExtraChoices == 'c' &&  W1Choice != 'q') //Magnitude of the 3/4 vector
	{
	  double i=0, j=0, k=0, l=0;

	  std::cout << "Enter the values of the x,y,z components" << std::endl;
	  std::cout << "x: ";
	  std::cin >> i;
	  if(cincheck(std::cin))	    continue;
	  std::cout << "y: ";
	  std::cin >> j;
	  if(cincheck(std::cin))	    continue;
	  std::cout << "z: ";
	  std::cin >> k;
	  if(cincheck(std::cin))	    continue;
	  std::cout << "Enter the fourth component (zero if three-vector): ";
	  std::cin >> l;
	  if(cincheck(std::cin))	    continue;

	  double m = vectormag(i,j,k,l);

	  std::cout << "The magnitude of your vector is: " << m << std::endl;
	}
      else if(ExtraChoices == 'd' && W1Choice != 'q') //Invariant mass
	{
	  double E=0, px=0, py=0, pz=0;
	
	  std::cout << "Enter the value of the energy: ";
	  std::cin >> E;
	  if(cincheck(std::cin))	    continue;
	  std::cout << "Enter the value of the momentum's x component: ";
	  std::cin >> px;
	  if(cincheck(std::cin))	    continue;
	  std::cout << "Enter the value of the momentum's y component: ";
	  std::cin >> py;
	  if(cincheck(std::cin))	    continue;
	  std::cout << "Enter the value of the momentum's z component: ";
	  std::cin >> pz;
	  if(cincheck(std::cin))	    continue;

	  double M = sqrt(E*E - vectormag(px,py,pz,0)*vectormag(px,py,pz,0));

	  std::cout << "The invariant mass is: " << M << std::endl;
	}
      else if(W1Choice=='a') Pr = addition(V1,V2); 
      else if(W1Choice=='s') Pr = subtraction(V1,V2);
      else if(W1Choice=='m') Pr = multiplication(V1,V2);
      else if(W1Choice=='d') Pr = division(V1,V2);
      else if(W1Choice=='q' || ExtraChoices=='q') break;
      else if(W1Choice!= 0)
	{
	  std::cout << "You entered it wrong!" << std::endl;
	  std::cin.clear();
	  std::cin.ignore(INT_MAX, '\n');
	  continue;
	}

      if(W1Choice == 'a' || W1Choice == 's' || W1Choice == 'm' || W1Choice == 'd')  std::cout << std::endl << "Operation of the two variables: " << Pr << std::endl;

      break;
    }
}
