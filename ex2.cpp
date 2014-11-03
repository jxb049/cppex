#include <iostream>
#include <climits>

int main()
{
  // This is a comment
  /*This is a
         Multiline comment */

  double a=0;
  double b=0;
  char c=0;
  double d=0;

  

  while(std::cin)
  {
    std::cout << "Type in a value for variable 1: ";
    std::cin >> a;
    if (!std::cin)
      {
        std::cout << "You entered it wrong!";
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	continue;
      }

    std::cout << std::endl << "Type in a value for variable 2: ";
    std::cin >> b;
    if (!std::cin)
      {
        std::cout << "You entered it wrong!";
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	continue;
      }

    std::cout << "What operation would you like to perform? (a=addition, s=subtraction, m=multiplication and d=division; or q to quit) ";
    std::cin >> c;

    if(c=='a') d=a+b; 
    else if(c=='s') d=a-b;
    else if(c=='m') d=a*b;
    else if(c=='d') d=a/b;
    else if(c=='q') break;
    else
      {
        std::cout << "You entered it wrong!" << std::endl;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	continue;
      }

    std::cout << std::endl << "Operation of the two variables: " << d << std::endl;


    break;
  }
  return 0;
}
