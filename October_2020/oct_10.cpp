#include <iostream>
//Good morning! Here's your coding interview
// problem for today.
//
//This problem was asked by Google.
//
//Given an array of integers and a number k,
// where 1 <= k <= length of the array, compute
// the maximum values of each subarray of length
// k.
//
//For example, given array = [10, 5, 2, 7, 8, 7]
// and k = 3, we should get: [10, 7, 8, 8], since:
//
//10 = max(10, 5, 2)
//7 = max(5, 2, 7)
//8 = max(2, 7, 8)
//8 = max(7, 8, 7)
//Do this in O(n) time and O(k) space. You can modify
// the input array in-place and you do not need to
// store the results. You can simply print them out
// as you compute them.
void findLargestOfSubArray(int k, int nums[], int lenOfNums);

int main(){
    int nums[] = {10, 5, 2, 7, 8, 7};
    int k = 3;
    int lenOfNums = *(&nums + 1) - nums;
    findLargestOfSubArray(k, nums, lenOfNums);
}

void findLargestOfSubArray(int k, int nums[], int lenOfNums){
    int currLastIndex = 0;
    int maxIndex = 0;
    int secondMaxIndex = 0;

    for(int i = 0; i < lenOfNums; i++){
        if (i > k){
            currLastIndex++;
        }
        if (nums[i] >= nums[maxIndex]){
            secondMaxIndex = maxIndex;
            maxIndex = i;
        }

        if (i - k == maxIndex || i == k + currLastIndex){
            std::cout<<nums[maxIndex]<<' ';

            int tempSecond = 0;
            for (int j = 0; j < k; ++j) {
                if (nums[i-j] > tempSecond && i-j != maxIndex && i-j != secondMaxIndex){
                    tempSecond = i-j;
                }
            }
            maxIndex = secondMaxIndex;
            secondMaxIndex = tempSecond;
        }

        if (nums[i] >= nums[secondMaxIndex] && maxIndex != i){
            secondMaxIndex = i;
        }
    }
}