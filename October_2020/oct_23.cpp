#include "iostream"
#include "string"
//This problem was asked by Google.
//
//The edit distance between two strings
// refers to the minimum number of character
// insertions, deletions, and substitutions
// required to change one string to the
// other. For example, the edit distance
// between “kitten” and “sitting” is three:
// substitute the “k” for “s”, substitute
// the “e” for “i”, and append a “g”.
//
//Given two strings, compute the edit
// distance between them

int findEditDist(std::string origWord, std::string wordToChangeTo);

int main(){
    std::cout<<findEditDist("kitten", "sitting");
}

//Loops through the strings and finds how many different characters there are between the strings
int findEditDist(std::string origWord, std::string wordToChangeTo){
    int i = 0;

    //Loops through the word. Could use a for loop but I figured
    // a while loop iterator served my purposes better originally
    while (i < wordToChangeTo.length()){
        int k = 1;
        while (origWord.find(wordToChangeTo.substr(i, k)) != -1 && k <= wordToChangeTo.length() - i){
            k++;
        }

        if (k == 1){
            i++;
        }
        else{
            int indexInOrig = origWord.find(wordToChangeTo.substr(i, k - 1));

            origWord = origWord.substr(0, indexInOrig) + origWord.substr(indexInOrig + k - 1);

            wordToChangeTo = wordToChangeTo.substr(0, i) + wordToChangeTo.substr(i + k-1);
        }
    }

    return wordToChangeTo.length() > origWord.length() ? wordToChangeTo.length() : origWord.length();
}

