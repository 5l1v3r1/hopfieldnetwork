#include "hopfield.h";

Hopfield_neuron::Hopfield_neuron(int *j)
{
     for(int i=0; i<4; i++)
       {
           weight[i] = *(j+i);
       }
}

int Hopfield_neuron::act(int m, int *pattern)
{
    int a = 0;

    for(int i=0; i<4; i++)
      {
         a += pattern[i] * weight[i];
      }

     return a;
 }

 int Hopfield_network::threshold(int k)
 {
     if ( k >= 0)
         return 1;
     else
        return 0;
  }

 void Hopfield_network::update(int node, int *pattern, int *weight)
 {
        int vin = 0;
        for(int i=0; i<4; i++)
          {
             vin += pattern[i] * weight[i];
          }

         if(threshold(vin) != pattern[node])
           {
                pattern[node] = threshold(vin);
           }
  }

 Hopfield_network::Hopfield_network(int nrn0[4], int nrn1[4], int nrn2[4],        int nrn3[4])
  {
          neuron[0] = Hopfield_neuron(nrn0);
          neuron[1] = Hopfield_neuron(nrn1);
          neuron[2] = Hopfield_neuron(nrn2);
          neuron[3] = Hopfield_neuron(nrn3);
  }

  void Hopfield_network::activation(int *pattern)
  {
         for(int i=0; i<4; i++)
           {
              neuron[i].activation = neuron[i].act(4, pattern);
              output[i] = threshold(neuron[i].activation);
           }
  } 

