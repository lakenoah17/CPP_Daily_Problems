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
    const char string[] = "ccbccccbcc";
    int strLen = *(&string + 1) - string;
    int numDistinct = 2;

    std::cout<<findLongestSub(string, numDistinct, strLen);
}

int findLongestSub(const char string[], int numOfDistinct, int strLen){
    int numOfDistinctInRun = 0;
    int maxRunLength = 0;
    int lenOfCurrRun = 0;
    char currRun[numOfDistinct];
    bool isDistinct = true;

    for (int i = 0; i < strLen; i++) {

        while (numOfDistinctInRun <= numOfDistinct && i + lenOfCurrRun + 1 != strLen){

            for (int j = 0; j < numOfDistinct; ++j) {
                if (currRun[j] == string[i+lenOfCurrRun]){
                    isDistinct = false;
                }
            }

            if (isDistinct){
                currRun[numOfDistinctInRun] = string[i+lenOfCurrRun];
                numOfDistinctInRun++;
            }

            lenOfCurrRun++;
            isDistinct = true;
        }

        if (numOfDistinctInRun > numOfDistinct){
            lenOfCurrRun--;
        }

        maxRunLength = (lenOfCurrRun > maxRunLength) ? lenOfCurrRun : maxRunLength;

        lenOfCurrRun = 0;
        numOfDistinctInRun = 0;

        for (int j = 0; j < numOfDistinct; ++j) {
            currRun[j] = '\0';
        }
    }

    return maxRunLength;
}
