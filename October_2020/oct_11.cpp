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

int main(){
    int n = 4;
    int k = 4;

    int costs[4][4] = {{100,100,200,300},
                       {200,300,400,100},
                       {300,200,100,200},
                       {400,400,200,400}};


}

int findLowestCost(int n, int k, int costs[n][k]){

}

int findLowestCostUtil(int lastColorIndex, int nums[]){

}

int findLowest(int num1, int num2){
    if (num1 < num2){
        return num1;
    }

    return num2;
}