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

double totalEnergyTensor(std::vector<std::vector<int> > & States, size_t gridSizeX, size_t gridSizeY, bool pbc, double J, std::vector<std::vector<std::vector<double> > > & InteractionTensor){
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

int IsingSimulation(double kT, std::ofstream & EOut){
  //params
  int seed = time(NULL);
  srand(seed);
  double Chi;
  size_t gridSizeX = 10;
  size_t gridSizeY = 10;
  size_t n_steps = 5E6;
  size_t eq_steps = 1E6;
  bool pbc = false;
  double J = 1;
  double k_dChi = 0;
  size_t num_states = 4; //2 for ising, 4 for noncanonical spin systems
  size_t confEvery = 5000;
  std::vector<std::vector<std::vector<double> > > IntTx (4, std::vector<std::vector<double> > (4, std::vector<double>(4,0)));
  GetIntTx("Spider", IntTx);

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
  double confEnergy = totalEnergyTensor(States, gridSizeX, gridSizeY, pbc, J, IntTx);
  double newEnergy = 0;
  double currEnergy = 0;

  //sim
  for (size_t t = 0; t < n_steps; t++){
    //print
    if (t % confEvery == 0 && t > eq_steps){
      confEnergy = totalEnergyTensor(States, gridSizeX, gridSizeY, pbc, J, IntTx);
      EOut << t << " " << confEnergy << "\n";
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
      IsingSimulation(kt, energy_output);
      energy_output.close();
    }
  }
  return EXIT_SUCCESS;
}
