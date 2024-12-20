/*

- https://leetcode.com/problems/happy-number/
- https://neetcode.io/solutions/happy-number

So, if you ever get 1, then from 1 you will go to 1, then go to 1 again, and so on.
So you will cycle in 1

If it never goes to 1, it is an observation that you will loop back again to some number (not 1) but it will be a cycle.


So, essentially you are supposed to find that the number that is repeating is 1 or something else. if it is 1, it is happy, or else it is not.


You can use a hashset to check if the number has been repeated or not.
Or else you can use floyd's cycle algorithm

TC: O(n)
SC: O(1)

*/
class Solution {

    int sumOfSqs(int n) {

        int sum = 0;
        while(n != 0) {

            int digit = n % 10;
            n = n / 10;

            sum += pow(digit, 2);
        }

        return sum;
    }

public:
    bool isHappy(int n) {
        
        int slow = n;
        int fast = sumOfSqs(n);

        while(slow != fast) {

            slow = sumOfSqs(slow);
            
            fast = sumOfSqs(fast);
            fast = sumOfSqs(fast);
        }

        if (slow == 1) return true;
        
        return false;
    }
};