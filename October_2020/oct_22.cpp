#include "iostream"
//This problem was asked by Facebook.
//
//You are given an array of non-negative
// integers that represents a two-dimensional
// elevation map where each element is
// unit-width wall and the integer is the
// height. Suppose it will rain and all
// spots between two walls get filled up.
//
//Compute how many units of water remain
// trapped on the map in O(N) time and O(1)
// space.
//
//For example, given the input [2, 1, 2], we
// can hold 1 unit of water in the middle.
//
//Given the input [3, 0, 1, 3, 0, 5], we can
// hold 3 units in the first index, 2 in the
// second, and 3 in the fourth index (we
// cannot hold 5 since it would run off to
// the left), so we can trap 8 units of water.

int findNumOfWater(int map[], int mapSize);

int main(){
    int map[] = {0,4,0,3};
    std::cout<<findNumOfWater(map, 4);
}

int findNumOfWater(int map[], int mapSize){
    int currMaxWallVal = map[0];
    int secondMaxWall = 0;
    int waterTotal = 0;
    int tallestWallIndex = 0;
    int secondTallestWallIndex = 0;

    for (int i = 1; i < mapSize; ++i) {
        if (currMaxWallVal <= map[i]){
            waterTotal += (i - tallestWallIndex - 1) * (currMaxWallVal - secondMaxWall);
            secondMaxWall = 0;
            currMaxWallVal = map[i];
            secondTallestWallIndex = i;
            tallestWallIndex = i;
        }
        else if (secondMaxWall <= map[i]){
            waterTotal += (i - secondTallestWallIndex - 1) * (map[i] - secondMaxWall);
            secondMaxWall = map[i];
            secondTallestWallIndex = i;
        }
        else{
            waterTotal -= map[i];
        }
    }

    return waterTotal;
}
