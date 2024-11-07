/*

- https://leetcode.com/problems/counting-bits/description/

Observations:
- We know that whenever a number if left shifted, the number doubles.
- And shifting a number left, essentially means that we are just adding a 0 at the end
- So, this means that when we left shift, we double the number and the number of 1s in the binary representation stay the same
- So I can say that any even number will have the same number of 1s as the half of that number
For example, 
    - 4 will have the same number of 1s as 2
    - 6 will have the same numbner of 1s as 3
So,
    if even number:
        ans[num] = ans[num/2]
-------

Now, if the number is odd number, 
    - then we can just reduce the number by 1, that will make the number even
        - For example, if we have 5, we will reduce by 1 and make it 4
    - And we already know how to find the answer for an even number (above)
    - The only thing we need to add is an additional 1
        - Because every odd number's binary rep has an additional 1 on top of the total number of 1s in the previous even number
            - For example: if it was 5 (101), and 4(100)
                - this means that we get 5 by adding a 1 to 4

So,
    if odd number:
        evenNum = oddNum - 1
        ans[oddNum] = ans[evenNum] + 1

And because ans[evenNum] = ans[evenNum/2]
We can change the equation to:
        ans[oddNum] = ans[evenNum/2] + 1

But since oddNum / 2 will be equal to evenNum / 2
    - for example: (int) 5/2 = 2 and  4/2 = 2

So, we can write:
    ans[oddNum] = ans[oddNum/2] + 1


So, 
    => ans[evenNum] = ans[evenNum/2]
    => ans[oddNum] = ans[oddNum/2] + 1

We can reduce this to
    ans[anyNum] = ans[anyNum/2] + (anyNum & 1)

(anyNum & 1) will return 1 if the number is odd, or else return 0

*/


class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1, 0);
        for(int i = 1; i <= n; i++) {
            ans[i] = ans[i/2] + (i&1);
        }

        return ans;
    }
};