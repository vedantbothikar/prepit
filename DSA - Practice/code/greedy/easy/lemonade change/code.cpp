/*

NOTE: in the case when we get a 20$ bill, we are first giving away
10$ and 5$
and NOT 3 x 5$

The reason is so that we want to save the number of 5$ bills with us

Suppose we current have
five = 3
ten = 1

And we get a 20$ bill, if we return 3 x 5$
and then we get a 10$ bill, we won't be able to serve the customer
But if we give 10$ and 5$ bill to the customer first
Then we will be left with 2 x 5$ bills with which we can serve the next customer with 10$ bill as well.


*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0, ten = 0;

        for(int bill : bills) {

            if(bill == 5) five++;
            
            else if(bill == 10) {
                
                if(five) {
                    five--;
                    ten++;
                }
                else return false;
            }
            
            else if (bill == 20) {

                if(five and ten) {
                    five--;
                    ten--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else return false;
            }
        }
        
        return true;
    }
};