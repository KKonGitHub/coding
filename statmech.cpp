#include<iostream>
#include<vector>
#include<bitset>
#include<cmath>
using namespace std;

#define BOLTZMANN 1
#define DEVIDE 0.5
#define MAX 1000

vector<int> spinol(__uint8_t n){
    bitset<8> bs(n);
    vector<int> s;
    for(int e=0;e<8;e++){
        if(bs[e]){
            s.push_back(1);
        }
        else{
            s.push_back(-1);
        }
    }
    return s;
}

double energy(vector<vector<int> >& adj, vector<int>& vertex ){
    double en;
    for(int i = 0; i<8; i++){
        for(int j = 0; j < 8; j++){
            en += double( vertex.at(i) * vertex.at(j) * adj.at(i).at(j) );
        }
    }
    return en;
}

vector<double> boltz ( vector<vector<int> > shape, double beta){
    __uint8_t n;
    bitset<8> bs(n);
    vector<int> s = {0,0,0,0,0,0,0,0};
    vector<double> boltzmann_factor;
    vector<double> energy_list; 
    double temp;
    for(n=0;n<256;n++){
        for(int i = 0 ;i<8 ;i++){
            if(bs[i]){
                s.at(i) = 1;
            }
            else{
                s.at(i) = -1;
            }
        }
        energy_list.push_back(energy(s))
        temp = exp(-beta*energy_list);
        boltzmann_factor.push_back(temp);        
    }
    return boltzmann_factor;
}


int main(){
    vector<vector<int> > shape = {{0,1,0,1,0,1,0,0},
                                  {1,0,1,0,0,0,1,0},
                                  {0,1,0,1,0,0,0,1},
                                  {1,0,1,0,1,0,0,0},
                                  {0,0,0,1,0,1,0,1},
                                  {1,0,0,0,1,0,1,0},
                                  {0,1,0,0,1,0,1,0},
                                  {0,0,1,0,0,1,0,1}};

     vector<double> internal;
     vector<double> T ;
    for(int m = 0; m < MAX/DEVIDE; m++){
        T.push_back(m * DEVIDE);
        internal.push_back(equil(shape,T.at(m)));
    };


    return 0;
}
   

// how to return vector type variables from main func?
