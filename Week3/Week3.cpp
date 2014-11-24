#include <iostream>
#include <climits>
#include <math.h>

#include "Week1.hpp"
#include "Week2.hpp"
#include "Week3.hpp"
#include "PP6Math.hpp"
#include "FileReader.hpp"
#include <cstdlib>

#include "LBoost.hpp"
#include "3VecClass.hpp"
#include "4VecClass.hpp"
#include "PartClass.hpp"

void Week3Functions(int Week)
{
  while(std::cin)
    {
      char W3Choice=0;

      std::cout << "Would you like to: " << std::endl << "(a) - Boost a 4-Vector Along z" << std::endl << "(b) - Calculate 4-Vector Length " << std::endl << "(c) - Operate on a four vector with another" << std::endl << "(d) - Calculate and display the top 10 invariant masses of combinations of muons and which event they correspond to;" << std::endl << "(q) - Quit" << std::endl;
      std::cin >> W3Choice;

      double v=0;

      double x1=0, y1=0, z1=0, t1=0;

      if(W3Choice == 'q') break; //Allow user to quit 
      else if(W3Choice != 'q' && W3Choice != 'd')
	{
	  FourVecEntry (x1,y1,z1,t1);
	}

      FourVector *q = new FourVector(x1,y1,z1,t1);

      if(W3Choice == 'a')
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
      else if(W3Choice == 'c')
	{
	  char Choice=0;

	  double x2=0, y2=0, z2=0, t2=0;	  
	  std::cout << "Please enter the four vector you would like to operate the original with." << std::endl;
	  FourVecEntry (x2,y2,z2,t2);

	  FourVector *p = new FourVector(x2,y2,z2,t2);

	  std::cout << "Which operation would you like to perform?" << std::endl << "(a) - Addition" << std::endl << "(b) - Subtraction"  << std::endl;
	  std::cin >> Choice;
	  
	  if(Choice == 'a') 
	    {
	      FourVector *r = q->operator+=(p);
	      r->PrintFourVec();
	    }
	  else if(Choice == 'b')
	    {
	      FourVector *r = q->operator-=(p);
	      r->PrintFourVec();
	    }
	  else	
	    {
	      std::cout << "You entered it wrong. Please try again." << std::endl;
	      continue;
	    }
	}
      else if(W3Choice == 'd')
	{
	  //Opens the data file and gives it the reference ObsParticles
	  FileReader ObsParticles("/home/jxb/mpagspp6-upstream/pp6calculator_jxb.git/observedparticles.dat");

	  int mupos_itr=0;
	  int muneg_itr=0;
	  int TotalCombinations=0;

	  std::string Mupos_Event[1000]; //Array to record the event number
	  std::string Muneg_Event[1000];

	  PartClass Mupospart[1000];
	  PartClass Munegpart[1000];

	  double Inv_Mass[10000]; //All the combinations of invariant mass

	  // Only process if the file is open/valid
	  if (ObsParticles.isValid()) {

	    // Loop until out of lines
	    while (ObsParticles.nextLine())
	      {
		if(ObsParticles.getFieldAsString(6) == "run4.dat") //Only uses data from run4
		  {
		    if(ObsParticles.getFieldAsString(2) == "mu+") //For positive muon extracts relevant data
		      {
			std::cout << mupos_itr << std::endl;
			double mass = 0.1057;
			int PDGCode = -13;
			//			Mupospart[mupos_itr] = new PartClass();
			Mupospart[mupos_itr].setThreeMomentum(ObsParticles.getFieldAsDouble(3),ObsParticles.getFieldAsDouble(4),ObsParticles.getFieldAsDouble(5));
	        	Mupospart[mupos_itr].setMass(mass);
	        	Mupospart[mupos_itr].setPDGCode(PDGCode);

			Mupos_Event[mupos_itr] = ObsParticles.getFieldAsString(0);
		     
			mupos_itr++;
		      }
		    else if(ObsParticles.getFieldAsString(2) == "mu-") //For negative muon extracts relevant data
		      {
			std::cout << muneg_itr << std::endl;
			double mass = 0.1057;
			int PDGCode = 13;
			//	Munegpart[muneg_itr] = new PartClass();
			Munegpart[muneg_itr].setThreeMomentum(ObsParticles.getFieldAsDouble(3),ObsParticles.getFieldAsDouble(4),ObsParticles.getFieldAsDouble(5));
	        	Munegpart[muneg_itr].setMass(mass);
	        	Munegpart[muneg_itr].setPDGCode(PDGCode);

			Muneg_Event[muneg_itr] = ObsParticles.getFieldAsString(0);
			muneg_itr++;
		      }
		  }
		// Check that input is o.k.
		if (ObsParticles.inputFailed()) break; //If something goes wrong start again
	      }
	  }

	  for(int i=1; i<mupos_itr; i++) 
	    {
	      for(int j=1; j<muneg_itr; j++)
		{
		  ThreeVector posv = Mupospart[i].getThreeMomentum();
		  ThreeVector negv = Munegpart[j].getThreeMomentum();

		  Inv_Mass[100*i+j]=sqrt((Mupospart[i].getEnergy()+Munegpart[j].getEnergy())*(Mupospart[i].getEnergy()+Munegpart[j].getEnergy())-(posv.getX()+negv.getX())*(posv.getX()+negv.getX())-(posv.getY()+negv.getY())*(posv.getY()+negv.getY())-(posv.getZ()+negv.getZ())*(posv.getZ()+negv.getZ()));
 
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
      else
	{
	  std::cout << "You entered it wrong. Please try again." << std::endl;
	  continue;
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

void FourVecEntry (double& x, double& y, double& z, double& t)
{
  std::cout << "Please enter the components of your 4-vector." << std::endl << "x: ";
  std::cin >> x;
  std::cout << "y: ";
  std::cin >> y;
  std::cout << "z: ";
  std::cin >> z;
  std::cout << "t: ";
  std::cin >> t;
}

