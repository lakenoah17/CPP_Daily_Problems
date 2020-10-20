#include "string"
#include <iostream>
//This problem was asked by Palantir.
//
//Write an algorithm to justify text.
// Given a sequence of words and an
// integer line length k, return a list
// of strings which represents each line,
// fully justified.
//
//More specifically, you should have as
// many words as possible in each line.
// There should be at least one space
// between each word. Pad extra spaces
// when necessary so that each line has
// exactly length k. Spaces should be
// distributed as equally as possible,
// with the extra spaces, if any, distributed
// starting from the left.
//
//If you can only fit one word on a line,
// then you should pad the right-hand side
// with spaces.
//
//Each word is guaranteed not to be longer
// than k.
//
//For example, given the list of words
// ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you should return the following:
//
//["the  quick brown", # 1 extra space on the left
//"fox  jumps  over", # 2 extra spaces distributed evenly
//"the   lazy   dog"] # 4 extra spaces distributed evenly

std::string * findJustifiedText(std::string * words, int k, int wordsLen);
std::string getSpacedString(std::string justifiedLine, int k);

int main(){
    std::string words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

    std::string * justified = findJustifiedText(words, 16, 9);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < justified[i].length(); ++j) {
            std::cout<<justified[i][j];
        }
        std::cout<<'\n';
    }
}

std::string * findJustifiedText(std::string * words, int k, int wordsLen){
    int charTotal = 0;
    int numLinesNeeded = 1;
    for (int i = 0; i < wordsLen; ++i) {
        if(charTotal + words[i].size() <= k){
            charTotal+=words[i].length() + 1;
        }
        else{
            numLinesNeeded++;
            charTotal = 0;
            i--;
            continue;
        }
    }

    std::string * justifiedText = new std::string[numLinesNeeded];

    charTotal = 0;
    int currLine = 0;
    std::string justifiedLine = "";

    for (int i = 0; i < wordsLen; ++i) {
        if(charTotal + words[i].length() <= k){
            charTotal += words[i].length() + 1;
            justifiedLine += words[i] + " ";
        }
        else if(charTotal + words[i].length() > k){
            justifiedText[currLine] = getSpacedString(justifiedLine, k);

            justifiedLine = "";

            currLine++;
            charTotal = 0;
            i--;
            continue;
        }
    }
    justifiedText[currLine] = getSpacedString(justifiedLine, k);

    return justifiedText;
}

std::string getSpacedString(std::string justifiedLine, int k){
    //Removes extra end spaces
    while (justifiedLine[justifiedLine.length()-1] == ' '){
        justifiedLine = justifiedLine.substr(0, justifiedLine.length()-1);
    }

    int j = -1;

    while (justifiedLine.length() < k){
        if (justifiedLine[j] == ' '){
            justifiedLine = justifiedLine.substr(0,j + 1) + " " + justifiedLine.substr(j + 1);
            while (justifiedLine[j + 1] == ' '){
                j++;
            }
        }

        j++;
        j %= justifiedLine.length();
    }
    return justifiedLine;
}



