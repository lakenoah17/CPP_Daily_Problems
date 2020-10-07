#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
//Good morning! Here's your coding
// interview problem for today.
//
//This problem was asked by Facebook.
//
//Given a stream of elements too large
// to store in memory, pick a random
// element from the stream with uniform
// probability.

float generateRandom();

int main(){
    std::cout<<generateRandom();
}

float generateRandom(){
    //Seeds rand with time
    srand(std::chrono::system_clock::now().time_since_epoch().count());

    //Opens in stream
    std::ifstream in("oct_7_nums.txt");

    if (!in){
        std::cout<<"Error: Can't open file";
        exit(1);
    }

    float prob = (float) rand() / (float) RAND_MAX;
    float lastProb;
    float num;
    float erasable;

    //Runs until the input is out of numbers
    while(in){
        lastProb = (float) rand() / (float) RAND_MAX;

        if(lastProb > prob){
            in >> num;
            prob = lastProb;
        }
        else{
            in >> erasable;
        }
    }

    return num;
}