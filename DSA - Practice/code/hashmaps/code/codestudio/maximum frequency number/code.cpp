#include <bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here

    unordered_map<int, int> count;

    int maxfreq = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;

        // storing the maximum frequency available
        maxfreq = max(maxfreq, count[arr[i]]);
    }

    // if two or more elements have same maxfrequency
    // we want to return the element which occurs first in the array
    // having the maximum frequency
    // which means the element with lower index

    // no we traverse the vector one by one
    // and check the element that has the same count as the maximum       // one
    for (int i = 0; i < arr.size(); i++)
    {
        if (count[arr[i]] == maxfreq)
        {
            return arr[i];
        }
    }
}

int main()
{

    return 0;
}