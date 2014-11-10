#include <iostream>
#include <climits>
#include <math.h>

double addition( double a, double b) 
{
  return a+b;
}

double subtraction(double a, double b)
{
  return a-b;
}

double multiplication (double a, double b)
{
  return a*b;
}

double division (double a, double b)
{
  return a/b;
}

double vectormag( double x, double y, double z, double t)
{
  return  sqrt(x*x+y*y+z*z+t*t);
}

void swap(double& a, double& b)
{
  double temp1 = 0;
  temp1 = a;
  a = b;
  b = temp1;
}

//Function assigns the values a&b to temporary variables and then reassigns them
void sort(double* a, int Size)
{
  double temp1 = 0;
  for(int j=0; j< Size; j++)
    {
      for(int i=0; i < Size; i++)
	{
	  if(a[i] < a[i+1])
	    {
	      swap(a[i],a[i+1]);
	    }
	}
    }
}

//Check whether the input was correct. If the input was correct cincheck is false.
bool cincheck (bool a)
{
  if (!a)
    {
      std::cout << "You entered it wrong!";
      std::cin.clear();
      std::cin.ignore(INT_MAX, '\n');
      return true;
    }
  return false;
}

bool Quadratic(double i, double j, double k, double* x_pos, double* x_neg)
{
  double Disc = j*j-4*i*k;

  if (Disc >= 0)
    {   
      *x_pos = (-j+sqrt(Disc))/(2*i);
      *x_neg = (-j-sqrt(Disc))/(2*i);
      return true;
    }
  return false;
}


int main()
{
  // This is a comment
  /*This is a
         Multiline comment */

  double a=0;
  double b=0;
  char c=0;
  double d=0;
  char e=0;


  //Behaves as an infinite loop until conditions within end the loop
  while(std::cin)
  {
    std::cout << "What operation would you like to perform?" << std::endl << "(a) addition, " << std::endl << "(s) subtraction," << std::endl << "(m) multiplication" << std::endl << "(d) division" << std::endl << "(q) to quit" << std::endl << "or (e) for extra functions" << std::endl;
    std::cin >> c;

    //Extra functions
    if(c == 'e')
      {
	std::cout << "Would you like to: " << std::endl << "(a) Calculate the intercept of a line on the x-axis, " << std::endl << "(b) Solve a quadratic equation, " << std::endl << "(c) Calculate the length of 3 and 4 vectors or " << std::endl << "(d) Calculate the invariant mass of two particles, " << std::endl << "(e) Order a group of numbers from highest to lowest, " << std::endl << "(q) quit?" << std::endl;
	std::cin >> e; 
      }
    else if(c == 'a' || c == 's' || c == 'm' || c == 'd') // The basic functions
      {
	std::cout << "Type in a value for variable 1: ";
	std::cin >> a;
	if(cincheck(std::cin))	    continue;

	std::cout << std::endl << "Type in a value for variable 2: ";
	std::cin >> b;
	if(cincheck(std::cin))	    continue;
      }


    //Calculating x intercept
    if(e == 'a' && c !='q')
      {
	double m=0;
	double i=0;
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
    else if(e == 'b' && c != 'q') //Solving quadratic equation
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
    else if(e == 'c' &&  c != 'q') //Magnitude of the 3/4 vector
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
    else if(e == 'd' && c != 'q') //Invariant mass
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
    else if(e == 'e' && c != 'q') 
      {

	int Size;

	std::cout << "How big is your array? " << std::endl;
	std::cin >> Size;
	if(cincheck(std::cin))	    continue;

	double x[Size];
	
	for(int k=0; k<Size; k++)
	  {
	    std::cout << "Enter a value for element " << k << ": " <<  std::endl;
	    std::cin >> x[k];
	    if(cincheck(std::cin))	    continue;
	  }

	double *x_point = x;

	sort(x_point, Size);


	std::cout << "Your elements are now have been sorted into the order of: " << std::endl;

	for(int k=0; k<Size; k++)
	  {
	    std::cout << x[k] << std::endl;
	  }

      }
    else if(c=='a') d = addition(a,b); 
    else if(c=='s') d = subtraction(a,b);
    else if(c=='m') d = multiplication(a,b);
    else if(c=='d') d = division(a,b);
    else if(c=='q' || e=='q') break;
    else
      {
        std::cout << "You entered it wrong!" << std::endl;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	continue;
      }

    if(c == 'a' || c == 's' || c == 'm' || c == 'd')  std::cout << std::endl << "Operation of the two variables: " << d << std::endl;


    break;
  }
  return 0;
}
