#ifndef DEFINED_INTERACTION_TENSORS
#define DEFINED_INTERACTION_TENSORS
#include <vector>

void GetIntTx(std::string name, std::vector<std::vector<std::vector<double> > > & IntTx){
  //std::vector<std::vector<std::vector<int> > > IntTx(4, std::vector<std::vector<int> > (4, std::vector<int>(4,0)));
    if(name=="NoInteractions"){
      IntTx[0][0][0] =  0;
      IntTx[0][0][1] =  0;
      IntTx[0][0][2] =  0;
      IntTx[0][0][3] =  0;
  
      IntTx[0][1][0] =  0;
      IntTx[0][1][1] =  0;
      IntTx[0][1][2] =  0;
      IntTx[0][1][3] =  0;

      IntTx[0][2][0] =  0;
      IntTx[0][2][1] =  0;
      IntTx[0][2][2] =  0;
      IntTx[0][2][3] =  0;
      
      IntTx[0][3][0] =  0;
      IntTx[0][3][1] =  0;
      IntTx[0][3][2] =  0;
      IntTx[0][3][3] =  0;
      


      
      IntTx[1][0][0] =  0;
      IntTx[1][0][1] =  0;
      IntTx[1][0][2] =  0;
      IntTx[1][0][3] =  0;
      
      IntTx[1][1][0] =  0;
      IntTx[1][1][1] =  0;
      IntTx[1][1][2] =  0;
      IntTx[1][1][3] =  0;
      
      IntTx[1][2][0] =  0;
      IntTx[1][2][1] =  0;
      IntTx[1][2][2] =  0;
      IntTx[1][2][3] =  0;
      
      IntTx[1][3][0] =  0;
      IntTx[1][3][1] =  0;
      IntTx[1][3][2] =  0;
      IntTx[1][3][3] =  0;


      
      
      IntTx[2][0][0] =  0;
      IntTx[2][0][1] =  0;
      IntTx[2][0][2] =  0;
      IntTx[2][0][3] =  0;
      
      IntTx[2][1][0] =  0;
      IntTx[2][1][1] =  0;
      IntTx[2][1][2] =  0;
      IntTx[2][1][3] =  0;
      
      IntTx[2][2][0] =  0;
      IntTx[2][2][1] =  0;
      IntTx[2][2][2] =  0;
      IntTx[2][2][3] =  0;
      
      IntTx[2][3][0] =  0;
      IntTx[2][3][1] =  0;
      IntTx[2][3][2] =  0;
      IntTx[2][3][3] =  0;


      

      IntTx[3][0][0] =  0;
      IntTx[3][0][1] =  0;
      IntTx[3][0][2] =  0;
      IntTx[3][0][3] =  0;
      
      IntTx[3][1][0] =  0;
      IntTx[3][1][1] =  0;
      IntTx[3][1][2] =  0;
      IntTx[3][1][3] =  0;
      
      IntTx[3][2][0] =  0;
      IntTx[3][2][1] =  0;
      IntTx[3][2][2] =  0;
      IntTx[3][2][3] =  0;
      
      IntTx[3][3][0] =  0;
      IntTx[3][3][1] =  0;
      IntTx[3][3][2] =  0;
      IntTx[3][3][3] =  0;
    }

    if(name=="Ising"){
      IntTx[0][0][0] = -1;
      IntTx[0][0][1] =  1;
      IntTx[0][0][2] = -1;
      IntTx[0][0][3] =  1;
  
      IntTx[0][1][0] = -1;
      IntTx[0][1][1] =  1;
      IntTx[0][1][2] = -1;
      IntTx[0][1][3] =  1;

      IntTx[0][2][0] = -1;
      IntTx[0][2][1] =  1;
      IntTx[0][2][2] = -1;
      IntTx[0][2][3] =  1;
      
      IntTx[0][3][0] = -1;
      IntTx[0][3][1] =  1;
      IntTx[0][3][2] = -1;
      IntTx[0][3][3] =  1;
      


      
      IntTx[1][0][0] =  1;
      IntTx[1][0][1] = -1;
      IntTx[1][0][2] =  1;
      IntTx[1][0][3] = -1;
      
      IntTx[1][1][0] =  1;
      IntTx[1][1][1] = -1;
      IntTx[1][1][2] =  1;
      IntTx[1][1][3] = -1;
      
      IntTx[1][2][0] =  1;
      IntTx[1][2][1] = -1;
      IntTx[1][2][2] =  1;
      IntTx[1][2][3] = -1;
      
      IntTx[1][3][0] =  1;
      IntTx[1][3][1] = -1;
      IntTx[1][3][2] =  1;
      IntTx[1][3][3] = -1;


      
      
      IntTx[2][0][0] = -1;
      IntTx[2][0][1] =  1;
      IntTx[2][0][2] = -1;
      IntTx[2][0][3] =  1;
      
      IntTx[2][1][0] = -1;
      IntTx[2][1][1] =  1;
      IntTx[2][1][2] = -1;
      IntTx[2][1][3] =  1;
      
      IntTx[2][2][0] = -1;
      IntTx[2][2][1] =  1;
      IntTx[2][2][2] = -1;
      IntTx[2][2][3] =  1;
      
      IntTx[2][3][0] = -1;
      IntTx[2][3][1] =  1;
      IntTx[2][3][2] = -1;
      IntTx[2][3][3] =  1;


      

      IntTx[3][0][0] =  1;
      IntTx[3][0][1] = -1;
      IntTx[3][0][2] =  1;
      IntTx[3][0][3] = -1;
      
      IntTx[3][1][0] =  1;
      IntTx[3][1][1] = -1;
      IntTx[3][1][2] =  1;
      IntTx[3][1][3] = -1;
      
      IntTx[3][2][0] =  1;
      IntTx[3][2][1] = -1;
      IntTx[3][2][2] =  1;
      IntTx[3][2][3] = -1;
      
      IntTx[3][3][0] =  1;
      IntTx[3][3][1] = -1;
      IntTx[3][3][2] =  1;
      IntTx[3][3][3] = -1;
    }

    if(name=="LeftRight"){
      IntTx[0][0][0] = -1;
      IntTx[0][0][1] =  0;
      IntTx[0][0][2] = -1;
      IntTx[0][0][3] =  0;
  
      IntTx[0][1][0] =  0;
      IntTx[0][1][1] =  0;
      IntTx[0][1][2] =  0;
      IntTx[0][1][3] =  0;

      IntTx[0][2][0] = -1;
      IntTx[0][2][1] =  0;
      IntTx[0][2][2] = -1;
      IntTx[0][2][3] =  0;
      
      IntTx[0][3][0] =  0;
      IntTx[0][3][1] =  0;
      IntTx[0][3][2] =  0;
      IntTx[0][3][3] =  0;
      


      
      IntTx[1][0][0] =  0;
      IntTx[1][0][1] =  0;
      IntTx[1][0][2] =  0;
      IntTx[1][0][3] =  0;
      
      IntTx[1][1][0] =  0;
      IntTx[1][1][1] = -1;
      IntTx[1][1][2] =  0;
      IntTx[1][1][3] = -1;
      
      IntTx[1][2][0] =  0;
      IntTx[1][2][1] =  0;
      IntTx[1][2][2] =  0;
      IntTx[1][2][3] =  0;
      
      IntTx[1][3][0] =  0;
      IntTx[1][3][1] = -1;
      IntTx[1][3][2] =  0;
      IntTx[1][3][3] = -1;


      
      
      IntTx[2][0][0] = -1;
      IntTx[2][0][1] =  0;
      IntTx[2][0][2] = -1;
      IntTx[2][0][3] =  0;
      
      IntTx[2][1][0] =  0;
      IntTx[2][1][1] =  0;
      IntTx[2][1][2] =  0;
      IntTx[2][1][3] =  0;
      
      IntTx[2][2][0] = -1;
      IntTx[2][2][1] =  0;
      IntTx[2][2][2] = -1;
      IntTx[2][2][3] =  0;
      
      IntTx[2][3][0] =  0;
      IntTx[2][3][1] =  0;
      IntTx[2][3][2] =  0;
      IntTx[2][3][3] =  0;


      

      IntTx[3][0][0] =  0;
      IntTx[3][0][1] =  0;
      IntTx[3][0][2] =  0;
      IntTx[3][0][3] =  0;
      
      IntTx[3][1][0] =  0;
      IntTx[3][1][1] = -1;
      IntTx[3][1][2] =  0;
      IntTx[3][1][3] = -1;
      
      IntTx[3][2][0] =  0;
      IntTx[3][2][1] =  0;
      IntTx[3][2][2] =  0;
      IntTx[3][2][3] =  0;
      
      IntTx[3][3][0] =  0;
      IntTx[3][3][1] = -1;
      IntTx[3][3][2] =  0;
      IntTx[3][3][3] = -1;
    }

    
    if(name=="Spider"){
      IntTx[0][0][0] = -4;
      IntTx[0][0][1] = -1;
      IntTx[0][0][2] = -4;
      IntTx[0][0][3] =  0;
  
      IntTx[0][1][0] =  0;
      IntTx[0][1][1] = -1;
      IntTx[0][1][2] = -1;
      IntTx[0][1][3] = -1;

      IntTx[0][2][0] = -4;
      IntTx[0][2][1] =  0;
      IntTx[0][2][2] = -4;
      IntTx[0][2][3] = -1;
      
      IntTx[0][3][0] =  0;
      IntTx[0][3][1] =  0;
      IntTx[0][3][2] =  0;
      IntTx[0][3][3] =  0;
      


      
      IntTx[1][0][0] =  0;
      IntTx[1][0][1] =  0;
      IntTx[1][0][2] =  0;
      IntTx[1][0][3] =  0;
      
      IntTx[1][1][0] =  0;
      IntTx[1][1][1] = -4;
      IntTx[1][1][2] = -1;
      IntTx[1][1][3] = -4;
      
      IntTx[1][2][0] = -1;
      IntTx[1][2][1] =  0;
      IntTx[1][2][2] = -1;
      IntTx[1][2][3] = -1;
      
      IntTx[1][3][0] = -1;
      IntTx[1][3][1] = -4;
      IntTx[1][3][2] =  0;
      IntTx[1][3][3] = -4;

      

      IntTx[2][0][0] = -4;
      IntTx[2][0][1] = -1;
      IntTx[2][0][2] = -4;
      IntTx[2][0][3] =  0;
      
      IntTx[2][1][0] =  0;
      IntTx[2][1][1] =  0;
      IntTx[2][1][2] =  0;
      IntTx[2][1][3] =  0;
      
      IntTx[2][2][0] = -4;
      IntTx[2][2][1] =  0;
      IntTx[2][2][2] = -4;
      IntTx[2][2][3] = -1;
      
      IntTx[2][3][0] = -1;
      IntTx[2][3][1] = -1;
      IntTx[2][3][2] =  0;
      IntTx[2][3][3] = -1;

      

      IntTx[3][0][0] = -1;
      IntTx[3][0][1] = -1;
      IntTx[3][0][2] = -1;
      IntTx[3][0][3] =  0;
      
      IntTx[3][1][0] =  0;
      IntTx[3][1][1] = -4;
      IntTx[3][1][2] = -1;
      IntTx[3][1][3] = -4;
      
      IntTx[3][2][0] =  0;
      IntTx[3][2][1] =  0;
      IntTx[3][2][2] =  0;
      IntTx[3][2][3] =  0;
      
      IntTx[3][3][0] = -1;
      IntTx[3][3][1] = -4;
      IntTx[3][3][2] =  0;
      IntTx[3][3][3] = -4;
    }

    if (name=="LShaped"){
      IntTx[0][0][0] =  0;
      IntTx[0][0][1] = -1;
      IntTx[0][0][2] = -1;
      IntTx[0][0][3] =  0;
  
      IntTx[0][1][0] =  0;
      IntTx[0][1][1] =  0;
      IntTx[0][1][2] = -1;
      IntTx[0][1][3] = -1;

      IntTx[0][2][0] =  0;
      IntTx[0][2][1] =  0;
      IntTx[0][2][2] =  0;
      IntTx[0][2][3] =  0;
      
      IntTx[0][3][0] =  0;
      IntTx[0][3][1] =  0;
      IntTx[0][3][2] =  0;
      IntTx[0][3][3] =  0;
      


      
      IntTx[1][0][0] =  0;
      IntTx[1][0][1] =  0;
      IntTx[1][0][2] =  0;
      IntTx[1][0][3] =  0;
      
      IntTx[1][1][0] =  0;
      IntTx[1][1][1] =  0;
      IntTx[1][1][2] = -1;
      IntTx[1][1][3] = -1;
      
      IntTx[1][2][0] = -1;
      IntTx[1][2][1] =  0;
      IntTx[1][2][2] =  0;
      IntTx[1][2][3] = -1;
      
      IntTx[1][3][0] =  0;
      IntTx[1][3][1] =  0;
      IntTx[1][3][2] =  0;
      IntTx[1][3][3] =  0;


      
      IntTx[2][0][0] =  0;
      IntTx[2][0][1] =  0;
      IntTx[2][0][2] =  0;
      IntTx[2][0][3] =  0;
      
      IntTx[2][1][0] =  0;
      IntTx[2][1][1] =  0;
      IntTx[2][1][2] =  0;
      IntTx[2][1][3] =  0;
      
      IntTx[2][2][0] = -1;
      IntTx[2][2][1] =  0;
      IntTx[2][2][2] =  0;
      IntTx[2][2][3] = -1;
      
      IntTx[2][3][0] = -1;
      IntTx[2][3][1] = -1;
      IntTx[2][3][2] =  0;
      IntTx[2][3][3] =  0;

      

      IntTx[3][0][0] =  0;
      IntTx[3][0][1] = -1;
      IntTx[3][0][2] = -1;
      IntTx[3][0][3] =  0;
      
      IntTx[3][1][0] =  0;
      IntTx[3][1][1] =  0;
      IntTx[3][1][2] =  0;
      IntTx[3][1][3] =  0;
      
      IntTx[3][2][0] =  0;
      IntTx[3][2][1] =  0;
      IntTx[3][2][2] =  0;
      IntTx[3][2][3] =  0;
      
      IntTx[3][3][0] = -1;
      IntTx[3][3][1] = -1;
      IntTx[3][3][2] =  0;
      IntTx[3][3][3] =  0;
    }

    if(name=="FShaped"){
      IntTx[0][0][0] =  0;
      IntTx[0][0][1] = -1;
      IntTx[0][0][2] = -2;
      IntTx[0][0][3] =  0;
  
      IntTx[0][1][0] =  0;
      IntTx[0][1][1] =  0;
      IntTx[0][1][2] = -1;
      IntTx[0][1][3] = -1;

      IntTx[0][2][0] =  0;
      IntTx[0][2][1] =  0;
      IntTx[0][2][2] =  0;
      IntTx[0][2][3] =  0;
      
      IntTx[0][3][0] =  0;
      IntTx[0][3][1] =  0;
      IntTx[0][3][2] =  0;
      IntTx[0][3][3] =  0;
      


      
      IntTx[1][0][0] =  0;
      IntTx[1][0][1] =  0;
      IntTx[1][0][2] =  0;
      IntTx[1][0][3] =  0;
      
      IntTx[1][1][0] =  0;
      IntTx[1][1][1] =  0;
      IntTx[1][1][2] = -1;
      IntTx[1][1][3] = -2;
      
      IntTx[1][2][0] = -1;
      IntTx[1][2][1] =  0;
      IntTx[1][2][2] =  0;
      IntTx[1][2][3] = -1;
      
      IntTx[1][3][0] =  0;
      IntTx[1][3][1] =  0;
      IntTx[1][3][2] =  0;
      IntTx[1][3][3] =  0;


      
      
      IntTx[2][0][0] =  0;
      IntTx[2][0][1] =  0;
      IntTx[2][0][2] =  0;
      IntTx[2][0][3] =  0;
      
      IntTx[2][1][0] =  0;
      IntTx[2][1][1] =  0;
      IntTx[2][1][2] =  0;
      IntTx[2][1][3] =  0;
      
      IntTx[2][2][0] = -2;
      IntTx[2][2][1] =  0;
      IntTx[2][2][2] =  0;
      IntTx[2][2][3] = -1;
      
      IntTx[2][3][0] = -1;
      IntTx[2][3][1] = -1;
      IntTx[2][3][2] =  0;
      IntTx[2][3][3] =  0;


      

      IntTx[3][0][0] =  0;
      IntTx[3][0][1] = -1;
      IntTx[3][0][2] = -1;
      IntTx[3][0][3] =  0;
      
      IntTx[3][1][0] =  0;
      IntTx[3][1][1] =  0;
      IntTx[3][1][2] =  0;
      IntTx[3][1][3] =  0;
      
      IntTx[3][2][0] =  0;
      IntTx[3][2][1] =  0;
      IntTx[3][2][2] =  0;
      IntTx[3][2][3] =  0;
      
      IntTx[3][3][0] = -1;
      IntTx[3][3][1] = -2;
      IntTx[3][3][2] =  0;
      IntTx[3][3][3] =  0;
    }
    
    if(name=="Lakshmi"){
      IntTx[0][0][0] = -2;
      IntTx[0][0][1] = -1;
      IntTx[0][0][2] = -2;
      IntTx[0][0][3] = -2;
  
      IntTx[0][1][0] = -1;
      IntTx[0][1][1] = -1;
      IntTx[0][1][2] = -1;
      IntTx[0][1][3] = -1;

      IntTx[0][2][0] = -2;
      IntTx[0][2][1] = -2;
      IntTx[0][2][2] = -2;
      IntTx[0][2][3] = -1;
      
      IntTx[0][3][0] = -1;
      IntTx[0][3][1] = -2;
      IntTx[0][3][2] = -2;
      IntTx[0][3][3] = -2;
      


      
      IntTx[1][0][0] = -2;
      IntTx[1][0][1] = -1;
      IntTx[1][0][2] = -2;
      IntTx[1][0][3] = -2;
      
      IntTx[1][1][0] = -2;
      IntTx[1][1][1] = -2;
      IntTx[1][1][2] = -1;
      IntTx[1][1][3] = -2;
      
      IntTx[1][2][0] = -1;
      IntTx[1][2][1] = -1;
      IntTx[1][2][2] = -1;
      IntTx[1][2][3] = -1;
      
      IntTx[1][3][0] = -1;
      IntTx[1][3][1] = -2;
      IntTx[1][3][2] = -2;
      IntTx[1][3][3] = -2;


      
      
      IntTx[2][0][0] = -2;
      IntTx[2][0][1] = -1;
      IntTx[2][0][2] = -2;
      IntTx[2][0][3] = -2;
      
      IntTx[2][1][0] = -2;
      IntTx[2][1][1] = -2;
      IntTx[2][1][2] = -1;
      IntTx[2][1][3] = -2;
      
      IntTx[2][2][0] = -2;
      IntTx[2][2][1] = -2;
      IntTx[2][2][2] = -2;
      IntTx[2][2][3] = -1;
      
      IntTx[2][3][0] = -1;
      IntTx[2][3][1] = -1;
      IntTx[2][3][2] = -1;
      IntTx[2][3][3] = -1;


      

      IntTx[3][0][0] = -1;
      IntTx[3][0][1] = -1;
      IntTx[3][0][2] = -1;
      IntTx[3][0][3] = -1;
      
      IntTx[3][1][0] = -2;
      IntTx[3][1][1] = -2;
      IntTx[3][1][2] = -1;
      IntTx[3][1][3] = -2;
      
      IntTx[3][2][0] = -2;
      IntTx[3][2][1] = -2;
      IntTx[3][2][2] = -2;
      IntTx[3][2][3] = -1;
      
      IntTx[3][3][0] = -1;
      IntTx[3][3][1] = -2;
      IntTx[3][3][2] = -2;
      IntTx[3][3][3] = -2;
    }
}

#endif
