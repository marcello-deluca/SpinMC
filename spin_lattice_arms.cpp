#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
#include <ostream>
#include <iostream>
#include <string>
#include <fstream>
#include "InteractionTensors.hpp"

void printStates(std::vector<std::vector<int> > & States, size_t gridSizeX, size_t gridSizeY){
  for (size_t i = 0; i < gridSizeY; i++){
    for (size_t j = 0; j < gridSizeX; j++){
      std::cout << States[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

double totalEnergyTensor(std::vector<std::vector<int> > & States, size_t gridSizeX, size_t gridSizeY, bool pbc,  std::vector<std::vector<std::vector<double> > > & InteractionTensor){
  // std::cout << "Starting energy calculation\n";
  double  EOut = 0;
  for (size_t i = 0; i < gridSizeY; i++){
    for (size_t j = 0; j < gridSizeX; j++){
      size_t Index1 = States[i][j];
      // Compare to  right
      size_t Index2 = 0;
      size_t Index3 = 0;
      if (j+1 < gridSizeX){
	      Index3 = States[i][j+1]; 
      } else if (j+1 == gridSizeX)  {
	      Index3 =  States[i][0];
      } else {
	      Index3 = 5;
      }
      if (Index3==5){
      } else {
	EOut += InteractionTensor[Index1][0][Index3];
      }
      Index2 = 0;
      if (i+1 < gridSizeY){
	      Index3 = States[i+1][j]; 
      } else if (i+1 == gridSizeX)  {
	      Index3 =  States[0][j];
      } else {
	      Index3 = 5;
      }
      if (Index3==5){	
      } else {
      EOut += InteractionTensor[Index1][1][Index3];
      }
    }
  }
  return  EOut;
}

double totalArmEnergyTensor(std::vector<std::vector<int> > & States, size_t gridSizeX, size_t gridSizeY, bool pbc, std::vector<std::vector<std::vector<double> > > & IntTx, size_t armIndex){
  int NeighborPositionX;
  int NeighborPositionY;
  int positionY, positionX;
  double EOut = 0;
  bool record = 0;
  //std::cout << "step\n";

  for (size_t i = 0; i < gridSizeY; i++){
    for (size_t j = 0; j < gridSizeX; j++){
      positionY = i;
      positionX = j;
      size_t S = States[i][j];

      std::cout << "Right\n";
      // -- RIGHT
      //check not at boundary or apply pbc
      if (positionX + 1 < gridSizeX){
	record = 1;
	NeighborPositionX = positionX + 1;
      } else {
	if (pbc){
	  record = 1;
	  NeighborPositionX = 0;
	} else { record = 0; }
      }
      //std::cout << "Checking arm\n";
      //check actually the arm in question
      //std::cout << (armIndex==0 && S==0)  <<  (armIndex==1 && S==3) << (armIndex==2 && S==2) << (armIndex==3 && S==1) << record << "\n";
      if (((armIndex==0 && S==0) || (armIndex==1 && S==3) || (armIndex==2 && S==2) || (armIndex==3 && S==1)) && record){
      } else { record = 0; }
      if (record){
	//std::cout << "accessing IntTx index " << States[positionY][positionX] << ", " << 0 << ", " << States[NeighborPositionY][NeighborPositionX] << ".\n";
	EOut += IntTx[States[positionY][positionX]][0][States[NeighborPositionY][NeighborPositionX]];
      }

      // std::cout << "Up\n";
      // -- UP
      if (positionY + 1 < gridSizeY){
	record = 1;
	NeighborPositionY = positionY + 1;
      } else {
	if (pbc){
	  record = 1;
	  NeighborPositionY = 0;
	} else { record = 0;}
      }
      if (((armIndex==0 && S==1) || (armIndex==1 && S==0) || (armIndex==2 && S==3) || (armIndex==3 && S==2)) && record){
      } else { record = 0;}
      if (record){
	EOut += IntTx[States[positionY][positionX]][1][States[NeighborPositionY][NeighborPositionX]];
      }

      //std::cout << "Left\n";
      // -- LEFT
      if (positionX >= 1){
	record = 1;
	NeighborPositionX = positionX - 1;  
      } else {
	if (pbc){
	  record = 1;
	  NeighborPositionX = gridSizeX - 1;
	} else { record = 0; }
      }
      if (((armIndex==0 && S==2) || (armIndex==1 && S==1) || (armIndex==2 && S==0) || (armIndex==3 && S==3)) && record){
      } else { record = 0; }
      if (record){
	EOut += IntTx[States[positionY][positionX]][2][States[NeighborPositionY][NeighborPositionX]];
      }

      //std::cout << "Down\n";
      // -- DOWN
      if (positionY >= 1){
	record = 1;
	NeighborPositionY = positionY - 1;  
      } else {
	if (pbc){
	  record = 1;
	  NeighborPositionY = gridSizeY - 1;
	} else { record = 0; }
      }
      if (((armIndex==0 && S==3) || (armIndex==1 && S==2) || (armIndex==2 && S==1) || (armIndex==3 && S==0)) && record){
      } else { record = 0; }
      if (record){
	EOut += IntTx[States[positionY][positionX]][3][States[NeighborPositionY][NeighborPositionX]];
      }
    }
  }
  return EOut/2;
}



double SingleEnergyTensor(std::vector<std::vector<int> > & States, size_t gridSizeX, size_t gridSizeY, bool pbc, double J, std::vector<std::vector<std::vector<double> > > & IntTx, size_t positionX, size_t positionY){
  int NeighborPositionX;
  int NeighborPositionY;
  double EOut = 0;
  bool record = 0;
  
  // -- RIGHT
  if (positionX + 1 < gridSizeX){
    record = 1;
    NeighborPositionX = positionX + 1;
  } else {
    if (pbc){
      record = 1;
      NeighborPositionX = 0;
    } else {
      record = 0;
    }
  }
  if (record){
    EOut += IntTx[States[positionY][positionX]][0][States[NeighborPositionY][NeighborPositionX]];
  }
  
  // -- UP
  if (positionY + 1 < gridSizeY){
    record = 1;
    NeighborPositionY = positionY + 1;
  } else {
    if (pbc){
      record = 1;
      NeighborPositionY = 0;
    } else {
      record = 0;
    }
  }
  if (record){
    EOut += IntTx[States[positionY][positionX]][1][States[NeighborPositionY][NeighborPositionX]];
  }
  
  // -- LEFT
  if (positionX >= 1){
    record = 1;
    NeighborPositionX = positionX - 1;  
  } else {
    if (pbc){
      record = 1;
      NeighborPositionX = gridSizeX - 1;
    } else {
      record = 0;
    }
  }
  if (record){
    EOut += IntTx[States[positionY][positionX]][2][States[NeighborPositionY][NeighborPositionX]];
  }
  
  // -- DOWN
  if (positionY >= 1){
    record = 1;
    NeighborPositionY = positionY - 1;  
  } else {
    if (pbc){
      record = 1;
      NeighborPositionY = gridSizeY - 1;
    } else {
      record = 0;
    }
  }
  if (record){
    EOut += IntTx[States[positionY][positionX]][3][States[NeighborPositionY][NeighborPositionX]];
  }
  return EOut;
}

int selectState(size_t num_possible_states){
  return rand()%num_possible_states;
}

template<typename T>
T Average(std::vector<T> & input){
  T output = 0;
  for (size_t i = 0; i < input.size(); i++){
    output += input[i];
  }
  output /= input.size();
  return output;
}

int IsingSimulation(double kT, std::ofstream & EOut, std::ofstream & EPSI0, std::ofstream & EPSI1, std::ofstream & EPSI2, std::ofstream & EPSI3){
  //params
  int seed = time(NULL);
  srand(seed);
  double Chi;
  size_t gridSizeX = 10;
  size_t gridSizeY = 10;

  double ETInf0 = -25;
  double ET00 = -50;
  //double ETInf1 = -37.5;
  //double ET01 = -50;
  double ETInf2  = -25;
  double ET02 = -50;
  
  
  size_t n_steps = 5E6;
  size_t eq_steps = 1E6;
  bool pbc = true;
  double J = 1;
  double k_dChi = 0;
  size_t num_states = 4; //2 for ising, 4 for noncanonical spin systems
  size_t confEvery = 5000;
  std::vector<std::vector<std::vector<double> > > IntTx (4, std::vector<std::vector<double> > (4, std::vector<double>(4,0)));
  GetIntTx("LeftRight", IntTx);
  std::vector<std::vector<int> > States(gridSizeY, std::vector<int>(gridSizeX,0));
  std::vector<double> eqEnergy;
  std::vector<double> orderParameterVector;
  //init
  do {
    for (size_t i = 0; i < gridSizeY; i++){
      for (size_t j = 0; j < gridSizeX; j++){
	      States[i][j] = selectState(4);
      }
    }
  } while (0);
  double confEnergy = totalEnergyTensor(States, gridSizeX, gridSizeY, pbc, IntTx);
  double newEnergy = 0;
  double currEnergy = 0;

  //sim

  for (size_t t = 0; t < n_steps; t++){
    //print
    if (t % confEvery == 0 && t > eq_steps){
      confEnergy = totalEnergyTensor(States, gridSizeX, gridSizeY, pbc, IntTx);
      EOut << t << " " << confEnergy << "\n";
      EPSI0 << t << " " << (ETInf0-totalArmEnergyTensor(States, gridSizeX, gridSizeY, pbc, IntTx, 0))/(ETInf0-ET00) << "\n";
      EPSI1 << t << " " << totalArmEnergyTensor(States, gridSizeX, gridSizeY, pbc, IntTx, 3) << "\n";//(ETInf1-totalArmEnergyTensor(States, gridSizeX, gridSizeY, pbc, IntTx, 1))/(ETInf1-ET01) << "\n";
      EPSI2 << t << " " << (ETInf2-totalArmEnergyTensor(States, gridSizeX, gridSizeY, pbc, IntTx, 2))/(ETInf2-ET02) << "\n";
      EPSI3 << t << " " << totalArmEnergyTensor(States, gridSizeX, gridSizeY, pbc, IntTx, 3) << "\n";
      
    }

    //mc move
    size_t xIdxToModify = rand() % gridSizeX; // between 0 and gridSizeX-1
    size_t yIdxToModify = rand() % gridSizeY; // between 0 and gridSizeY-1     
    int old_state = States[yIdxToModify][xIdxToModify];
    double currEnergy = SingleEnergyTensor(States, gridSizeX, gridSizeY, pbc, J, IntTx, xIdxToModify, yIdxToModify);
    do {
      States[yIdxToModify][xIdxToModify] = selectState(num_states);
    } while (States[yIdxToModify][xIdxToModify] == old_state); 

    //acc
    newEnergy = SingleEnergyTensor(States, gridSizeX, gridSizeY, pbc, J, IntTx, xIdxToModify, yIdxToModify);
    if (newEnergy <= currEnergy){ //acceptance block
    } else {
      double dE = newEnergy - currEnergy;
      double pacc = exp(-(double)dE/(double) kT);
      double test = (double) rand() / (double) INT_MAX;   
      if (test > pacc){
	States[yIdxToModify][xIdxToModify] = old_state; // If you fail, change it back
      }
    }
  }
  return EXIT_SUCCESS;
}

int main(void){
  for (int simnum = 1; simnum <= 10; simnum++){
    std::string simnumstr = std::to_string(simnum);
    for (double kt = 0.03; kt <= 3; kt += 0.03){
      std::cout << "starting simulation set " << simnum << ", kT/epsilon = " << kt << ".\n";
      std::ofstream energy_output;
      std::string energy_output_file_name;
      energy_output_file_name.append("T_");
      energy_output_file_name.append(std::to_string(kt));
      energy_output_file_name.append("_set_");
      energy_output_file_name.append(simnumstr);
      energy_output_file_name.append(".dat");
      energy_output.open(energy_output_file_name); 
      std::ofstream trajectory;
      std::string trajectory_file_name;

      std::ofstream energy_outputPsi0;
      std::ofstream energy_outputPsi1;
      std::ofstream energy_outputPsi2;
      std::ofstream energy_outputPsi3;

      std::string Psi0Name;
      std::string Psi1Name;
      std::string Psi2Name;
      std::string Psi3Name;

      Psi0Name.append(energy_output_file_name);
      Psi1Name.append(energy_output_file_name);
      Psi2Name.append(energy_output_file_name);
      Psi3Name.append(energy_output_file_name);


      Psi0Name.append("_EPSI0.dat0");
      Psi1Name.append("_EPSI1.dat1");
      Psi2Name.append("_EPSI2.dat2");
      Psi3Name.append("_EPSI3.dat3");
	
      energy_outputPsi0.open(Psi0Name);
      energy_outputPsi1.open(Psi1Name);
      energy_outputPsi2.open(Psi2Name);
      energy_outputPsi3.open(Psi3Name);
      IsingSimulation(kt, energy_output, energy_outputPsi0, energy_outputPsi1, energy_outputPsi2, energy_outputPsi3);

      energy_output.close();
      energy_outputPsi0.close();
      energy_outputPsi1.close();
      energy_outputPsi2.close();
      energy_outputPsi3.close();
    }
  }
  return EXIT_SUCCESS;
}
