/*

- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Buy wherever you get the low price, (keep updating the low price as long as you keep getting the low price)

Then whenever you get the first high price considering you bought the stock once, sell it immediately.
Then buy the same stock on the same day and continue this process.

Initially consider that you bought the stock on first day. and then continue the process.

// edge cases of len

profit = 0 
buy = prices[0]
for(i = 1 to len){

   if(price < buy) {
        buy = price
   }
   else {
    profit = price - buy 
    buy = price;
   }


}


*/
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            
            int len = prices.size();
            if (len == 1) return 0;
    
            int profit = 0;
            int buyPrice = prices[0];
            for(int i = 1; i < len; i++) {
    
                int currPrice = prices[i];
    
                if(currPrice > buyPrice) {
                    profit += currPrice - buyPrice;
                    buyPrice = currPrice;
                }
                else {
                    buyPrice = currPrice;
                }
            }
    
            return profit;
        }
    };