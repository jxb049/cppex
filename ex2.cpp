#include <iostream>
int main()
{
  // This is a comment
  /*This is a
         Multiline comment */

  double a=0;
  double b=0;
  std::cout << "Type in a value for variable 1: ";
  std::cin >> a;
  std::cout << "\n" << "Type in a value for variable 2: ";
  std::cin >> b;

  double c=a*b;

  std::cout << "\n" << "Product of the two variables: " << c << "\n";

  return 0;
}
