#include <iostream>

//Good morning! Here's your coding interview problem for today.
//
//This problem was asked by Amazon.
//
//Given an integer k and a string s, find the length of the longest
// substring that contains at most k distinct characters.
//
//For example, given s = "abcba" and k = 2, the longest substring
// with k distinct characters is "bcb".

int findLongestSub(const char string[], int numOfDistinct, int strLen);

int main(){
    const char string[] = "acbcccccba";
    int strLen = *(&string + 1) - string;
    int numDistinct = 3;

    std::cout<<findLongestSub(string, numDistinct, strLen);
}

int findLongestSub(char string[], int numOfDistinct, int strLen){
    int numOfDistinctInRun = 0;
    int maxRunLength = 0;
    int lenOfCurrRun = 0;
    char currRun[numOfDistinct];
    bool isDistinct = true;


    for (int j = 0; j < numOfDistinct; ++j) {
        if (currRun[j] == string[0]){
            isDistinct = false;
        }
    }

    if (isDistinct){
        currRun[numOfDistinctInRun] = string[0];
        numOfDistinctInRun++;

        if (numOfDistinctInRun > numOfDistinct){
            maxRunLength = (lenOfCurrRun > maxRunLength) ? lenOfCurrRun : maxRunLength;

            lenOfCurrRun = 0;
            numOfDistinctInRun = 0;
            for (int j = 0; j < numOfDistinct; ++j) {
                currRun[j] = '\0';
            }
        }
    }

    return ;
}
