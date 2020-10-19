#include "string"
#include <iostream>
//This problem was asked by Facebook.
//
//Given a string of round, curly, and
// square open and closing brackets,
// return whether the brackets are
// balanced (well-formed).
//
//For example, given the string
// "([])[]({})", you should return
// true.
//
//Given the string "([)]" or "((()",
// you should return false.

bool findBalanced(std::string brackString);

int main(){
    std::cout<<findBalanced("([][]{})");
    std::cout<<findBalanced("([)]");
    std::cout<<findBalanced("((())");
}

bool findBalanced(std::string brackString){
    int depth = 0;
    for (int i = 0; i < brackString.length(); ++i) {

        if (depth == 0){
            brackString = brackString.substr(i + 1);
            i = 0;
        }

        if (brackString[i] == '(' || brackString[i] == '[' || brackString[i] == '{'){
            depth++;
        }

        if (brackString[i] == ')' || brackString[i] == ']' || brackString[i] == '}'){

            for (int j = 1; j <= depth; ++j) {
                if ((brackString[i - j] == '(' && brackString[i + j - 1] != ')') ||
                    (brackString[i - j] == '[' && brackString[i + j - 1] != ']') ||
                    (brackString[i - j] == '{' && brackString[i + j - 1] != '}')){
                    return false;
                }
            }

            depth = 0;
        }
    }

    if (brackString.empty()){
        return true;
    }
    return false;
}
