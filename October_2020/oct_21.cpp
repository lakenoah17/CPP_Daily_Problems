#include <iostream>
#include <cstring>
#include "math.h"
//This problem was asked by Amazon.
//
//Run-length encoding is a fast and simple
// method of encoding strings. The basic
// idea is to represent repeated successive
// characters as a single count and character.
// For example, the string "AAAABBBCCDAA"
// would be encoded as "4A3B2C1D2A".
//
//Implement run-length encoding and decoding.
// You can assume the string to be encoded have
// no digits and consists solely of alphabetic
// characters. You can assume the string to be
// decoded is valid.

char* encode(char* strToEncode, int strLen);
char* decode(char* strToDecode, int strLen);

int main(){
    char* str = encode("AAAABBBCCDAA", 12);
    int strLen = strlen(str);
    std::cout<<str<<'\n';

    char* decoded = decode(str, strLen);

    std::cout<<decoded;
    return 0;
}

char * encode(char* strToEncode, int strLen){
    char* encoded = new char;
    int encodedIndex = 0;
    int runLength = 0;
    char currRunChar = strToEncode[0];
    int encodedLen = 0;

    for (int i = 0; i <= strLen; ++i) {
        if (i != strLen && strToEncode[i] == currRunChar){
            runLength++;
        } else{
            int lenNum = 0;
            int tempRun = runLength;
            while (tempRun/(int)pow(10,lenNum) != 0){
                tempRun/=(int)pow(10,lenNum);
                lenNum++;
            }

            for (int j = lenNum-1; j >= 0; j--) {
                encoded[lenNum-1-j+encodedIndex] = '0' + (runLength/(int)pow(10,j));
                runLength%=(int)pow(10,lenNum);
            }

            encoded[encodedIndex + lenNum] = currRunChar;
            encodedIndex+=lenNum + 1;

            currRunChar = strToEncode[i];
            runLength = 1;
            encodedLen+=lenNum+1;
        }
    }

    encoded[encodedLen] = '\0';
    return encoded;
}

char * decode(char* strToDecode, int strLen){
    char * decoded = new char;
    int decodedIndex = 0;

    while(strcmp("", strToDecode)) {
        int lenNum = 0;
        int tempRun = atoi(strToDecode);
        while (tempRun/(int)pow(10,lenNum) != 0){
            tempRun/=(int)pow(10,lenNum);
            lenNum++;
        }

        for (int j = 0; j < atoi(strToDecode); ++j) {
            decoded[decodedIndex] = strToDecode[lenNum];
            decodedIndex++;
        }

        strToDecode += lenNum + 1;
    }

    decoded[decodedIndex] = '\0';
    return decoded;
}

