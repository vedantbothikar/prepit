#include <bits/stdc++.h>

int hammingWeight(uint32_t n)
{
    /* Approach:        
            CHECK last bit if it is set or not ... if set: count++
            then right shift the number until it becomes zero    
        */

    int count = 0;

    while (n > 0)
    {

        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }

    return count;
}