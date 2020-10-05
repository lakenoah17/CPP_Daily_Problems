#include <iostream>

//Good morning! Here's your coding interview problem for today.
//
//This problem was asked by Amazon.
//
//There exists a staircase with N steps, and you can climb up
// either 1 or 2 steps at a time. Given N, write a function
// that returns the number of unique ways you can climb the
// staircase. The order of the steps matters.
//
//For example, if N is 5, then there are 8 unique ways:
//
//1, 1, 1, 1, 1
//2, 1, 1, 1
//1, 2, 1, 1
//1, 1, 2, 1
//1, 1, 1, 2
//2, 2, 1
//2, 1, 2
//1, 2, 2

//What if, instead of being able to climb 1 or 2 steps at a
// time, you could climb any number from a set of positive
// integers X? For example, if X = {1, 3, 5}, you could climb
// 1, 2, 3, or 5 steps at a time.

//1 1 1 1 1 1
//2, 1, 1, 1 1
//1, 2, 1, 1 1
//1, 1, 2, 1 1
//1, 1, 1, 2 1
//1, 1, 1, 1, 2
//2, 2, 1, 1
//2, 1, 2, 1
//2, 1, 1, 2
//1, 2, 1, 2
//1, 2, 2, 1
//1, 1, 2, 2
//2 2 2
//3 1 1 1
//1 3 1 1
//1 1 3 1
//1 1 1 3
//1 2 3
//2 1 3
//3 1 2
//3 2 1
//2 3 1
//1 3 2
//3 3
//5 1
//1 5

int findNumOfStairClimbPossible(int numOfStairs, int numOfStairsPossible[], int arrLength);

int main() {
    int numOfStairsPossible[] = {1, 2, 3, 5};
    int numOfStairs = 6;

    //Found this solution on Google but I love this!!!
    //Pointer arithmetic is so f*ing cool!!! By finding
    //the last memory address of the array then subtracting
    //the memory address of the start we find the difference
    //in memory address which is the length of the array
    int arrLength = *((&numOfStairsPossible) + 1) - numOfStairsPossible;

    std::cout<<findNumOfStairClimbPossible(numOfStairs, numOfStairsPossible, arrLength);

    return 0;
}

int findNumOfStairClimbPossible(int numOfStairs, int numOfStairsPossible[], int arrLength){
    int totalCombinations = 0;

    if (numOfStairs < 0){
        return 0;
    }

    if (numOfStairs <= 1){
        return 1;
    }

    for (int i = 0; i < arrLength; i++) {
        totalCombinations += findNumOfStairClimbPossible(numOfStairs - numOfStairsPossible[i],
                                                         numOfStairsPossible,
                                                         arrLength);
    }

    return totalCombinations;
}
