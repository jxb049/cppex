#include <iostream>
int main()
{
  // This is a comment
  /*This is a
         Multiline comment */

  double a=0;
  double b=0;
  double c=0;
  double d=0;



  std::cout << "Type in a value for variable 1: ";
  std::cin >> a;
 if (!std::cin)
    {
       std::cout << "You entered it wrong!";
       return 1;
    }

  std::cout << std::endl << "Type in a value for variable 2: ";
  std::cin >> b;
 if (!std::cin)
    {
       std::cout << "You entered it wrong!";
       return 1;
    }

  std::cout << "What operation would you like to perform? (1=addition, 2=subtraction, 3=multiplication and 4=division) ";
  std::cin >> c;

  if (!std::cin)
    {
      std::cout << "You entered it wrong!" << std::endl;
       return 1;
    }
  else if(c==1)  d=a+b; 
  else if(c==2) d=a-b;
  else if(c==3) d=a*b;
  else if(c==4) d=a/b;

  std::cout << std::endl << "Operation of the two variables: " << d << std::endl;

  return 0;
}
