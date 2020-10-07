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
    //Should be "cbccccbcc" which is 9
    const char string[] = "cacbccccbccaaa";
    int strLen = *(&string + 1) - string;
    int numDistinct = 2;

    std::cout<<findLongestSub(string, numDistinct, strLen);
}

int findLongestSub(const char string[], int numOfDistinct, int strLen){
    int numOfDistinctInRun = 0;
    int maxRunLength = 0;
    int lenOfCurrRun = 0;
    char currRunDistinctLetters[numOfDistinct];
    bool isDistinct = true;

    //Loops through the string
    for (int i = 0; i < strLen; i++) {

        //Checks for runs at every possible letter
        while (numOfDistinctInRun <= numOfDistinct && i + lenOfCurrRun + 1 != strLen){

            //Checks if the current letter is a distinct letter
            for (int j = 0; j < numOfDistinct; ++j) {
                if (currRunDistinctLetters[j] == string[i + lenOfCurrRun]){
                    isDistinct = false;
                }
            }

            //If letter is distinct add it to the distinct arr
            //and add one to distinct count
            if (isDistinct){
                currRunDistinctLetters[numOfDistinctInRun] = string[i + lenOfCurrRun];
                numOfDistinctInRun++;
            }

            lenOfCurrRun++;
            isDistinct = true;
        }

        //Checks if the run ran to the end of the string without
        // more than allotted distinct letters possible and corrects
        // for the extra 1 added to the run length as a result
        if (numOfDistinctInRun > numOfDistinct){
            lenOfCurrRun--;
        }

        //Checks if the currRunDistinctLetters was the longest run
        maxRunLength = (lenOfCurrRun > maxRunLength) ? lenOfCurrRun : maxRunLength;

        lenOfCurrRun = 0;
        numOfDistinctInRun = 0;

        //Resets the distinct letter arr
        for (int j = 0; j < numOfDistinct; ++j) {
            currRunDistinctLetters[j] = '\0';
        }
    }

    return maxRunLength;
}
