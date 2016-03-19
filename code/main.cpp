#include "hopfield.h"

int main()
  {
         int pattern1[] = {1,1,0,0};

         int weight1[] = { 0, -5,  4,  4};
         int weight2[] = {-5,  0,  4,  4};
         int weight3[] = { 4,  4,  0, -5};
         int weight4[] = { 4,  4, -5,  0};

        std::cout<<"This is hopfield network with a single layer of 4";
        std::cout<<"\nfully interconnected neurons. The network should  recall the \nPatterns 1111, 1010, 0101, 1001, 0110 correctly.\n";

        Hopfield_network h1(weight1, weight2, weight3, weight4);

        h1.activation(pattern1);

       for(int i=0; i<4; i++)
          {
              if(h1.output[i] == pattern1[i])
               {
                   std::cout<<"\n pattern = "<<pattern1[i]<<"  output = "<<h1.output[i]<<"  component matches";
               }
              else
              {
                   std::cout<<"\n pattern = "<<pattern1[i]<<"  output = "<<h1.output[i]<<"  discrepancy occured";
              }
         }


        int choosedNodes[8] = {1,2,3,4,1,2,3,4};
        int weight[4];

        for(int i=0; i<8; i++)
          {
              switch(choosedNodes[i])
                 {
                    case 1: weight[0] =  0; weight[1] = -5;  weight[2] =   4;  weight[3] =  4; 
                    break;
                    case 2: weight[0] = -5; weight[1] =  0;  weight[2] =   4;  weight[3] =  4; 
                    break;
                    case 3: weight[0] =  4; weight[1] =  4;  weight[2] =   0;  weight[3] = -5;  
                    break;
                    case 4: weight[0] =  4; weight[1] = 4;   weight[2]  = -5;  weight[3] =  0; 
                     break;

                  }
             h1.update(choosedNodes[i]-1, pattern1, weight);
         }

         std::cout<<"\n\n The recalled Pattern\n";


         for(int i=0; i<4; i++)
           {
               std::cout<<"\n pattern = "<<pattern1[i];

           }

          std::cin.get();
}
