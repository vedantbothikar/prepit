/*

- https://leetcode.com/problems/hand-of-straights/
- https://neetcode.io/solutions/hand-of-straights

store the counts of each card in a hashmap
sort all the cards

Now one by one check in loops of groupSize if the next elements exists. If they do, then decrement their counts from the hashmap


TC: O(nglogn)
SC: O(n)

*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        unordered_map<int, int> count; // card -> count

        // populate count map
        for(int num : hand) {
            count[num]++;
        }

        // sort the cards
        sort(hand.begin(), hand.end());

        // traverse ever card 
        for(int num : hand) {

            if(count[num] > 0) {

                // traverse for groupSize
                for(int i = 0; i < groupSize; i++) {

                    int card = num + i;
                    if(count[card] == 0) return false;

                    count[card]--;
                }
            }
        }

        return true;
    }
};