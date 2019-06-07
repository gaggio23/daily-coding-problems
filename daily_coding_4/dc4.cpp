/*
PROBLEM: 
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. 
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

STRATEGY:
The base strategy will be to set all elements of the array that are negative or larger than the max index of the array to 0.
Once this first step is done, second step is to place every element x in arr[x] by swapping pairs (O(n)). 
If, during swapping, x == arr[x], x is seto to 0. 
At the end of this second step, if you traverse the array from index 1 to end, the first index of the array that has a 0 is the
lowest positive integer missing. If there are no 0s, the array has all elements from 0 to max_index, 
so the answer is arr[max_index] + 1
*/


#include <iostream>
#include <vector>
#include <algorithm>


void setupArray(std::vector<int>& arr)
{
    for(int& i : arr)
    {
        if((i < 0) || (i >= static_cast<int>(arr.size())))
        {
            i = 0;
        }
    }
}

int isElementSwappable(int element, std::vector<int>& arr)
{
    if((element == 0) || (element == arr[element])) return false;
    return true;
}

void hashElements(std::vector<int>& arr)
{
    setupArray(arr);
    for(int& i : arr)
    {
        while(isElementSwappable(i, arr))
        {
            if(i == arr[i]) i = 0;
            else std::swap(i, arr[i]);
        }
    }
}

int getFirstMissingPositiveInteger(std::vector<int>& arr)
{
    hashElements(arr);
    for(int i = 1; i < static_cast<int>(arr.size()); ++i)
    {
        if(arr[i] == 0) return i;
    }
    return *std::max_element(arr.begin(), arr.end()) + 1;
}

int main()
{
    std::vector<int> arr = {8, 8, 8, 8, 8};
    std::cout << getFirstMissingPositiveInteger(arr) << std::endl;
    return 0;
}