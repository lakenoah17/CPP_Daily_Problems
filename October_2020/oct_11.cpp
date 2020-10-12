#include <math.h>
#include <iostream>

//This problem was asked by Facebook.
//
//A builder is looking to build a row of N
// houses that can be of K different colors.
// He has a goal of minimizing cost while
// ensuring that no two neighboring houses
// are of the same color.
//
//Given an N by K matrix where the nth row
// and kth column represents the cost to
// build the nth house with kth color,
// return the minimum cost which achieves
// this goal.
int findLowestCost(int row, int rowCount, int length, int **costs, int lastColorIndex);
int findLowestIndex(int nums[], int length, int indexToExclude = -1);


int main(){
    int n = 4;
    int k = 4;

    int * costs[4] = {new int[4]{100,100,200,300},
                      new int[4]{200,300,400,100},
                      new int[4]{300,200,100,200},
                      new int[4]{400,400,200,400}};

    std::cout<<findLowestCost(0,n,k,costs,-1);
}

int findLowestCost(int row, int rowCount, int length, int **costs, int lastColorIndex){
    int lowestIndex = findLowestIndex(costs[row], length);

    if (lowestIndex == lastColorIndex){
        return -1;
    }

    if (row == rowCount){
        return costs[row][lowestIndex];
    }

    int returnedVal = findLowestCost(row + 1, rowCount, length, costs, lowestIndex);

    while (returnedVal != -1){
        lowestIndex = findLowestIndex(costs[row], length, lowestIndex);
        returnedVal = findLowestCost(row + 1, rowCount, length, costs, lowestIndex);
    }

    return returnedVal + costs[row][lowestIndex];

}

int findLowestIndex(int nums[], int length, int indexToExclude){
    int lowestIndex = 0;

    for (int i = 1; i < length; ++i) {
        if (nums[i] < nums[lowestIndex] && i != indexToExclude){
            lowestIndex = i;
        }
    }

    return lowestIndex;
}