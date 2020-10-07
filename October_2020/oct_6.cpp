#include <iostream>
#include <random>
#include <chrono>

//Good morning! Here's your coding
// interview problem for today.
//
//This problem was asked by Google.
//
//The area of a circle is defined as
// πr^2. Estimate π to 3 decimal places
// using a Monte Carlo method.
//
//Hint: The basic equation of a circle
// is x2 + y2 = r2.

double findPI(double numOfRandAttempts);

int main(){
    std::cout<<findPI(1000);
}

double findPI(double numOfRandAttempts){
    std::default_random_engine gen;
    gen.seed(std::chrono::system_clock::now().time_since_epoch().count());

    std::uniform_int_distribution<int> randDistrib(-1000,1000);
    int radius = 1000;

    double numInCircle = 0;

    for (int i = 0; i < numOfRandAttempts; ++i) {
        double x = randDistrib(gen);
        double y = randDistrib(gen);
        double distFromCenter = sqrt(pow(x, 2) + pow(y, 2));

        if(distFromCenter < radius){
            numInCircle++;
        }
    }

    return trunc(4000.0 * (numInCircle / numOfRandAttempts)) / 1000;
}

