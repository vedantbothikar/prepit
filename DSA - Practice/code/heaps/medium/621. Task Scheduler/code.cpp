/*

- https://leetcode.com/problems/task-scheduler/
- https://neetcode.io/solutions/task-scheduler

A -> 2
B -> 2
C -> 1
D -> 1


GOOD QUESTION. Will take time, but will understand concepts well.

- map will store the frequency count of the characters
- heap will store the pair {count, char} so that we can easily access the char with highest freq

our goal is that we need to reduce the count of the most occurring character first.

so while(n) we have to pop the top from the heap and reduce the count 
Now after popping n times,
    if the heap is empty and n is still left:
        // IDLE
        count++;
    else if n is completed and heap still has elements:
        // put back the chars popped from the heap
        you could use a stack to push pairs that were popped earlier, and then push them back again from the stack to pq here 


If the n is greater than the 


the maxheap push and pop will take constant time because at max there would be 26 characters (types of tasks)
so it will be O(log26) which is constant

So, 
TC: O(n)    // n is total number of tasks (adding all frequencies)
SC: O(1)    // since we have at most 26 different characters.

*/
class Solution {

    void populatePQ(vector<char>& tasks, priority_queue <int>& pq) {

        unordered_map <char, int> charCnt;

        for(char task : tasks) {
            charCnt[task]++;
        }

        // push frequencies in pq
        for(auto x : charCnt) {
            
            pq.push(x.second);
        }
    }

public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue <int> pq;
        populatePQ(tasks, pq);  // populate pq with frequencies of chars
        n++;    // we need to increment because that will be the Effective number of slots in a cycle (dry run and think, check examples)

        int count = 0;
        stack<int> tempStack;   // Temporary storage for tasks with remaining frequencies

        int time = n;
        while(!pq.empty()) {

            // pop the top time times and reduce its count 
            while(time > 0 && !pq.empty()) {
                
                int freq = pq.top();
                pq.pop();

                freq--;

                if(freq != 0) {  // if top is 0 we dont want that now
                    tempStack.push(freq);
                }

                time--;
                count++;
            }

            // if time is left, we have to stay idle
            // but if there are no more elements (which means s is empty) we dont need to stay idle
            while(time > 0 && !tempStack.empty()) {
                time--;
                count++;
            }

            // put back the popped elements in pq again
            while(!tempStack.empty()) {
                int freq = tempStack.top();
                tempStack.pop();

                pq.push(freq);
            }

            // reset back time for next iteration
            time = n;
        }

        return count;
    }
};