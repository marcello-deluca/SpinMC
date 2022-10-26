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

int SpinSimulation(double kT, double chi_des, double E_T0, double E_TInf, double k_chi, std::ofstream & ChiOut, std::ofstream & EOut){
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
  double currchi =  (E_TInf-confEnergy)/(E_TInf-E_T0);
  double totalEnergy = confEnergy + 0.5 * k_chi * pow(currchi-chi_des,2);

  std::cout << "Initialized\n";
  std::cout << "Total energy = " << totalEnergy << ".\n";
  //sim
  for (size_t t = 0; t < n_steps; t++){
    confEnergy = totalEnergyTensor(States, gridSizeX, gridSizeY, pbc, J, IntTx);
    currchi = (E_TInf-confEnergy)/(E_TInf-E_T0);
    totalEnergy = confEnergy + 0.5 * k_chi * pow(currchi-chi_des,2);
    //print
    if (t % confEvery == 0 && t > eq_steps){
      std::cout << "time " << t << " total E " << totalEnergy << " and conf E = " << confEnergy << ".\n";
      double printEnergy = totalEnergyTensor(States, gridSizeX, gridSizeY, pbc, J, IntTx);
      EOut << t << " " << printEnergy << "\n";
      currchi = (E_TInf-printEnergy)/(E_TInf-E_T0);
      ChiOut << t << " " << currchi << "\n";
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
    double newEnergy = SingleEnergyTensor(States, gridSizeX, gridSizeY, pbc, J, IntTx, xIdxToModify, yIdxToModify);

    //need current confEnergy and totalEnergy to evaluate for umbrella sampling.
    double dConf = newEnergy - currEnergy;
    double newConfEnergy = confEnergy + dConf;
    double newChi = (E_TInf-newConfEnergy)/(E_TInf-E_T0);
    double proposedEnergy = newConfEnergy + 0.5 * k_chi * pow(newChi-chi_des,2);
    double total_dE = proposedEnergy - totalEnergy;

    //std::cout << "[dConf, newConf, newChi, prop, dE] = " << dConf << ", " << newConfEnergy << ", " << newChi << ", " << proposedEnergy << ", " << total_dE << ".\n";
    
    if (total_dE <= 0){ //acceptance block
      // totalEnergy = proposedEnergy;
      //confEnergy = newConfEnergy;
      
    } else {
      double dE = newEnergy - currEnergy;
      double pacc = exp(-(double)dE/(double) kT);
      double test = (double) rand() / (double) INT_MAX;   
      if (test > pacc){
	States[yIdxToModify][xIdxToModify] = old_state; // If you fail, change it back
      } else { //accept
	//totalEnergy = proposedEnergy;
	//confEnergy = newConfEnergy;
      }
    }
  }
  return EXIT_SUCCESS;
}

int main(void){
  double E_T0 = -450;
  double E_TInf = -262.5;
  double k_chi = 16;
  //for (int simnum = 1; simnum <= 10; simnum++){
  //  std::string simnumstr = std::to_string(simnum);
    for (double kt = 0.05; kt <= 3; kt += 0.05){
      // wham file
      std::ofstream whamfile;
      std::string whamfilename;
      whamfilename.append("wham.metadata_");
      whamfilename.append(std::to_string(kt));
      whamfile.open(whamfilename);
      for (double chi_target = 0; chi_target <=1; chi_target+=0.05){
	//append to whamfile
	std::string chi_m_string = std::to_string(chi_target);
        chi_m_string.append("_");
        chi_m_string.append(std::to_string(kt));
	whamfile << chi_m_string << ".dat   " << chi_target << "   10\n";
	//std::cout << "starting simulation set " << simnum << ", kT/epsilon = " << kt << ".\n";

	//energies
	std::ofstream energy_output;
	std::string energy_output_file_name;
	energy_output_file_name.append("T_");
	energy_output_file_name.append(std::to_string(kt));
	energy_output_file_name.append("_chi_");
	energy_output_file_name.append(std::to_string(chi_target));
	energy_output_file_name.append(".dat");
	energy_output.open(energy_output_file_name); 

	// chi
	std::ofstream chifile;
	std::string chifile_name;
	chifile_name.append(chi_m_string);
        chifile_name.append(".dat");
        chifile.open(chifile_name);

	std::cout << "starting simulation for Chi = " << chi_m_string << ".\n";
	SpinSimulation(kt,chi_target,E_T0, E_TInf, k_chi, chifile,  energy_output);
	energy_output.close();
	chifile.close();	
      }
    }
    //}
  return EXIT_SUCCESS;
}
