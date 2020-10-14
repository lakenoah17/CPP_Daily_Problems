#include "map"
#include "string"
#include "iostream"
//This problem was asked by Microsoft.
//
//Given a dictionary of words and a string
// made up of those words (no spaces),
// return the original sentence in a list.
// If there is more than one possible
// reconstruction, return any of them. If
// there is no possible reconstruction,
// then return null.
//
//For example, given the set of words
// 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox",
// you should return ['the', 'quick', 'brown', 'fox'].
//
//Given the set of words
// 'bed', 'bath', 'bedbath', 'and', 'beyond',
// and the string "bedbathandbeyond", return
// either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond']

std::string * findSentenceArr(std::map<std::string, std::string> words, std::string sentence);

int main(){
    std::map<std::string, std::string> words;
    words.insert(std::make_pair("quick","thequickbrownfox"));
    words.insert(std::make_pair("brown","thequickbrownfox"));
    words.insert(std::make_pair("the","thequickbrownfox"));
    words.insert(std::make_pair("fox","thequickbrownfox"));

    std::string * wordArr = findSentenceArr(words, "thequickbrownfox");

    int wordCount = wordArr->size();

    std::cout<<'[';
    for (int i = 0; i < wordCount; ++i) {
        std::cout<<*(wordArr + i)<<','<<' ';
    }
    std::cout<<*(wordArr + wordCount)<<']';
}

std::string * findSentenceArr(std::map<std::string, std::string> words, std::string sentence){
    int numOfWordsPossible = words.size();

    auto * wordsArr = new std::string[numOfWordsPossible];
    int currWordIndex = 0;
    int savedIndex = 0;
    int runLength = sentence.length();

    for (int i = 0; i < runLength; ++i) {
        if (words.find(sentence.substr(0, savedIndex)) != words.end()){
            wordsArr[currWordIndex] = sentence.substr(0, savedIndex);
            currWordIndex++;
            sentence = sentence.substr(savedIndex, sentence.length());
            savedIndex = 0;
            i--;
        } else{
            savedIndex++;
        }


    }

    if (words.find(sentence.substr(0, savedIndex+1)) != words.end()){
        wordsArr[currWordIndex] = sentence.substr(0, savedIndex);
        sentence = sentence.substr(savedIndex, sentence.length());
    }

    if (sentence.empty()){
        return wordsArr;
    }
    return nullptr;
}

