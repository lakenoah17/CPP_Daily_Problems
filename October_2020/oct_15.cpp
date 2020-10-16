#include "iostream"

//This problem was asked by Google.
//
//You are given an M by N matrix consisting
// of booleans that represents a board. Each
// True boolean represents a wall. Each False
// boolean represents a tile you can walk on.
//
//Given this matrix, a start coordinate, and
// an end coordinate, return the minimum number
// of steps required to reach the end coordinate
// from the start. If there is no possible path,
// then return null. You can move up, left,
// down, and right. You cannot move through
// walls. You cannot wrap around the edges of
// the board.
//
//For example, given the following board:
//
//[[f, f, f, f],
//[t, t, f, t],
//[f, f, f, f],
//[f, f, f, f]]
//and start = (3, 0) (bottom left) and end = (0, 0)
// (top left), the minimum number of steps required
// to reach the end is 7, since we would need to go
// through (1, 2) because there is a wall everywhere
// else on the second row.
int findShortestPath(int rowLen, int colLen, bool **boolMap, int yCurr, int xCurr, int xEnd, int yEnd);
int findMin(int num1, int num2);

int main(){
    int rowLen = 4;
    int colLen = 4;
    bool *map[4] = {new bool[4]{false, false, false, false},
                  new bool[4]{true, true, false, true},
                  new bool[4]{false, false, false, false},
                  new bool[4]{false, false, false, false}};

    std::cout<<findShortestPath(rowLen, colLen, map, 0, 3, 0, 0);


}

int findShortestPath(int rowLen, int colLen, bool **boolMap, int yCurr, int xCurr, int xEnd, int yEnd){
    if (yCurr < 0 || yCurr >= rowLen || xCurr < 0 || xCurr >= colLen || boolMap[xCurr][yCurr]){
        return rowLen*colLen;
    }

    if (yCurr == xEnd && xCurr == yEnd){
        return 1;
    }

    boolMap[xCurr][yCurr] = true;

    int path1 = findShortestPath(rowLen, colLen, boolMap, yCurr, xCurr + 1, xEnd, yEnd);

    int path2 = findShortestPath(rowLen, colLen, boolMap, yCurr, xCurr - 1, xEnd, yEnd);

    int path3 = findShortestPath(rowLen, colLen, boolMap, yCurr + 1, xCurr, xEnd, yEnd);

    int path4 = findShortestPath(rowLen, colLen, boolMap, yCurr - 1, xCurr, xEnd, yEnd);

    return findMin(findMin(path1, path2), findMin(path3, path4)) + 1;
}

int findMin(int num1, int num2){
    return num1 < num2 ? num1 : num2;
}