#include "PP6Math.hpp"

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
void sort(double* a, int Size, double* b)
{
  for (int h=0; h < Size; h++)
    {
      b[h] = h;
    }

  for(int j=0; j< Size; j++)
    {
      for(int i=0; i < Size; i++)
	{
	  if(a[i] < a[i+1])
	    {
	      swap(a[i],a[i+1]);
	      swap(b[i],b[i+1]);
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
