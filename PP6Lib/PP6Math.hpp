#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH

double addition( double a, double b);
double subtraction(double a, double b);
double multiplication (double a, double b);
double division (double a, double b);
double vectormag( double x, double y, double z, double t);
void swap(double& a, double& b);
//Function assigns the values a&b to temporary variables and then reassigns them
void sort(double* a, int Size, double* b);
//Check whether the input was correct. If the input was correct cincheck is false.
bool cincheck (bool a);
bool Quadratic(double i, double j, double k, double* x_pos, double* x_neg);


#endif //PP6CALCULATOR_PP6MATH_HH
