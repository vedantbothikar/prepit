/*

Problem Name: 346. Moving Average from Data Stream
Problem Link: https://leetcode.com/problems/moving-average-from-data-stream/description/?envType=problem-list-v2&envId=design

Approach 1:
- We use a queue
- We keep inserting the elements in the queue
- If we want the average:
    - find the sum of elements from (qSize - size) to (qSize)
    - take the average


Time: 
Every time we are traversing the last size elements, so the TC will be
O(size)

Space:
O(totalElements we insert)



Approach 2:

- Use a dequeue
- since we dont need the past elements, using dequeue we can remove past elementss
- so our dq will be of fixed size always
- and we can maintain the window sum
    - so when a new element comes, we remove the first elemnt and add new element to end
    - and the new window sum can be adjusted
    - this means we can get the window average in constant time






*/
class MovingAverage {

    int windowSum = 0;
    int totalEle = 0;
    deque<int> dq;

    int movAvgWndSize;

public:
    MovingAverage(int size) {
        this->movAvgWndSize = size;
    }
    
    double next(int val) {
        /*

            totalEle++;
            if totalEle > movAvgWndSize:
                - remove the first element
                - insert new element at end
                - deduct firstEle value from windowSum
                - add newEle value to windowSum
                - find the avg = windowSum / movAvgSize

            else if totalEle <= movAvgWndSize:
                - insert the newElement
                - return avg = windowSum / totalEle

        */

        totalEle++;
        int newEle = val;

        if(totalEle > movAvgWndSize) {

            // remove front ele
            int frontEle = dq.front();
            dq.pop_front();

            // push new ele to dq
            dq.push_back(newEle);

            // update the windowSum
            windowSum = windowSum - frontEle + newEle;

            // return avg
            return (double) windowSum / movAvgWndSize;
        }
        
        // if there are less or equal elements
        dq.push_back(newEle);
        windowSum += newEle;
        return (double) windowSum / totalEle;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */