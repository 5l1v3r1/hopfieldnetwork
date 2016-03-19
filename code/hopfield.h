#include <iostream>
#include <stdio.h>
#include <math.h>

class Hopfield_neuron
   {
     protected:
            int activation;
            friend class Hopfield_network;

     public:
            int weight[4];
            Hopfield_neuron() {};
            Hopfield_neuron(int *j);
            int act(int , int*);
};

class Hopfield_network
{
     public:
     Hopfield_neuron neuron[4];
     int output[4];
     int threshold(int);
     void update(int, int*, int*);
     void activation(int j[4]);
     Hopfield_network(int*, int*, int*, int*);
};
