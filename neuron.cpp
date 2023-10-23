#include <iostream>
#include <vector>
#include <bitset>
#include <memory>
#include <cmath>
using namespace std;



const int N = 7;
const int M = 30;



class neuron{
    vector<bool> synapse; // True is 1 False is -1
    bool result ;

    neuron(unsigned int num){
        bitset<N> set(num);
        for(short i; i < N ; i++){
            if(set[i]){
                synapse.push_back(true);
            }
            else{
                synapse.push_back(false);
            }
        } 

    };

    public:

    bool neuron::deal(vector<bool> input){
        int a=0;
        for(short i=0; i<N; i++){
            if(input.at(i) == synapse.at(i)){
                a++;
            }
            else{
                a--;
            }
        };
        if(a>0){
            result = true ;
        }
        else{
            result = false ;
        }
    }
};


int power(int base, unsigned int index){
    int ans = 1;
    for(int i=1; i<index+1 ; i++){
        ans = ans * base;
    }
    return ans;
}



int main(){
    auto alc = allocator<neuron>() ;
    int* arr = alc.allocate(32);    // 2**5
                                    /* Using allocator, while the amount of objects and process would be too large for the memory, 
                                    the computer can deal with because it can utilize same memory place again and again */

    unsigned int amount = power(2,N-5);

    for(int cl = 0; ) 



}