#include "string"
#include "iostream"
//This problem was asked by Facebook.
//
//Implement regular expression matching
// with the following special characters:
//
//. (period) which matches any single character
//* (asterisk) which matches zero or more of the
// preceding element
//That is, implement a function that takes in a
// string and a valid regular expression and
// returns whether or not the string matches
// the regular expression.
//
//For example, given the regular expression "ra."
// and the string "ray", your function should return
// true. The same regular expression on the string
// "raymond" should return false.
//
//Given the regular expression ".*at" and the string
// "chat", your function should return true. The same
// regular expression on the string "chats" should
// return false.

bool findExpressionMatch(std::string expression, std::string stringToMatch);

int main(){
    std::cout<<findExpressionMatch("ra.","ray")<<'\n';
    std::cout<<findExpressionMatch("ra.","raymond")<<'\n';

    std::cout<<findExpressionMatch(".*at","chhhhhhhhatat")<<'\n';
    std::cout<<findExpressionMatch(".*at","chats")<<'\n';
}

bool findExpressionMatch(std::string expression, std::string stringToMatch){
    int currIndex = 0;
    int expressionIndex = 0;

    while (currIndex < stringToMatch.length() && expressionIndex < expression.length()){
        if (expression[expressionIndex] == '.'){
            currIndex++;
            expressionIndex++;
        }
        else if (expression[expressionIndex] == '*') {
            std::string afterAstString = "";
            expressionIndex++;

            if (expressionIndex == expression.length()){
                return true;
            }

            while (expression[expressionIndex] != '*' && expression[expressionIndex] != '.' && expressionIndex < expression.length()){
                afterAstString += expression[expressionIndex];
                expressionIndex++;
            }

            if (stringToMatch.substr(currIndex).find(afterAstString) != -1){
                currIndex = stringToMatch.substr(currIndex).find(afterAstString) + afterAstString.length() + 1;
            }
            else{
                return false;
            }
        }
        else{
            if (expression[expressionIndex] == stringToMatch[currIndex]){
                currIndex++;
                expressionIndex++;
            }
            else{
                return false;
            }
        }
    }

    return currIndex == stringToMatch.length() && expressionIndex == expression.length();
}