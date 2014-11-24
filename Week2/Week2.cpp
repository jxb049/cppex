#include "Week1.hpp"
#include "Week2.hpp"
#include "PP6Math.hpp"
#include "FileReader.hpp"
#include <cstdlib>

#include <iostream>
#include <climits>
#include <math.h>



//Function to generate a random integer
double GenerateRandom()
{
  return rand()%100; // Random number between 0-99
}

//Functions of Week 2
void Week2Functions(double Week)
{
  //Infinite loop that returns the user to the beginning of the program if they enter something incorrect
  while(std::cin)
    {
      char W2Choice=0;

      std::cout << "Would you like to: " << std::endl << "(a) - Order a group of numbers from highest to lowest; " << std::endl << "(b) - Generate 100 different 4-momenta and calculate the mean and standard deviation;" << std::endl << "(c) - Calculate and display the top 10 invariant masses of combinations of muons and which event they correspond to;" << "(q) - Quit" << std::endl;
      std::cin >> W2Choice;
      if(W2Choice == 'q') break; //Allow user to quit 	
      else if(W2Choice == 'a') //Order a group of numbers from highest to lowest
	{
	  int Size = 0; //Allow the user to define a size of the array
	  std::cout << "How big is your array? (Limited to 1000 points) " << std::endl;
	  std::cin >> Size;
	  if(cincheck(std::cin))   continue; //Checks input valid
	  if(Size > 1000) continue; //Ensures the array size is beneath the limit

	  double x[1000]; //Creates an array of size 1000, which limits the number of data points to be entered
	  double Ignore[1000];//Creates an array to satisfy the sort function
	
	  for(int k=0; k<Size; k++) //Loops over the elements of the array and inputs the user defined values
	    {
	      std::cout << "Enter a value for element " << k << ": " <<  std::endl;
	      std::cin >> x[k];
	      if(cincheck(std::cin))	    continue;
	    }

	  double *x_point = x; //Pointer to avoid the issue of arrays being passed to a function
	  double *Ignore_point = Ignore; //Pointer and array to satisfy the function - has no effect

	  sort(x_point, Size, Ignore_point); //Sort function to order the array from highest to lowest

	  std::cout << "Your elements have been sorted into the order of: " << std::endl;

	  for(int k=0; k<Size; k++) //Output new array order
	    {
	      std::cout << x[k] << std::endl;
	    }

      }
      else if (W2Choice =='b')
	{
	  double P_x[100]; //Array for components of 100 different events
	  double P_y[100];
	  double P_z[100];
	  double M[100];
	  double E[100];
	  double OrderE[100];//Array that obtains the index of energies in order highest to lowest
	  double Moment; //Mean minus the data point; all squared
	  double SumE = 0; //Sum of the energies to then calculate the mean
	  int Size  = 100; //Number of array elements
	  double Mean = 0;
	  
	  for(int i=0; i<100; i++) //Generates 100 random 4-momenta
	    {
	      P_x[i] = GenerateRandom();
	      P_y[i] = GenerateRandom();
	      P_z[i] = GenerateRandom();
	      M[i] = GenerateRandom();

	      E[i] = vectormag(P_x[i],P_y[i],P_z[i],M[i]);
	      //    std::cout << E[i] << std::endl;
	    }
	  double *E_point = E; //Pointer for the first value of the energy array, such that the elements can be accessed in the sort function
	  double *OrderE_point = OrderE; //Pointer to access the order array in the sort function
	  sort(E_point, Size, OrderE_point); //Sorts the energies in order highest to lowest and records the index in order
	  

	  for(int j=0; j<100; j++) //Output the energies in order and their corresponding index
	    {
	      std::cout << E[j] << " from position: " << OrderE[j] << std::endl;
	      SumE = SumE + E[j];
	    }
	  Mean = SumE/100;
	  for(int k=0; k<100; k++) //Loop through all of the moments, adding them to the overall sum
	    {
	      Moment = Moment+(Mean-E[k])*(Mean-E[k]);
	    }
	  double Stand_Dev = sqrt((Moment)/100);
	  std::cout << "Mean: " << Mean <<  ". Standard deviation: " << Stand_Dev << std::endl;

	  int MaxE  = OrderE[0]; //Maximum energy is the zeroth element 

	  std::cout << "Energy of highest energy particle: " << E[0]<< std::endl << "With momentum: Px = " << P_x[MaxE] << ", Py = " << P_y[MaxE] << " and Pz = " << P_z[MaxE] << std::endl;
	}
      else if(W2Choice == 'c')
	{
	  // std::string DataSource[1001];
	  //  std::string run4[1001];
	  int mupos_itr=1; //An iterator for positive muons
	  int muneg_itr=1; //An iterator for negative muons
	  double Mupos_px[100];
	  double Mupos_py[100];
	  double Mupos_pz[100];
	  std::string Mupos_Event[100]; //Array to record the event number
	  double Muneg_px[100];
	  double Muneg_py[100];
	  double Muneg_pz[100];
	  std::string Muneg_Event[100];
	  double E_mupos[100];
	  double E_muneg[100];
	  double Inv_Mass[10000]; //All the combinations of invariant mass

	  double Muon_Mass = 0.1057; //Muon mass in GeV
	  
	  //Opens the data file and gives it the reference ObsParticles
	  FileReader ObsParticles("/home/jxb/mpagspp6-upstream/pp6calculator_jxb.git/observedparticles.dat");	
	  
	  
	  // Only process if the file is open/valid
	  if (ObsParticles.isValid()) {

	    // Loop until out of lines
	    while (ObsParticles.nextLine())
	      {
		if(ObsParticles.getFieldAsString(6) == "run4.dat") //Only uses data from run4
		  {
		    if(ObsParticles.getFieldAsString(2) == "mu+") //For positive muon extracts relevant data
		      {
			// 	std::cout <<"Pos" <<  ObsParticles.getFieldAsDouble(3) << std::endl;
			Mupos_px[mupos_itr] = ObsParticles.getFieldAsDouble(3);
			Mupos_py[mupos_itr] = ObsParticles.getFieldAsDouble(4);
			Mupos_pz[mupos_itr] = ObsParticles.getFieldAsDouble(5);
			Mupos_Event[mupos_itr] = ObsParticles.getFieldAsString(0);
			mupos_itr++;
		      }
		    else if(ObsParticles.getFieldAsString(2) == "mu-") //For negative muon extracts relevant data
		      {
			//	std::cout <<"Neg" <<  ObsParticles.getFieldAsDouble(3) << std::endl;
			Muneg_px[muneg_itr] = ObsParticles.getFieldAsDouble(3);
			Muneg_py[muneg_itr] = ObsParticles.getFieldAsDouble(4);
			Muneg_pz[muneg_itr] = ObsParticles.getFieldAsDouble(5);
			Muneg_Event[muneg_itr] = ObsParticles.getFieldAsString(0);
			muneg_itr++;
		      }
		  }
		// Check that input is o.k.
		if (ObsParticles.inputFailed()) break; //If something goes wrong start again
	      }
	  }
	  
	  int TotalCombinations = 0; //Sets an integer to record the number of combinations of mu+ and mu- 

	  //Loops over all combinations, calculates the energy of each muon and then works out the invariant mass of the combination. Result stored in the array by using the 100s for positive muons and units for negative muons (limiting the data to 100 of each).
	  for(int i=1; i<mupos_itr; i++) 
	    {
	      for(int j=1; j<muneg_itr; j++)
		{
		  E_mupos[i] = vectormag(Mupos_px[i],Mupos_py[i],Mupos_pz[i],Muon_Mass);
		  E_muneg[j] = vectormag(Muneg_px[j],Muneg_py[j],Muneg_pz[j],Muon_Mass);

	   	  Inv_Mass[100*i+j]=sqrt(((E_mupos[i]+E_muneg[j])*(E_mupos[i]+E_muneg[j])-(Mupos_px[i]+Muneg_px[j])*(Mupos_px[i]+Muneg_px[j])-(Mupos_py[i]+Muneg_py[j])*(Mupos_py[i]+Muneg_py[j])-(Mupos_pz[i]+Muneg_pz[j])*(Mupos_pz[i]+Muneg_pz[j])));
 
		  //std::cout << Inv_Mass[10*i+j] << std::endl;
		   TotalCombinations = 100*i+j;
		}
	    }
	  
	  //Creates pointers and an index to allow sorting of the invariant mass
	  double* Inv_Mass_point = Inv_Mass;
	  double Index[10000];
	  double* Index_point = Index;
	  sort(Inv_Mass_point, TotalCombinations, Index_point); //Invariant mass ordered from highest to lowest; with indexes recorded
	  
	  for(int k=0; k<10; k++)
	    {
	      int a = Index[k]; //Use the index to find the original location of the top 10 combination values and then separate the index to find the positive and negative event numbers
	      int Posnum = a/100;
	      int Negnum = a%100;

	      std::cout << "Number " << k+1 << " highest invariant mass is: " << Inv_Mass[k] << "GeV, corresponding to events: mu+ " <<  Mupos_Event[Posnum] << " and mu- " << Muneg_Event[Negnum] << "." << std::endl;	      
	    }
	}
      else continue;
     
      break;
    }
}
